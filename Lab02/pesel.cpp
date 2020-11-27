#include "pesel.h"
#include <string.h>

/**
  * @brief check if it is leap year
  * @param year
  * @return true or false
  */
bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
      }

/**
  * @brief check if pesel is correct
  * @param [char*] pesel which should be converted to int
  * @param [int*] array fullfilled with pesel
  * @return true or false
  */
bool PeselValidator(char* Tpesel,int * PESEL){

    if((strlen((const char*)Tpesel)) == 11){
        for(int i = 0;i < 11;i++){
            PESEL[i] =*(Tpesel+i)-48;
        }

        if(getCtrlNumber(PESEL) != PESEL[10])
             return 0;
        if(!leapYear(getYear(PESEL)) && getMonth(PESEL) == 2 && getDay(PESEL) >= 29)
            return 0;
        return 1;

    }else return 0;

}

/**
  * @param [int*] array with pesel
  * @return day from pesel
  */
int getDay(int *PESEL){
    return (10*PESEL[4] + PESEL[5]);
}

/**
  * @param [int*] array with pesel
  * @return month from pesel
  */
int getMonth(int *PESEL){
    int m = (10*PESEL[2] + PESEL[3]);
    m = m%20;
    return m;
}

/**
  * @param [int*] array with pesel
  * @return year from pesel
  */
int getYear(int *PESEL){

    int m = (10*PESEL[2] + PESEL[3]);
    int y = (10*PESEL[0] + PESEL[1]);

    if(m<=12 && m>=1)
        y = y+1900;

    if(m>=21 && m<=32)
        y = y+2000;

    if(m>=41 && m<=52)
        y = y+2100;


    return y;

}

/**
  * @brief print pesel
  * @param [int*] array with pesel
  */
void printPesel(int *PESEL){

    for(int i = 0;i < 11;i++){
        std::cout << PESEL[i];
    }
std::cout << std::endl;
}

/**
  * @brief decide if it is man or woman
  * @param [int*] array with pesel
  * @return Man or Woman
  */
const char *sex(int *PESEL){

    if(PESEL[9] % 2 == 0){
       return "Kobieta";
    }else return "Mezczyzna";


}

/**
  * @brief count control number 
  * @param [int*] array with pesel
  * @return control number
  */
int getCtrlNumber(int *PESEL){
   
    int tab[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int nr = 0;

    for(int i = 0;i < 10;i++){
     nr = tab[i] * PESEL[i] + nr;
    }

     nr = nr % 10;

     nr = 10 - nr;

     nr = nr % 10;

     return nr;

}