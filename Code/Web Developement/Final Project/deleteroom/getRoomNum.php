<?php
$q = $_GET['q'];

$con = mysqli_connect('localhost','s002681','her3ved8', 'test');
if (!$con) {
    die('Could not connect: ' . mysqli_error($con));
}
mysqli_select_db($con,"test");
$sql="SELECT RoomNumber FROM room WHERE Building = '".$q."' ORDER BY RoomNumber";
$result = mysqli_query($con,$sql);

echo "<option value='' disabled selected>Select Room Number</option>";

while($row = mysqli_fetch_array($result)) {
    echo "<option value=" . $row['RoomNumber'] . ">" . $row['RoomNumber'] . "</option> ";
}
mysqli_close($con);
?>