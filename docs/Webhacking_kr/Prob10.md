---
layout: default
title: Prob10
parent: WebHacking.kr
nav_order: 10
---

# Prob10

문제 사이트에 접속하면 마우스를 갖다대면 조금씩 왼쪽으로 움직이는 그림이 보인다.

![index](/assets/images/webhacking_kr/prob10/1.png)

소스를 보면 마우스를 한번 갖다댈 때마다 왼쪽으로 1씩 움직이고, 총 800만큼 움직여야 한다는 것을 알 수있다.

![code](/assets/images/webhacking_kr/prob10/2.png)

문제를 푸는 방법은 3가지가 있다.

1. 마우스를 800번 갖다 대 800만큼 이동

2. 소스를 posLeft+=800으로 수정 후 한번에 이동

3. url를 조작해 해당 소스가 가리키는 url로 이동

![code 조작](/assets/images/webhacking_kr/prob10/3.png)

필자는 2번 방법을 이용해 풀었다.

![clear](/assets/images/webhacking_kr/prob10/4.png)