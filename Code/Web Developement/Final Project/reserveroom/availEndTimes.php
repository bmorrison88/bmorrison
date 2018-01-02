<?php 
include $_SERVER['DOCUMENT_ROOT'] . 'Final/html/reserve/php/db/database.php';
$con = db_connect();
$startTime = mysqli_real_escape_string($con, $_POST['t']);
$date = mysqli_real_escape_string($con, $_POST['date']);
$building = mysqli_real_escape_string($con, $_POST['build']);
$roomNum = mysqli_real_escape_string($con, $_POST['rnum']);
//$time = date("H:i", strtotime($time));
//$date = date('Y-n-j', strtotime($date));
//Get starttime $startTime
//Add three hours to start time
$currdate = date('Y-m-d',strtotime($date));

//echo "<script type='text/javascript'>alert('$message');</script>";
$currday = date("l",strtotime($currdate));
// Get starttime and endtime for that dayname
$currTimes = $con->query("SELECT start_time,end_time FROM days WHERE day_name = '".$currday."' ORDER BY id");
$result = mysqli_fetch_assoc($currTimes);
$endTime = $result["end_time"];
$endTimeHour = date("H",strtotime($endTime)); 
$startTimeHour = date("H",strtotime($startTime));
$startTimeMinutes = date(":i",strtotime($startTime));
$startTimeInt = intval($startTimeHour);
$endTimeInt = intval($endTimeHour);
$optionsArray = array();
for ($i = 1;$i<=3;$i++){
	if($endTimeInt - $startTimeInt >= 3){
		$incrementEndTime = $startTimeInt + $i;
		$endTimeConcat = $incrementEndTime.$startTimeMinutes;
		$endTimeOption = date("h:i A", strtotime($endTimeConcat));
		array_push($optionsArray, $endTimeOption);
	}else if($endTimeInt - $startTimeInt == 2 && $i<=2){
		$incrementEndTime = $startTimeInt + $i;
		$endTimeConcat = $incrementEndTime.$startTimeMinutes;
		$endTimeOption = date("h:i A", strtotime($endTimeConcat));
		array_push($optionsArray, $endTimeOption);
	}else if($endTimeInt - $startTimeInt == 1 && $i==1){
		$incrementEndTime = $startTimeInt + $i;
		$endTimeConcat = $incrementEndTime.$startTimeMinutes;
		$endTimeOption = date("h:i A", strtotime($endTimeConcat));
		array_push($optionsArray, $endTimeOption);
	}
}

echo json_encode($optionsArray);

exit();




/* include $_SERVER['DOCUMENT_ROOT'] . 'Final/html/reserve/php/db/database.php';
$con = db_connect();
$time = mysqli_real_escape_string($con, $_POST['t']);
$date = mysqli_real_escape_string($con, $_POST['date']);
$building = mysqli_real_escape_string($con, $_POST['build']);
$roomNum = mysqli_real_escape_string($con, $_POST['rnum']);
    //$time = date("H:i", strtotime($time));
    $date = date('Y-n-j', strtotime($date));

    $array1 = array();
    $avail = array();
    if (!$con) {
        die('Could not connect: ' . mysqli_error($con));
    }
 

    $avail_time="SELECT removedend FROM schedule WHERE startdate = '". $date ."' AND Building = '". $building ."' AND RoomNumber = '". $roomNum ."'"; 
    $result_time = mysqli_query($con,$avail_time);
    
    while($row = mysqli_fetch_array($result_time)) {
        $output = $row['removedend'];
        array_push($array1, $output);
    }
    $array1 = implode(",", $array1);
    $array1 = explode(",", $array1);

    //takes care of 4pm to 7pm options and limitations
    if(($time == '21' || $time == '22')){
        if($time == '21' && !in_array(($time + 1 . ":00"), $array1)){
            array_push($avail, "<option value='". ($time + 1) ."'>" . date('g:i a', strtotime($time + 1 . ':00')) . "</option>");
            if(!in_array(($time + 2 . ":00"), $array1)){
                array_push($avail, "<option value='". ($time + 2) ."'>" . date('g:i a', strtotime($time + 2 . ':00')) . "</option>"); 
            }
        }
        if($time == '22' && !in_array(($time + 1 . ":00"), $array1)){
            array_push($avail, "<option value='". ($time + 1) ."'>" . date('g:i a', strtotime($time + 1 . ':00')) . "</option>");
        }
    }
    else {
        if(!in_array(($time + 1 . ":00"), $array1)){
            array_push($avail, "<option value='". ($time + 1) ."'>" . date('g:i a', strtotime($time + 1 . ':00')) . "</option>");
        }
        if(!in_array(($time + 2 . ":00"), $array1)){
            array_push($avail, "<option value='". ($time + 2) ."'>" . date('g:i a', strtotime($time + 2 . ':00')) . "</option>");
        }
        if(!in_array(($time + 3 . ":00"), $array1) && !in_array(($time + 2 . ":00"), $array1)){
            array_push($avail, "<option value='". ($time + 3) ."'>" . date('g:i a', strtotime($time + 3 . ':00')) . "</option>");
        }
    }

    echo json_encode($avail);

    exit(); */
?>