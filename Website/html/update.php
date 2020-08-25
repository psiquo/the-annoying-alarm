<?php
if(isset($_GET['hours']) && isset($_GET['minutes'])){
  $alarmFile = fopen(__DIR__."/alarm.txt","w");
  $txt = $_GET['hours'].":".$_GET['minutes'];
  fwrite($alarmFile,$txt);
  fclose($alarmFile);
}

header("location:/index.php");
?>
