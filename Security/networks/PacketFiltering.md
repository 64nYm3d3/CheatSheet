## The Packet Filter as a Basic Network Tool

Packet filtering is one technique among many implemented in securing firewalls. It is a tool in the sense that it is an instrument 
that aids in the accomplishing tasks. It is a technique because it is a method of accomplishing a tasks.

In a TCP/IP connection, a packet filter analyzes the IP datagram, checking the header information of inbound and outbound traffic, and then either blocks or allows the datagram to pass based on the contents of the source address, destination address, source port, destination port, and/or the connection status. The leading IP routers like Cisco, Bay, and Lucent can be configured to filter IP datagrams. May operating systems can be configured to perform packet filtering, it can be added to any \*nix systems. Support for packet filtering via *ipchains* is included by default in the linux kernel.

These support packet filtering

* \*nix systems
* Windows NT
* Windows 2000
* Virtually all commercial firewalls
* Big $$$ company Routers

Some commercial firewalls have the ability to perform stateful inspection.

# Why use Packet filtering 

Packet filtering, generally, is inexpensive to implement, however it must be understood that a packet filtering device does not provide the same level of security as an application or proxy firewall. In a practical sense, all IP networks are composed of IP subnets and contain routers. Each router is a potential filtering point. Because the cost of the router has already been absorbed, additional cost for packet filtering is not required.

Packet filtering is appropriate where there are modest security requirements. The internal networks of many organizations are not highly segmented. Highly sophisticated firewalls are not necesscary for isolating one part of a network from another. However its a really solid idea to provide some sort of protection separating the production network from the lab or experimental network. A packet filtering device is a very appropriate measure for providing isolation of one subnet from another.

# How do packet filters work?

All packet filters function in the same general fashion. Operating at the layer 3 (*network*) and layer 4 (*transport*), every packet is examined as it enters the protocol stack. The network and transport layers are examined for the following:

* **Protocol** (IP header, network layer) \- In the IP header, the 9th byte (remember the byte count begins with 0) identifies the protocol of the packet. Most filter devices have the capability to differentiate between TCP, UDP, and ICMP
* **Source Address** (IP header, network layer) \- The source addres is the 32\-bit IP address of the  host which created the packet. 
* **Destination Address** (IP header, network layer) \- The destination address is the 32\-bit address of the host the packet is destined for.
* **Source Port** (TCP or UDP header, transoprt layer) \- Each end of a TCP or. UDP connection is bound to a oprt that the packet is sent to. TCP ports are separate and distinct from UDP ports. Generally ports numbered below 1024 are "reserved" ports that many of which well known and have a specifically defined use.Ports numbered above 1024 (inclusive) are known as ephemeral ports, they can be used however a vendor chooses. For a list of well known ports, [refer to RFC1700.](https://tools.ietf.org/html/rfc3232) The source port is pseudo randomly assigned ephemeral port number. Thus it is often not very useful to filter on the source port.
* **Destination Port** (TCP or UDP header, transport layer)\- The destination port number indicates a port that the packet is sent to. Each ervice on the destination host listens to a port. Some well-known ports that might be filtered are 20/TCP and 21/TCP - ftpconnection/data, 23/TCP - telnet, 80/TCP - http, and 53/TCP - DNS zone transfers.
* **Connection Status**(TCP header, transport layer)\- The connection status tells us whether the packet is the first packet of the session. The ACK bit in the TCP header is set to "false" or 0 if this is the first packet in te session. It simply disallows a host from establishing a connection by rejecting or discarding any packets which have the ACK bit set to "false" or 0.

The filtering device compares the values of these fields to rules that have been defined, based upon the values and the rules the packet is either passed or discarded. Many filters also allow additional criteria from the link layer (layer 2) to be defined, such as the network interface where the filtering is to occur.

# Example
Suppose you want to create a simple packet-filtering firewall in linux. You have two NICs, installed and conigured for the two IP subnets, with packet forwarding enabled between the to network interfaces. At this point you have a linux based router.

Supposing that this is your primary firewall between your internal network and the internet, then you might want to allow only www connections originating internally and reject all else. Your ipchains configuration might look like this.

~~~
ipchains -A int-ext -p tcp -dport www -j ACCEPT
ipchains -A int-ext -j REJECT
~~~

The first line adds the ability for connections on port 80 (www) to be accepted and pass from the internal interface to the external interface. It is added to the int-ext chain (sometimes referred to as the access control list). Line two acts as a catch that rejects all other packets. 

Even though its an extremely simplified example, it illustrates a few important popints. First, for a packet to pass, it must be be explicitly defined in the rules. Second, its a good idea to have a "catch all" rule for handling the unexpected.

# Limitations

Packet filters do not inspect the payload of the packet. They do not read the data and make decisions based on the contents. Dangerous forms of permissaible traffic may pass through the filter undetected based on the contents. DA virus in an e-mail attachment will pass id SMTP/POP connections are allowed.

Packet filters are not stateful and will not remember a packet once it's passed. Conversation streams cannot be reconstructe to determine if a connection attempt is malicious (tcpdump might help ;p)  As a result, an assault based upon some packet fragmentation scheme, is difficult to prevent using a packet filter only.

Packet filtering does not deal well with the quirks of certain protocols. FTP is a good example of this. The FTP command stream is established on port 21/TCP and the data stream is on port 20/TCP. The client uses random high TCP ports. The data connection from the ftp server has a source port of 20 and tries to connect to a high destination port number.There are ways around this, but the best all-around solution seemsto be an FTP proxy server.

# Applications of packet filtering

A packet filtering device can be te first-line of defense in the networkand used to block in-bound packets of specific types from ever reaching the protected network. This is known as ingress filtering. Although not a robust firewall, it can be used to reduce the load on the proxy or application firewall.

---
This is a modified and expanded upon GIAC paper I made for personal use.

Ref: https://www.giac.org/paper/gsec/131/packet-filter-basic-network-security-tool/100197


