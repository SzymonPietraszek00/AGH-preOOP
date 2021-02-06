#include "myString.h"
#include <iostream>

using namespace mystring;

int main() {

 
	String s0("Swieta tuz tuz.");  
	String s1("Swieta tuz tuz");
	const String s2(s0);  

	s0.print("S0: "); s1.print("S1: "); s2.print("S2: "); 
	std::cout << "\n*** Porownywanie napisow ***" << std::endl;
 	std::cout << "Napisy s0 i s2 " << (s0 == s2 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	std::cout << "Napisy s2 i s1 " << (s2 == s1 ? "sa identyczne" :"nie sa identyczne") << std::endl;
  std::cout << "Napisy \"Swieta tuz tuz.\" i s2 " << ("Swieta tuz tuz." == s2 ? "sa identyczne" :"nie sa identyczne") << std::endl;
	
	std::cout << "\n*** Dodawanie i przypisywanie napisow ***" <<  std::endl;
	std::cout << "S2: " << static_cast<char*>(s2) << std::endl; //= s2.print("S2: :");
	s1 = "Duzo zdrowia i szczescia!!!";
	std::cout << "S1: " << s1 << std::endl;
  
	String s3 = "Wiecie? " + s2;
	s3.print("S3: ");
	String s4 = s2 + ".. " + s1 + "\n\t" + s3; 
	s4.print("S4: ");

	std::cout << "\n*** Powielanie napisow ***" << std::endl;
	String s5 = String(":-)") *2;
  s5.print("S5: ");
	String s6 = ":-D " + s5*4;
	s6.print("S6: " );
	String const s7 = std::move(s1);
  std::cout << "S7: "<< s7 << std::endl; 
  s1.print("S1: ");
  
}

/* Oczekiwany wynik ./main
S0: Swieta tuz tuz.
S1: Swieta tuz tuz
S2: Swieta tuz tuz.

*** Porownywanie napisow ***
Napisy s0 i s2 sa identyczne
Napisy s2 i s1 nie sa identyczne
Napisy "Swieta tuz tuz." i s2 sa identyczne

*** Dodawanie i przypisywanie napisow ***
S2: Swieta tuz tuz.
S1: Duzo zdrowia i szczescia!!!
S3: Wiecie? Swieta tuz tuz.
S4: Swieta tuz tuz... Duzo zdrowia i szczescia!!!
    Wiecie? Swieta tuz tuz.

*** Powielanie napisow ***
S5: :-):-)
S6: :-D :-):-):-):-)
S7: Duzo zdrowia i szczescia!!!
S1:
*/
