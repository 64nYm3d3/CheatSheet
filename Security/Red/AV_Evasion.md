# AV evasion

The testing ground Link for your malware.

Step 1: Upload your malware herehttps://www.virustotal.com

Step 2: Was it detected? Modify it.

Step 3: Repeat

Step 4: ???

Step 5; profit

VBA Macro as a Stager
VBA (Visual Basic for Applications) is a subset of Microsoft’s proprietary Visual Basic programming language. It is designed to run solely within Microsoft Word and Excel in order to automate repetitive operations and create custom commands or toolbar buttons. It is capable of importing outside libraries including the entire Windows API. 

Tips: 
 - Function names and variables have been generated randomly
 - Functions being imported from kernel32.dll are suspicious. ie,processes such as 
    + **CreateThread**creating process threads
    + **VirtualAlloc**allocating shellcode
    + **RtlMoveMemory**  moving shellcode into memory.
These will specific ones will generally be flagged by AV regardless of whether there is shellcode or not.

  - Avoid Using Shellcode. We can encode in a number of ways using a number of iterations to ensure that it doesn’t trigger an AV signature and that’s great; that works fine. The problem is that doesn’t alter the fact that it is still obviously shellcode.
  - Modern AV is capable of passing compiled code (including shellcode) into a micro-virtual machine to test.
  - Don't use the auto-open function too much
 
 
 
 
 
 
---
Refs: 

Wil Allsopp - Advanced Penetration testing
 
