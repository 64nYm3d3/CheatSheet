# This is documentation for smart chips

Plagiarism is likely all around and formatted for my needs!

### Table
[Basic Construction](#Basic_Construction)
[Memory](#Memory)


<a name="Basic_Construction"></a>
![SmartCardVertConstruct](https://upload.wikimedia.org/wikipedia/commons/2/2e/Smartcard_chip_structure_and_packaging_EN.svg)

**Chip Adhesive:** Pretty sure this is self explanatory, adhesive keeping the chip in place inside the encapsulation

**Hotmelt:** I'm guessing this is glue mounting the substrate to the card body

**Substrate:** This is the epoxy resin thing that all electronics go in (like the memory, raw DIE, pins, whatever) and acts as the system GND(Vss) for the chip 

**Card Body:** The pvc card the chip is attached to

**Encapsulation:** I'm guessing this is a supporting case that prevents physical damage and corrosion of the chip, and is probably IC packaging

**Chip:** It kind of looks like a semi conductor device honestly Im not sure what the purpose of this is in detail 

**Wire Bonding:** A way of making interconnections between an IC or other semi conductor device and IC packaging

![Contact card pinout](http://www.smartcardbasics.com/smart_card_images/smart-card-module.gif)

It is important to know that of the 8 contacts only 6 are defined (The two that arent are c4 and c8)

**C1 	Vcc:** 	+5 VDC power supply input (optional use by the card). As we move towards the future we will likely see this change to +3 VDC

**C2 	RESET:** 	Reset signal, used to reset the card's communications. Either used itself (reset signal supplied from the interface device) or in combination with an interal reset control circuit (optional use by the card). If internal reset is implemented, the voltage supply on Vcc is mandatory. Reset  is  the  signal  line  that  is  used  to  initiate  the  state  of  the  integrated circuit after power on and it is an integral complex process that I will hopefully get too later.

**C3 	CLOCK:** 	Provides the card with a clock signal, from which data communications timing is derived. The  clock  signal  is  used  drive  the  logic  of  the  IC  and  is  also  used  as  the  reference  for  the  serial communications link, the two most common being 3.57 MHz and 4.92 MHz . Which is a weird thing about cameras and really probably not worth explaining why those frequencies.

**C4 	RESERVED 	AUX1:** optionally used for USB interfaces and other uses.

**C5 	GND:** 	Ground (reference voltage). Vss  is  the  substrate  or  ground  reference  voltage  against  which  the  Vcc
potential  is  measured.  

**C6 	VPP:** 	Programing voltage input (optional). This contact may be used to supply the voltage required to program or to erase the internal non-volatile memory.  The Vpp  connector    is  used  for  the  high  voltage  signal  that  is  necessary  to  program  the  EPROM memory. ISO/IEC 7816-3:1997 designated this as a programming voltage: an input for a higher voltage to program persistent memory (e.g., EEPROM). ISO/IEC 7816-3:2006 designates it SPU, for either standard or proprietary use, as input and/or output.

**C7 	I/O:** 	Input or Output for serial data (half-duplex) to the integrated circuit inside the card. Used for sending and receiving commands with either T=0 or T=1 protocol. Their is a communication unit between a smart card and a smart card reader called an [APDU (Application Protocol Data Unit.](https://en.wikipedia.org/wiki/Smart_card_application_protocol_data_unit) There are two categories of APDUs: command APDUs and response APDUs. A command APDU is sent by the reader to the card – it contains a mandatory 4-byte header (CLA, INS, P1, P2) and from 0 to 65 535 bytes of data. A response APDU is sent by the card to the reader – it contains from 0 to 65 536 bytes of data, and 2 mandatory status bytes (SW1, SW2).

**C8 	RESERVED 	AUX2:** optionally used for USB interfaces and other uses.

Communication protocols for contact smart cards include T=0 (character-level transmission protocol, defined in ISO/IEC 7816-3) and T=1 (block-level transmission protocol, defined in ISO/IEC 7816-3). In contrast to the application protocol data unit (APDU, which is the communication unit between the smart card and the smart card reader) specified by ISO/IEC 7816-4, length information is provided only by parameter P3. This indicates the length of the command data or response data. It is also specified by the ISO/IEC 7816-3 standard.

<a name="Memory"></a>
The fundamental component of these IC cards are for portable storage and retrieval of data with the following being commonly used memory types:

- ROM Read only memory (mask ROM)
- PROM Programmable read only memory
- EPROM Erasable programmable ROM
- EEPROM Electrically erasable PROM
- RAM Random access memory

A particular chip may have one or more of these memory types.

ROM is fixed and cannot be changed once manufactured. This  is  a  low  cost memory,  in  that,  it  occupies  minimum  space  on  the  silicon  substrate. The  use  of  the  silicon  is often  referred  to  as  real  estate  because  clearly  one  wants  to  get  as  much  as  possible  into  the smallest possible space. Usually this contains the chips OS.
ROM
- Can not be changed 
- Takes several months to  be  produced  by  the  semiconductor  company.  
- There  is  also  effectively  a  minimum  order quantity in order to achieve this low cost.

In order of increaing real estate: 

PROM
- Programmable by the user through fusible links
- High voltage and currents are required for the programming cycle (and not normally used in ICC)

EPROM
-Widely  used  in  the  past.
-While the  memory  is technically erasable,  by  means  of  ultra  violet  light,  the  necessary  quartz
window  is  never  available  in  the  ICC  and  the  memory  is  really  used  in  one  time  programmable
mode (OTP). 

Getting  pretty heavy in real estate terms is: 

EEPROM 
- This memory is erasable by the user and can be rewritten many times (between 10,000 and 1,000,000 in a typical implementation)  

RAM
-The  random  access  memory  (RAM)  is a bit different from the other types of memory here in that it is  volatile  memory  and  as  soon  as  the  power  is  removed  the  datacontents is lost.

As applications became more advanced we implemented more technology into these chips. Where old telphone cards such as SIM could operate with EEPROM   memory   (128   -   512   bytes)   and   the   memory   control   logic. More
sophisticated  applications  will  demand  ROM,  EEPROM,  RAM  and  a  CPU depending on the application. The CPU or micro-controller really being the implementation that lets us refer to them as a "smart".

The  control  logic  should  not  be  overlooked  as  this  is  necessary  not  only  for  communication protocols  but  also  to  offer  some  protection  of  the  memory  against  fraudulent  use. We can differentiate the different types of ICC by their content

-Memory Only
-Memory with security logic
-Memory with CPU

The T = 0 protocol is byte-oriented, which means that the smallest unit processed by the protocol is a single byte. The transmission data unit consists of a header containing a class byte, a command byte and three parameter bytes, optionally followed by a data section. 


| Class  | Command | Parameter 1 | Parameter 2 | Parameter 3 | Data (optional) |
| --- | --- |  --- |  --- |  --- | --- |
| CLS 8 bits  | CMDS 8 bits  | P1 8 bits | P2 8 bits | P3 8 bits | Data |
 | Data (Optional) | Data (Optional) | Data (Optional) | Data (Optional) | Data (Optional) | Data (Optional)|


40 bits and I’m guessing 8 more bits will get tacked on in data to terminate the header if there is no data, but didnt see anything on it. So I will asssume frames(?) will end up being a minimum of 48 bits or 6 bytes minimum. I apologize as I did not find a visual example or a detailed description on the header size when reading about T=0 transmission protocol.

The  clock  signal  is  used  drive  the  logic  of  the  IC  and  is  also  used  as  the  reference  for  the  serial
communications link.

---
Refs and Material: 

ISO 7816 (Which I didnt use because of the common 200$ shakedown and paywall with ISO, its a good thing they let us know "Only informative sections are publicly available" with this doc. The only public information from this ISO standard is the introduction and the definition of a few terms, which is soooo informative /s.)

http://www.smartcardbasics.com/smart-card-types.html

http://pinoutguide.com/Memory/SmartCardIso_pinout.shtml

http://www.gorferay.com/the-t-0-transmission-protocol/

https://en.wikipedia.org/wiki/Smart_card_application_protocol_data_unit

http://www.smartcard.co.uk/tutorials/sct-itsc.pdf
