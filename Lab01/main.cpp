
#include <iostream> 
#include <cmath>

#include "funkcje.h"
using namespace std;

int main ()
{
  int i, abs_i;
  cout << "Podaj liczbę całkowitą: ";
  cin >> i;
  cout << "Podano liczbę " << i;
  abs_i = abs(i);
  cout << " a jej wartość bezwzględna wynosi " << abs_i << endl;


  int k = (i<0? i : -i);
  int abs_k = abs(k);
  cout <<  0 << "! = " << silnia(0) << endl;
  cout <<  k << "! = " << silnia(k) << endl;
  cout << abs_k << "! = " << silnia(abs_k) << endl;
  cout << "Silnia obliczona rekurencyjnie:\n";
  cout << 0 << "! = " << silnia_rec(0) << endl;
  cout << k << "! = " << silnia_rec(k) << endl;
  cout << abs_k << "! = " << silnia_rec(abs_k) << endl;

  double tab[] = { 3, -1, 4, 10, -9, 10, 3 };
  const int size = sizeof(tab)/sizeof(tab[0]);
  double factor = 2.;


  cout << "tab[] = ";
  wypisz (tab, size);
  powiel (tab, factor, size);
  cout << "Po przemnożeniu przez " << factor << endl;
  cout << "tab[] = ";
  wypisz (tab, size);
  cout << "Suma: " << suma (tab, size) << endl;
  cout << "Średnia: " << srednia (tab, size) << endl;

  return 0;
}
