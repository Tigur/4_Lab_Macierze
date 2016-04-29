#include <iostream>
#include "UkladRownanLiniowych.hh"
#include "Macierz.hh"

using namespace std;


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */


 istream &  operator >> (istream &wejscie, UkladRownanLiniowych &Uklad)
  {
    cout << "wprowadz transponowana macierz wspolczynnikow ukladu rownan: "<< endl;
    cin >> Uklad.M ;
    cout << "wprowadz transponowany wektor wyrazow wolnych: "<<endl;
    cin >> Uklad.b ;


    return wejscie;

  }
 ostream & operator << (ostream & wyjscie, UkladRownanLiniowych  &Uklad)
  {





    return wyjscie;
  }




