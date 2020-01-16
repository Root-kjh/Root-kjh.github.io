---
layout: default
title: dmbs335
parent: Wargame.kr
nav_order: 19
---

# dmbs335

코드 중 parse_str 이라는 함수의 취약점을 사용해 query_parts를 덮어버린 후, col이 preg_match가 안되게 만들어 SQL Injection을 진행한다.

```php
<?php 

if (isset($_GET['view-source'])) {
        show_source(__FILE__);
        exit();
}

include("../lib.php");
include("./inc.php"); // Database Connected

function getOperator(&$operator) { 
    switch($operator) { 
        case 'and': 
        case '&&': 
            $operator = 'and'; 
            break; 
        case 'or': 
        case '||': 
            $operator = 'or'; 
            break; 
        default: 
            $operator = 'or'; 
            break; 
}} 

if(preg_match('/session/isUD',$_SERVER['QUERY_STRING'])) {
    exit('not allowed');
}

parse_str($_SERVER['QUERY_STRING']); 
getOperator($operator); 
$keyword = addslashes($keyword);
$where_clause = ''; 

if(!isset($search_cols)) { 
    $search_cols = 'subject|content'; 
} 

$cols = explode('|',$search_cols); 

foreach($cols as $col) { 
    $col = preg_match('/^(subject|content|writer)$/isDU',$col) ? $col : ''; 
    if($col) { 
        $query_parts = $col . " like '%" . $keyword . "%'"; 
    } 

    if($query_parts) { 
        $where_clause .= $query_parts; 
        $where_clause .= ' '; 
        $where_clause .= $operator; 
        $where_clause .= ' '; 
        $query_parts = ''; 
    } 
} 

if(!$where_clause) { 
    $where_clause = "content like '%{$keyword}%'"; 
} 
if(preg_match('/\s'.$operator.'\s$/isDU',$where_clause)) { 
    $len = strlen($where_clause) - (strlen($operator) + 2);
    $where_clause = substr($where_clause, 0, $len); 
} 


?>
<style>
    td:first-child, td:last-child {text-align:center;}
    td {padding:3px; border:1px solid #ddd;}
    thead td {font-weight:bold; text-align:center;}
    tbody tr {cursor:pointer;}
</style>
<br />
<table border=1>
    <thead>
        <tr><td>Num</td><td>subject</td><td>content</td><td>writer</td></tr>
    </thead>
    <tbody>
        <?php
            $result = mysql_query("select * from board where {$where_clause} order by idx desc");
            while ($row = mysql_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>{$row['idx']}</td>";
                echo "<td>{$row['subject']}</td>";
                echo "<td>{$row['content']}</td>";
                echo "<td>{$row['writer']}</td>";
                echo "</tr>";
            }
        ?>
    </tbody>
    <tfoot>
        <tr><td colspan=4>
            <form method="">
                <select name="search_cols">
                    <option value="subject" selected>subject</option>
                    <option value="content">content</option>
                    <option value="content|content">subject, content</option>
                    <option value="writer">writer</option>
                </select>
                <input type="text" name="keyword" />
                <input type="radio" name="operator" value="or" checked /> or &nbsp;&nbsp;
                <input type="radio" name="operator" value="and" /> and
                <input type="submit" value="SEARCH" />
            </form>
        </td></tr>
    </tfoot>
</table>
<br />
<a href="./?view-source">view-source</a><br />
```

![index](/assets/images/wargame_kr/dmbs335/1.png)