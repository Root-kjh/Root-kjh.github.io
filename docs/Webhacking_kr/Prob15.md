---
layout: default
title: Prob15
parent: WebHacking.kr
nav_order: 15
---

# Prob15

문제 사이트에 접속하면 access denied가 뜨면서 접근이 제한된다.

크롬 설정에서 javascript를 차단시키고 접속하면 해당 문제의 소스를 볼 수 있다.

```javascript
  alert("Access_Denied");
  location.href='/';
  document.write("<a href=?getFlag>[Get Flag]</a>");
```

콘솔에서 document.write 코드를 실행시키거나, 직접 ?getFlag를 치고 들어가면 소스에 플레그가 출력된다.