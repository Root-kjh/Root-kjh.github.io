---
layout: default
title: Prob12
parent: WebHacking.kr
nav_order: 12
---

# Prob12

문제 사이트에 접속해 코드를 보면 암호화 된 javascript코드가 보인다.

![index](/assets/images/webhacking_kr/prob12/1.png)

아스키코드를 문자열로 바꾸어 주면 아래와 같은 코드를 볼 수 있다.

```javascript
var enco='';
var enco2=126;
var enco3=33;
var ck=document.URL.substr(document.URL.indexOf('='));

for(i=1;i<122;i++){
enco=enco+String.fromCharCode(i,0);
}

function enco_(x){
return enco.charCodeAt(x);
}

if(ck=="="+String.fromCharCode(enco_(240))+String.fromCharCode(enco_(220))+String.fromCharCode(enco_(232))+String.fromCharCode(enco_(192))+String.fromCharCode(enco_(226))+String.fromCharCode(enco_(200))+String.fromCharCode(enco_(204))+String.fromCharCode(enco_(222-2))+String.fromCharCode(enco_(198))+"~~~~~~"+String.fromCharCode(enco2)+String.fromCharCode(enco3)){
alert("Password is "+ck.replace("=",""));
}
```

if 문에서 비교하는 코드를 긁어서 콘솔에서 실행시키면 플레그가 나온다.

```javascript
"="+String.fromCharCode(enco_(240))+String.fromCharCode(enco_(220))+String.fromCharCode(enco_(232))+String.fromCharCode(enco_(192))+String.fromCharCode(enco_(226))+String.fromCharCode(enco_(200))+String.fromCharCode(enco_(204))+String.fromCharCode(enco_(222-2))+String.fromCharCode(enco_(198))+"~~~~~~"+String.fromCharCode(enco2)+String.fromCharCode(enco3)
```

![clear](/assets/images/webhacking_kr/prob12/2.png)
