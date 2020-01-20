---
layout: default
title: Giant
parent: Load Of SQL Injection
nav_order: 14
---

# Giant

띄어쓰기만 하면 풀 수 있는 문제다.

하지만 띄어쓰기, 탭, 줄바꿈이 모두 필터링 되어있다.

글자수도 1글자로 제한되어있다.

%0b, %0c, %0d 등으로 띄어쓰기를 우회해주면 풀 수 있다. 

```php
<?php 
  include "./config.php"; 
  login_chk(); 
  dbconnect(); 
  if(strlen($_GET[shit])>1) exit("No Hack ~_~"); 
  if(preg_match('/ |\n|\r|\t/i', $_GET[shit])) exit("HeHe"); 
  $query = "select 1234 from{$_GET[shit]}prob_giant where 1"; 
  echo "<hr>query : <strong>{$query}</strong><hr><br>"; 
  $result = @mysql_fetch_array(mysql_query($query)); 
  if($result[1234]) solve("giant"); 
  highlight_file(__FILE__); 
?>
```