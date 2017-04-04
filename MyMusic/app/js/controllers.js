'use strict';

/* Controllers */

/*var MyMusicControllers = angular.module('MyMusicControllers',[]);

MyMusicControllers.controller('TrackListCtrl',['$scope','Track',
  function($scope,Track){
  $scope.tracks = Track.query();
  $scope.orderProp = 'rating';
}
]);*/
var MyMusic = angular.module('MyMusic',[]);

MyMusic.controller('TrackListCtrl',['$scope','$http',function($scope,$http){
  $http({
      method : "GET",
      url : "tracks/tracks.json"
    }).then(function mySucces(response) {
    $scope.tracks = response.data;
  }, function myError(response) {
    $scope.myWelcome = response.statusText;
  });
  //$scope.orderProp = 'rating';
}]);
