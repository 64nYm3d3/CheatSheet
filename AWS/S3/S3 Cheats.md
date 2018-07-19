# S3

I registered my website initially through google but AWS is so easy I'm happy with using that for everyting.

## Creating a website
1. Transfer registrar
2. Create two buckets, one being the ~~~ www.examplesite.com~~~ and ~~~ examplesite.com~~~
3. Upload .html file to the bucket you like the most
4. Check the properties, set one to static website hostng to that same bucket, and in the other bucket redirect traffic
5. Go to route53, configure A record, using the same settings for  both domain names 
