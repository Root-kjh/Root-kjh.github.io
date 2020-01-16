---
layout: default
title: Gremlin
parent: Load Of SQL Injection
nav_order: 1
---

# Gremlin

가장 간단한 SQL Injection 문제다.

작은따옴표로 문자열에서 빠져나와 or 연산자로 쿼리의 결과를 True로 만들어주면 풀 수 있다.

```php
<?php
  include "./config.php";
  login_chk();
  dbconnect();
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[id])) exit("No Hack ~_~"); // do not try to attack another table, database!
  if(preg_match('/prob|_|\.|\(\)/i', $_GET[pw])) exit("No Hack ~_~");
  $query = "select id from prob_gremlin where id='{$_GET[id]}' and pw='{$_GET[pw]}'";
  echo "<hr>query : <strong>{$query}</strong><hr><br>";
  $result = @mysql_fetch_array(mysql_query($query));
  if($result['id']) solve("gremlin");
  highlight_file(__FILE__);
?>
```