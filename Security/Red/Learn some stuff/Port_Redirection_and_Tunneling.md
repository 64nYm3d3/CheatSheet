# Port Redirection and Tunneling

Tunneling involves carrying a protocol over the network encapsulated within a different payload protocol

Portforwarding involves accepting traffic on a given IP address and port and then redirecting it to a different IP address and port. 
~~~ rnetd ~~~ 

can function as an internet redirection server. Redirects TCP connections from one IP address and port to another. rinetd is a single-process server which handles any number of connections to the address/port pairs specified in the file 
~~~ /etc/rinetd.conf. ~~~
