---
layout: default
title: Prob5
parent: WebHacking.kr
nav_order: 5
---

# Prob5

문제 사이트에 접속하면 Login과 Join 버튼이 보입니다.

![index](/assets/images/webhacking_kr/prob5/1.png)

login.php를 지우고 상위 디렉터리로 이동합니다.

![Url조작](/assets/images/webhacking_kr/prob5/2.png)

디렉터리 리스팅이 가능한 것을 확인할 수 있습니다.

![Directory Listening](/assets/images/webhacking_kr/prob5/3.png)

join.php에 접속해봅니다.

![join.php](/assets/images/webhacking_kr/prob5/4.png)

난독화된 javascript 코드가 보이는데, form 부분만 해독해 보면 다음과 같은 코드가 나옵니다.

```html
    <form method=post action='join.php'>

   <table border=1><tr><td><font color=gray>id</font></td><td><input type=text name='id' maxlength=5></td></tr>

    <tr><td><font color=gray>pass</font></td><td><input type=text name='pw' maxlength=10></td></tr>

    <tr align=center><td colspan=2><input type=submit></td></tr></form></table>
```

간단히 admin으로만 넣으면 이미 존재하는 아이디로 인식하기 때문에 maxlength를 6으로 고치고 admin뒤에 띄어쓰기를 넣어 join한 뒤 login합니다.

![clear](/assets/images/webhacking_kr/prob5/5.png)