#include "Vector.h"

Vector::Vector(int dimension) : _dimension(dimension){
  _vect = new int[dimension];

  for(int i = 0; i < _dimension; i++){
    _vect[i] = 0;
  }

}



Vector::~Vector(){
  delete [] _vect;
}


Vector::Vector(const Vector&v1): _dimension(v1._dimension){
 
  _vect = new int[_dimension];

  for(int i = 0; i < _dimension; i++){
    _vect[i] = v1._vect[i];
  }
  
}


Vector::Vector(Vector&& v1): _dimension(std::move(v1._dimension)), _vect(std::move(v1._vect)){
    v1._dimension = 0;
    v1._vect = nullptr;
}


int& Vector::at(int index){

  return _vect[index];
}


void Vector::print(std::string s) const{
  std::cout << s << "(";

  for(int i = 0; i < _dimension-1; i++){
    std::cout << _vect[i] << ", ";
  }

  std::cout << _vect[_dimension-1] << ")" << std::endl;
}


double Vector::dot(Vector v1,Vector v2){
  double x = 0;
  for(int i = 0; i < v1._dimension; i++){
    x += (v1._vect[i] * v2._vect[i]);
  }

  return x;
}


double Vector::norm()const{
    return sqrt(dot(*this, *this));
}

Vector Vector::sum(Vector v1,Vector v2){
  Vector x(v1._dimension);

  for(int i = 0; i < v1._dimension; i++){
    x._vect[i] = v1._vect[i] + v2._vect[i];
  }
  return x;
}


Vector Vector::sum(Vector v1,int y){

  Vector x(v1._dimension);

  for(int i = 0; i < v1._dimension; i++){
    x._vect[i] = v1._vect[i] + y;
  }

  return x;
}

