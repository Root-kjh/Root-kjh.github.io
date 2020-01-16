---
layout: default
title: Vampire
parent: Load Of SQL Injection
nav_order: 9
---

# Vampire

admin이라는 문자열을 공백으로 치환하는 코드가 추가되었다.

str_replace 함수는 문자열을 치환하는 함수이다.

하지만 adm**admin**in 등과 같은 문자열의 경우, 가운데 admin 문자열을 공백으로 치환하면 양 옆의 문자가 합쳐져 admin 문자열을 완성하는 방식으로 우회할 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/\'/i', $_GET[id])) exit("No Hack ~_~"); 
  $_GET[id] = str_replace("admin","",$_GET[id]); 
  $query = "select id from prob_vampire where id='{$_GET[id]}'"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id'] == 'admin') solve("vampire"); 
  highlight_file(__FILE__); 
?>
```