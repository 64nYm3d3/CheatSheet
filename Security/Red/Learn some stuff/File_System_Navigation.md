# Finding your way around an operating system

## While this does go in depth, key points to remember
### - Daemons can be managed with **systemctl**
### - Understand the **difference** between **find** (agressive), **locate** (local db), and **which** ($Path)

Also included (**remember to update this**)
- **rcconf** useage ( rcconf allows you to control which services are started when the system boots up or reboots.)
- **sysv-rc-conf** useage(Run-level configuration for SysV like init script link)
- **dconf** useage (maybe? Are you a paranoid sysadmin? Snapshot a machine before it's broken!)

---

### Managing daemons

Most services are operated in much the same way that the SSH and HTTP daemons are managed, through their service or init scripts. To get more granular control of these services, you can use tools such as rcconf or sysv- rc-conf, both designed to help simplify and manage the boot persistence of these services.

**Start a service**
The HTTP service can come in handy during a penetration test, either for hosting a site,or providing a platform for downloading files to a victim machine.
~~~
┌─[ganymede@parrot]─[~]
└──╼ $sudo systemctl start apach2
~~~

**Verify a running process**

In this case it's ssh. Using netstat to view our current listening and non listening ports we grep for the ssh daemon.
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo netstat -antp|grep sshd
tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      19438/sshd          
tcp6       0      0 :::22                   :::*                    LISTEN      19438/sshd
~~~


**Start SSH services automatically at boot time**
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo systemctl enable ssh
[sudo] password for ganymede: 
\Synchronizing state of ssh.service with SysV service script with /lib/systemd/systemd-sysv-install.
Executing: /lib/systemd/systemd-sysv-install enable ssh
insserv: warning: current start runlevel(s) (empty) of script `ssh' overrides LSB defaults (2 3 4 5).
insserv: warning: current stop runlevel(s) (2 3 4 5) of script `ssh' overrides LSB defaults (empty).
~~~

### Find, Locate, and Which
Knowing the difference between find, locate, and which.


Prior to using the **locate** command, we must build a local database of **all files** on the file system before using it.
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo updatedb
[sudo] password for ganymede: 
┌─[ganymede@parrot]─[~]
└──╼ $locate svc.exe
/usr/share/metasploit-framework/data/meterpreter/metsvc.exe
/usr/share/metasploit-framework/data/templates/template_x64_windows_svc.exe
/usr/share/metasploit-framework/data/templates/template_x86_windows_svc.exe
/usr/share/responder/tools/MultiRelay/bin/Syssvc.exe
~~~

The **which** command only searches through directories that are defined in the *$PATH* environment variable for a  given filename. If a  match is found, which returns the full path to the file. Since svc 

~~~
┌─[ganymede@parrot]─[~]
└──╼ $which svc
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $which sh
/bin/sh
~~~

The **find** command is more aggressive than either than locate or which, allowing you to recursively search a given path for various files. 
Due to the size of this example I had to collapse it.


<details><summary>Details</summary><p>
   
~~~
┌─[✗]─[ganymede@parrot]─[~]
└──╼ $sudo find / -name svc*
/usr/include/rpc/svc_auth.h
/usr/include/rpc/svc.h
/usr/lib/python2.7/dist-packages/samba/dcerpc/svcctl.x86_64-linux-gnu.so
/usr/lib/python2.7/dist-packages/volatility/plugins/malware/svcscan.py
/usr/lib/x86_64-linux-gnu/wine/svchost.exe.so
/usr/lib/x86_64-linux-gnu/wine/fakedlls/svchost.exe
/usr/bin/svcrack
/usr/bin/svcrash
/usr/share/bash-completion/completions/svcadm
/usr/share/regripper/plugins/svcdll.pl
/usr/share/regripper/plugins/svc.pl
/usr/share/regripper/plugins/svchost.pl
/usr/share/regripper/plugins/svc_plus.pl
/usr/share/regripper/plugins/svc2.pl
/usr/share/metasploit-framework/lib/rex/proto/dcerpc/svcctl.rb
/usr/share/metasploit-framework/lib/rex/proto/dcerpc/svcctl
/usr/share/man/man3/svcerr_auth.3.gz
/usr/share/man/man3/svc_freeargs.3.gz
/usr/share/man/man3/svcfd_create.3.gz
/usr/share/man/man3/svc_sendreply.3.gz
/usr/share/man/man3/svc_getreqset.3.gz
/usr/share/man/man3/svc_getargs.3.gz
/usr/share/man/man3/svcerr_progvers.3.gz
/usr/share/man/man3/svcerr_noprog.3.gz
/usr/share/man/man3/svctcp_create.3.gz
/usr/share/man/man3/svc_getcaller.3.gz
/usr/share/man/man3/svcerr_systemerr.3.gz
/usr/share/man/man3/svcerr_decode.3.gz
/usr/share/man/man3/svcerr_weakauth.3.gz
/usr/share/man/man3/svcerr_noproc.3.gz
/usr/share/man/man3/svcudp_create.3.gz
/usr/share/man/man3/svc_unregister.3.gz
/usr/share/man/man3/svc_register.3.gz
/usr/share/man/man3/svc_run.3.gz
/usr/share/man/man3/svc_getreq.3.gz
/usr/share/man/man3/svcudp_bufcreate.3.gz
/usr/share/man/man3/svc_destroy.3.gz
/usr/share/man/man3/svcraw_create.3.gz
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc_xprt.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcauth.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svc_rdma.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcauth_gss.h
/usr/src/linux-headers-4.14.0-parrot13-common/include/linux/sunrpc/svcsock.h
~~~
</p></details>

---
Refs:
PWK coursework
