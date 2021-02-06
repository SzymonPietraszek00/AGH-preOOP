#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "functions.h"

///klasa która przyjmuje i przechowuje obiekty funkcyjne
class FunctionVector{
public:

  /**
   * funkcja dodajaca do konetenera
  */
  void insert(std::function<double(double)>);

  /**
   * funkcja realizujaca funkcje
  */
  double calc(double);

  /**
   * operator [], zwracajacy element konetenera vector
  */
  double operator[](unsigned const int);


private:

  /**
   * kontener vector,typu double, przechowujacy wyniki operacji 
  */
  std::vector<double> result;

  /**
   * kontener przechowujacy ffunkcje
  */
  std::vector<std::function<double(double)>> vect;

};