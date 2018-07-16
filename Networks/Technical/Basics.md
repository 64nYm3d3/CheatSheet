
## Netoworking quickguide
---

Various headers

## Mac Address
-
The mac address breakdown
[Macs](https://en.wikipedia.org/wiki/MAC_address#/media/File:MAC-48_Address.svg)

Routing
-

Icon Guide
![Icon Guide](http://www.conceptdraw.com/How-To-Guide/picture/Cisco-switches-and-hubs-Design-elements.png)

#### Hubs

A dumb device allowing computers to communicate with eachother.  Hubs dont segment networks, they connect network segments. All hosts hear data being on the same line. 

#### Switch

A device that separates collision domains on a network segment, but not broadcast domains. All hosts in the same broadcast domain hear broadcasts sent to FF:FF:FF:FF:FF:FF on the local network. (Layer 2) These forward or filter frames

#### Router
A device that efficiently breaks up broadcast domains, they also provide connections to WAN services through a serial interface for WAN connections.
* a V.35 physical interface on cisco routers, You can sometimes use V.35-to-RS-232 gender changers to connect V.35 equipment using 25-pin (DB25) serial cables, I know because it's what I have to do.

Hosts must use a protocol like IPv4 to communicate with a host to another network (Layer 3) When a host or server sends a network broadcast, every device on the netork must read and process that broadcast unless you have a router. When a routers interface receives this layer 2 broadcast it can discard it without forwarding it to other networks.

So...
* They don't forward broadcasts by default
* They can filter the network based on Layer 3 information such as an IP address

Functionally in your network they do this...
* Packet Switching (transmitting data via an addressed packet)
* Packet filtering (controlling access to a network based on IP address of source and destination) *packet filtering is both a tool and a technique that is a basic building block of network security*
* Internetwork communication (Two or more routers, connected to eachother, routing traffic between two or more networks)
* Path Selection (routing data from one location to another efficiently)


