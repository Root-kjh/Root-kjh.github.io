---
layout: default
title: Tmitter
parent: Wargame.kr
nav_order: 13
---

# Tmitter

문제를 풀기 전, 설명에 Table Struct가 나와있다.

```
create table tmitter_user(
 idx int auto_increment primary key,
 id char(32),
 ps char(32)
);
```

접속하면 로그인과 회원가입 버튼이 보인다.

![index](/assets/images/wargame_kr/tmitter/1.png)

회원가입 창에 들어가 소스를 보면 admin으로 회원가입 하라는 주석이 보인다.

ID로 어드민 ID를 친 후에 띄어쓰기로 32칸을 모두 채우고 그 뒤에 아무 글자나 넣으면 admin 계정으로 회원가입 할 수 있다.

```html
<head>
 <style>
  body {background-color:#eef;}
  table td {text-align:center; background-color:#dde;}
  .ex {text-align:left; color:#99a; font-size:9pt;}
 </style>
 <script>
  function chk(f){
   if(f.id.value.length<4){alert("chk id"); return false;}
   if(f.ps.value.length<7){alert("chk ps"); return false;}
   return true;
  }
 </script>
</head>
<body>
<center>
 <img src="./tmitter.png">
 <form onsubmit="return chk(this);" method="post">
  <table>
   <tr><td>ID</td><td><input type="text" name="id" maxlength="32"></td><td class="ex">at least 4char</td></tr>
   <tr><td>PS</td><td><input type="password" name="ps" maxlength="32"></td><td class="ex">at least 7char</td></tr>
   <tr><td colspan=2><input type="submit" value="join"></td></tr>
  </table>
 </form>
</body>
<!-- hint : you need join with admin -->
```