#pragma once
#include <iostream>
#include "MapPoint.h"
#include <cmath>

//deklaracja klasy mappoint
class MapPoint;

//deklaracja i definicja klasy mapdist
class MapDist{

//deklaracja przyjazni z klasa MapPoint
  friend class MapPoint;

//deklaracja przyjazni z funkcja distance
  friend MapDist distance(MapPoint&, MapPoint&);

public:

//konstruktor tworzacy obiekt klasy mapdist i obliczajacy odległość pomiędzy dwoma punktami.
  MapDist(MapPoint&, MapPoint&);

//konstruktor domyslny
  MapDist();

//destruktor
  ~MapDist();

//funkcja zwracajaca prywatna zmienna - dlugosc geograficzna
  double getlongitude() const;

//funkcja zwracajaca prywatna zmienna - szerokosc geograficzna
  double getlatitude() const;
  
//Funkcja angularDistance oblicza pierwiastek z sumy kwadratów odległości względem południków i równoleżników,
  double angularDistance() const;

private:

//odleglosc miedzy wspolrzednymi dlugosc dwoch punktow na mapie
  double _longitude1;

//odleglosc miedzy wspolrzednymi szerokosc dwoch punktow na mapie
  double _latitude1;

};

// funkcja tworzy obiekt klasy mapdist i oblicza odległość pomiędzy dwoma punktami.
MapDist distance(MapPoint&, MapPoint&);