#include "MapPoint.h"

void MapPoint::checksides(double longitude, double latitude){

  if(_longitude >= 0){

    _side_long = 'E';

  }else{

    _side_long = 'W';

  }

  if(_latitude >= 0){

    _side_lati = 'N';

  }else{

    _side_lati = 'S';
  }

}

MapPoint::MapPoint(){


}

MapPoint::~MapPoint(){
  std::cout << "Usuwanie " << _name << std::endl;
}


MapPoint::MapPoint(std::string name,double longitude,double latitude){
  
  _name = name;
  _longitude = longitude;
  _latitude = latitude;

  checksides(longitude,latitude);

}

MapPoint::MapPoint(std::string name,double longitude,char longe,double latitude,char lati){

  _name = name;
  _longitude = longitude;
  _latitude = latitude;
  _side_long = longe;
  _side_lati = lati;

  if(_side_long == 'W'){
    _longitude = -longitude;
  }

  if(_side_long == 'S'){
    _latitude = -latitude;
  }

}


void MapPoint::print() const{

  if(_latitude < 0 && _longitude < 0){
    std::cout << "Wspolrzedne dla "<< _name << " " << -_longitude <<_side_long <<  " " << -_latitude << _side_lati << std::endl;
    return;
  }

  if(_latitude < 0){
    std::cout << "Wspolrzedne dla "<< _name << " " << _longitude <<_side_long <<  " " << -_latitude << _side_lati << std::endl;
    return;
  }

  if(_longitude < 0){
    std::cout << "Wspolrzedne dla "<< _name << " " << -_longitude <<_side_long <<  " " << _latitude << _side_lati << std::endl;
    return;
  }


  std::cout << "Wspolrzedne dla "<< _name << " " << _longitude <<_side_long <<  " " << _latitude << _side_lati << std::endl;

}

void MapPoint::movePoint(double longshift,double latishift){

  _longitude += longshift;
  _latitude += latishift;

  checksides(_longitude,_latitude);
}


std::string MapPoint::getName() const{
  return _name;
}


MapPoint& MapPoint::closestPlace(MapPoint *city1, MapPoint *city2){

  MapDist a = distance(*city1, *city2);
  MapDist b = distance(*city1, *city2);

  double x = sqrt(pow(a._latitude1,2) + pow(a._longitude1,2));
  double y = sqrt(pow(b._latitude1,2) + pow(b._longitude1,2));

  if(x <= y){

    return *city1;

  }else{
    return *city2;
  }
  

}

MapPoint inTheMiddle(MapPoint *city1,MapPoint *city2, std::string name){

  MapPoint mid;
  mid._name = name;

  mid._longitude = (city1->_longitude - city2->_longitude)/2;
  mid._latitude = (city1->_latitude - city2->_latitude)/2;

  mid._longitude = city1->_longitude - mid._longitude;
  mid._latitude = city1->_latitude - mid._latitude;

  if(mid._longitude >= 0){

    mid._side_long = 'E';

  }else{

    mid._side_long = 'W';

  }

  if(mid._latitude >= 0){

    mid._side_lati = 'N';

  }else{

    mid._side_lati = 'S';
  }
  
  return mid;
}