---
layout: default
title: Prob25
parent: WebHacking.kr
nav_order: 25
---

# Prob25

문제에 접속하면 get으로 받는 file name에 .txt를 붙여 해당 파일의 내용을 출력한다는 것을 알 수 있다.

![index](/assets/images/webhacking_kr/prob25/1.png)

get으로 password.php을 보내고 끝에 %00을 붙여 .txt가 붙는걸 막으면 해결된다.
