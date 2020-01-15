---
layout: default
title: Strcmp
parent: Wargame.kr
nav_order: 11
---

# Strcmp

알수 없는 Password와 input으로 받은 문자열을 비교해 같을 경우 풀리는 코드다.

```php
<?php
    require("../lib.php"); // for auth_code function

    $password = sha1(md5(rand().file_get_contents("/var/lib/dummy_file")).rand());

    if (isset($_GET['view-source'])) {
        show_source(__FILE__);
        exit();
    }else if(isset($_POST['password'])){
        sleep(1); // do not brute force!
        if (strcmp($_POST['password'], $password) == 0) {
            echo "Congratulations! Flag is <b>" . auth_code("strcmp") ."</b>";
            exit();
        } else {
            echo "Wrong password..";
        }
    }

?>
<br />
<br />
<form method="POST">
    password : <input type="text" name="password" /> <input type="submit" value="chk">
</form>
<br />
<a href="?view-source">view-source</a>
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

strcmp는 문자열을 비교해서 같을경우 0을 반환하는 함수인데, 만약 배열을 넣으면 NULL을 반환한다.

strcmp에서 0==NULL이기 때문에 이 점을 이용해 풀 수 있다.