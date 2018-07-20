
# Inter-neato-working basics
learn the basics of networking

---

Various headers

Icons you'll see in the wild
-

Icon Guide
![Icon Guide](http://www.conceptdraw.com/How-To-Guide/picture/Cisco-switches-and-hubs-Design-elements.png)

Common LAN networking equipment
-

#### Hubs

A dumb device allowing computers to communicate with eachother.  
* Hubs dont segment networks, they connect network segments. 
* All hosts hear data being on the same line. 

While we don't see traditional hubs in the wild anymore, we do see hubs in the form of an access point in present day!

#### Switch

A device that separates collision domains on a network segment, but not broadcast domains. 

* All hosts in the same broadcast domain hear broadcasts sent to FF:FF:FF:FF:FF:FF on the local network. (Layer 2) 
* These forward or filter frames(Layer 2)

#### Router
A device that efficiently breaks up broadcast domains, they also provide connections to WAN services through a serial interface for WAN connections.
* a V.35 physical interface on cisco routers, You can sometimes use V.35-to-RS-232 gender changers to connect V.35 equipment using 25-pin (DB25) serial cables, I know because it's what I have to do.

Hosts must use a protocol like IPv4 to communicate with a host to another network (Layer 3) When a host or server sends a network broadcast, every device on the netork must read and process that broadcast unless you have a router. When a routers interface receives this layer 2 broadcast it can discard it without forwarding it to other networks.

So...
* They don't forward broadcasts by default
* They can filter the network based on Layer 3 information such as an IP address

Functionally in your network they do this...
* **Packet Switching** (transmitting data via an addressed packet)
* **Packet filtering** (controlling access to a network based on IP address of source and destination) *packet filtering is both a tool and a technique that is a basic building block of network security*
* **Internetwork communication** (Two or more routers, connected to eachother, routing traffic between two or more networks)
* **Path Selection** (routing data from one location to another efficiently)

Common WLAN Equipment
-
WLAN devices connect wireless devices such as computers, printers and tablets to the network. Since most devices today have a WNIC (wireless NIC) you just need to configure a basic access point (AP) to connect to the wored network.

#### Access Points (AP)
Allow wireless devices to connect to a wired network
- extend a collision domain from a switch
- typically their own own stand alone broadcast domain (VLAN)
- Can be standalone, but usually managed through a wireles controller .

#### WLAN Controllers
These are devices that NOC's or admins use to manage AP's in medium to large quantities.
- Automatically handles configuration of AP's
- Traditionally used in Enterprise systems
- With Meraki you can manage small to medium sized network via the cloud using their simple configuration web controller system

#### Firewalls
 Firewalls typically establishes a barrier between a trusted, secure, internal network and the internet.  IPS (Intrusion prevention system) it's really important to be aware of another tool called an IDS (Intrusions detection systems), where the IPS is like a firewall, the IDS is a visibility tool. These monitor and control incoming and outgoing network traffic based on predetermined security rules. There are a few different types of firewalls commonly found:
 
 - Cisco ASA (Adaptive security appliance) firewall, one of the most widely used firewall/VPN solutions for small to medium businesse
 - Fortinet Fortigate
 -Juniper SRX
 -pfSense
 - FireEye

NAT and PAT
-
These two guys are pretty cool and you should get to know them.


#### NAT
It's a method of remapping one IP address space into another by modifying network address information in the IP header of packets while they are in transit across a traffic routing device.

Simply put, NAT gateways can map IP addresses in several ways:

- From a local IP address (like 10.10.3.34) to appear as one global IP address statically
- From a local IP address to any of a rotating pool of global IP addresses a company may have
- From a local IP address plus a particular TCP port to a global IP address or one in a pool of ports (PAT ;) 
- From a global IP address to any of a pool of local IP addresses on a round-robin basis
- Translating IPv4 to IPv6 and vice versa


A NAT gateway will sit between an internal network and an external network
"Pure NAT", operating on IP alone, may or may not correctly parse protocols that are totally concerned with IP information, such as ICMP, depending on whether the payload is interpreted by a host on the "inside" or "outside" of translation. As soon as the protocol stack is traversed, even with such basic protocols as TCP and UDP, the protocols will break unless NAT takes action beyond the network layer. 

It is worth mentioning that there are a few different kinds of NAT 

#### PAT

Is an extension to network address translation (NAT) that permits multiple devices on a local area network (LAN) to be mapped to a single public IP address. 

For example an ISP assigns your router an IP adress, when your client communicates out, it is assigned a port number representing your client, and appended to the private IP address of the router giving it a unique internal address. Lets say your brother drops by your house unannounced after his girlfriend left him, then connects to your personal network with his own client, he gets a different port number, and while you are playing videogames, the traffic from the videos he's watching of his ex on instagram can distinguished by you ISP thanks to this.

It's got a shorter definition under NAT if you just wann a read that.

#### VLANS

Virtual LANs logically break up broadcast domains in a Layer 2 switched network
 - It's really important to understand that even in a swtiched network, a router is still need to provide communications between traffic

