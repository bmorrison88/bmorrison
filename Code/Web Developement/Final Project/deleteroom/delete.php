<?php
    	

    #Creates the connection to the database used			  
    $con = mysqli_connect('localhost','s002681','her3ved8', 'test');
    
    if (!$con) {
        die('Could not connect: ' . mysqli_error($con));
    }
    $building = mysqli_real_escape_string($con, $_POST['building']);
    $number = mysqli_real_escape_string($con, $_POST['number']);

    #Selects the proper database
    mysqli_select_db($con,"test");
    
    #Checks if the current item is different and also makes sure the db isn't updated with an empty variable			       
    $delete = "DELETE FROM room WHERE Building = '".$building."' AND RoomNumber= '".$number."'";
    if(mysqli_query($con, $delete )){
        echo "success";
    }
    else{
        echo "fail";
    }

    exit();

?>
