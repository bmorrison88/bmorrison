<?php
//$con = mysqli_connect('localhost','s002681','her3ved8', 'test');
$con = mysqli_connect('localhost','root','iceman45', 'bookworms');
if (!$con) {
    die('Could not connect: ' . mysqli_error($con));
} 

$schedule="SELECT user, starttime, endtime, name, DATE_FORMAT(startdate, '%Y-%m-%d') FROM schedule WHERE DATE(startdate) = CURDATE()  ORDER BY MONTH(startdate) ASC, DAYOFMONTH(startdate) ASC, HOUR(starttime) ASC"; 
$result_sched = mysqli_query($con,$schedule);
$results = array();
while($row = mysqli_fetch_array($result_sched)) {
    $email = $row['user'] . '@siue.edu';
    array_push($results,"<tr><td> " .$row['user'] ." </td><td> " . date("g:i a", strtotime($row['starttime'])) ." </td><td> ". date("g:i a", strtotime($row['endtime'])) ." </td><td> ". $row['name'] ."</td><td> " . $email ." </td></tr>");
}

echo json_encode($results);
exit;
?>