#include <iostream>
/*
#include "Wektor.h"
#include "Macierz.hh"
*/
#include "UkladRownanLiniowychh.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  UkladRownanLiniowych   UklRown; // To tylko przykladowe definicje zmiennej
  Macierz Mp; // macierz pomocnicza
  float w[ROZMIAR+1]; // tablica wyznacznikow
  int iter=0;
  
  cout << endl << " Start programu " << endl << endl;


  cin>> UklRown;
  Mp= UklRown.M;
  cout<< "licze wyznaczniki ..."<< endl;

  for( iter=0;iter<ROZMIAR+1;iter++)
  {
	  while((UklRown.M.i)!=(ROZMIAR-2))
	  {
		  UklRown.M.Zjedynkuj(UklRown.M);

		  cout << "zjedynkowano"<< endl;

		  UklRown.M.Wyzerujprawo(UklRown.M);

		  cout<< "wyzerowano prawo"<< endl;

		  UklRown.M.Laplace(UklRown.M); //!!

		  cout<< "byl laplace" << endl;
		  cout<< "M.i = "<< UklRown.M.i<< endl;
		 // UklRown.M.i++; // iterator skosny laplasowy

	  }

		  UklRown.M.LiczWyzn(UklRown.M,w[iter]);
		  UklRown.M.i=0; // zeruje iterator La place'owania
		  cout << "jeden z wyznaczników policzony !\n"<< endl;
		  Mp.i=UklRown.M.i; // ?
		  UklRown.M=Mp; // resetuje macierz
		  UklRown.M[iter]=UklRown.b; // podmieniam kolumny
  }
  UklRown.X[0]=w[1]/w[0];
  UklRown.X[1]=w[2]/w[0];
  UklRown.X[2]=w[3]/w[0];



  cout<< "x1 = "<< UklRown.X[0] << endl;
  cout<< "x2 = "<< UklRown.X[1]<< endl;
  cout<< "x3 = "<< UklRown.X[2]<< endl;

  cout<<"\n\n "<< UklRown.M.i<< "\n";
  // WYpisywanie *********
}
