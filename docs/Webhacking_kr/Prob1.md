---
layout: default
title: Prob1
parent: WebHacking.kr
nav_order: 1
---

# Prob1

문제 사이트에 접속하면 index.phps라는 문구가 보인다.

![index](/assets/images/webhacking_kr/prob1/1.png)

URL을 조작해 index.phps에 접속한다.

![url조작](/assets/images/webhacking_kr/prob1/2.png)

index.phps에서 아래와 같은 소스를 확인할 수 있다.

```php
<?
if(!$_COOKIE[user_lv])
{
SetCookie("user_lv","1");
echo("<meta http-equiv=refresh content=0>");
}
?>
<html>
<head>
<title>Challenge 1</title>
</head>
<body bgcolor=black>
<center>
<br><br><br><br><br>
<font color=white>
---------------------<br>
<?

$password="????";

if(eregi("[^0-9,.]",$_COOKIE[user_lv])) $_COOKIE[user_lv]=1;

if($_COOKIE[user_lv]>=6) $_COOKIE[user_lv]=1;

if($_COOKIE[user_lv]>5) @solve();

echo("<br>level : $_COOKIE[user_lv]");

?>
<br>
<pre>
<a onclick=location.href='index.phps'>----- index.phps -----</a>
</body>
</html>
```

소스를 보고 cookie 값을 조작해 6과 5 사이의 값으로 만들어 줄 때 문제가 풀린다는 것을 확인할 수 있다.

![cookie조작](/assets/images/webhacking_kr/prob1/3.png)

![clear](/assets/images/webhacking_kr/prob1/4.png)