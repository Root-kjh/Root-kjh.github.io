---
layout: default
title: Goblin
parent: Load Of SQL Injection
nav_order: 3
---

# Goblin

no 부분에 SQL Injection이 가능하지만, 문자열을 사용하지 못하게 막아놨다.

문자열 대신 문자열을 hex로 변환한 값을 넣으면 mysql 내부적으로 문자열로 변환한다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[no])) exit("No Hack ~_~"); 
  if(preg_match('/\'|\"|\`/i', $_GET[no])) exit("No Quotes ~_~"); 
  $query = "select id from prob_goblin where id='guest' and no={$_GET[no]}"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
  if($result['id'] == 'admin') solve("goblin");
  highlight_file(__FILE__); 
?>
```