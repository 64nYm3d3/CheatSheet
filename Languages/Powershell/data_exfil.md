# Powershell for data exfil!

Powershell functions as a great tool for windows machines. Both PS and .net primitives are installed on every windows machine, and while you can use VBS or wscript to perform exfil, they come with a higher chance for detection. Powershell is a solid framework to perform in and we'll cover some usage and options here.

While there are multiple ways to exfiltrate data, there are a a few really common methods.

- Raw sockets
- HTTP/HTTPS
- Mail(SMTP)
- Other protocols(VoIP, QUIC, e.g.)

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
My host mahine see's the connection
~~~
┌─[ganymede@parrot]─[~]
└──╼ $nc -lvp 5555
listening on [any] 5555 ...
connect to [127.0.0.1] from localhost [127.0.0.1] 57950
~~~


