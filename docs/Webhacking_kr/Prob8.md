---
layout: default
title: Prob8
parent: WebHacking.kr
nav_order: 8
---

# Prob8

문제 사이트에 접속하면 USER-AGENT 문구가 보인다.

![index](/assets/images/webhacking_kr/prob8/1.png)

소스를 보면 index.phps가 주석처리 되어있으니 index.phps에 접속해 소스를 확인한다.

```php
<?php
  include "../../config.php";
  if($_GET['view_source']) view_source();
?><html>
<head>
<title>Challenge 8</title>
<style type="text/css">
body { background:black; color:white; font-size:10pt; }
</style>
</head>
<body>
<br><br>
<center>
<?php
$agent=trim(getenv("HTTP_USER_AGENT"));
$ip=$_SERVER['REMOTE_ADDR'];
if(preg_match("/from/i",$agent)){
  echo("<br>Access Denied!<br><br>");
  echo(htmlspecialchars($agent));
  exit();
}
$db = dbconnect();
$count_ck = mysqli_fetch_array(mysqli_query($db,"select count(id) from chall8"));
if($count_ck[0] >= 70){ mysqli_query($db,"delete from chall8"); }

$result = mysqli_query($db,"select id from chall8 where agent='".addslashes($_SERVER['HTTP_USER_AGENT'])."'");
$ck = mysqli_fetch_array($result);

if($ck){
  echo "hi <b>".htmlentities($ck[0])."</b><p>";
  if($ck[0]=="admin"){
    mysqli_query($db,"delete from chall8");
    solve(8);
  }
}

if(!$ck){
  $q=mysqli_query($db,"insert into chall8(agent,ip,id) values('{$agent}','{$ip}','guest')") or die("query error");
  echo("<br><br>done!  ({$count_ck[0]}/70)");
}
?>
<a href=./?view_source=1>view-source</a>
</body>
</html>
```
(스크린샷과 문제 소스의 복사 시점이 달라 조금 차이가 있을 수 있습니다.)

User-Agent 값을 조작해 SQL Injection을 통해 admin 계정을 생성한다.

![User-Agent SQL Injection](/assets/images/webhacking_kr/prob8/2.jpg)

생성한 계정으로 접속한다.

![admin접속](/assets/images/webhacking_kr/prob8/3.png)


![clear](/assets/images/webhacking_kr/prob8/4.png)