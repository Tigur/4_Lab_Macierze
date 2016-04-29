#include <iostream>

#include "Wektor.h"
#include "Macierz.hh"

#include "UkladRownanLiniowych.hh"



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
  float Wyz[ROZMIAR+1]; // tablica wyznacznikow
  int numer=0;
  
  cout << endl << " Start programu " << endl << endl;


  cin>> UklRown;
  Mp= UklRown.M;
  cout<< "licze wyznaczniki ..."<< endl;

  for( numer=0;numer<=ROZMIAR;numer++) // wszystko na macierzy pomocniczej, Czy dobrze ?
    {
	  cout << "poczatek petli:\n"<< endl;
	  Mp.WypiszMacierz();

     MacierzoweSzarady(Mp,Wyz[numer]);
     Mp=UklRown.M;
     cout << "wstawiam wektor wolny" << endl;
     WstawWolny(Mp,UklRown.b,numer);

    }
  

  LiczenieNiewiadomych(UklRown.X,Wyz);


  cout<< "x1 = "<< UklRown.X[0] << endl;
  cout<< "x2 = "<< UklRown.X[1]<< endl;
  cout<< "x3 = "<< UklRown.X[2]<< endl;
  cout << "Wypisuje wyznaczniki:"<< endl;
  for (int i=0;i<=ROZMIAR;i++)
  {
	  cout << Wyz[i]<< endl;
  }
  
  // Wypisywanie *********
}
