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

### The upper layers are the top 3 layers of the OSI model.

**Application** 

Provides a user interface; *File, print, message, database, and application services.* The application layer is working as an interface between the actual program and the next layer down by providing way for the application to send information down through the protocol stack. Identifying an confirming the communication partners availibilty, verifying the required resources to permit the specified type of communication also occurs at this layer.
 
**Presentation** 

Presents data and handles processes such as encryption; *Data encryption, compression, and translation services.* The presentation layer gets its name form it's purpose. It presents data to the Application Layer and is responsible for data translation and copde formatting. For example, the layer is responsible for encoding data into a generic standard format for transportation so one application layey on a machine can read data from another one. With this in mind, OSI also includes protocols defining how standard data should be formatted, so functions like data compression , decompression, encryption, decryption, incuding some multimedia operations as well.


**Session**

Keeps diferent applications data separate; *Dialog control.* This layer is responsible for setting up, managing, and dismatling sessions between presentation layer entities, and keeping user data separate. Dialog control between devices also occurs at this layer. Communications is coordinated and organized via 3 different modes:
  - **Simplex** (One way communication, like when I try to flirt)
  - **Half-Duplex**  (Two way communication, but only one can communicate at a time, like a debate)
  - **Full Duplex** (Two way simultanous communication, kind of like an argument)

Since the upper layers dont need to know nothin 'bout networking and network adresses, fuhget-about-em

### The Lower 4 layers of the OSI model

**Transport** - Provides reliable (or unreliable in UDP's case) delivery, it also performs error correction before retransmit; *End-to-end connection*

**Network** - provides logical addressing which routers use for path determination; *Routing*

**Data Link** - Combines packets  into bytes and bytes into frames, provides access to media using MAC addressing,  performs error detection (not correction); *Framing*

**Phsyical** - Moves bits between devices, specifies voltage, wire speed, and pinout of cables; *Physical Topology*






While 

---
Ref:
Todd Lamle SYBEX CCNA study guide
