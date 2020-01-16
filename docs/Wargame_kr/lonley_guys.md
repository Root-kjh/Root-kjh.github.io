---
layout: default
title: Lonley Guys
parent: Wargame.kr
nav_order: 19
---

# Lonley Guys

sort 변수를 넣는 부분에서 if 함수와 pow 함수를 이용해 Blind SQL Injection을 진행한다.

```php
<?php
if (isset($_GET['view-source'])) {
    show_source(__FILE__);
    exit();
}
include("./inc.php");
include("../lib.php");
//usleep(200000*rand(2,3));
if(isset($_POST['sort'])){
 $sort=$_POST['sort'];
}else{
 $sort="asc";
}
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
<html>
 <head>
  <style type="text/css">
   body {background-color:#eaeafe;}
   #title {text-align:center; font-size:22pt; border:1px solid #cacaca;}
   #reg:hover {color:#557; cursor:pointer;}
   #contents {text-align:center; width:550px; margin: 30px auto;}
   #admin_tbl {width:100%;}
   #admin_tbl thead tr td {border-bottom:1px solid #888; font-weight:bold;}
   #admin_tbl tbody tr td {border-bottom:1px solid #aaa;}
   #admin_tbl #reg {width:200px;}
  </style>
  <script type="text/javascript" src="./jquery.min.js"></script>
  <script type="text/javascript" src="./jquery.color-RGBa-patch.js"></script>
  <script type="text/javascript"> var sort="<?php echo $sort; ?>"; </script>
  <script type="text/javascript" src="./main.js"></script>
 </head>
 <body>
  <div id="title"> Lonely guys Management page </div>
  <div id="contents">
   <table id="admin_tbl">
    <thead>
     <tr><td>the list of guys that need a girlfriend.</td><td id="reg">reg_single <sub>(sort)</sub></td></tr>
    </thead>
    <tbody>
     <?php
      mysql_query("update authkey set authkey='".auth_code('lonely guys')."'");
      $sort = mysql_real_escape_string($sort);
      $result=mysql_query("select * from guys_tbl order by reg_date $sort");
      while($row=mysql_fetch_array($result)){
       echo "<tr><td>$row[1]</td><td>$row[2]</td></tr>";
      }
     ?>
    </tbody>
   </table>
  </div>
  <div style="text-align:center;">
      <a href="?view-source">view-source</a>
  </div>
 </body>
</html>
```

![index](/assets/images/wargame_kr/lonley_guys/1.png)