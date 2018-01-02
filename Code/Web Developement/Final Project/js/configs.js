  $( function() {
  	var dayNameIndex,days,options,hourConversions, startTime,endTime,startDate,endDate;
  	days = new Array();
  	hourConversions = new Array();
  	
  	hourConversions = [
  		{"0": 0},
  		{"1": 1},
  		{"2": 2},
  		{"3": 3},
  		{"4": 4},
  		{"5": 5},
  		{"6": 6},
  		{"7": 7},
  		{"8": 8},
  		{"9": 9},
  		{"10": 10},
  		{"11": 11},
  		{"12": 12},
  		{"13": 1},
  		{"14": 2},
  		{"15": 3},
  		{"16": 4},
  		{"17": 5},
  		{"18": 6},
  		{"19": 7},
  		{"20": 8},
  		{"21": 9},
  		{"22": 10},
  		{"23": 11}
	]
  	
  	// Date Picker for start date
  	$( "#startDate" ).datepicker(
  		    {
  		    	minDate:0,
  		    	
  		    	onSelect: function(dateText,inst){
  		    	var theDate = $(this).datepicker('getDate');
  		    	dayNameIndex = theDate.getUTCDay();
  		    	 
  			    days[0] = "Sunday";
  			    days[1] = "Monday";
  			    days[2] = "Tuesday";
  			    days[3] = "Wednesday";
  			    days[4] = "Thursday";
  			    days[5] = "Friday";
  			    days[6] = "Saturday";
  			    
  			    
  			    //Get regular hours from a JSON file
  		    	$.getJSON('../json/regularHours.json', function(obj){
  		    	//console.log(obj);
  		    	// Displays the current hours for that day
  		    	$("#currentHours").empty().append("Current Hours: " + obj.calendarDays[dayNameIndex].startTime + " to " + obj.calendarDays[dayNameIndex].endTime);
  		    	
  		    	})
  			     // days[dayNameIndex] = the day of the week
  		    	}
  		    })
    
    // Submit button will output day of week
    $("#submitButton").on("click", function(){
    	/*console.log(days[dayNameIndex]);
    	startTime = $("#startHours option:selected").text() + ":" + $("#startMinutes option:selected").text() + " " + $("#startAmpm").val();
    	endTime = $("#endHours option:selected").text() + ":" + $("#endMinutes option:selected").text() + " " + $("#endAmpm").val();
    	console.log(startTime);
    	console.log(endTime);
    	
    	//PROBLEM: Doesn't actually save the new times on the json file
    	$.getJSON('../json/regularHours.json', function(obj){
    	obj.calendarDays[dayNameIndex].startTime = startTime;
    	obj.calendarDays[dayNameIndex].endTime = endTime;
    	console.log(obj);
    	$("#currentHours").empty().append("Current Hours: " + obj.calendarDays[dayNameIndex].startTime + " to " + obj.calendarDays[dayNameIndex].endTime);
    	})*/
    	
    })
    
    //Populates the options for starting time (24 or 12)
    for (i = 1; i <= 12; i++)
	{ 
     	$('#startHours').append($('<option>',
     	{
        value: i,
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) //Makes number 2 digits in length
    	}));
	}
	
	for (i = 0; i <= 59; i++)
	{ 
     	$('#startMinutes').append($('<option>',
     	{
        value: i,
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) 
    	}));
	}
	
	//Populates the options for ending time
    for (i = 1; i <= 12; i++)
	{ 
     	$('#endHours').append($('<option>',
     	{
        value: i,
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) //Makes number 2 digits in length
    	}));
	}
	
	for (i = 0; i <= 59; i++)
	{ 
     	$('#endMinutes').append($('<option>',
     	{
        value: i,
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) 
    	}));
	}
	
   })
    									
    									
    /*$.each(obj, function(key,value){
    		if(days[dayNameIndex == value.dayName]){
    			$("#currentHours").append("<p>" + value.startTime + "</p>");
    		}
    	})*/											