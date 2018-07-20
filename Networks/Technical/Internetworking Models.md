# Internetworking models

When networks first came into being, things communications were proprietary. Most companies ran either a complet DECnet solution or an IBM solution, never both together. In the late 1970's ISO created the OSI model. The *Open Systems Interconnection reference model* was created to help vendors create interoperable network devices and software in the form of **protocols**,  so the world could come to peace. 

**OSI is the primary architectural model for networks.** It describes how data and network communication occurs from one place to another. 
Well at least it should be, it's  a conceptual reference model and blueprint of how communications should take place. It Addresses all the processes needed for communication and divides them into logical groupings called *layers*. When a communcations system is designed in this manner, it's known as a hierarchal or *layered architecture*.

There is a concept called *binding*, in which communication processes that are related to eachother are bound, or grouped, together, at a particular layer. The reason a model is important, is if someone is developing a protocol or application, they only need to be concerned with the function of their layer.
