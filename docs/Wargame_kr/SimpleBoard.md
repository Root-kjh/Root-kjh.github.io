---
layout: default
title: Simple Board
parent: Wargame.kr
nav_order: 14
---

# Simple Board

![index](/assets/images/wargame_kr/simpleboard/1.png)

view Cookie 값을 이용해 SQL Injection을 실시한다.

```php
<?php
    if (isset($_GET['view-source'])){
        if (array_pop(split("/",$_SERVER['SCRIPT_NAME'])) == "classes.php") {
            show_source(__FILE__);
            exit();
        }
    }

    Class DB {
        private $connector;

        function __construct(){
            $this->connector = mysql_connect("localhost", "SimpleBoard", "SimpleBoard_pz");
            mysql_select_db("SimpleBoard", $this->connector);
        }

        public function get_query($query){
            $result = $this->real_query($query);
            return mysql_fetch_assoc($result);
        }

        public function gets_query($query){
            $rows = [];
            $result = $this->real_query($query);
            while ($row = mysql_fetch_assoc($result)) {
                array_push($rows, $row);
            }
            return $rows;
        }

        public function just_query($query){
            return $this->real_query($query);
        }

        private function real_query($query){
            if (!$result = mysql_query($query, $this->connector)) {
                die("query error");
            }
            return $result;
        }

    }

    Class Board {
        private $db;
        private $table;

        function __construct($table){
            $this->db = new DB();
            $this->table = $table;
        }

        public function read($idx){
            $idx = mysql_real_escape_string($idx);
            if ($this->read_chk($idx) == false){
                $this->inc_hit($idx);
            }
            return $this->db->get_query("select * from {$this->table} where idx=$idx");
        }

        private function read_chk($idx){
            if(strpos($_COOKIE['view'], "/".$idx) !== false) {
                return true;
            } else {
                return false;
            }
        }

        private function inc_hit($idx){
            $this->db->just_query("update {$this->table} set hit = hit+1 where idx=$idx");
            $view = $_COOKIE['view'] . "/" . $idx;
            setcookie("view", $view, time()+3600, "/SimpleBoard/");
        }

        public function get_list(){
            $sql = "select * from {$this->table} order by idx desc limit 0,10";
            $list = $this->db->gets_query($sql);
            return $list;
        }

    }
```

![index](/assets/images/wargame_kr/simpleboard/2.png)

![index](/assets/images/wargame_kr/simpleboard/3.png)

![index](/assets/images/wargame_kr/simpleboard/4.png)

![index](/assets/images/wargame_kr/simpleboard/5.png)

![index](/assets/images/wargame_kr/simpleboard/6.png)

![index](/assets/images/wargame_kr/simpleboard/7.png)