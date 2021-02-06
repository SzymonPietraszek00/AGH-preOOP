#include "functions.h"
#include "functionVector.h"
#include <iostream>




double my_abs(double x){
	return x>=0 ? x : -x;
}

int main ()
{  
  std::cout <<std::endl;
    Linear lin(-0.25, -1.);
   std::cout << "f(x) = " << lin << std::endl;
   const Sqrt squareroot;
    Sin sinus(M_PI, M_PI/3.);

  double x = 10;
  std::cout << "\n*** Wyniki pojedynczych funkcji dla x=10 *** \n" << std::endl;
  std::cout << "Sinus:\t\t" << sinus(x) << std::endl; 
  std::cout << "Pierwiastek:\t" << squareroot(x) << std::endl; 
  std::cout << "Funkcja liniowa: " << lin(x) << std::endl; 

  
  FunctionVector fs;
  fs.insert(sinus);
  fs.insert(squareroot);
  fs.insert(lin);
  fs.insert(my_abs);
  
   //test operatora () do zagnieżdżania funkcji
   double result1 = fs.calc(x);
   double result2 = my_abs(lin(squareroot(sinus(x))));
   std::cout << "\n*** Obliczamy abs(-0.25*sqrt(sin(pi*x+pi/3))+1) *** \n" << std::endl;
   std::cout << "--- Dla x=10 :\t" << result1 << ", " << result2 << std::endl; 

   x = 0.5;
   std::cout << "--- Dla x=0.5 :\t" << fs.calc(x) << ", " << my_abs(lin(squareroot(sinus(x)))) << std::endl;

   // test operatora [] zwracającego wyniki pośrednich obliczeń 
   std::cout << "\n*** Wyniki posrednie dla x=0.5: *** \n" << std::endl;
   double sinx = sinus(x);
  std::cout << "--- f1 = sin(pi*x+pi/3): " << sinx << ", " << fs[0] << std::endl; 
  std::cout << "--- f2 = sqr(f1):\t" << squareroot(sinx) << ", " << fs[1] << std::endl; 
  std::cout << "--- f3 = -0.25*f3+1:\t" << lin(squareroot(sinx)) << ", " << fs[2] << std::endl; 
  std::cout << "--- f4 = abs(f3):\t" << my_abs(lin(squareroot(sinx))) << ", " << fs[3] << std::endl; 
}

/* Oczekiwany wynik: ./main

f(x) = -0.25*x^2+-1*x

*** Wyniki pojedynczych funkcji dla x=10 ***

Sinus:          0.866025
Pierwiastek:    3.16228
Funkcja liniowa: -3.5

*** Obliczamy abs(-0.25*sqrt(sin(pi*x+pi/3))+1) ***

--- Dla x=10 :  1.23265, 1.23265
--- Dla x=0.5 : 1.17678, 1.17678

*** Wyniki posrednie dla x=0.5: ***

--- f1 = sin(pi*x+pi/3): 0.5, 0.5
--- f2 = sqr(f1):       0.707107, 0.707107
--- f3 = -0.25*f3+1:    -1.17678, -1.17678
--- f4 = abs(f3):       1.17678, 1.17678
*/
