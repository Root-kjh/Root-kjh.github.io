---
layout: default
title: Dragon
parent: Load Of SQL Injection
nav_order: 20
---

# Dragon

id 옆에 주석이 달려있다.

\# 주석은 줄단위 주석이기 때문에 줄바꿈으로 우회가 가능하다.

줄바꿈 한 뒤, SQL Injection을 실행하면 풀 수 있다.

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  $query = "select id from prob_dragon where id='guest'# and pw='{$_GET[pw]}'";
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id']) echo "<h2>Hello {$result[id]}</h2>"; 
  if($result['id'] == 'admin') solve("dragon");
  highlight_file(__FILE__); 
?>
```