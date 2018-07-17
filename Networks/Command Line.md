# Cisco IOS Command Line Cheatsheet
---

### Verify Basic Configuration:

Shows information about the switch and its interfaces, RAM, NVRAM, flash, IOS, etc.
SW1# show version

Shows the current configuration file stored in DRAM.

~~~
Switch1-Name# show running-config
~~~
 
 

Shows the configuration file stored in NVRAM which is used at first boot process.
~~~
Switch1-Name# show startup-config
~~~
 
 

Lists the commands currently held in the history buffer.
~~~
Switch1-Name# show history
~~~
 
 

Shows an overview of all interfaces, their physical status, protocol status and ip address if assigned.
~~~
Switch1-Name# show ip interface brief
~~~

 
 
Shows detailed information about the specified interface, its status, protocol, duplex, speed, encapsulation, last 5 min traffic.
~~~
Switch1-Name# show interface vlan 1
~~~

 
 
Shows the description of all interfaces
~~~
Switch1-Name# show interfaces description
~~~

 
 
Shows the status of all interfaces like connected or not, speed, duplex, trunk or access vlan.
~~~
Switch1-Name# show interfaces status
~~~

 
 
Shows the public encryption key used for SSH.
~~~
Switch1-Name# show crypto key mypubkey rsa
~~~

 
 
Shows information about the leased IP address (when an interface is configured to get IP address via a dhcp server)
~~~
Switch1-Name# show dhcp lease
~~~

### Router Modes:

Router>: User mode = Limited to basic monitoring commands

Router#: Privileged mode (exec-level mode) = Provides access to all other router commands

Router(config)#: global configuration mode = Commands that affect the entire system

Router(config-if)#: interface mode = Commands that affect interfaces

Router(config-subif)#: subinterface mode = Commands that affect subinterfaces

Router(config-line)#: line mode = Commands that affect in lines modes (console, vty, aux…)

Router(config-router)#: router configuration mode

### Changing switch hostname:

~~~
Switch(config)# hostname SW1
~~~

### Configuring passwords:
~~~
Switch1-Name(config)# enable secret cisco    ! MD5 hash
Switch1-Name(config)# enable password notcisco    ! Clear text
~~~

### Securing console port:

~~~
Switch1-Name(config)# line con 0
Switch1-Name(config-line)# password cisco
Switch1-Name(config-line)# login
~~~

### Securing terminal lines:
~~~
Switch1-Name(config)# line vty 0 4
Switch1-Name(config-line)# password cisco
Switch1-Name(config-line)# login
~~~

### Encrypting passwords:
~~~
Switch1-Name(config)# service password-encryption
~~~
### Configuring banners:
~~~
Switch1-Name(config)# banner motd $
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
UNAUTHORIZED ACCESS IS PROHIBITED
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
$
~~~
(Pretty Banners save lives!)

### Giving the switch an IP address:

~~~
Switch1-Name(config)# interface vlan 1
Switch1-Name(config-if)# ip address 172.16.1.11 255.255.255.0    ! or DHCP
Switch1-Name(config-if)# no shutdown
~~~

### Setting the default gateway:
~~~
Switch1-Name(config)# ip default-gateway 172.16.1.1
~~~
### Saving configuration:
~~~
Switch1-Name# copy running-config startup-config
Destination filename [startup-config]?    ! Press enter to confirm file name.
Building configuration…
[OK]
 
! Short for write memory.
Switch1-Name# wr
Building configuration…
[OK]
~~~
---
Refs: 
https://github.com/slyth11907/Cheatsheets

CCNA Routing and switching guide Todd Lamle
