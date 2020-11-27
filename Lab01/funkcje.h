#pragma once
#include <iostream>


/** @brief factorial by iteration
  * @param [int] number of which is factorial
  * @return factorial
  */
int silnia(int);

/** @brief factorial recursively
  * @param [int] number of which is factorial
  * @return factorial
  */
int silnia_rec(int);

/** @brief print out 
  * @param [double *] array of numbers
  * @param [const int ] size of 
  */
void wypisz(double *tab,const int size);

/** @brief multiply value of array elements 
  * @param [double *] array of numbers
  * @param [factor ] factor
  * @param [ int ] size of array
  */
void powiel (double *tab,double factor,int size);

/** @brief sum up elements of array
  * @param [double *] array of numbers
  * @param [int ] size of array
  */
double suma (double *tab, int size);

/** @brief average of array numbers
  * @param [double *] array of numbers
  * @param [int ] size of array
  */
double srednia (double *tab,int size);