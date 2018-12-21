

## Gather info

**OS information:** C:\Windows\system32> systeminfo | findstr /B /C:"OS Name" /C:"OS Version"
**Hostname:** C:\Windows\system32> hostname
**Our shell uname:** C:\Windows\system32> echo %username%
- **List all users:** C:\Windows\system32> net users
- **Show detailed info about a single user(user1):** C:\Windows\system32> net user user1

**Network interfaces:** C:\Windows\system32> ipconfig /all
**Routing tables:** C:\Windows\system32> route print
**Displays the cache table for all available interfaces:**  C:\Windows\system32> arp -A
**Network connections:** C:\Windows\system32> netstat -ano
**Firewall rules:** C:\Windows\system32> netsh firewall show state
**Firewall config:** C:\Windows\system32> netsh firewall show config

**Lists verbose output for all scheduled tasks:** C:\Windows\system32> schtasks /query /fo LIST /v
**Links running processes to started services:** C:\Windows\system32> tasklist /SVC
**started services:** C:\Windows\system32> net start

**This can be useful sometimes as some 3rd party drivers, even by reputable companies, contain more holes
than Swiss cheese. This is only possible because ring0 exploitation lies outside most peoples expertise:** C:\Windows\system32> DRIVERQUERY


Source
---
http://www.fuzzysecurity.com/tutorials/16.html
