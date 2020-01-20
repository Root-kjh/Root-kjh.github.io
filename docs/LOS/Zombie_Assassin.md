---
layout: default
title: Zombie Assassin
parent: Load Of SQL Injection
nav_order: 16
---

# Zombie Assassin

작은 따옴표가 필터링 되어있다.

하지만 취약한 함수(ereg)로 필터링하기 때문에 필터링을 우회할 수 있다.

ereg 함수는 %00을 문자열의 끝으로 인식하기 때문에 그 뒤의 문자는 검사하지 않는다.

%00을 넣은 뒤 SQL Injection을 실행하면 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/\\\|prob|_|\.|\(\)/i', $_GET[id])) exit("No Hack ~_~"); 
  if(preg_match('/\\\|prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  if(@ereg("'",$_GET[id])) exit("HeHe"); 
  if(@ereg("'",$_GET[pw])) exit("HeHe"); 
  $query = "select id from prob_zombie_assassin where id='{$_GET[id]}' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) solve("zombie_assassin"); 
  highlight_file(__FILE__); 
?>
```