<?php
$name     = urlencode('hunter');
$email = urlencode('9195157171');

$str= "?name=".$name."&email=".$email;

print $str;

 $ch=curl_init();
 curl_setopt($ch,CURLOPT_URL,'http://www.calhat.com/reserve.php'.$str);
 curl_exec($ch);
 curl_close($ch);
?>
