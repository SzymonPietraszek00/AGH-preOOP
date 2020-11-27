/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 Struktura MapPoint (pliki MapPoint.h, MapPoint.cpp) reprezentuje punkt na mapie składający się z nazwy, długości (longitude) i szerokości (latitude) geograficznej oraz oznaczeń półkul.
 
 Funkcje construct i clear to funkcje tworzące i usuwające punkt.
  Funkcja construct posiada dwie wersje. Pierwsza przyjmuje współrzędne w postaci dodatniej (unsigned) oraz strony świata w postaci char ('E', 'W' dla długości i 'N', 'S' dla szerokości). Druga przyjmuje również ujemne wartości wspórzędnych i na ich podstawie wnioskujemy strony świata. Odpowiednio zgodnie z układem współrzędnych dla długości ujemnych mamy W, a dla szerokości ujemnych mamy S.
  Wskazówka: Aby w późniejszych funkcjach uniknąć konieczności sprawdzania stron świata, można w strukturze przechowywać wartości ze znakiem.
 
 Funkcja movePoint zmienia współrzedne punktu, przesuwając go o wartości podane w argumentach funkcji. Proszę pamiętać o ew. zmianach stron świata.
 
 Funkcja inTheMiddle powinna tworzyć nowy punkt na mapie o zadanej nazwie i położeniu, które jest średnią arytmetyczną z położeń podanych punktów czyli x = (x1 + x2)/2 itp. Proszę uważać w przypadku różnych półkul.

 Struktura MapDist (pliki MapDist.h, MapDist.cpp)reprezentuje odległość pomiędzy dwoma punktami. Odległość wzdłuż południków lub równoleżników należy obliczyć po prostu odejmując od siebie współrzędne punktów końcowego i początkowego (funkcja distance).

 Funkcja angularDistance oblicza pierwiastek z sumy kwadratów odległości względem południków i równoleżników, czyli sqrt(delta_x*delta_x + delta_y*delta_y).
 Funkcja obliczająca pierwiastek nazywa się: sqrt(double) i znajduje się w bibliotece "cmath".
 
 Funkcja closestPlace pobiera 3 argumenty. Pierwszy argument jest punktem referencyjnym. Z dwóch kolejnych wybiera ten, który jest najbliżej punktu referencyjnego. Funkcja wykorzystuje angularDistance.

 Proszę zadbać o dobre zarządzanie pamięcią.
 Uruchom make check (valgrind ./main), aby sprawdzić, czy nie ma żadnych błędów ani wycieków pamięci.
 Pliku main.cpp, nie wolno modyfikować.
 UWAGA! Wysyłamy spakowany katalog Grupa_nazwisko_lab5, nie oddzielne pliki. 
 Wcześniej kasujemy niepotrzebne pliki, w przypadku cmake wysyłamy tylko plik CMakeLists.txt.
*/


#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"

int main() {
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint* krakow     = construct("Krakow", longitude, latitude); //kierunki E i N
  print(krakow);
  MapPoint* nyc     = construct("Nowy Jork", 74.0059, 'W', 40.7127, 'N' );
  print(nyc);
  MapPoint *sydney = construct ("Sydney", 151.102, -33.454); // kierunki E i S  - jak ujemna to S
  print(sydney);
  MapPoint* porto   = construct("Porto", 41.162142, 8.621953); // kierunki E i N
  const MapPoint& portugalCity = *porto;
  print(&portugalCity);

  const double longitudeShift = 4.1234;
  const double latitudeShift = -25.987;
  std::cout << "*** Po przesunieciu ***\n";
  movePoint (porto, longitudeShift, latitudeShift);
  print (&portugalCity);
  std::cout << "*** Po przesunieciu ***\n";
  movePoint (porto, -90.5710, 34.7300);
  print (&portugalCity);

  const MapDist d = distance(*nyc, *sydney);
  std::cout <<"Odleglosci między NYC i Sydney: \nRoznica dlugosci: " << d.longitude << "\nRoznica szerokosci: "<< d.latitude << "\nOdleglosc: "<<angularDistance(d) << std::endl;

  const MapPoint& cl = closestPlace(krakow, nyc, sydney);
  std::cout << "Bliżej Krakowa jest " << getName(cl) << std::endl;

  MapPoint mp = inTheMiddle(nyc, sydney, "Kenia");
  print(&mp);

  std::cout << "*** Czyszczenie ***\n";
  clear(krakow, nyc, porto);
  clear(sydney);
  std::cout << "*** Koniec ***\n";
}
/** Wynik działania programu:
./main
Wspolrzedne dla Krakow: 19.9383E, 50.0614N
Wspolrzedne dla Nowy Jork: 74.0059W, 40.7127N
Wspolrzedne dla Sydney: 151.102E, 33.454S
Wspolrzedne dla Porto: 41.1621E, 8.62195N
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855E, 17.365S
*** Po przesunieciu ***
Wspolrzedne dla Porto: 45.2855W, 17.365N
Odleglosci między NYC i Sydney: 
Roznica dlugosci: 225.108
Roznica szerokosci: 74.1667
Odleglosc: 237.011
Blizej Krakowa jest Nowy Jork
Wspolrzedne dla Kenia: 38.5481W, 3.62935N
*** Czyszczenie ***
Usuwanie Krakow
Usuwanie Nowy Jork
Usuwanie Porto
Usuwanie Sydney
*** Koniec ***
*/