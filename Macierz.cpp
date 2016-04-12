#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::istream& operator >> (std::istream &wejscie, Macierz &Mac)
{
    Wektor W[ROZMIAR];
    for(int Ind=0;Ind<ROZMIAR;Ind++)
    {
        wejscie >> W[Ind];
        Mac[Ind]=W[Ind];
    }
    return wejscie;

}
std::ostream& operator << (std::ostream &wyjscie, const Macierz &Mac)
{
    wyjscie << Mac[0]<< "  "
    << Mac[1]<< "  "
     << Mac[2];

     return wyjscie;

}
/*
int main ()
{

}
*/
