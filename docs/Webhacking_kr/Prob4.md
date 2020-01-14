---
layout: default
title: Prob4
parent: WebHacking.kr
nav_order: 4
---

# Prob4

문제 사이트에 접속하면 base64로 encoding 된듯한 문자열이 보인다.

![index](/assets/images/webhacking_kr/prob4/1.png)

base64로 decoding하니 40글자의 문자열이 나오는데, output이 40글자인 sha1로 복호화를 진행하면 Flag가 나온다.

![sha1](/assets/images/webhacking_kr/prob4/2.png)
