#include "Wektor.h"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

float Wektor::IloczynSkal( const Wektor& V1, const Wektor& V2 )
{

    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]*V2[Ind];
    return Wynik;
}
istream operator >> (istream wejscie, Wektor W)
{
    float r0,r1,r2;
    cout << "Wprowadz 3 wspolzedne wektora w kolejnosci: r0, r1, r2"<< endl;
    wejscie>> r0>> r1 >> r2;
    W[0]=r0; W[1]=r1; W[2]=r2;

    return wejscie;
}

ostream operator << (ostream wyjscie, const Wektor W)
{
    cout << W[0] << "  "<<
    << W[1] << "  " <<
    <<W[2] endl;

    return wyjscie;

}

Wektor operator * ( const Wektor & V1, const float d)

{
    float Wynik = 0;
    for (int Ind=0;Ind<ROZMIAR;++Ind) // sprawdziæ czy nie crushuje
    Wynik+=V1[Ind]*d;

    return Wynik;
}
    float operator + (const Wektor & V1, const Wektor & V2)
{
    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]+V2[Ind];
    return Wynik;
}

    float operator + (const Wektor & V1, const float d)
{
    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]+d;
    return Wynik;
}
    float operator - (const Wektor & V1, const Wektor & V2)
{
    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]-V2[Ind];
    return Wynik;
}

 float operator - (const Wektor & V1, const float d)
{
    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]-d;
    return Wynik;
}
 float operator / (const Wektor & V1, const float d)
{
    float Wynik = 0;
    for (int Ind = 0; Ind < ROZMIAR; ++Ind) Wynik += V1[Ind]/d;
    return Wynik;
}
