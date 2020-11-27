#pragma once
#include <iostream>
#include "MapPoint.h"
#include <cmath>

//definicja sturktury przechowuajca dlgusoc i szerokosc geograficzna 
struct MapDist{

    double longitude;
    double latitude;


};

typedef struct MapDist MapDist;

//funkcja obliczajaca dystans pomiedzy wspolrzednymi punktow
const MapDist distance(MapPoint nyc,MapPoint sydney);

//funkcja obliczajaca pierwiastek z sumy kwadratów odległości względem południków i równoleżników
double angularDistance(MapDist d);

//funkcja porownujaca stworzone punkty i obliczajaca czy punkt 2 czy punkt 3 lezy blizej punktu nr 1
const MapPoint closestPlace(MapPoint *krakow,MapPoint* nyc,MapPoint* sydney);

//funkcja zwracajaca nazwe punktu
std::string getName(MapPoint cl);