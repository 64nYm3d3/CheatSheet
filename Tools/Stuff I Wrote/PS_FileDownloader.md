I would love to say I made this for a ctf but I'd be lying. This was made because I was too lazy to download and install curl on my Win10 machine for a while. It was made as a way to download multiple images from an image gallery I was looking at.

~~~
$filetype = $null
$x = $null


$website = Read-Host -Prompt "Website link?"

$x = Read-Host -Prompt "Number of files?"
$n = 0..$x;

$filetype =  Read-Host -Prompt "File Extension?"




foreach ($i in $n) 
	{
	
	wget  "$website$i$filetype" -OutFile "$i$filetype"
	print $i	
	}
  ~~~
