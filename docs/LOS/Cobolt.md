---
layout: default
title: Cobolt
parent: Load Of SQL Injection
nav_order: 2
---

# Cobolt

pw 부분에 md5 hash화가 되면서 pw에서는 SQL Injection이 불가능하게 되었다.

ID에서 SQL Injection을 한 뒤, 주석처리로 그 뒤의 쿼리를 무시해주면 풀 수 있다.

```php
<?php
  include "./config.php"; 
  login_chk();
  dbconnect();
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[id])) exit("No Hack ~_~"); 
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~"); 
  $query = "select id from prob_cobolt where id='{$_GET[id]}' and pw=md5('{$_GET[pw]}')"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result['id'] == 'admin') solve("cobolt");
  elseif($result['id']) echo "<h2>Hello {$result['id']}<br>You are not admin :(</h2>"; 
  highlight_file(__FILE__); 
?>
```