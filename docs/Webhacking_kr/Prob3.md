---
layout: default
title: Prob3
parent: WebHacking.kr
nav_order: 3
---

# Prob3

문제 사이트에 들어가면 로직으로 보이는 판이 보인다.

![index](/assets/images/webhacking_kr/prob2/1.png)

로직을 풀고 들어가면 입력창 하나가 나온다.

![input](/assets/images/webhacking_kr/prob2/2.png)

아무 값이나 입력하니 아래와 같이 입력값 name과 입력하지 않은 answer, ip가 출력된다.

![result](/assets/images/webhacking_kr/prob2/3.png)

html 코드에서 hidden으로 answer값이 넘어가는 것을 볼 수 있다.
![answer_html](/assets/images/webhacking_kr/prob2/4.png)

answer 코드에 SQL Injection을 시도하면 플레그가 출력된다.

![Flag](/assets/images/webhacking_kr/prob2/5.png)