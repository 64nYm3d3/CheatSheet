
![SmartCardVertConstruct](https://upload.wikimedia.org/wikipedia/commons/2/2e/Smartcard_chip_structure_and_packaging_EN.svg)

Chip Adhesive: Pretty sure this is self explanatory, adhesive keeping the chip in place inside the encapsulation

Hotmelt: I'm guessing this is glue mounting the substrate to the card body

Substrate: I'm guessing the is the mount for the contacts on the chip

Card Body: The pvc card the chip is attached to

Encapsulation: I'm guessing this is a supporting case that prevents physical damage and corrosion of the chip, and is probably IC packaging

Chip: It kind of looks like a semi conductor device honestly Im not sure what the purpose of this is in detail 

Wire Bonding: A way of making interconnections between an IC or other semi conductor device and IC packaging

![Contact card pinout](http://www.smartcardbasics.com/smart_card_images/smart-card-module.gif)

C1 	VCC: 	+5 VDC power supply input (optional use by the card)

C2 	RESET: 	Reset signal, used to reset the card's communications. Either used itself (reset signal supplied from the interface device) or in combination with an interal reset control circuit (optional use by the card). If internal reset is implemented, the voltage supply on Vcc is mandatory

C3 	CLOCK: 	Provides the card with a clock signal, from which data communications timing is derived

C4 	RESERVED 	AUX1: optionally used for USB interfaces and other uses.

C5 	GND: 	Ground (reference voltage)

C6 	Vpp: 	Programing voltage input (optional). This contact may be used to supply the voltage required to program or to erase the internal non-volatile memory. ISO/IEC 7816-3:1997 designated this as a programming voltage: an input for a higher voltage to program persistent memory (e.g., EEPROM). ISO/IEC 7816-3:2006 designates it SPU, for either standard or proprietary use, as input and/or output.

C7 	I/O: 	Input or Output for serial data (half-duplex) to the integrated circuit inside the card. 

C8 	RESERVED 	AUX2: optionally used for USB interfaces and other uses.

![TheCost](http://www.smartcardbasics.com/smart_card_images/smart-card-functionality.gif)

---
Refs and Material: 

ISO 7816 (Which I didnt use because of the common 200$ shakedown and paywall, its a good thing they let us know "Only informative sections are publicly available" with this doc. The only public information from this ISO standard is the introduction and the definition of a few terms, so informative /s.)

http://www.smartcardbasics.com/smart-card-types.html

http://pinoutguide.com/Memory/SmartCardIso_pinout.shtml
