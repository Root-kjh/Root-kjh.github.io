---
layout: default
title: Prob26
parent: WebHacking.kr
nav_order: 26
---

# Prob26

admin이라는 문자열을 preg_match를 우회해 넣으면 된다.

```php
<?php
  include "../../config.php";
  if($_GET['view_source']) view_source();
?><html>
<head>
<title>Challenge 26</title>
<style type="text/css">
body { background:black; color:white; font-size:10pt; }    
a { color:lightgreen; }
</style>
</head>
<body>
<?php
  if(preg_match("/admin/",$_GET['id'])) { echo"no!"; exit(); }
  $_GET['id'] = urldecode($_GET['id']);
  if($_GET['id'] == "admin"){
    solve(26);
  }
?>
<br><br>
<a href=?view_source=1>view-source</a>
</body>
</html>
```

a, d, m, i, n을 hex로 바꾼 후 한번 더 urlencode해서 넣으면 된다.