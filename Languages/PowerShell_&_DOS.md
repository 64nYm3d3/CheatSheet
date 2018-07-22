# How to install cygwin (I'm kidding)

Like the bash sheet, I'm not going to differentiate between too much PS, the CLI, and common tools. It will become more apparent in the when scripting but for simple usage not so much

Basics

**[cmd] /?** - typing '/?' after a command will get you everywhere. It displays help info about a tool

**dir**

**cd**

**cls**

**mkdir**

**move**

**rename**

**del**

**rmdir**

## Advanced Darkness and commandlets

**Get-Process** - Gets the processes that are running on the local computer or a remote computer. Want something specific? Use the -name switch and separate the processes you're interested by comments

~~~
 Get-Process -Name firefox, powershell (I'll fix this later)
~~~

**Get-Alias** - Get-Alias takes an alias and returns the command name

~~~
PS /> Get-Alias

CommandType     Name
-----------     ----
…

Alias           cd -> Set-Location
Alias           cls -> Clear-Host
Alias           copy -> Copy-Item
Alias           dir -> Get-ChildItem
Alias           gc -> Get-Content
Alias           gmo -> Get-Module
Alias           ri -> Remove-Item
Alias           type -> Get-Content
...[Lotta Stuff here]
~~~

**Set-Location** - set the current working location to a specified path

~~~
PS /> Set-Location /home
PS /home>
~~~

**Get-ChildItem**

~~~
Get all files under the current directory:

PS /> Get-ChildItem

//Get all files under the current directory as well as its subdirectories:
PS /> cd $home
PS /home/jello> dir -Recurse

//List all files with "txt" file extension.

PS /> cd $home
PS /home/jello> dir –Path *.txt -Recurse

//Get-ChildItem -Path *.txt -Recurse -Force
~~~










---
Ref:https://github.com/PowerShell/PowerShell/tree/master/docs/learning-powershell
