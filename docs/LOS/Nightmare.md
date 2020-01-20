---
layout: default
title: Nightmare
parent: Load Of SQL Injection
nav_order: 18
---

# Nightmare

6글자 이하의 글자로 SQL Injection을 실행해야 한다.

작은따옴표와 닫는 괄호는 필수니 4글자 안으로 SQL Injection 구문을 넣어야 한다.

mysql의 auto type cast라는 특성을 이용해 글자수를 줄일 수 있다.

pw='' 라는 구문은 아무 result가 없기 때문에 False 값이다.

mysql에서 False==0 이기 때문에 pw=''=0 이라는 구문이 True 처리된다.


')=0;%00 구문을 넣어 SQL Injection을 실행시킬 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)|#|-/i', $_GET[pw])) exit("No Hack ~_~"); 
  if(strlen($_GET[pw])>6) exit("No Hack ~_~"); 
  $query = "select id from prob_nightmare where pw=('{$_GET[pw]}') and id!='admin'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) solve("nightmare"); 
  highlight_file(__FILE__); 
?>
```