#pragma once
#include <iostream>
#include <cmath>

//klasa reprezentujaca wektor
class Vector{

public:

//konstruktor tworzacy wektor i ustawiajacy jego wymiar
  explicit Vector(int);

//destruktor
  ~Vector();

//konstruktor kopiujacy
  Vector(const Vector&);

//konstruktor przenoszacy
  Vector(Vector&&);

//funkcja zwracajaca referencje
  int &at(int);

//funkcja drukujaca
  void print(std::string) const;

//funkcja obliczajaca iloczyn skalarny
  static double dot(Vector ,Vector );

//funkcja obliczajaca sume wektorow
  static Vector sum(Vector ,Vector );
  
//funkcja obliczajaca sume wektorow
  static Vector sum(Vector ,int);
  
//funkcja obliczajaca norme wektora
  double norm() const;

//operator zamieniajacy klase na typ double, zwracajac jego norme
  explicit operator double() const{
    return norm();
  }

private:

//wymiar wektora
  int _dimension;

//zawartosc wektora
  int *_vect;

};