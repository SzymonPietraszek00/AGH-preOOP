#pragma once
#include <iostream>
#include <cmath>

// klasa reprezentujaca wektor z dwoma wspolrzednymi i nazwą
class Vector2D{

public:

  //konstruktor tworzący wektor o wartościach domyślnych
  Vector2D(std::string nm = "Vx");

  //destruktor
  ~Vector2D();

  //konstruktor kopiujący
  Vector2D(const Vector2D&);

  //konstruktor przenoszący
  Vector2D(Vector2D&& vect);

  //named constructor idiom zwracajacy obiekt o nadanych wspolrzednych kartezjanskich i nazwie
  static Vector2D fromCarthesian(std::string, double, double);

  //named constructor idiom zwracajacy obiekt o nadachnych wartosiach i domyslnej nazwie
  static Vector2D fromCarthesian(double, double);

  //named constructor idiom zwracajacy obiekt o nadanych wartosciach i nazwie
  static Vector2D fromPolar(std::string, double, double);
  
  //zmienna statyczna przechowujaca liczbe wektorow
  static int count;

  //funkcja zwracajaca iloczyn skalarny dwoch wektorow
  double dot(const Vector2D &) const;

  //funkcja drukujaca wektor - jego wspolrzedne oraz nazwe
  void print(std::string n ="") const;

  //funkcje zwracająca nowo powstały wektor będacy sumą dwóch wektorow
  Vector2D add(const Vector2D &) const;

private:
  //konstruktor tworzący wektor o nadanej nazwie i wpolrzednych
  Vector2D(std::string nm, double x, double y);
  
  //nazwa wektora
  std::string _name;
  
  //pierwsza wspolrzedna wektora
  double _x;
  
  //druga wspolrzedna wektora
  double _y;

};