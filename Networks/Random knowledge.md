
# Egress & Ingress

**Egress** traffic is any data or traffic bound for an external entity and passing through the edge router of the host network to reach its destination node.

Egress filtering is a popular network management technique. It scans all egress traffic for any sign of abnormality or malicious activity and then discards any infected data packets.

**Ingress** traffic is composed of all the data communications and network traffic originating from external networks and destined for a node in the host network.

Ingress traffic can be any form of traffic whose source lies in an external network and whose destination resides inside the host network. Ingress traffic can be from all applications accessed via a remote server or over the Internet.


# Common LAN Traffic issues
* Too many Hosts in a collision or Broadcast Domain
* Broadcast Storms
* Too much multicast Traffic
* Low Badwidth
* Adding hubs for connectivity to the network
* A bunch of ARP broadcasts
* Be wary of broadcast domain size, too large and your bandwidth is wasted
* Get low latency switch ports for all your devices, the biggest bottleneck on your local network now are usually routers and switches, especially since people there are so many legacy ones! Right now, 1 Gbps for desktop and 10 Gbps between switch uplinks should be the minimum
* If a receiving host fails to receives all bytes that is should acknowledge, the communication session may be improved by decresing window size

# Important Things

If a packet hits a pocket on a socket on a port,

And the bus is interrupted as a very last resort, 

And the address of the memory makes your floppy disk abort, 

Then the socket packet pocket has an error to report!

---


If the label on the cable on the table at your house, 

Says the network is connected to the button on your mouse, 

But your packets want to tunnel on another protocol, 

That's repeatedly rejected by the printer down the hall, 

And your screen is all distorted by the side effects of gauss

So your icons in the window are as wavy as a souse,

Then you may as well reboot and go out with a bang,

'Cause as sure as I'm a poet, the sucker's gonna hang!
