---
layout: default
title: Prob20
parent: WebHacking.kr
nav_order: 20
---

# Prob20

문제 사이트에 접속하면 여러 input을 볼 수 있다.

![index](/assets/images/webhacking_kr/prob20/1.png)

해당 input에 text와 code를 넣고 2초 안에 submit을 하면 풀 수 있다.

python으로 툴을 작성하거나 콘솔에 script를 입력해 해결하면 된다.

```javascript
lv5frm.id.value='a';
lv5frm.cmt.value='a';
lv5frm.captcha.value=lv5frm.captcha_.value;
```