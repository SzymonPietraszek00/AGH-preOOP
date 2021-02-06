#include "functions.h"

Linear::Linear(double a, double b): _a(a), _b(b){
}

double Linear::operator()(const double& x) const{
 return _a*x+_b;
}

std::ostream& operator<<(std::ostream& strm, const Linear &l1){
  return strm << l1._a << "*x^2+" << l1._b <<"*x" << std::endl;
}


double Sqrt::operator()(const double& x)const{
  return sqrt(x);
}


Sin::Sin(double a, double b):_a(a) ,_b(b){}


double Sin::operator ()(const double& x)const{
  return sin(_a*x+_b);
}