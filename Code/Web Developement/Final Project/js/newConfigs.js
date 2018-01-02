/*Use for referral*/  

$( function() {
  	var dayNameIndex,days,options,hourConversions, startTime,endTime,startDate,endDate,startDateText,endDateText;
  	days = new Array();
  	
  	
  	// Date Picker functionality
  	/*$( function() {
  	    var dateFormat = "mm/dd/yy",
  	      startDate = $( "#startDate" )
  	        .datepicker({
  	          minDate: 0,
  	          defaultDate: "+1w",
  	          changeMonth: true
  	          })
  	        .on( "change", function() {
  	          endDate.datepicker( "option", "minDate", getDate( this ) );
  	        }),
  	      endDate = $( "#endDate" ).datepicker({
  	        minDate:0,
  	    	defaultDate: "+1w",
  	        changeMonth: true
  	      })
  	      .on( "change", function() {
  	        startDate.datepicker( "option", "maxDate", getDate( this ) );
  	      });
  	 
  	    function getDate( element ) {
  	      var date;
  	      try {
  	        date = $.datepicker.parseDate( dateFormat, element.value );
  	      } catch( error ) {
  	        date = null;
  	      }
  	 
  	      return date;
  	    }
  	  } );*/
  	
  	$( function() {
  	    var dateFormat = "dd/mm/yy",
  	      startDate = $( "#startDate" )
  	        .datepicker({
  	          dateFormat: "yy-mm-dd",
  	          minDate: 0,
  	          defaultDate: "+1w",
  	          changeMonth: true
  	          })
  	        .on( "change", function() {
  	          endDate.datepicker( "option", "minDate", getDate( this ) );
  	        }),
  	      endDate = $( "#endDate" ).datepicker({
  	    	dateFormat: "yy-mm-dd",
  	    	minDate:0,
  	    	defaultDate: "+1w",
  	        changeMonth: true
  	      })
  	      .on( "change", function() {
  	        startDate.datepicker( "option", "maxDate", getDate( this ) );
  	      });
  	 
  	    function getDate( element ) {
  	      var date;
  	      try {
  	        date = $.datepicker.parseDate( dateFormat, element.value );
  	      } catch( error ) {
  	        date = null;
  	      }
  	 
  	      return date;
  	    }
  	  } );
  	
    // Submit button will save data to database
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
    	startTime = $("#startHours option:selected").text() + ":" + $("#startMinutes option:selected").text() + ":00";
    	endTime = $("#endHours option:selected").text() + ":" + $("#endMinutes option:selected").text() + ":00";
    	
    	/*//DATETIME FORMAT
    	startDateText = $("#startDate").val() + " " + startTime ;
    	endDateText = $("#endDate").val() + " " + endTime;*/
    	//DATE FORMAT
    	startDateText = $("#startDate").val();
    	endDateText = $("#endDate").val();
    	/*console.log(startDateText);
    	console.log(endDateText);*/
    	
    	//SEND THIS DATE AND TIME TO THE DATABASE
    	
    })
    
    //Populates the options for starting time (24 or 12)
    for (i = 1; i <= 12; i++)
	{ 
     	$('#startHours').append($('<option>',
     	{
        value: (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}),
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) //Makes number 2 digits in length
    	}));
	}
	
	for (i = 0; i <= 59; i++)
	{ 
     	$('#startMinutes').append($('<option>',
     	{
        value: (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}),
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) 
    	}));
	}
	
	//Populates the options for ending time
    for (i = 1; i <= 12; i++)
	{ 
     	$('#endHours').append($('<option>',
     	{
        value: (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}),
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) //Makes number 2 digits in length
    	}));
	}
	
	for (i = 0; i <= 59; i++)
	{ 
     	$('#endMinutes').append($('<option>',
     	{
        value: (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}),
        text : (i).toLocaleString('en-US', {minimumIntegerDigits: 2, useGrouping:false}) 
    	}));
	}
	
   })
    									
    									
    /*$.each(obj, function(key,value){
    		if(days[dayNameIndex == value.dayName]){
    			$("#currentHours").append("<p>" + value.startTime + "</p>");
    		}
    	})*/											