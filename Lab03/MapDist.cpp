#include "MapDist.h"

const MapDist distance(MapPoint nyc,MapPoint sydney){

  MapDist x;

  x.longitude = nyc.longitude + sydney.longitude;
  x.latitude = nyc.latitude - sydney.latitude;

  return x;
}

double angularDistance(MapDist d){
  
  double x = sqrt( pow(d.latitude,2) + pow(d.longitude,2));
  return x;

}

const MapPoint closestPlace(MapPoint *krakow,MapPoint* nyc,MapPoint* sydney){

  MapDist a = distance(*krakow,*nyc);
  MapDist b = distance(*krakow,*sydney);
  double ax = angularDistance(a);
  double bx = angularDistance(b);

  if(ax > bx){
    return *sydney;
  }
  else{
    return *nyc;
  }
}

std::string getName(MapPoint cl){
  return cl.name;
}