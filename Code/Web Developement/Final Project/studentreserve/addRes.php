<?php 
//EDIT: Alter times and db_connect
session_start();
include $_SERVER['DOCUMENT_ROOT'] . 'Final/html/reserve/php/db/database.php';
$con = db_connect();
//$curUser= $_SESSION['username'];
$curUser = "branmor";

    $startdate = date('Y-m-d', strtotime($_POST['d']));
    $enddate = "";
    $starttime = mysqli_real_escape_string($con, $_POST['t']);
    $endtime = mysqli_real_escape_string($con, $_POST['end']);
    $color = "#511730";
    $url = "";
    $user = mysqli_real_escape_string($con, $_POST['e']);
    $building = mysqli_real_escape_string($con, $_POST['b']);
    $roomnumber = mysqli_real_escape_string($con, $_POST['n']);
    $removedstart = "";
    $removedend = "";
    $name = $building." ".$roomnumber;
    /**WARNING: This is vulnerable until we use phpCAS!!**/
    $facID = db_getFacultyID($curUser);
    if ($facID == -1) {
        //$user = phpCAS::getUser();
    }
    
    
    $timeDiff = $endtime - $starttime;

    
    if($timeDiff == 1){
        $removedstart = $starttime;
        $removedend = date ("h:i A", strtotime("+1 hour", strtotime($starttime)));
    }
    else if($timeDiff == 2){
        $removedstart = $starttime.",".
        	date ("h:i A", strtotime("+1 hour", strtotime($starttime)));
        $removedend = date ("h:i A", strtotime("+1 hour", strtotime($starttime))).",".
        	date ("h:i A", strtotime("+2 hour", strtotime($starttime)));
    }
    else if($timeDiff == 3){
        $removedstart = $starttime.",".date ("h:i A", strtotime("+1 hour", strtotime($starttime))).",".
        	date ("h:i A", strtotime("+2 hour", strtotime($starttime)));
        $removedend = date ("h:i A", strtotime("+1 hour", strtotime($starttime))).",".
        	date ("h:i A", strtotime("+2 hour", strtotime($starttime))).",".
        	date ("h:i A", strtotime("+3 hour", strtotime($starttime)));
    }

    $query = mysqli_query($con, "SELECT user FROM schedule WHERE startdate='".$startdate."' AND user= '".$user."' AND starttime = '".$starttime."' AND endtime = '".$endtime."' AND name = '".$name."'");
    if(mysqli_num_rows($query) > 0){
        echo 'already reserved';
        exit();
    }
    else{
        $res = "INSERT INTO schedule (name, startdate, enddate, starttime, endtime, color, url, user, building, roomnumber, removedstart, removedend) VALUES ('$name', '$startdate', '$enddate', '$starttime', '$endtime', '$color', '$url', '$user', '$building', '$roomnumber', '$removedstart', '$removedend')";
        if (mysqli_query($con, $res)) {
            echo 'success';
        } 
        else {
            echo 'failed';
        }
        exit();
    }
?>
