#include <iostream>
#include "pesel.h"

int main() {
char* Tpesel[] ={(char*)"80022901235", 
                 (char*)"81022901232",
                 (char*)"01251213366",
                 (char*)"11323113335",
                 (char*)"04422956295",
                 (char*)"044229562",
                 (char*)"044229562957"};

int PESEL[11]; // tablica, w której bêdziemy trzymaæ skonwertowany PESEL
bool valid;
// tablica do konwersji liczby miesi¹ca na nazwê
char *monthName[] = {0,(char*)" stycznia ",(char*)" lutego ", (char*)" marca ",
    (char*)" kwietnia ",(char*)" maja ",(char*)" czerwca ",
    (char*)" lipca ",(char*)" sierpnia ",(char*)" wrzesnia ",
    (char*)" pazdziernika ",(char*)" listopada ",(char*)" grudnia "};

for (int i=0; i < 7; ++i){
  valid = PeselValidator(Tpesel[i], PESEL); //wykonuje konwersjê i zwraca poprawnoœæ numeru
 if (valid) {
    std::cout << "PESEL: ";
   printPesel(PESEL);
   std::cout << " Suma kontrolna: " << getCtrlNumber(PESEL) << std::endl;
    std::cout << "Numer PESEL jest prawidlowy\n";
    std::cout << "Plec: " << sex(PESEL) << std::endl;
    std::cout << "Data urodzenia: " << getDay(PESEL)
                                   << monthName[getMonth(PESEL)]
                                << getYear(PESEL) << std::endl;

  }
  else {
    std::cout << "PESEL: "<< Tpesel[i];
    std::cout << " jest nieprawidlowy\n";
}
  std::cout << "-----------------------------------------\n";
}
  return 0;
}

/*  Oczekiwany wynik:

PESEL: 80022901235 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Plec: Mezczyzna
Data urodzenia: 29 lutego 1980
-----------------------------------------
PESEL: 81022901232 jest nieprawidlowy
-----------------------------------------
PESEL: 01251213366 Suma kontrolna: 6
Numer PESEL jest prawidlowy
Plec: Kobieta
Data urodzenia: 12 maja 2001
-----------------------------------------
PESEL: 11323113335 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Plec: Mezczyzna
Data urodzenia: 31 grudnia 2011
-----------------------------------------
PESEL: 04422956295 Suma kontrolna: 5
Numer PESEL jest prawidlowy
Plec: Mezczyzna
Data urodzenia: 29 lutego 2104
-----------------------------------------
PESEL: 044229562 jest nieprawidlowy
-----------------------------------------
PESEL: 044229562957 jest nieprawidlowy
-----------------------------------------
*/

