# Sniff_For_Jesus

How to sniff a hub
As you probablyknow, traffic sent through a hub is sent to every port connected to that hub. Therefore, to analyze a computer on a hub, all you have to do is plug in a packet sniffer to an empty port on the hub, and you can see all communication to and from all computers connected to that hub. While someone may argue that hubs no longer exist in the wild, they a appear in modern under the guise of "Access Points" 

How to sniff a sqwitch

There are three primary ways to capture traffic from a target device on a switched network: port mirroring, ARP cache poisoning, and hubbing out.

Port mirroring, or port spanning is the easiest way to capture the traffic from a target device on a switched network. In this type of setup, you must have access to the command-line of the switch on which the target computer is located. Also, the switch must support port mirroring and have an empty port into which you can plug your analyzer. Using the switches command line, you enter a command that forces the switch to copy all traffic on a certain port to another port ([For cisco this is your resource for learning more about that. ](https://www.cisco.com/c/en/us/td/docs/switches/lan/catalyst2960/software/release/12-2_55_se/configuration/guide/scg_2960/swspan.html (SPAN and RSPAN))) 

Otherwise here is a shortlist of commands:

**Cisco** ```set span <source port> <destination port>```

**Enterasys** ```set port mirroring create <source port> <destination port>```

**Nortel** ```port-mirroring mode mirror-port <source port> monitor-port <destination port>```








