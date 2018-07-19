# Finding your way around an operating system

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

---
Refs:
PWK coursework
