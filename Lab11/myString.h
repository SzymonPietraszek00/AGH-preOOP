#pragma once
#include <iostream>
#include <cstring>

/**
 *przestrzen nazw mystring
*/
namespace mystring{

  /**
   *klasa reprezentujaca napis
  */
  class String{

  public:

  //konstruktor
    String(const char*);
  
  //destruktor
    ~String();
  
  //konstruktor kopiujacy
    String(const String&);
    
  //konstruktor przenoszacy
    String(String&&);

  /**
   *funkcja drukujaca
   * @param [const char*] napis poprzedzajacy drukujacego stringa
  */
    void print(const char*) const;

   /**
    *operator zamieniajacy klase na char* (zwracajacy jej napis)
   */
    operator char*() const{
      return _str;
    }

    /**
     * funkcja zwracajaca zmienna prywatna
    */
    char* getstr() const{
      return _str;
    }

    /**
     * operator ktory przypisuje napis do zmiennej prywatnej klasy
     * @param - str - napis przypisywany
    */
    String operator=(const char* str){

      delete [] _str;
      _str = new char[strlen(str) + 1];
      strcpy(_str, str);

      return _str;
    }

    /**
     * operator ktory przypisuje klase do klasy
     * @param - str - klasa ktorej napis jest przepisywany
    */
    String operator=(String &str){

      delete [] _str;

      _str = new char[strlen(str._str) + 1];
      strcpy(_str, str._str);

      return _str;
    }

  private:

    //zmienna przechowujacy napis
    char *_str;
  };

  /**
   * operator ktory porownuje napisy zawarte w klasie
   * @param - s1 - klasa pierwsza
   * @param - s2 - klasa druga
  */
  inline bool operator==(String s1, String s2){

    int x = strcmp(s1.getstr(),s2.getstr());

    if(x == 0){
      return true;
    }else{
      return false;
    }

   
  }

  /**
   * operator ktory porownuje napis i napis zawartt w klasie
   * @param - txt - napis
   * @param - s1 - klasa w ktorej zawarty jest napis
  */
  inline bool operator==(const char* txt,String s1){

    int x = strcmp(s1.getstr(),txt);

    if(x == 0){
      return true;
    }else{
      return false;
    }
  }


  
  const String operator+(const char *txt,const String &s1);
  const String operator+(const String &s1,const String &s2);
  String operator*(const String &s1,int x);
 

}