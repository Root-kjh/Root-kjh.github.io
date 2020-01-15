---
layout: default
title: Prob20
parent: WebHacking.kr
nav_order: 20
---

# Prob20

문제 사이트에 접속하면 input과 javascript 소스를 볼 수 있다.

```javascript
function ck(){
  var ul=document.URL;
  ul=ul.indexOf(".kr");
  ul=ul*30;
  if(ul==pw.input_pwd.value) { location.href="?"+ul*pw.input_pwd.value; }
  else { alert("Wrong"); }
}
```
input에 넣은 text가 ul과 같으면 ?로 이동시킨다. 간단히 ul 값을 구하면 되는 문제다.

```javascript
document.URL.indexOf(".kr")*30
```

![clear](/assets/images/webhacking_kr/prob14/1.png)
