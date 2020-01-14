---
layout: default
title: Prob11
parent: WebHacking.kr
nav_order: 11
---

# Prob11

문제 사이트에 접속하면 정규식이 보인다. get 방식으로 val를 보내 정규식을 만족시키면 된다.

![index](/assets/images/webhacking_kr/prob11/1.jpg)

앞부터 살펴보면

* [1-3] : 1~3 중 숫자 하나를 넣는다.

* [a-f]{5} : a~f중 알파벳 5개를 넣는다.

* \* : 아무 글자나 넣는다.

* ETC : 나머지는 그대로 써준다.

![clear](/assets/images/webhacking_kr/prob11/2.png)
