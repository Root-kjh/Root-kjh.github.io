---
layout: default
title: Prob7
parent: WebHacking.kr
nav_order: 7
---

# Prob7

문제 사이트에 접속하면 auth 버튼이 보입니다.

![index](/assets/images/webhacking_kr/prob7/1.png)

소스를 보니 val을 2로 조작해서 admin mode로 들어가야 한다는 힌트와, index.phps로 접속해 소스를 보라는 힌트가 나와있습니다.

![code](/assets/images/webhacking_kr/prob7/2.png)

index.phps로 접속해 소스를 확인합니다.

```php
<?php
  include "../../config.php";
  if($_GET['view_source']) view_source();
?><html>
<head>
<title>Challenge 7</title>
</head>
<body>
<?php
$go=$_GET['val'];
if(!$go) { echo("<meta http-equiv=refresh content=0;url=index.php?val=1>"); }
echo("<html><head><title>admin page</title></head><body bgcolor='black'><font size=2 color=gray><b><h3>Admin page</h3></b><p>");
if(preg_match("/2|-|\+|from|_|=|\\s|\*|\//i",$go)) exit("Access Denied!");
$db = dbconnect();
$rand=rand(1,5);
if($rand==1){
  $result=mysqli_query($db,"select lv from chall7 where lv=($go)") or die("nice try!");
}
if($rand==2){
  $result=mysqli_query($db,"select lv from chall7 where lv=(($go))") or die("nice try!");
}
if($rand==3){
  $result=mysqli_query($db,"select lv from chall7 where lv=((($go)))") or die("nice try!");
}
if($rand==4){
  $result=mysqli_query($db,"select lv from chall7 where lv=(((($go))))") or die("nice try!");
}
if($rand==5){
  $result=mysqli_query($db,"select lv from chall7 where lv=((((($go)))))") or die("nice try!");
}
$data=mysqli_fetch_array($result);
if(!$data[0]) { echo("query error"); exit(); }
if($data[0]==1){
  echo("<input type=button style=border:0;bgcolor='gray' value='auth' onclick=\"alert('Access_Denied!')\"><p>");
}
elseif($data[0]==2){
  echo("<input type=button style=border:0;bgcolor='gray' value='auth' onclick=\"alert('Hello admin')\"><p>");
  solve(7);
}
?>
<a href=./?view_source=1>view-source</a>
</body>
</html>
```
(스크린샷과 문제 소스의 복사 시점이 달라 조금 차이가 있을 수 있습니다.)

Union SQL Injection을 이용해 val을 2로 조작합니다.

![clear](/assets/images/webhacking_kr/prob7/3.png)