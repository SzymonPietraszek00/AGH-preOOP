#include "MapDist.h"


MapDist::MapDist(){}

MapDist::~MapDist(){}

MapDist distance(MapPoint& p1, MapPoint &p2){
  
  MapDist x;

  x._longitude1 = p1._longitude - p2._longitude;
  x._latitude1 = p1._latitude - p2._latitude;

  if(x._longitude1 < 0){
    x._longitude1 = -x._longitude1;
  }

  if(x._latitude1 < 0){
    x._latitude1 = -x._latitude1;
  }

  return x;
}


MapDist::MapDist(MapPoint &p1, MapPoint &p2){


  _longitude1 = p1._longitude - p2._longitude;
  _latitude1 = p1._latitude - p2._latitude;

  if(_longitude1 < 0){
    _longitude1 = -_longitude1;
  }

  if(_latitude1 < 0){
    _latitude1 = -_latitude1;
  }

  
}

double MapDist::getlongitude() const{

  return _longitude1;
}

double MapDist::getlatitude() const{
  return _latitude1;
}


double MapDist::angularDistance() const{

  return sqrt(pow(_latitude1,2) + pow(_longitude1,2));
}