---
layout: default
title: Troll
parent: Load Of SQL Injection
nav_order: 8
---

# Troll

ereg 함수로 admin 문자열을 필터링하지만, 대소문자를 구분하는 취약점이 있다.

Admin, aDmin 등으로 필터링을 우회할 수 있다.

```php
<?php  
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/\'/i', $_GET[id])) exit("No Hack ~_~");
  if(@ereg("admin",$_GET[id])) exit("HeHe");
  $query = "select id from prob_troll where id='{$_GET[id]}'";
  echo "<hr>query : <strong>{$query}</strong><hr><br>";
  $result = @mysql_fetch_array(mysql_query($query));
  if($result['id'] == 'admin') solve("troll");
  highlight_file(__FILE__);
?>
```