#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
struct UkladRownan // wszysto co wizualnie wyœwietla sie na ekranie
{
    Macierz M;
    Wektor b;
    //Wektor X;
  istream &  operator >> (istream wejscie, UkladRownan Uklad)
  {
      cout << "wprowadz transponowana macierz wspolczynnikow ukladu rownan: "<< endl;
      cin >> M >> endl;
      cout << "wprowadz transponowany wektor wyrazow wolnych: "<<endl;
      cin >> b >> endl;


      return wejscie;
  }
  ostream & operator << (ostream wejscie, UkladRownan Uklad)
  {


      return wyjscie;
  }

};
