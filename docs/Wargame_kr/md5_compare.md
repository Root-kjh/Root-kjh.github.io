---
layout: default
title: MD5 Compare
parent: Wargame.kr
nav_order: 8
---

# MD5 Compare

첫번째 입력창에는 문자열을, 두번째 입력창에는 숫자를 넣어 md6 암호화를 했을 때 같으면 clear 되는 문제다.

```php
<?php
    if (isset($_GET['view-source'])) {
         show_source(__FILE__);
         exit();
    }

    if (isset($_GET['v1']) && isset($_GET['v2'])) {
        sleep(3); // anti brute force

        $chk = true;
        $v1 = $_GET['v1'];
        $v2 = $_GET['v2'];

        if (!ctype_alpha($v1)) {$chk = false;}
        if (!is_numeric($v2) ) {$chk = false;}
        if (md5($v1) != md5($v2)) {$chk = false;}

        if ($chk){
            include("../lib.php");
            echo "Congratulations! FLAG is : ".auth_code("md5_compare");
        } else {
            echo "Wrong...";
        }
    }
?>
<br />
<form method="GET">
    VALUE 1 : <input type="text" name="v1" /><br />
    VALUE 2 : <input type="text" name="v2" /><br />
    <input type="submit" value="chk" />
</form>
<br />
<a href="?view-source">view-source</a>
```

md5 magic hash를 이용해 문자열과 숫자를 md5로 암호화한 값이 0e로 시작되게 만들어주면 풀 수 있다.