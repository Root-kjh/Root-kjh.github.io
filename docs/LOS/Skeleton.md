---
layout: default
title: Skeleton
parent: Load Of SQL Injection
nav_order: 10
---

# Skeleton

pw부분에 SQL Injection을 진행한 뒤, 뒷 부분에 주석을 달아 and 1=0 부분을 무시함으로써 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  $query = "select id from prob_skeleton where id='guest' and pw='{$_GET[pw]}' and 1=0"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id'] == 'admin') solve("skeleton"); 
  highlight_file(__FILE__); 
?>
```