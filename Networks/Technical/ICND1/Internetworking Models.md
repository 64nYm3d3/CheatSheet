# Internetworking models

When networks first came into being, things communications were proprietary. Most companies ran either a complete DECnet solution or an IBM solution, never both together. In the late 1970's ISO created the OSI model. The *Open Systems Interconnection reference model* was created to help vendors create interoperable network devices and software in the form of **protocols**,  so the world could come to peace. 

**OSI is the primary architectural model for networks.** It describes how data and network communication occurs from one place to another. 
Well at least it should be, it's  a conceptual reference model and blueprint of how communications should take place. It Addresses all the processes needed for communication and divides them into logical groupings called *layers*. When a communcations system is designed in this manner, it's known as a hierarchal or *layered architecture*.

There is a concept called *binding*, in which communication processes that are related to eachother are bound, or grouped, together, at a particular layer. The reason a model is important, is if someone is developing a protocol or application, they only need to be concerned with the function of their layer.

#### Some important benefits of the OSI model:
- It divides thenetwork communication process into smaller, comprehensible components, helping facilitate with development, design, and troubleshooting those components.
- Allows multiple vendors to contribute towards developmment through the standardizatoin of network components.
- It encourages industry standardization
- It allows varying network hardware and software to communicate
- It prevents changes in one layer from affecting other layers to expedite development.


## OSI Reference model

Thhe OSI model has seven different layers. These layers are divided into two groups.

![OSI Model](https://www.lifewire.com/thmb/HmXo1D1vHnFhx9SNVJ34dEuZoDI=/400x0/filters:no_upscale():max_bytes(150000):strip_icc()/basics_osimodel-56a1ad0c5f9b58b7d0c19c53.jpg)

*7 layers of the OSI model*

### The upper 3 layers of the OSI model.

**Application** 

Provides a user interface; *File, print, message, database, and application services.* The application layer is working as an interface between the actual program and the next layer down by providing way for the application to send information down through the protocol stack. Identifying an confirming the communication partners availibilty, verifying the required resources to permit the specified type of communication also occurs at this layer.
 
**Presentation** 

Presents data and handles processes such as encryption; *Data encryption, compression, and translation services.* The presentation layer gets its name form it's purpose. It presents data to the Application Layer and is responsible for data translation and copde formatting. For example, the layer is responsible for encoding data into a generic standard format for transportation so one application layey on a machine can read data from another one. With this in mind, OSI also includes protocols defining how standard data should be formatted, so functions like data compression , decompression, encryption, decryption, incuding some multimedia operations as well.


**Session**

Keeps diferent applications data separate; *Dialog control.* This layer is responsible for setting up, managing, and dismatling sessions between presentation layer entities, and keeping user data separate. Dialog control between devices also occurs at this layer. Communications are coordinated and organized via 3 different modes:
  - **Simplex** (One way communication, like when I try to flirt)
  - **Half-Duplex**  (Two way communication, but only one can communicate at a time, like a debate)
  - **Full Duplex** (Two way simultanous communication, kind of like an argument)

Since the upper layers dont need to know nothin 'bout networking and network adresses, fuhget-about-em

### The Lower 4 layers of the OSI model

**Transport** 

Provides reliable (or unreliable in UDP's case) delivery, it also performs error correction before retransmit; *End-to-end connection.* The Transport layer segments and reassembles data into aa single data stream. Taking all the data from the upper layers and combining them into a concise data stream. These protocols provide end-to-end data transport services and can establish a logical connection betweeen the sending host and the destination host on an internetwork. TCP and UDP are integral to this layerr. The transportation lai responsible for:
 - Providing mechanisms for multiplexingupper applications
 - Estalbishing sessions
 - Tearing down virtual circuits.
 - Hide details of network-dependant information from higher levels or provide transparent data transfer
It can be either connectionless or connection oriented. Reliable networking requires that acknowledgements, sequencing, and flow control all be used

*Connection Oriented communication*

![SYN/ACK](https://s25785.pcdn.co/wp-content/uploads/2017/02/standard_tcp_handshake.png?t=1505317731683&width=673&name=standard_tcp_handshake.png)

For reliable transport, a connection oriented communications session must first be established between devices. It's a peer system known as a *call setup* or more commonly *three way handshake.* 
 **1.** Three way handshake occurs
     
 **2.** Data Transfer occurs
     
 **3.** Call termination tears down virtual circuits
 
 *Connection Oriented communication*

- **SYN** a syncronization request is sent out
- **SYN/ACK** the request is acknowledges the request and and establishes connection parameters. These segments request that the receivers sequencing is synchronized here as well so that a bi-directional connection can be formed.
- **ACK** the final segment is also an ACK, notifying the destination host that the connection agreement has been accepted, with the connection established, data transfer can now begin

Lets say datagrams get sent out from one machine to another on a switched network, too quickly for that machine to process, then they get stored in a memory section called a *buffer*. If the buffer is filled and we run out of allocated memory it's  flooded. The datagrams just get lost and can't find their way home, the subsequent datagrams received just dissapear. Luckily there is a thing called  *flow control*

*Flow Control*

 The fail safe solution to avoid floods and losing data. Flow control ensures data integrity at the transport layer. It  prevents a sending host from overflowing the buffers on the receiving host at request. 
 - The segments delivered are acknowledged back to the sender upon reception
 - Segments are sequenced back into proper order upon arrival at their destination.
 - A manageable data flow is maintained in order to avoid congestion, overloading, or data loss.

 Insteading of dumping and losing data the transport layer can indicate whether it's "ready" or "not ready" to receive segments. Datagrams are delivered to the receiving host (hopefully) in the same sequence they were transmitted. If a failure occurs, data segments are lost, duplicated, or damaged, the receiving host will acknowledge this, have the the sending host retransmit, otherwise acknowledge it has received each and every data segment.
 
 To be connection oriented, a service has to have the following characteristics
 - A virtual circuit or "three-way handshake" is established
 - It uses sequencing
 - It uses acknowledgements
 - It uses flow control
 
 *Windowing*
 
If a machine had to wait for acknowledgement after sending each segment before sending another, the process would be extremely slow. The quantityof data segments that a transmitting machine is allowed to send without receiving acknowledgement is called a *window*.

While some protocols use the number of packets, TCP/IP uses it by counting the number of bytes. 
 
 ![windowing](http://www.learncisco.net/assets/images/icnd1/17-windowing.jpg)
 
 *Windowing Acknowledgements Example*
 
     
     
**Network** - provides logical addressing which routers use for path determination; *Routing.* 

**Data Link** - Combines packets  into bytes and bytes into frames, provides access to media using MAC addressing,  performs error detection (not correction); *Framing*

**Phsyical** - Moves bits between devices, specifies voltage, wire speed, and pinout of cables; *Physical Topology*







While 

---
Ref:

Todd Lamle SYBEX CCNA study guide

http://www.learncisco.net/courses/icnd-1/building-a-network/tcpip-transport-layer.html - if you can't afford the book.
