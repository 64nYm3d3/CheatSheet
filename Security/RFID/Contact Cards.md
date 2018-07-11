# This is documentation for smart chips

Plagiarism is all around and formatted for my needs!

### Table
[Basic Construction](#Basic_Construction)
 - [Memory Fundamentals](#Memory_Fundamentals)
 
[Card Fabrication](#Card_Construction)
 - [Chip Specification](#Chip_Specification)
 - [Card Specifications](#Card_Specifications)
 - [Mask ROM](#Mask_ROM)


## Basic Construction
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

<a name="Memory_Fundamentals"></a>
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
- Widely  used  in  the  past.
- While the  memory  is technically erasable,  by  means  of  ultra  violet  light,  the  necessary  quartz
window  is  never  available  in  the  ICC  and  the  memory  is  really  used  in  one  time  programmable
mode (OTP). 

Getting  pretty heavy in real estate terms is: 

EEPROM 
- This memory is erasable by the user and can be rewritten many times (between 10,000 and 1,000,000 in a typical implementation)  

RAM
- The  random  access  memory  (RAM)  is a bit different from the other types of memory here in that it is  volatile  memory  and  as  soon  as  the  power  is  removed  the  datacontents is lost.

As applications became more advanced we implemented more technology into these chips. Where old telphone cards such as SIM could operate with EEPROM   memory   (128   -   512   bytes)   and   the   memory   control   logic. More
sophisticated  applications  will  demand  ROM,  EEPROM,  RAM  and  a  CPU depending on the application. The CPU or micro-controller really being the implementation that lets us refer to them as a "smart".

The  control  logic  should  not  be  overlooked  as  this  is  necessary  not  only  for  communication protocols  but  also  to  offer  some  protection  of  the  memory  against  fraudulent  use. We can differentiate the different types of ICC by their content

- Memory Only
- Memory with security logic
- Memory with CPU

The  security  logic  can  be  used  to  control  access  to  the  memory  for  authorized  use  only.  This  is
usually  accomplished  by  some  form  of  access  code  which  may  be  quite  large  (64  bits  or  more). Clearly the use of EEPROM memory must be strictly controlled and this applies as much to telephone cards as applications using  ICC  for  cryptographic  key  carriers.  The  security  advantage  of  the  CPU  device  is  of  course more significant because the CPU is capable of implementing cryptographic algorithms in its own right, but will be, probably, maybe covered later.

## Card Fabrication
<a name="Card_Construction"></a>

The  manufacture  of  a  smart  card  involves  a  large  number  of  processes  of  which  the  embedding  of  the  chip into the plastic card is key in achieving an overall quality product. This latter process is usually referred to as card  fabrication.  

1. The  whole  operation  starts  with  the  application  requirements  specification.  

2. From  the requirements  individual  specifications  can  be  prepared  for  the  chip,  card,  mask  ROM  software  and  the
application  software.  

3. The  ROM  software  is  provided  to  the  semiconductor  supplier  who  manufactures  the chips. 

4. The card fabricator embeds the chip in the plastic card. It is also quite normal for the fabricator to load the  application  software  and  personalisation  data.  

Security  is  a  fundamental  aspect  in  the  manufacture  of  a smart card and is intrinsic to the total process. However for now consider security separate and it will be covered later.

![SmartCardmanufactureProcess](https://i.imgur.com/0FUIfnf.png)
*Stages involved in the process of manufacturing smart cards*

#### Chip specification
<a name=Chip_Specification></a>
There are **a number of factors to be decided in the specification of the integrated circuit for the smart card. For the purpose of this discussion we will consider a CPU based card although the manufacture of a memory card  is  substantially  a  subset  of  that  described  here.** The  key  parameters  for  the  chip  specification  are  as follows: 
- Microcontroller type (e.g 6805,8051)
- Mask ROM size
- RAM size
- Non volatile memory type (e.g EPROM, EEPROM)
- Non volatile memory size
- Clock speed (external, and optionally internal)
- Electrical parameters (voltage and current)
- Communications parameters  (asynchronous, synchronous, byte, block)
- Reset          mechanism
- Sleep mode (low current standby operation)
- Co-processor (e.g for public key cryptography)


In  practice  the  semiconductor  manufacturers  have  a  range  of  products  for  which  the  above  parameters  are pre-defined.  **The  task  of  the  designer  is  therefore  concerned  with  choosing  the  appropriate  product  for  the particular  application.***  As  mentioned  previously  security  may  be  an  important  issue  for  the  application  and accordingly  there  may  be  extra  requirements  on  the  physical  and  logical  security  offered  by  the  particular chip. 

Conformance  to  ISO  standards  is  also  likely  to  be  a  requirement  and  in  this  area  ISO  7816  -  3 (Electronic signals and transmission protocols) is the principle standard to be considered. It should be noted however  that  ETSI  (European  Telecommunications  Standard  Institute)  are  currently  developing  new standards for the CEN TC224 committee. These standards are more stringent than that described by the ISO standards.  For  example  the  ISO  7816-3  allows  a  card  current  supply  of  up  to  200  mA.  ETSI  have recommended 20mA for normal use and 10mA for applications such as portable phones.

#### Card Specifications
<a name =Card_Specifications></a>
The specification of a card involves parameters that are common to many existing applications using the ISO
ID-1 card. The following list defines the main parameters that should be defined,
- Card dimensions
- Chip location (contact card)
- Card material (e.g PVC, ABS)
- Printing requirements
- Magnetic stripe (optional)
- Signature strip (optional)
- Hologram or photo (optional)
- Embossing (optional)
- Environmental parameters

The  characteristics  of  the  smart  card  are  part  of  the  ISO  7816  part  1  (physical)  and  2  (contact  location) standards. The choice of chip location has been a difficult subject due largely to the use of magnetic stripes. The  early  French  cards  put  the  IC  module  further  off  the  longitudinal  axis  of  the  card  than  the  standard eventually agreed by ISO.

This  was  preferable  because  of  the  residual  risk  of  chip  damage  due  to  bending.  The  French  Transac  tracks were  lower  on  the  card  which  also  made  this  position  preferable.  The  now  agreed  ISO  standards  for magnetic  stripes  resulted  in  the  French  chip  position  and  the  magnetic  stripe  being  coincident.  Hence  the now agreed lower location which does of course result in higher bending stress on the chip.  The ISO 7816-2 standard  does  however  allow  the  position  of  the  contacts  to  be  either  side  of  the  card.  More  recently  there have  been  moves  to  remove  this  option  with  the  front  (opposite  to  the  side  containing  the  magnetic  stripe) being the preferred position for the IC connector.

The  choice  of  card  material  effects  the  environmental  properties  of  the  finished  product.  PVC  was traditionally  used  in  the  manufacture  of  cards  and  enabled  a  higher  printing  resolution.  Such  cards  arelaminated as three layers with transparent overlays on the front and back. More recently ABS has been usedwhich  allows  the  card  to  be  produced  by  an  injection  moulding  process.  It  is  even  proposed  that  the  chipmicromodule  could  be  inserted  in  one  step  as  part  of  the  moulding  process.  Temperature  stability  is  clearly important for some applications and ETSI are particulary concerned here, such that their higher temperature requirement will need the use of polycarbonate materials

#### Mask ROM Specification
<a name=Mask_ROM></a>
**The  mask  ROM  contains  the  operating  system  of  the  smart  card.**  It  is  largely  concerned  with  themanagement  of  data  files  but  it  may  optionally  involve  additional  features  such  as  cryptographic  algorithms (e.g  DES).  In  some  ways  this  is  still  a  relatively  immature  part  of  the  smart  card  standards  since  the  early applications  used  the  smart  card  largely  as  a  data  store  with  some  simple  security  features  such  as  PIN checking.  The  relevant  part  of  the  ISO  standard  is  7816-4  (commands).  There  is  a  school  of  thought    that envisages  substantial  changes  in  this  area  to  account  for  the  needs  of  multi-application  cards  where  it  is essential  to  provide  the  necessary  security  segregation.  The  developed  code  is  given  to  the  supplier  who incorporates this data as part of the chip manufacturing process

#### Application Software Specification
**This  part  of  the  card  development  process  is  clearly  specific  to  the  particular  application.**  The  application code  could  be  designed  as  part  of  the  mask  ROM  code  but  the  more  modern  approach  is  to  design  the application  software  to  operate  from  the  PROM  non  volatile  memory.  This  allows  a  far  more  flexible approach  since  the  application  can  be  loaded  into  the  chip  after  manufacture.  More  over  by  the  use  of EEPROM it is possible to change this code in an development environment. The manufacturer of a chip with the users ROM code takes on average three months. Application code can be loaded into the PROM memory in minutes with no further reference to the chip manufacturer.

#### Chip Fabrication
The fabrication of the card involves a number of processes as shown below. The first part of the process is to  manufacture  a  substrate  which  contains  the  chip.    This  is  often  called  a  COB  (Chip  On  Board)  and consists  of  a  glass  epoxy  connector  board  on  which  the  chip  is  bonded  to  the  connectors.  There  are  three technologies  available  for  this  process,  wire  bonding,  flip  chip  processing  and  tape  automated  bonding (TAB).  In  each  case  the  semiconductor  wafer  manufactured  by  the  semiconductor  supplier  is  diced  intoindividual  chips .  This  may  be  done  by  scribing  with  a  diamond  tipped  point  and  then  pressure  rolling  thewafers so that it fractures along the scribe lines. More commonly the die are separated from the wafer by the use of a diamond saw. A mylar sheet is stuck to the back of the wafer so that following separation the dice remain attached to the mylar film. Danger Will Robinson! Raw DIEs ahead

![ChipFabrication](https://i.imgur.com/G2W2AUB.png)

Wire bonding is the most commonly used technique in the manufacture of smart cards. Here a 25uM gold or aluminium wire is bonded to the pads on the chip using ultrasonic or thermo compression bonding. Thermo compression bonding requires the substrate to be maintained at between 150C and 200C. The temperature at 6 the bonding interface can reach 350C. To alleviate these problems thermo sonic bonding is often used which is a combination of the two processes but which operate at lower temperatures.

The  die  mounting  and  wire  bonding  processes  involve  a  large  number  of  operations  and  are  therefore  quite expensive.  Because  in  general  only  5  or  6  wires  are  bonded  for  smart  card  applications  this  approach  is acceptable.  However  in  the  semiconductor  industry  generally  two  other  techniques  are  used,  the  flip  chip process and tape automated bonding. In both cases gold bumps are formed on the die. In flip chip processing the dice are placed face down on the substrate and bonding is effected by solder reflow. With tape automated bonding the dice are attached by thermocompression to copper leads supported on a flexible tape similar to a 35mm film.

The  finished  substrate  is  hermetically  sealed  with  an  inert  material  such  as  epoxy  resin.  The  complete micromodule is then glued into the card which contains the appropriately sized hole. The  fabrication  of  a  contactless  card  is  somewhat  different  since  it  always  involves  a  laminated  card  as shown  inext.  The  ICs  and  their  interconnections  as  well  as  the  aerial  circuits  are  prepared  on  a  flexible polyimide substrate








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

Sneaky plug for the real wiz kids out there https://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication500-157.pdf p.s. I didnt read this either.
