<?php
/**
 * Purpose: Isolate database connection's to a single instance that needs changed.
 */
 //Scoping to prevent unintended variable leakage
 // ADDED: Connection to my local database
function dbConnect(){
	/* $host = "localhost";
	$user = "s002681";
	$pass = "her3ved8";
	$defaultDB = 'test'; */
	$host = "localhost";
	$user = "root";
	$pass = "iceman45";
	$defaultDB = 'bookworms';

	return mysqli_connect($host,$user,$pass,$defaultDB);
}
?>