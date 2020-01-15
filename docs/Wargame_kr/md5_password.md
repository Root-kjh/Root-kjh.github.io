---
layout: default
title: MD5 Password
parent: Wargame.kr
nav_order: 9
---

# MD5 Password

SQL Injection을 통해 admin 계정으로  Login 해야 하지만 입력값을 MD5 암호화 하는 코드가 있다.

```php
<?php
 if (isset($_GET['view-source'])) {
  show_source(__FILE__);
  exit();
 }

 if(isset($_POST['ps'])){
  sleep(1);
  mysql_connect("localhost","md5_password","md5_password_pz");
  mysql_select_db("md5_password");
  mysql_query("set names utf8");
  /*
  
  create table admin_password(
   password char(64) unique
  );
  
  */

  include "../lib.php"; // include for auth_code function.
  $key=auth_code("md5 password");
  $ps = mysql_real_escape_string($_POST['ps']);
  $row=@mysql_fetch_array(mysql_query("select * from admin_password where password='".md5($ps,true)."'"));
  if(isset($row[0])){
   echo "hello admin!"."<br />";
   echo "Password : ".$key;
  }else{
   echo "wrong..";
  }
 }
?>
<style>
 input[type=text] {width:200px;}
</style>
<br />
<br />
<form method="post" action="./index.php">
password : <input type="text" name="ps" /><input type="submit" value="login" />
</form>
<div><a href='?view-source'>get source</a></div>
```

MD5 함수의 true 옵션이 붙어있으면 암호화가 hex가 아닌 binary 형식으로 진행되며 특수문자를 포함한 다른 여러 문자들이 나오게 된다.

이를 활용해 SQL Injection을 진행하면 된다.