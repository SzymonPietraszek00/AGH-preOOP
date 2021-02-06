#include "functionVector.h"

void FunctionVector::insert(std::function<double(double)> sample){
  vect.push_back(sample);
}

double FunctionVector::calc(double x){
  result.clear();

  double y = x;

  for(unsigned i=0; i<vect.size();i++){
    y = vect[i](y);
    result.push_back(y);
  }

  return y;
}


double FunctionVector::operator[](unsigned const int x){
  return result[x];
}