#include <iostream>
#include "Vector2D.h"

Vector2D fun(Vector2D v) {
  return v;
}

int main() {
	{
		Vector2D v0("V0"); //nie ma potrzeby określania
    Vector2D v1 = Vector2D::fromCarthesian("V1", 2., 3.);		// (x, y)
		const Vector2D v2 = Vector2D::fromPolar("V2", 4., 30.);	// (promień, kąt w stopniach)

    v0.print("v0: ");
		v1.print("v1: ");
		v2.print("v2: ");
		std::cout << "\n*** ETAP 1 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

		double prod = v1.dot(v2);
		std::cout << "Iloczyn skalarny v1 i v2: " << prod << std::endl;
		
		const Vector2D v3 = v1.add(v2); 
		v3.print("v3: ");
		std::cout << "Iloczyn skalarny v3,v1: " << v3.dot(v1) << ", v3,v2: " << v3.dot(v2) << std::endl;

		Vector2D v4 = v2;
		v4.print("v4: ");
		std::cout << "\n*** ETAP 2 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

		Vector2D v5 (std::move(v3.add(v1)));
    Vector2D v6 = fun(Vector2D::fromCarthesian(2.5,3.5));
    Vector2D v7 = std::move(Vector2D("V7"));
		v5.print("v5: ");
    v6.print("v6: ");
    v7.print("v7: ");

    Vector2D v8 = std::move(v6);
    v8.print("v8: ");
    v6.print("v6: ");

    std::cout << "Liczba wektorow 2D: " << Vector2D::count << std::endl;
	}
	std::cout << "\n*** ETAP 3 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;
}
