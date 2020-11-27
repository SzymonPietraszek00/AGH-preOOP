#include "funkcje.h"
#include <iostream>

int silnia(int i){
  
  int wyniksilnia=1;

  if(i<0){  

    std::cout<<"brak rozwiazania";
    return -1;

  }else if(i>=0){
        
          for(i=i; i>1; i--){
              wyniksilnia = wyniksilnia * i;
          }
          return wyniksilnia;
    }

    return wyniksilnia;
}


int silnia_rec(int k){

    if(k<0){
      std::cout<<"brak rozwiazania";
      return -1;
    }
    if(k<2){
      return 1;
    }
    else return k*silnia_rec(k-1);
}


void wypisz(double *tab,const int size){

  for(int i=0;i<size;i++){
    std::cout<<tab[i]<<" ";
  }
  std::cout<<std::endl;
}

void powiel (double *tab,double factor,int size){

  for(int i=0;i<size;i++){
    tab[i]=tab[i]*factor;
  }
}

double suma (double *tab, int size){
  double sum=0;

  for(int i=0;i<size;i++){
    sum=sum+tab[i];
  }
return sum;
}

double srednia (double *tab,int size){

  double srednia;
  srednia=(suma(tab, size))/size;
  return srednia;

}