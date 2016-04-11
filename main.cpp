#include <iostream>
#include "Wektor.h"
#include "Macierz.hh"
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
  float w[ROZMIAR+1]; // tablica wyznacznikow
  int iter=0;
  
  cout << endl << " Start programu " << endl << endl;


  cin>> UklRown;
  cout<< "licze wyznacznik ogolny ..."<< endl;

  for( iter=0;iter<ROZMIAR;iter++)
  {
	  while((UklRown.M.i)!=(ROZMIAR-2))
	  {
		  UklRown.M.Zjedynkuj(UklRown.M);
		  UklRown.M.Wyzerujprawo(UklRown.M);
		  UklRown.M.Laplace(UklRown.M); //!!
		  UklRown.M.i++;

	  }
	  	  UklRown.M.i=0; // zeruje iterator La place'owania
		  UklRown.M.LiczWyzn(UklRown.M,w[iter]);
		  UklRown.M[iter]=UklRown.b; // czy to jest dobrze ?           !!!!!!!
  }
  UklRown.X[0]=w[1]/w[0];
  UklRown.X[1]=w[2]/w[0];
  UklRown.X[2]=w[3]/w[0];


  // WYpisywanie *********
}
