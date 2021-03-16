#pragma once
#include <iostream>
#include "MapDist.h"

//deklaracja klasy mapdist
class MapDist;

//deklaracja i definicja klasy mappoint
class MapPoint{

//deklaracja przyjazni z klasa mapdist
  friend class MapDist;

//deklaracja przyjazni z funkcja distance
  friend MapDist distance(MapPoint&, MapPoint&);

//deklaracja przyjazni z funkcja inthemiddle
  friend MapPoint inTheMiddle(MapPoint *,MapPoint *, std::string);


public:

//funkcja ustalajaca kierunki geograficzne (N-W-S-E) 
  void checksides(double longitude, double latitude); 

//konstruktor tworzacy punkt na mapie przypisujac nazwe ,dlugosc, szereokosc i okresla kierunki geograficzne
  MapPoint(std::string,double,double);

//konstruktor tworzacy punkt na mapie przypisujac nazwe ,dlugosc, szereokosc i kierunki geograficzne
  MapPoint(std::string,double,char,double,char);

//konstruktor domyslny - tworzy punkt
  MapPoint();

//destruktor
  ~MapPoint();
  
//funkcja drukujaca nazwe i wspolrzedne punktu na mapie oraz kierunki geograficzne
  void print() const;

//funkcja zmienia współrzedne punktu, przesuwając go o wartości podane w argumentach funkcji.
  void movePoint(double,double);

//funkcja pobiera 3 argumenty. Pierwszy argument jest punktem referencyjnym. Z dwóch kolejnych wybiera ten,który jest najbliżej punktu referencyjnego. 
  MapPoint& closestPlace(MapPoint*, MapPoint*);

//zwraca zmienna prywatna , nazwe punktu
  std::string getName() const;

  

private:
//nazwa punktu na mapie
  std::string _name;

//wspolrzedne dlugosci geograficznej
  double _longitude;

//wspolrzedne szerokosci geograficznej
  double _latitude;

//kierunek geograficzny - dlugosc
  char _side_long;

//kierunek geograficzny - szerokosc
  char _side_lati;
  
};

//tworzy nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów
MapPoint inTheMiddle(MapPoint *,MapPoint *, std::string);

