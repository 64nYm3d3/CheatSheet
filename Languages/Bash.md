# Bash

Basic commands for interacting with linux

**cd** - Change Directory

**ls** - List Selection

**file** - determine filetype

**mkdir** - Make Directory

**touch** - create a file

**mv** - move the file

**cp** - copy and paste a file

**pwd** - print working directory

**tree** - creates a kind of map

**ifconfig** - displays cnetwork interfaces, can be used to do some configurations


Useful to know

Knowing the difference between find, locate, and which.


Prior to using the **locate** command, we must build a local database of **all files** on the file system before using it.
~~~
uname@box:~# updatedb
uname@box:~# locate mal_svc.exe
/usr/share/windows-binaries/mal_svc.exe
/usr/share/windows-binaries/backdoors/mal_svc.exe
~~~

The **which** command only searches through directories that are defined in the *$PATH* environment variable for a  given filename. If a  match is found, which returns the full path to the file

~~~
uname@box:~# which sh
/usr/bin/sh
~~~

**find** is more aggressive than either than locate or which, allowing you to recursively search a given path for various files
~~~
~~~
