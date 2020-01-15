---
layout: default
title: Prob23
parent: WebHacking.kr
nav_order: 23
---

# Prob23

xss를 통해 해당 script를 실행시키면 풀리는 문제이다.

![index](/assets/images/webhacking_kr/prob22/1.png)

2글자 이상 문자를 넣으면 no hack이라고 나오며 필터링 되니 %00을 넣고, 그 뒤로 스크립트를 넣어 문자열 검사를 피한다.