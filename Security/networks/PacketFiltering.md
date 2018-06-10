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



---
This is a modified and expanded upon GIAC paper I made for personal use.

Ref: https://www.giac.org/paper/gsec/131/packet-filter-basic-network-security-tool/100197


