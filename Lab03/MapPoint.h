#pragma once
#include <iostream>
using namespace std;

//definicja punktu, miasta na mapie jako struktura
struct MapPoint{
  std::string name;
  double longitude;
  double latitude;
  char dlugosci;
  char szerokosci;
};

typedef struct MapPoint MapPoint;

//funkcja tworzy punkt przyjmujac nazwe i szerokosc oraz dlugosc geograficzna
MapPoint *construct(std::string name ,double longitude,double latitude);

//funkcja tworzy punkt przyjmujac nazwe i szerokosc oraz dlugosc geograficzna oraz skrotowe nazwy kierunkow geograficznych
MapPoint *construct(std::string,double,char,double,char );


//funkcja drukujaca
void print(MapPoint *city);

//funkcja drukujaca
void print(const MapPoint *portugalCity);

//funkcja przesuwa punkt na "mapie" o dane dlugosci i szerokosci
void movePoint(MapPoint *porto,const double longitudeShift,const double latitudeShift);

//funkcja oblicza wspolrzedne punktu znajdujacego sie pomiedzy danymi punktami(miastami)
MapPoint inTheMiddle(MapPoint*, MapPoint*,std::string);

//funkcja usuwajaca punkty z pamieci
void clear(MapPoint *krakow,MapPoint * nyc,MapPoint * porto);

//funkcja usuwajaca jeden punkt z pamieci
void  clear(MapPoint* sydney);