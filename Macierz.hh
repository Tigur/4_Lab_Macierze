#ifndef MACIERZ_HH
#define MACIERZ_HH

#include<cassert>
#include<cstdlib>
#include "Wektor.h"
#include "rozmiar.h"
//#include"UkladRownanLiniowych.hh"
#include <iostream>
using namespace std;


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */

public:
	Wektor Kolumna[ROZMIAR];
    const Wektor & operator[] (int Kol) const { return Kolumna[Kol]; }
    Wektor & operator[] (int Kol) { return Kolumna[Kol]; }
    const float operator() (int Wi, int Ko) const {return Kolumna[Ko][Wi];}
    float& operator() (int Wi, int Ko) {return Kolumna[Ko][Wi];}
    Macierz & operator / (float d)
		{
			for (int i=0;i<ROZMIAR;i++)
			{
				(*this)[i]=(*this)[i]/d;
			}

    		return (*this);
		}

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

  //    int i=0; // index w rozwinięciu La place'a
  




  bool  ZamienKolumny ( int j);
  
  
 
  //  Wektor & AlgorytmLiczenia ();

  
  Macierz & Zjedynkuj ( int i)
    {
		 if ( (*this)(i,i)!=0)  // unikamy dzielenia przez zero. rozpatrujemy przypadek
		 {
			  (*this)= (*this)/(*this)(i,i); // jedynkuje - czyli dziele przez identyczna wartosc cala kolmne.
				return (*this);
		 }
		else
		 {

			if (ZamienKolumny (i))
			{
				cout << "Zamiana kolumn udana :)" << endl;
				cout << " po zamianie " << endl;
				(*this).WypiszMacierz();
				cout << "\n\n";

				(*this)[i]= (*this)[i]/(*this)(i,i);
				if(i<ROZMIAR-1)
				{
					(*this)[i+1]= (*this)[i+1]*(*this)(i,i);
				}
				else
				{
					(*this)[i-1]= (*this)[i-1]*(*this)(i,i);
				}


			}
			else
			{
			cerr<< "WYZNACZIK GŁOWNY = 0"<< endl;
			abort();
			}
			return (*this);
		 }
      assert(0);
    }

  Macierz &  Wyzerujprawo ( int i);
  void WypiszMacierz();

};

     
void WstawWolny(Macierz & M, Wektor wolny, int pozycja);


     inline float & LiczWyzn(Macierz M, float & w)                                            ////LICZ!!!!!!
    {
    	 w=1; // liczba neutralna względem mnozenia

		  for (int i=ROZMIAR-1;i>=0;i--)
		{
		  w=w*M(i,i);
		}
	return w;

    }

float MacierzoweSzarady(Macierz M, float& wyz);

void LiczenieNiewiadomych(Wektor & X,float TabNiewiadomych[]);


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 * 
 * Przeciazenie operatora wejscia - przyjmuje obiekty typu Macierz
 *
 *
 *
 */
std::istream& operator >> (std::istream &wejscie, Macierz &Mac);

/*
 *
 *  Przeciazenie operatora wyjscia - przyjmuje obiekty typu Macierz
 *
 *
 *
 *
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */



std::ostream& operator << (std::ostream &wyjscie, const Macierz &Mac);


#endif
