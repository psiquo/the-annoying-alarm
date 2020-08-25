<!doctype html>
<?php
 require __DIR__.'/vendor/autoload.php';
 function check_time($time,$min,$max) {
      if(ctype_digit($time)){
          $time = (int) $time;
          return $time >= $min && $time <= $max;
      }
      return false;
  }
$msg_num = 0;
$server = 'mqtt.atrent.it';
$port = '1883';
$client_id = 'alarm-website';
$channel = 'SistEmbed/Davide/AnnoyingAlarm';
$mqtt = new \PhpMqtt\Client\MQTTClient($server,$port,$client_id);
$mqtt ->connect();
?>
<html lang="en">
  <head>
    <title>The Pisquo Sveglia</title>
  </head>
  <body>
    <h1 style="text-align:center">The Pisquo Sveglia</h1>
    <form action="index.php" method="post" style="align-content:center; text-align:center">
        <input type="text" name="hours" placeholder="Hours" />
        :
        <input type="text" name="minutes" placeholder="Minutes" />
        <br>
        <input type="submit" name="submit" style="margin-top:5px" />
    </form>
  </body>
  <?php

  $correct= true;
  if (isset($_POST["hours"]) && isset($_POST["minutes"])) {
      $hours = $_POST["hours"];
      $minutes = $_POST["minutes"];
      if(!check_time($hours,0,23)){
          $correct=false;
  ?>
      <p style="color:red;text-align:center"> Invalid hour format <?php echo $hours?> </p>
  <?php
     }
      if(!check_time($minutes,0,59)){
          $correct = false;
  ?>
      <p style="color:red;text-align:center"> Invalid minute format <?php echo $minutes?> </p>
  <?php
      }
  ?>
  <?php
      if($correct){
          $hours= (int) $hours;
          $minutes = (int) $minutes;
          $mqtt -> publish($channel,"$hours:$minutes",$msg_num++);
          $alarmFile = fopen( __DIR__ ."/alarm.txt","w");
          $txt = $hours.":".$minutes;
          fwrite($alarmFile,$txt);
          fclose($alarmFile);
  ?>
      <p style="text-align:center"> Sveglia impostata per le <?php echo sprintf('%02d',$hours) ?>:<?php echo sprintf('%02d',$minutes)?> </p>
  <?php
      }
  } else {
      $alarmFile = fopen( __DIR__ ."/alarm.txt","r");
      $alarm = fgets($alarmFile);
      fclose($alarmFile);
      $data = explode(":",$alarm);
  ?>
      <p style="text-align:center"> La sveglia suonerà alle <?php echo sprintf('%02d',$data[0]).":".sprintf('%02d',$data[1]) ?> </p>
  <?php

  }
   ?>
</html>
