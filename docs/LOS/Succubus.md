---
layout: default
title: Succubus
parent: Load Of SQL Injection
nav_order: 17
---

# Succubus

작은 따옴표가 필터링 되어 사용할 수 없다.

하지만 id에 역슬래시(\\)를 넣으면 바로 뒤에있는 작은따옴표가 문자열처리되면서 id\'**\\\' and pw=\'**' 가 된다.

id의 문자열을 닫는 작은따옴표를 역슬래시로 문자열 처리 해준 뒤, pw부분에서 SQL Injection을 실행하면 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[id])) exit("No Hack ~_~"); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  if(preg_match('/\'/i', $_GET[id])) exit("HeHe"); 
  if(preg_match('/\'/i', $_GET[pw])) exit("HeHe"); 
  $query = "select id from prob_succubus where id='{$_GET[id]}' and pw='{$_GET[pw]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) solve("succubus"); 
  highlight_file(__FILE__); 
?>
```