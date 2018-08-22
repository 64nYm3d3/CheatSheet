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
    
    Realistically there is no reason that this functionality even be available to  macro code running inside a word processor or a spreadsheet. Virus Scanners will generally scan the main body of code, but generally not the declaration section. Which means you can Alias a function import. like this:
~~~
Private Declare PtrSafe Function CreateThread Lib "kernel32" Alias
"CTAlias" (ByVal Zdz As Long, ByVal Tfnsv As Long, ByVal Kyfde As LongPtr,
Spjyjr As Long, ByVal Pcxhytlle As Long, Coupxdxe As Long) As LongPtr
~~~
Compared to this which will have a higher chance of detection:
~~~
Private Declare PtrSafe Function CreateThread Lib "kernel32" (ByVal Zdz
As Long, ByVal Tfnsv As Long, ByVal Kyfde As LongPtr, Spjyjr As Long,
ByVal Pcxhytlle As Long, Coupxdxe As Long) As LongPtr
Private Declare PtrSafe Function VirtualAlloc Lib "kernel32" (ByVal
Hflhigyw As Long, ByVal Zeruom As Long, ByVal Rlzbwy As Long, ByVal
Dcdtyekv As Long) As LongPtr
Private Declare PtrSafe Function RtlMoveMemory Lib "kernel32" (ByVal
Kojhgx As LongPtr, ByRef Und As Any, ByVal Issacgbu As Long) As LongPtr
~~~

  - Avoid Using Shellcode. We can encode in a number of ways using a number of iterations to ensure that it doesn’t trigger an AV signature and that’s great; that works fine. The problem is that doesn’t alter the fact that it is still obviously shellcode.
  - Modern AV is capable of passing compiled code (including shellcode) into a micro-virtual machine to test.

  - It’s possible to encode this array in a number of ways (for instance as a Base64string) and then reconstruct it at runtime, but this doesn’t reduce AV hit count enough to be generally worth the effort.
 
 
 
 
 
 
 
---
Refs: 

Wil Allsopp - Advanced Penetration testing
 
