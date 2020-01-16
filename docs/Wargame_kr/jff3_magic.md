---
layout: default
title: JFF3 Magic
parent: Wargame.kr
nav_order: 24
---

# JFF3 Magic

문제에 접속하면 swp을 hint로 준다.

![index](/assets/images/wargame_kr/jff3_magic/1.png)

hint를 통해 .index.php.swp 파일을 통해 index.php 파일의 소스를 획득한다.

소스 중, 한 부분을 보면 custom_firewall에 no를 넣고 돌린 후, 쿼리를 실행한다는 것을 알 수 있다.

```php
$test = custom_firewall($_GET['no']);

if ($test != 0){ exit("No Hack - ".test); }

$q = mysql_query("select * from member where no=".$_GET['no']);
```

![index](/assets/images/wargame_kr/jff3_magic/2.png)

필터링을 우회해서 admin의 pw를 뽑아내면 hash암호화가 되어있는데, magic hash를 이용해 풀면 된다.

![index](/assets/images/wargame_kr/jff3_magic/3.png)