

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
