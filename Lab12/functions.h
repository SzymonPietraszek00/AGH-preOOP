#pragma once
#include <iostream>
#include <cmath>

#include "functionVector.h"

/// klasa reprezentujaca funkcje liniowa
class Linear{

  /**
   * zaprzyjazniony, przeciazony operator " << "
  */
  friend std::ostream& operator<<(std::ostream& strm, const Linear &l1);

public:
  /**
   *konstruktor przypisujacy wspolczynnik a i b funkcji liniowej
   * @param [double] - wspolczynnik a f.liniowej
   * @param [double] - wspolczynnik b f.liniowej
  */
  Linear(double,double);

  /**
   * operator () ktory oblicza i zwraca f.liniowa
  */
  double operator()(const double&) const;

private:

  /**
   * @param [double] - wspolczynnik a f.liniowej
  */
  double _a;

  /**
   * @param [double] - wspolczynnik b f.liniowej
  */
  double _b;

};

///klasa reprezentujaca funkcje pierwiastka
class Sqrt{

public:
 
 /**
   * operator () typu double, ktory oblicza i zwraca pierwiastek z liczby
   * @param [const double&] - wartosc z ktorej obliczany jest pierwiastek
  */
 double operator()(const double&)const;


private:

};

///klasa reprezentujaca funkcje sinus
class Sin{

public:
  /**
   *konstruktor przypisujacy wartosci z ktorych ma byc obliczony sinus
   * @param [double] - wspolczynnik _a
   * @param [double] - wspolczynnik _b
  */
  Sin(double,double);

  /**
   * operator () typu double, ktory oblicza i zwraca sinusa z liczby
   * @param [const double&] - wartosc z ktorej obliczany jest sinus
  */
  double  operator()(const double &x) const;

private:
  /**
   *zmienna przechowujaca wartosc typu double
  */
  double _a;

  /**
   *zmienna przechowujaca wartosc typu double
  */
  double _b;

};