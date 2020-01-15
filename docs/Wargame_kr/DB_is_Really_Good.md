---
layout: default
title: DB is really good
parent: Wargame.kr
nav_order: 6
---

# DB is really good

![index](/assets/images/wargame_kr/DB_IS_REALLY_GOOD/1.png)

문제 페이지에 user name을 치고 Login하면 메모를 할 수 있는 페이지가 나온다.

user name에 /를 넣으면 해당 오류가 출력된다.

이를 통해 메모를 /home/www/db_is_really_good/db/wkrm_[username].db 파일에서 가져온다는 사실을 알 수 있다.

![index](/assets/images/wargame_kr/DB_IS_REALLY_GOOD/2.png)

/home/www/db_is_really_good/db/wkrm_admin.db 파일을 다운받아 열면 FLAG가 나온다.