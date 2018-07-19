# Bash

Table
-

### Basic commands for interacting with linux

**cd** - Change Directory

**ls** - List Selection

**file** - determine filetype

**mkdir** - Make Directory

**touch** - create a file

**mv** - move the file

**cp** - copy and paste a file

**pwd** - print working directory


### Useful commands

**tree** - creates a kind of map

**ifconfig** - displays cnetwork interfaces, can be used to do some configurations

**passwd** - changes password

**systemctl** - gives control over **systemd**, which is the system and service manager for linux. When run as first process on boot (as PID 1), it acts as init system that brings up and maintains userspace services.

**grep** - "global regular expression print", processes text line by line and prints any lines which match a specified pattern.
 

Command cheatsheet

**Create sudo user**
~~~
uname@box~# adduser username
uname@box~# usermod -aG sudo username
uname@box~# su - username
~~~

**Start a service**
In this case it's ssh
~~~
┌─[ganymede@parrot]─[~]
└──╼ $sudo systemctl start ssh
~~~

**Verify a running process**

In this case it's ssh again. If you're sexually insecure, don't worry, the "D" only means Damon.
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo netstat -antp|grep sshd
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      19438/sshd          
tcp6       0      0 :::22                   :::*                    LISTEN      19438/sshd
~~~


Dirty knowledge ;)
-

### Systemctl
 - **start** 
 - **stop**
 - **enable**
 - **disable**


### Find, Locate, and Which
Knowing the difference between find, locate, and which.


Prior to using the **locate** command, we must build a local database of **all files** on the file system before using it.
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo updatedb
[sudo] password for ganymede: 
┌─[ganymede@parrot]─[~]
└──╼ $locate svc.exe
/usr/share/metasploit-framework/data/meterpreter/metsvc.exe
/usr/share/metasploit-framework/data/templates/template_x64_windows_svc.exe
/usr/share/metasploit-framework/data/templates/template_x86_windows_svc.exe
/usr/share/responder/tools/MultiRelay/bin/Syssvc.exe
~~~

The **which** command only searches through directories that are defined in the *$PATH* environment variable for a  given filename. If a  match is found, which returns the full path to the file. Since svc 

~~~
┌─[ganymede@parrot]─[~]
└──╼ $which svc
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $which sh
/bin/sh
~~~

The **find** command is more aggressive than either than locate or which, allowing you to recursively search a given path for various files. 
Due to the size of this example I had to collapse it.


<details><summary>Details</summary><p>
   
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo find / -name svc*
/usr/include/rpc/svc_auth.h
/usr/include/rpc/svc.h
/usr/lib/python2.7/dist-packages/samba/dcerpc/svcctl.x86_64-linux-gnu.so
/usr/lib/python2.7/dist-packages/volatility/plugins/malware/svcscan.py
/usr/lib/x86_64-linux-gnu/wine/svchost.exe.so
/usr/lib/x86_64-linux-gnu/wine/fakedlls/svchost.exe
/usr/bin/svcrack
/usr/bin/svcrash
/usr/share/bash-completion/completions/svcadm
/usr/share/regripper/plugins/svcdll.pl
/usr/share/regripper/plugins/svc.pl
/usr/share/regripper/plugins/svchost.pl
/usr/share/regripper/plugins/svc_plus.pl
/usr/share/regripper/plugins/svc2.pl
/usr/share/metasploit-framework/lib/rex/proto/dcerpc/svcctl.rb
/usr/share/metasploit-framework/lib/rex/proto/dcerpc/svcctl
/usr/share/man/man3/svcerr_auth.3.gz
/usr/share/man/man3/svc_freeargs.3.gz
/usr/share/man/man3/svcfd_create.3.gz
/usr/share/man/man3/svc_sendreply.3.gz
/usr/share/man/man3/svc_getreqset.3.gz
/usr/share/man/man3/svc_getargs.3.gz
/usr/share/man/man3/svcerr_progvers.3.gz
/usr/share/man/man3/svcerr_noprog.3.gz
/usr/share/man/man3/svctcp_create.3.gz
/usr/share/man/man3/svc_getcaller.3.gz
/usr/share/man/man3/svcerr_systemerr.3.gz
/usr/share/man/man3/svcerr_decode.3.gz
/usr/share/man/man3/svcerr_weakauth.3.gz
/usr/share/man/man3/svcerr_noproc.3.gz
/usr/share/man/man3/svcudp_create.3.gz
/usr/share/man/man3/svc_unregister.3.gz
/usr/share/man/man3/svc_register.3.gz
/usr/share/man/man3/svc_run.3.gz
/usr/share/man/man3/svc_getreq.3.gz
/usr/share/man/man3/svcudp_bufcreate.3.gz
/usr/share/man/man3/svc_destroy.3.gz
/usr/share/man/man3/svcraw_create.3.gz
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc_xprt.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcauth.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc_rdma.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcauth_gss.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcsock.h
~~~
</p></details>
