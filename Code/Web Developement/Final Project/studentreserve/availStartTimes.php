<?php 
//EDIT:
//changed date format from 'y-n-j' to 'y-m-d' [9]; 
//changed currdate[14]
include $_SERVER['DOCUMENT_ROOT'] . 'Final/html/reserve/php/db/database.php';
$con = db_connect();
date_default_timezone_set('America/Chicago');
$date = mysqli_real_escape_string($con, $_POST['date']);
$building = mysqli_real_escape_string($con, $_POST['build']);
$roomNum = mysqli_real_escape_string($con, $_POST['rnum']);
    //$date = date('Y-m-d', strtotime($date));
    // Check what day the user selected
    $currdate = date('Y-m-d',strtotime($date));
    //Check if the selected date is a special hour
    $specialHours = $con->query("SELECT * FROM specialhours ORDER BY ID");
    $a = array(); //Array of special hour rows
    $arr = array(); // Array of dates within a range with start time
    $brr = array(); // Array of dates within a range with end time
    
    while ($row = $specialHours->fetch_assoc()){
    	array_push($a, $row);
    }
    //For each row in the special hours table,generate spaecial dates
    foreach ($a as $b){
    	//$arr[$b["start_date"]] = $b["start_time"];
    	//for(startdate <= end date,increase start date by 1 day)
    	//Populates array with dates within a range
    	while (strtotime($b["start_date"]) <= strtotime($b["end_date"])){
    		$arr[$b["start_date"]] = $b["start_time"];
    		$brr[$b["start_date"]] = $b["end_time"];
    		//array_push($arr, $b["start_date"]);
    		$b["start_date"] = date ("Y-m-d", strtotime("+1 day", strtotime($b["start_date"])));
    	}
    }
    	//For each key-value pair, compare the current date to the days in the range
    	 foreach ($arr as $key => $value){
    		if ($currdate == $key){
    			//If the currdate exist in the range, it must have exist in array with the end times
    			foreach ($brr as $key2 => $value2){
    				if($currdate == $key2){
    				$days = date("l",strtotime($currdate));
    				$setTime = $con->query ("UPDATE days SET start_time = '".$value."', end_time = '".$value2."' WHERE day_name = '".$days."'");
    				break;
    				}
    			}
    			break;
     		}else{
    			$resetToDefaults = $con->query("SELECT * FROM days ORDER BY id");
    			while($row = $resetToDefaults->fetch_assoc()){
    				$days = $row["day_name"];
    				$defaultStartTime = $row["default_start_time"];
    				$defaultEndTime = $row["default_end_time"];
    				//echo "DAY: ".$day."  Start Time: ".$defaultStartTime."  End Time: ".$defaultEndTime."<br>";
    				$setTime = $con->query ("UPDATE days SET start_time = '".$defaultStartTime."', end_time = '".$defaultEndTime."' WHERE day_name = '".$days."'");
    			}
    		}
    	} 
    	
    $currday = date("l",strtotime($currdate));
    // Get starttime and endtime for that dayname
    $currTimes = $con->query("SELECT start_time,end_time FROM days WHERE day_name = '".$currday."' ORDER BY id");
    $result = mysqli_fetch_assoc($currTimes);
    $st = $result["start_time"];
    $et = $result["end_time"];
    //Populate options from starttime to endtime -1
    
    //Get start hour
    $out = array();
    //$s = date("H:i A",strtotime($st));
    $startHour = date("H",strtotime($st));
    $startRest = date(":i",strtotime($st));
    
    /* $timeStartArray = str_split($st,1); //Parse the start time into in array
    $startFirstTwo = $timeStartArray[0].$timeStartArray[1]; // Combine the first 2 digits of the time
    $startHoursInt = intval($startFirstTwo); // Convert str representation into integer */
    
    $endHour = date("H",strtotime($et));
    $endRest = date(":i",strtotime($et));
    
    $intStartHour = intval($startHour);
    $intEndHour = intval($endHour);
    //$t = date("H:i A",strtotime($et));
    /* $timeEndArray = str_split($t,1); //Parse the start time into in array
    $endFirstTwo = $timeEndArray[0].$timeEndArray[1]; // Combine the first 2 digits of the time
    $endHoursInt = intval($endFirstTwo); // Convert str representation into integer */
    
    //$rest = $timeStartArray[2].$timeStartArray[3].$timeStartArray[4].$timeStartArray[5];
    //$message = $a;
    while ($intStartHour < $intEndHour){
    	//print_r($test);
    	//echo "<br>";
    	$startTime = $intStartHour.$startRest;
    	$startTimeOptions = date("h:i A",strtotime($startTime));
    	//array_push($out, $f);
    	array_push($out, $startTimeOptions);
    	
    	$intStartHour = $intStartHour+1;
    }
    echo json_encode($out);
    
    exit();
?>