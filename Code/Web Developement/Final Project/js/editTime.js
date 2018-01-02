$( function() {
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