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

#### The upper layers are the top 3 layers of the OSI model.

**Application** - provides a user interface

**Presentation** - Presents data and handdles processes such as encryption

**Session** - Keeps diferent applications data separate
