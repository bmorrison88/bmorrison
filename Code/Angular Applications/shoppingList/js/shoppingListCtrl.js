app.controller("shoppingListCtrl", function($scope){
    $scope.products = ["Eggs","Milk", "Butter"];
    $scope.addItem = function(addMe){
        $scope.errText = "";
        var x = [];

        for(var i = 0; i < $scope.products.length;i++){
            x.push($scope.products[i].toLowerCase());
        }

        if(!$scope.addMe){
             $scope.errText = "You can't add an empty item.";
             return;
            }
        if(x.indexOf($scope.addMe.toLowerCase())==-1)
            $scope.products.push($scope.addMe);
        else
            $scope.errText = "The item is already in your shopping list."
        
        
    };
    $scope.removeItem = function(removedIndex){
        $scope.errText = "";
        $scope.products.splice(removedIndex,1);
    };
});