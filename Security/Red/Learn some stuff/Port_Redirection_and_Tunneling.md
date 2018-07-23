# Port Redirection and Tunneling

Tunneling involves carrying a protocol over the network encapsulated within a different payload protocol

Portforwarding involves accepting traffic on a given IP address and port and then redirecting it to a different IP address and port. 

## Port Forwarding

The tool **rinet** functions as an internet redirection server. Redirects TCP connections from one IP address and port to another. rinetd is a single-process server which handles any number of connections to the address/port pairs specified in the file 
~~~ /etc/rinetd.conf. 
~~~
Install the tool:
~~~
┌─[✗]─[ganymede@parrot]─[~/Downloads]
└──╼ $sudo apt-get install rinetd
~~~
Edit the file:
~~~
┌─[ganymede@parrot]─[~/Downloads]
└──╼ $vim /etc/rinetd.conf#
~~~
~~~
# this is the configuration file for rinetd, the internet redirection server
#
# you may specify global allow and deny rules here
# only ip addresses are matched, hostnames cannot be specified here
# the wildcards you may use are * and ?
#
# allow 192.168.2.*
# deny 192.168.2.1?


#
# forwarding rules come here
#
# you may specify allow and deny rules after a specific forwarding rule
# to apply to only that forwarding rule
#
# bindadress    bindport  connectaddress  connectport
321.321.321.321    445    123.123.123.123   80

# logging information
logfile /var/log/rinetd.log

# uncomment the following line if you want web-server style logfile format
# logcommon
~~~

So in this example, lets say we have access to a machine, with outbound network traffic only allowed on port 445, we've edited the rinetd.conf file on our home machine at 321.321.321.321 to only allow incoming connections on port 445. On the compromised machine, we can browse connect to http://321.321.321.321:445 which we will then send to another machine,a web browser at 123.123.123.123

## SSH Tunneling

One lesser known feature of SSH is to create encrypted tunnels within the SSH protocol, which supports bi-directional communication channels. Lets say there is trickery going on, and we need to bypass (egress restrictions)[https://github.com/64nYm3d3/CheatSheet/blob/master/Networks/Random%20knowledge.md] on syntax like this 
~~~
ssh <gateway> -L <local port to listen>:<remote host>:<remote port>
~~~



