

Webbrowser module

~~~
import webbrowser
webrowser.open('https://example.url.com') //opens a webpage
~~~
system module
~~~
import sys
sys.argv[1:] //this stores a list or filename in it, chopping off the first element of the array with the ":" character as a delimiter
~~~

requests module
~~~
import requests
webpage = request.get('https://example.url.com') //Downloads the webpage
type(webpage) //returns the Response object
res.status_code == requests.codes.ok //running the status_code function will return the server response(like 200,404,300) and the second part just checks whether its the OK response(200)

len(webpage.text) //number of chars in the file
print(webpage.text[:1000]) //prints the first 1000 characters in the file

webpage2 = request.get('https://example.url2.com')
try:
  webpage2.raiseforstatus() //raises an exception status if there was an error, verifies the the download workedz
except Exception as exc:
  print('Problem: %s' % (exc)) //prints the status exception
  
  file = open(thevideo.mp4, 'wb') //opens the file, the wb will be used to indicate that we want to write to binary in order to preserve encoding when we passit too the write() function
  
  fr

~~~


