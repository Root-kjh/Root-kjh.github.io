---
layout: default
title: Prob24
parent: WebHacking.kr
nav_order: 24
---

# Prob24

문제에 접속하면 ip정보와 user_agent 정보를 table에 넣는것을 알 수 있다.

![index](/assets/images/webhacking_kr/prob24/1.jpg)

소스를 보면 str_replace 함수를 우회해 ip를 127.0.0.1로 만들면 풀린다는 것을 알 수 있다.

```php
<?php
  include "../../config.php";
  if($_GET['view_source']) view_source();
?><html>
<head>
<title>Challenge 24</title>
</head>
<body>
<p>
<?php
  extract($_SERVER);
  extract($_COOKIE);
  $ip = $REMOTE_ADDR;
  $agent = $HTTP_USER_AGENT;
  if($REMOTE_ADDR){
    $ip = htmlspecialchars($REMOTE_ADDR);
    $ip = str_replace("..",".",$ip);
    $ip = str_replace("12","",$ip);
    $ip = str_replace("7.","",$ip);
    $ip = str_replace("0.","",$ip);
  }
  if($HTTP_USER_AGENT){
    $agent=htmlspecialchars($HTTP_USER_AGENT);
  }
  echo "<table border=1><tr><td>client ip</td><td>{$ip}</td></tr><tr><td>agent</td><td>{$agent}</td></tr></table>";
  if($ip=="127.0.0.1"){
    solve(24);
    exit();
  }
  else{
    echo "<hr><center>Wrong IP!</center>";
  }
?><hr>
<a href=?view_source=1>view-source</a>
</body>
</html>
```

str_replace 함수는 1**12**2와 같은 문자열이 있을 때, 가운데 12를 공백으로 replace 함으로써 1과 2가 합쳐서 12가 되는 것을 이용해 우회하면 된다. 