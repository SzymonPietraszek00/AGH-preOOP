#include "MapPoint.h"


MapPoint *construct(std::string name ,double longitude,double latitude){

    MapPoint *city = new MapPoint;
    city->name = name;
    city->latitude = latitude;
    city->longitude = longitude;

    if(city->longitude > 0){
      city->dlugosci = 'E';
      
    }else{
      
      city->dlugosci = 'W';
    }

    if(city->latitude > 0){
      city->szerokosci = 'N';
      
    }else{
      city->szerokosci = 'S';
      
    }


    return city;

}

void print(MapPoint *city){

  std::cout << "Wspolrzedne dla " << city->name << ": " << abs(city->longitude) << city->dlugosci << " " << abs(city->latitude) << city->szerokosci << std::endl;

}

MapPoint *construct(std::string name,double longitude ,char x,double latitude,char y){

    MapPoint *city = new MapPoint;
    city->name = name;
    city->longitude = longitude; 
    city->latitude = latitude;
    city->dlugosci = x;
    city->szerokosci = y;

    return city;

}

void print(const MapPoint *city){

  std::cout << "Wspolrzedne dla " << city->name << ": " << abs(city->longitude) << city->dlugosci << " " <<abs(city->latitude) << city->szerokosci << std::endl;

}


void movePoint(MapPoint *porto,const double longitudeShift,const double latitudeShift){

   porto->longitude += longitudeShift;
   porto->latitude += latitudeShift;

   if(porto->longitude>0){
      porto->dlugosci = 'E';
      
    }else{
      
      porto->dlugosci = 'W';
    }

    if(porto->latitude > 0){
      porto->szerokosci = 'N';
      
    }else{
      porto->szerokosci = 'S';
      
    }


}

MapPoint inTheMiddle(MapPoint* a, MapPoint* b,std::string name){
    MapPoint middle;
    middle.name = name;
    middle.longitude = (a->longitude - b->longitude)/2;
    middle.latitude = (a->latitude + b->latitude)/2;

    return middle;
}



void clear(MapPoint *krakow,MapPoint * nyc,MapPoint * porto){

  std::cout << "Usuwanie " << krakow->name << std::endl;
  delete krakow;
  std::cout << "Usuwanie " << nyc->name << std::endl;
  delete nyc;
  std::cout << "Usuwanie " << porto->name << std::endl;
  delete porto;

}

void  clear(MapPoint* sydney){
  std::cout << "Usuwanie " << sydney->name << std::endl;
  delete sydney;
}