# NMap Cheatz
Quick littles cheat sheet for NMap usage of what I find useful to know :p

Scan Types
-

**\-sN** Probe only (host discovery, not port scan)

**\-sS** SYN Scan

**\-sT** TCP Connect Scan

**\-sU** UDP Scan

**\-sV** Version Scan

**\-O** OS Detection

**--scanflags** Set custom list of TCP  using  URGACKPSHRSTSYNFIN in any order

Aggregate timing options
-
For the longest time could not figure out why my scans were not working in lab but did on the image in my home lab. I struggled because I knew that it was an issue with what I thought was an IPS or some other security measure knowing that the host I wanted to attack existed at the other end. I thought maybe NMap had a signature to its scan and the intention was for me to use ncat or write my own port scanner. Two weeks later at a local security meeting, I learned that the default nmap scan I had been using was too aggressive. I needed to use this setting in order to scan the vulnerable machine in lab. After that day, I gave up technology, and moved into a small off grid community in Montana. I was happy performing each night with them the ritual of peaceful calm.  Throwing rocks at the moon, shaking my fist, screaming to scare away the glowing space egg, which would work every fortnight or so. Eventually despair came over me, as it will when nobody around has any sexual relevance to you. 

**\-T0** Paranoid: Very slow, used for IDS evasion

**\-T1** Sneaky: Quite slow, used for IDS evasion

**\-T2** Polite: Slows down to consume less  bandwidth, runs ~10 times slower than default

**\-T3** Normal: Default, a dynamic timing model  based on target responsiveness

**\-T4** Aggressive: Assumes a fast and reliable network and may overwhelm targets

**\-T5** Insane Very aggressive; will likely overwhelm targets or miss open ports

Scripting engine
- 
Did you guys know NMap has scripting engine? It's useful too

**\-sC** Run default scripts

**--script=<ScriptName>|  <ScriptCategory>|<ScriptDir>...** Run individual or groups of scripts
  
**--script-args=<Name1=Value1,...>** Use the list of script arguments

**--script - updatedb** Update script database
