#include "myString.h"


namespace mystring{

String::String(const char* str){
  _str = new char[strlen(str) + 1];
  strcpy(_str, str);
}

String::~String(){
  delete [] _str;
  _str = nullptr;

}

String::String(const String& s1){
  _str = new char[strlen(s1._str) + 1];
  strcpy(_str, s1._str);
}

String::String(String&& s1){
  _str = new char[strlen(s1._str) + 1];
  strcpy(_str, s1._str);
  delete [] s1._str;
  s1._str = nullptr;
}

void String::print(const char* str) const{
  std::cout << str << _str << "\n";
}


const String operator+(const char *txt,const String &s1){
      char* txt1 = new char[strlen(txt) + strlen(s1.getstr()) + 1];
      strcpy(txt1,txt);
      strcat(txt1,s1.getstr());

      String help(txt1);
      delete [] txt1;
      return help;
}

const String operator+(const String &s1,const String &s2){
      char* txt1 = new char[strlen(s2.getstr()) + strlen(s1.getstr()) + 1];
      strcpy(txt1,s1.getstr());
      strcat(txt1,s2.getstr());

      String help(txt1);
      delete [] txt1;
      return help;
}


const String operator+(const String&s1, const char*txt){
      char* txt1 = new char[strlen(txt) + strlen(s1.getstr()) + 1];
      strcpy(txt1,txt);
      strcat(txt1,s1.getstr());

      String help(txt1);
      delete [] txt1;
      return help;
}

String operator*(const String &s1,int x){
  char* txt1 = new char[(strlen(s1.getstr()) * 2) + 1];
  strcpy(txt1,s1.getstr());
  strcat(txt1,s1.getstr());

  String help(txt1);
  delete [] txt1;
  return help;
}


}