#ifndef MACIERZ_HH
#define MACIERZ_HH

#include<cstdlib>
#include "Wektor.h"
#include "rozmiar.h"
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


  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

    int i=0; // index w rozwinięciu La place'a

    Macierz & Zjedynkuj (Macierz & M)
    {
    	if ( M(i,i)!=0)
    	{
			M[i]= M[i]/M(i,i);

			return M;
    	}
    	else
    	{
    		M[i]=M[i]+M[i+1]+M[i+2];
    		if(M(i,i)==0)
    		{
    			cerr << "uklad sprzeczny lub ma nieskonczenie wiele rozwiazan"<< endl;
    			abort();

    			return M;
    		}
    		else
    		{
    			M[i]= M[i]/M(i,i);

    		}
    	}
    }

    Macierz &  Wyzerujprawo (Macierz & M)
    {
    	M[i+1]=M[i+1]-(M[i]*M(i,i+1));
    	M[i+2]=M[i+2]-(M[i]*M(i,i+2));

    	return M;
    }
    Macierz & Laplace(Macierz & M)
    {
    	M.i++;  // zwiększm iterację i zmniejszam kwadrat macierzy

    	return M;
    }
    float & LiczWyzn(Macierz M, float & w)
    {
    	int a=1; // pozycjoner wsteczny dopelnien

    	w=(M(i,i)*M(i+1,i+1))-(M(i,i+1)*M(i+1,i));

    	while ((i-a)>=0) // mnozenie przez dopełnienie.
    	{
    	w=M(i-a,i-a)*w;
    	a++;
    	}
    	return w;
    }
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &wejscie, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */



std::ostream& operator << (std::ostream &wyjscie, const Macierz &Mac);


#endif
