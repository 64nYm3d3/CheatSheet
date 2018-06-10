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
* **Source Address** (IP header, network layer) \-

---
This is a modified and expanded upon GIAC paper I made for personal use.

Ref: https://www.giac.org/paper/gsec/131/packet-filter-basic-network-security-tool/100197


