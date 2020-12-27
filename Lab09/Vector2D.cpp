#include "Vector2D.h"

int Vector2D::count = 0;

Vector2D::Vector2D(std::string name) : _name(name), _x(0), _y(0){

  count++;
}


Vector2D::Vector2D(std::string name, double x, double y) : _name(name), _x(x), _y(y){

  count++;
}


Vector2D::~Vector2D(){
  count--;
}


Vector2D::Vector2D(const Vector2D& vect) : _name(vect._name), _x(vect._x), _y(vect._y){

  vect.print("-- kopiowanie " );

  count++;
}


Vector2D::Vector2D(Vector2D&& vect) : _name(std::move(vect._name)), _x(std::move(vect._x)), _y(std::move(vect._y)){

  vect.print("-- przenoszenie ");

  vect._name = "Vx";
  vect._x = vect._y = 0;

  count++;
}


Vector2D Vector2D::fromCarthesian(std::string name, double x, double y){
  return Vector2D(name, x, y);
}


Vector2D Vector2D::fromCarthesian(double x, double y){

  return Vector2D("Vx", x, y);
}


Vector2D Vector2D::fromPolar(std::string name, double r, double phi){

  return Vector2D(name, r*std::cos(M_PI/180*phi), r*std::sin(M_PI/180*phi));
}


void Vector2D::print(std::string name) const{

  std::cout << name << _name << "=(" << _x << ", " << _y << ")" << std::endl;
}


double Vector2D::dot(const Vector2D& vect) const{
  return (_x * vect._x) + (_y * vect._y);
}


Vector2D Vector2D::add(const Vector2D & vect) const{

  Vector2D vector;
  
  vector._x = _x + vect._x;
  vector._y = _y + vect._y;

  return vector;
}




