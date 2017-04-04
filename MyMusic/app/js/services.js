'use strict';

/* Services */

var MyMusicServices = angular.module('MyMusicServices', ['ngResource']);

MyMusicServices.factory('Track',['$resource',
  function($resource){
    return $resource()
  }
]);
