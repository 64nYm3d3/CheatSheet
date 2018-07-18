# Big list of tools, exploits, whatever I felt needed to be here and how to use them
This is a modified list of the pentest-standard.org technical guidelines. The site misses a few things involving social engineering, physec, buffer overflows and some others. I've (hopefully) compressed the table of contents a bit and added to the document.


##### Table of Contents  


   1 Tools_Required
        1.1 Operating_Systems
            1.1.1 MacOS_X
            1.1.2 VMware_Workstation
                1.1.2.1 Linux
                1.1.2.2 Windows_XP/7
        1.2 Radio_Frequency_Tools
            1.2.1 Frequency_Counter
            1.2.2 Frequency_Scanner
            1.2.3 Spectrum_Analyzer
            1.2.4 802.11_USB_adapter
            1.2.5 External_Antennas
            1.2.6 USB_GPS
        1.3 Software
    2 Intelligence Gathering
        2.1 OSINT
            2.1.1 Corporate
            2.1.2 Physical
                2.1.2.1 Locations
                2.1.2.2 Shared/Individual
                2.1.2.3 Owner
                    2.1.2.3.1 Land/tax_records
            2.1.3 Datacenter_Locations
                2.1.3.1 Time_zones
                2.1.3.2 Offsite_gathering
                2.1.3.3 Product/Services
                2.1.3.4 Company_Dates
                2.1.3.5 Position_identification
                2.1.3.6 Organizational_Chart
                2.1.3.7 Corporate_Communications
                    2.1.3.7.1 Marketing
                    2.1.3.7.2 Lawsuits
                    2.1.3.7.3 Transactions
                2.1.3.8 Job_openings
            2.1.4 Relationships
                2.1.4.1 Charity_Affiliations
                2.1.4.2 Network_Providers
                2.1.4.3 Business_Partners
                2.1.4.4 Competitors
        2.2 Individuals
            2.2.1 Social_Networking_Profile
            2.2.2 Social_Networking_Websites
            2.2.3 Cree.py
        2.3 Internet_Footprint
            2.3.1 Email_addresses
                2.3.1.1 Maltego
                2.3.1.2 TheHarvester
                2.3.1.3 NetGlub
            2.3.2 Usernames/Handles
            2.3.3 Social_Networks
                2.3.3.1 Newsgroups
                2.3.3.2 Mailing_Lists
                2.3.3.3 Chat_rooms
                2.3.3.4 Forums_Search
            2.3.4 Personal_Domain_Names
            2.3.5 Personal_Activities
                2.3.5.1 Audio
                2.3.5.2 Video
            2.3.6 Archived_Information
            2.3.7 Electronic_Data
                2.3.7.1 Document_leakage
                2.3.7.2 Metadata_leakage
                    2.3.7.2.1 FOCA_(Windows)
                    2.3.7.2.2 Foundstone_SiteDigger_(Windows)
                    2.3.7.2.3 Metagoofil_(Linux/Windows)
                    2.3.7.2.4 Exif Reader_(Windows)
                    2.3.7.2.5 ExifTool_(Windows/ OS X)
                    2.3.7.2.6 Image_Search
        2.4 Covert_gathering
            2.4.1 On-location_gathering
                2.4.1.1 Adjacent_Facilities
                2.4.1.2 Physical_security_inspections
                    2.4.1.2.1 Security_guards
                    2.4.1.2.2 Badge_Usage
                    2.4.1.2.3 Locking_devices
                    2.4.1.2.4 Intrusion_detection_systems_(IDS)/Alarms
                    2.4.1.2.5 Security_lighting
                    2.4.1.2.6 Surveillance_/CCTV_systems
                    2.4.1.2.7 Access_control_devices
                    2.4.1.2.8 Environmental_Design
                2.4.1.3 Employee_Behavior
                2.4.1.4 Dumpster_diving
                2.4.1.5 RF_/Wireless_Frequency_scanning
            2.4.2 Frequency_Usage
            2.4.3 Equipment_Identification
                2.4.3.1 Airmon-ng
                2.4.3.2 Airodump-ng
                2.4.3.3 Kismet-Newcore
                2.4.3.4 inSSIDer
        2.5 External_Footprinting
            2.5.1 Identifying_IP_Ranges
                2.5.1.1 WHOIS_lookup
                2.5.1.2 BGP_looking_glasses
            2.5.2 Active_Reconnaissance
            2.5.3 Passive_Reconnaissance
            2.5.4 Active_Footprinting
                2.5.4.1 Zone_Transfers
                    2.5.4.1.1 Host
                    2.5.4.1.2 Dig
                2.5.4.2 Reverse_DNS
                2.5.4.3 DNS_Bruting
                    2.5.4.3.1 Fierce2_(Linux)
                    2.5.4.3.2 DNSEnum_(Linux)
                    2.5.4.3.3 Dnsdict6_(Linux)
                2.5.4.4 Port_Scanning
                    2.5.4.4.1 Nmap_(Windows/Linux)
                2.5.4.5 SNMP_Sweeps
                    2.5.4.5.1 SNMPEnum_(Linux)
                2.5.4.6 SMTP_Bounce_Back
                2.5.4.7 Banner_Grabbing
                    2.5.4.7.1 HTTP
        2.6 Internal_Footprinting
            2.6.1 Active_Footprinting
                2.6.1.1 Ping_Sweeps
                    2.6.1.1.1 Nmap_(Windows/Linux)
                    2.6.1.1.2 Alive6_(Linux)
                2.6.1.2 Port_Scanning
                    2.6.1.2.1 Nmap_(Windows/Linux)
                2.6.1.3 SNMP_Sweeps
                    2.6.1.3.1 SNMPEnum_(Linux)
                2.6.1.4 Metasploit
                2.6.1.5 Zone_Transfers
                    2.6.1.5.1 Host
                    2.6.1.5.2 Dig
                2.6.1.6 SMTP_Bounce_Back
                2.6.1.7 Reverse_DNS
                2.6.1.8 Banner_Grabbing
                    2.6.1.8.1 HTTP
                    2.6.1.8.2 httprint
                2.6.1.9 VoIP_mapping
                    2.6.1.9.1 Extensions
                    2.6.1.9.2 Svwar
                    2.6.1.9.3 enumIAX
                2.6.1.10 Passive_Reconnaissance
                    2.6.1.10.1 Packet_Sniffing
    3 Vulnerability_Analysis
        3.1 Vulnerability Testing
            3.1.1 Active
            3.1.2 Automated Tools
                3.1.2.1 Network/General Vulnerability Scanners
                3.1.2.2 Open Vulnerability Assessment System (OpenVAS) (Linux)
                3.1.2.3 Nessus (Windows/Linux)
                3.1.2.4 NeXpose
                3.1.2.5 eEYE Retina
                3.1.2.6 Qualys
                3.1.2.7 Core IMPACT
                    3.1.2.7.1 Core IMPACT Web
                    3.1.2.7.2 Core IMPACT WiFi
                    3.1.2.7.3 Core IMPACT Client Side
                    3.1.2.7.4 Core Web
                    3.1.2.7.5 coreWEBcrawl
                    3.1.2.7.6 Core Onestep Web RPTs
                    3.1.2.7.7 Core WiFi
                3.1.2.8 SAINT
                    3.1.2.8.1 SAINTscanner
                    3.1.2.8.2 SAINTexploit
                    3.1.2.8.3 SAINTwriter
            3.1.3 Web Application Scanners
                3.1.3.1 General Web Application Scanners
                    3.1.3.1.1 WebInspect (Windows)
                    3.1.3.1.2 IBM AppScan
                    3.1.3.1.3 Web Directory Listing/Bruteforcing
                    3.1.3.1.4 Webserver Version/Vulnerability Identification
                3.1.3.2 NetSparker (Windows)
                3.1.3.3 Specialized Vulnerability Scanners
                    3.1.3.3.1 Virtual Private Networking (VPN)
                    3.1.3.3.2 IPv6
                    3.1.3.3.3 War Dialing
            3.1.4 Passive Testing
                3.1.4.1 Automated Tools
                    3.1.4.1.1 Traffic Monitoring
                3.1.4.2 Wireshark
                3.1.4.3 Tcpdump
                3.1.4.4 Metasploit Scanners
                    3.1.4.4.1 Metasploit Unleashed
        3.2 Vulnerability Validation
            3.2.1 Public Research
                3.2.1.1 Common/default passwords
            3.2.2 Establish target list
                3.2.2.1 Mapping Versions
                3.2.2.2 Identifying Patch Levels
                3.2.2.3 Looking for Weak Web Applications
                3.2.2.4 Identify Weak Ports and Services
                3.2.2.5 Identify Lockout threshold
        3.3 Attack Avenues
            3.3.1 Creation of Attack Trees
            3.3.2 Identify protection mechanisms
                3.3.2.1 Network protections
                    3.3.2.1.1 "Simple" Packet Filters
                    3.3.2.1.2 Traffic shaping devices
                    3.3.2.1.3 Data Loss Prevention (DLP) systems
                3.3.2.2 Host based protections
                    3.3.2.2.1 Stack/heap protections
                    3.3.2.2.2 Whitelisting
                    3.3.2.2.3 AV/Filtering/Behavioral Analysis
                3.3.2.3 Application level protections
    4 Exploitation
        4.1 Precision strike
            4.1.1 Countermeasure Bypass
                4.1.1.1 AV
                4.1.1.2 Human
                4.1.1.3 HIPS
                4.1.1.4 DEP
                4.1.1.5 ASLR
                4.1.1.6 VA + NX (Linux)
                4.1.1.7 w^x (OpenBSD)
                4.1.1.8 WAF
                4.1.1.9 Stack Canaries
                    4.1.1.9.1 Microsoft Windows
                    4.1.1.9.2 Linux
                    4.1.1.9.3 MAC OS
        4.2 Customized Exploitation
            4.2.1 Fuzzing
            4.2.2 Dumb Fuzzing
            4.2.3 Intelligent Fuzzing
            4.2.4 Sniffing
                4.2.4.1 Wireshark
                4.2.4.2 Tcpdump
            4.2.5 Brute-Force
                4.2.5.1 Brutus (Windows)
                4.2.5.2 Web Brute (Windows)
                4.2.5.3 THC-Hydra/XHydra
                4.2.5.4 Medusa
                4.2.5.5 Ncrack
            4.2.6 Routing protocols
            4.2.7 Cisco Discovery Protocol (CDP)
            4.2.8 Hot Standby Router Protocol (HSRP)
            4.2.9 Virtual Switch Redundancy Protocol (VSRP)
            4.2.10 Dynamic Trunking Protocol (DTP)
            4.2.11 Spanning Tree Protocol (STP)
            4.2.12 Open Shortest Path First (OSPF)
            4.2.13 RIP
            4.2.14 VLAN Hopping
            4.2.15 VLAN Trunking Protocol (VTP)
        4.3 RF Access
            4.3.1 Unencrypted Wireless LAN
                4.3.1.1 Iwconfig (Linux)
                4.3.1.2 Windows (XP/7)
            4.3.2 Attacking the Access Point
                4.3.2.1 Denial of Service (DoS)
            4.3.3 Cracking Passwords
                4.3.3.1 WPA-PSK/ WPA2-PSK
                4.3.3.2 WPA/WPA2-Enterprise
            4.3.4 Attacks
                4.3.4.1 LEAP
                    4.3.4.1.1 Asleap
                4.3.4.2 802.1X
                    4.3.4.2.1 Key Distribution Attack
                    4.3.4.2.2 RADIUS Impersonation Attack
                4.3.4.3 PEAP
                    4.3.4.3.1 RADIUS Impersonation Attack
                    4.3.4.3.2 Authentication Attack
                4.3.4.4 EAP-Fast
                4.3.4.5 WEP/WPA/WPA2
                4.3.4.6 Aircrack-ng
        4.4 Attacking the User
            4.4.1 Karmetasploit Attacks
            4.4.2 DNS Requests
            4.4.3 Bluetooth
            4.4.4 Personalized Rogue AP
            4.4.5 Web
                4.4.5.1 SQL Injection (SQLi)
                4.4.5.2 XSS
                4.4.5.3 CSRF
            4.4.6 Ad-Hoc Networks
            4.4.7 Detection bypass
            4.4.8 Resistance of Controls to attacks
            4.4.9 Type of Attack
            4.4.10 The Social-Engineer Toolkit
        4.5 VPN detection
        4.6 Route detection, including static routes
            4.6.1 Network Protocols in use
            4.6.2 Proxies in use
            4.6.3 Network layout
            4.6.4 High value/profile targets
        4.7 Pillaging
            4.7.1 Video Cameras
            4.7.2 Data Exfiltration
            4.7.3 Locating Shares
            4.7.4 Audio Capture
            4.7.5 High Value Files
            4.7.6 Database Enumeration
            4.7.7 Wifi
            4.7.8 Source Code Repos
            4.7.9 Git
            4.7.10 Identify custom apps
            4.7.11 Backups
        4.8 Business impact attacks
        4.9 Further penetration into infrastructure
            4.9.1 Pivoting inside
                4.9.1.1 History/Logs
            4.9.2 Cleanup
        4.10 Persistence
    5 Post Exploitation
        5.1 Windows Post Exploitation
            5.1.1 Blind Files
            5.1.2 Non Interactive Command Execution
            5.1.3 System
            5.1.4 Networking (ipconfig, netstat, net)
            5.1.5 Configs
            5.1.6 Finding Important Files
            5.1.7 Files To Pull (if possible)
            5.1.8 Remote System Access
            5.1.9 Auto-Start Directories
            5.1.10 Binary Planting
            5.1.11 Deleting Logs
            5.1.12 Uninstalling Software “AntiVirus” (Non interactive)
            5.1.13 Other
                5.1.13.1 Operating Specific
                    5.1.13.1.1 Win2k3
                    5.1.13.1.2 Vista/7
                    5.1.13.1.3 Vista SP1/7/2008/2008R2 (x86 & x64)
            5.1.14 Invasive or Altering Commands
            5.1.15 Support Tools Binaries / Links / Usage
                5.1.15.1 Various tools
        5.2 Obtaining Password Hashes in Windows
            5.2.1 LSASS Injection
                5.2.1.1 Pwdump6 and Fgdump
                5.2.1.2 Hashdump in Meterpreter
            5.2.2 Extracting Passwords from Registry
                5.2.2.1 Copy from the Registry
                5.2.2.2 Extracting the Hashes
            5.2.3 Extracting Passwords from Registry using Meterpreter
    6 Reporting
        6.1 Executive-Level Reporting
        6.2 Technical Reporting
        6.3 Quantifying the risk
        6.4 Deliverable
    7 Custom tools developed
    8 Appendix A - Creating OpenVAS "Only Safe Checks" Policy
        8.1 General
        8.2 Plugins
        8.3 Credentials
        8.4 Target Selection
        8.5 Access Rules
        8.6 Preferences
        8.7 Knowledge Base
    9 Appendix B - Creating the "Only Safe Checks" Policy
        9.1 General
        9.2 Credentials
        9.3 Plugins
        9.4 Preferences
    10 Appendix C - Creating the "Only Safe Checks (Web)" Policy
        10.1 General
        10.2 Credentials
        10.3 Plugins
        10.4 Preferences
    11 Appendix D - Creating the "Validation Scan" Policy
        11.1 General
        11.2 Credentials
        11.3 Plugins
        11.4 Preferences
    12 Appendix E - NeXpose Default Templates
        12.1 Denial of service
        12.2 Discovery scan
        12.3 Discovery scan (aggressive)
        12.4 Exhaustive
        12.5 Full audit
        12.6 HIPAA compliance
        12.7 Internet DMZ audit
        12.8 Linux RPMs
        12.9 Microsoft hotfix
        12.10 Payment Card Industry (PCI) audit
        12.11 Penetration test
        12.12 Penetration test
        12.13 Safe network audit
        12.14 Sarbanes-Oxley (SOX) compliance
        12.15 SCADA audit
        12.16 Web audit


---

Ref:http://www.pentest-standard.org/index.php/PTES_Technical_Guidelines

