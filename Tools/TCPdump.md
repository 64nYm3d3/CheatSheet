# TCP dump

Otherwise known as "3 l33t wireshark" among industry professionals. This is truly a tool that the Woz, Torvald, and Gates have blessed for us all.

Table
TCPdump Cheatsheet
pcap Analyses Cheatheet
libpcap
Scripting with pcap


## Cheatsheet

### Command Line Options
* **-A** Print - frame payload in ASCII
* **-c** <count> - Exit after capturing  count packets
* **-D** List available interfaces
* **-e** Print - link-level headers
* **-F** <file> - Use file as the filter expression
* **-G** <n> Rotate the dump file every n seconds
* **-i** <iface> Specifies the capture interface
* **-K** Don't verify TCP checksums
* **-L** List data link types for the interface
* **-n** Don't convert addresses to names
* **-p** Don't capture in promiscuous mode
* **-q** Quick output
* **-r** <file> Read packets from  file
* **-s** <len> Capture up to len bytes per packet
* **-S** Print absolute TCP sequence numbers
* **-t** Don't print timestamps
* **-v[v[v]]** Print more verbose output
* **-w <file>** Write captured packets to file
* **-x** Print frame payload in hex
* **-X** Print frame payload in hex and ASCII
* **-y <type>** Specify the data link type
* **-Z <user>** Drop privileges from root to user

### Capture Filter Primitives
* **[src|dst] host \<host>** - Matches a host as the IP source, destination, or either
* **ether [src|dst] host \<ehost>**- Matches a host as the Ethernet source, destination, or either
* **gateway host \<host>** - Matches packets which used hostas a gateway
* **[src|dst] net \<network>/\<len>** -  Matches packets to or from an endpoint residing in network
* **[tcp|udp] \[src|dst]** - port <port>Matches TCP or UDP packets sent to/from port
* **[tcp|udp] [src|dst]** - portrange <p1> - <p2> Matches TCP or UDP packets to/from a port in the given range
* **less \<length>** - Matches packets less than or equal to length
* **greater \<length>** - Matches packets greater than or equal to length
* **(ether|ip|ip6) proto \<protocol>** - Matches an Ethernet, IPv4, or IPv6 protocol
* **(ether|ip) broadcast** - Matches Ethernet or IPv4 broadcasts
* **(ether|ip|ip6) multicast** - Matches Ethernet, IPv4, or IPv6 multicasts
* **type (mgt|ctl|data) [subtype \<subtype>]** - Matches 802.11 frames based on type and optional subtype
* **vlan [\<vlan>]** - Matches 802.1Q frames, optionally with a VLAN ID of vlan
* **mpls [\<label>]** - Matches MPLS packets, optionally with a label of label
* **\<expr> \<relop> \<expr>** - Matches packets by an arbitrary expression
  
### Protocols
* arp
* ether
* fddi
* icmp
* ip
* ip6
* link
* ppp
* radio
* rarp
* slip
* tcp
* tr
* udp
* wlan

### TCP Flags
* tcp-urg
* tcp-rst
* tcp-ack
* tcp-syn
* tcp-psh
* tcp-fin

### Modifiers
* ! or not
* && or and
* || or or
#### Examples
~~~
udp dst port not 53                   \\UDP not bound for port 53
host 10.0.0.1 && host 10.0.0.2        \\Traffic between these hosts
tcp dst port 80 or 8080               \\Packets to either TCP port
~~~

### ICMP Types
icmp-echoreply
icmp-routeradvert
icmp-tstampreply
icmp-unreach
icmp-routersolicit
icmp-ireq
icmp-sourcequench
icmp-timxceed
icmp-ireqreply
icmp-redirect
icmp-paramprob
icmp-maskreq
icmp-echo
icmp-tstamp
icmp-maskrepl


---
Ref:
http://packetlife.net/media/library/12/tcpdump.pdf
http://www.tcpdump.org/#documentation
