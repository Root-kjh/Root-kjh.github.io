---
layout: default
title: Type Confusion
parent: Wargame.kr
nav_order: 12
---

# Type Confusion

입력받은 문자열을 json_decode 함수로 decode 후, key 값과 sha1로 암호화 한 값이 같으면 flag가 나오는 구조다. 

```php
<?php
 if (isset($_GET['view-source'])) {
     show_source(__FILE__);
    exit();
 }
 if (isset($_POST['json'])) {
     usleep(500000);
     require("../lib.php"); // include for auth_code function.
    $json = json_decode($_POST['json']);
    $key = gen_key();
    if ($json->key == $key) {
        $ret = ["code" => true, "flag" => auth_code("type confusion")];
    } else {
        $ret = ["code" => false];
    }
    die(json_encode($ret));
 }

 function gen_key(){
     $key = uniqid("welcome to wargame.kr!_", true);
    $key = sha1($key);
     return $key;
 }
?>

<html>
    <head>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.1/jquery.min.js"></script>
        <script src="./util.js"></script>
    </head>
    <body>
        <form onsubmit="return submit_check(this);">
            <input type="text" name="key" />
            <input type="submit" value="check" />
        </form>
        <a href="./?view-source">view-source</a>
    </body>
</html>
```

sha1 Magic Hash를 활용해 풀 수 있다.