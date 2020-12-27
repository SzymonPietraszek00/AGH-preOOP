
#include <iostream>
#include "Vector.h"

// Odkomentowanie poniższej linii MUSI powodować błąd kompilacji (w przeciwnym razie -1 pkt)
//#define ERROR

int main() {
	Vector v1(3);		
	const Vector v2(4);	

	v1.at(0) = 4;
	v1.at(1) = 1;
	const Vector v3 = v1;
	v1.at(1) = 2;

	v1.print("v1 = ");
	v2.print("v2 = ");
	v3.print("v3 = ");

	double prod = Vector::dot(v1, v3); 
	std::cout << "Iloczyn skalarny v1 i V2: " << prod << std::endl;
  
	double norm = static_cast<double>(v3); // == v3.norm();
	std::cout << "Norma wektora |v3| = " << norm << ", " << v3.norm() << std::endl;
	
	Vector v4 = Vector::sum(v1, v3); 
	v4.print("v1 + v3 = ");

	Vector v5 = std::move(Vector::sum(v1, v3));
  v5.print("v1 + v3 = ");

	Vector::sum(v1, 3).print("v1 + 3 = ");
	
	#ifdef ERROR // wywołanie make error albo odkomentowanie linii
	Vector s= 5;
	s.print();
	std::cout << "Iloczyn skalarny V1 i V6: " << Vector::dot(v1, s) << std::endl;s.print();
	#endif


}
