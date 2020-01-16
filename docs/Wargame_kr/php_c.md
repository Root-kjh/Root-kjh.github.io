---
layout: default
title: PHP? C?
parent: Wargame.kr
nav_order: 22
---

# PHP? C?

C로 된 실행파일에 입력값을 인자로 넣어 실행시켜 나온 값을 입력값과 비교한다. 

```php
<?php
 if (isset($_GET['view-source'])) {
     show_source(__FILE__);
    exit();
 }
 require("../lib.php"); // include for auth_code function.
 if(isset($_POST['d1']) && isset($_POST['d2'])){
  $input1=(int)$_POST['d1'];
  $input2=(int)$_POST['d2'];
  if(!is_file("/tmp/p7")){exec("gcc -o /tmp/p7 ./p7.c");}
  $result=exec("/tmp/p7 ".$input1);
  if($result!=1 && $result==$input2){echo auth_code("php? c?");}else{echo "try again!";}
 }else{echo ":p";}
?>
<style>
 table {background-color:#000; color:#fff;}
 td {background-color:#444;}
</style>
<hr />
 <center>
  <form method='post'>
  <table>
  <tr><td>D1:</td><td><input type='text' id="firstf" style="width:75px;" maxlength="9" name='d1'></td></tr>
  <tr><td>D2:</td><td><input type='text' style="width:75px;" name='d2'></td></tr>
  <tr><td colspan="2" style="text-align:center;"><input type='submit' value='try'></td></tr>
  </table>
  </form>
 <div><a href='?view-source'>get source</a></div>
 </center>
 <script>
  document.getElementById("firstf").focus();
 </script>
 ```

C 소스파일이 들어있는 URL에 접속하면 소스코드가 보인다.

인자로 0보다 큰 값을 받으면서 +5를 했을 때 4보다 작아야한다.

Integer Overflow를 발생시키면 풀 수 있다.

 ```c
 #include <stdio.h>
#include <stdlib.h>
void nono();
int main(int argc,char **argv){
 int i;
 if(argc!=2){nono();}
 i=atoi(argv[1]);
 if(i<0){nono();}
 i=i+5;
 if(i>4){nono();}
 if(i<5){printf("%d",i);}
 return 0;
}
void nono(){
  printf("%d",1);
  exit(1);
}
```