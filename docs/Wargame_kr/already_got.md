---
layout: default
title: already got
parent: Wargame.kr
nav_order: 1
---

# Already got

문제에 접속하면 **you've already got key! :p** 이라는 문구가 나온다.

크롬 개발자도구로 Response Header를 보면 FLAG가 나와있다.

```
Connection: Keep-Alive
Content-Length: 27
Content-Type: text/html; charset=UTF-8
Date: Wed, 15 Jan 2020 05:13:24 GMT
FLAG: 8ff9062701dca99becebc4168d7e983aa6500d9c
Keep-Alive: timeout=5, max=95
Server: Apache/2.4.18 (Ubuntu)
```