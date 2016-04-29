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

Macierz & Macierz :: Wyzerujprawo ( int i)
    {

		  for(int j=ROZMIAR;j>i;j--)
		{
		  (*this)[j]=(*this)[j]-((*this)[i]*(*this)(i,j));

		}
		  cout<< "Wyzerowane"<< endl;
		  cout<< "po Wyzerowaniu: \n"<< endl;
		  (*this).WypiszMacierz();

      return (*this);
    }

bool Macierz :: ZamienKolumny( int i)
{
  Macierz Mp=(*this);
  for(int j=ROZMIAR;j>i;j--)
    {


		  if ((*this)(0,j)!=0)
		{

		  (*this)[i]=(*this)[j];
		  (*this)[j]=Mp[i];

		  return true;
		}


    }
  cout << "Macierz nie ma rozwiazan !  " << endl;
  abort();
  return false;
}

 void WstawWolny(Macierz & M, Wektor wolny, int pozycja)
{
  M[pozycja]=wolny;

  
}
void LiczenieNiewiadomych(Wektor & X,float TabNiewiadomych[])
{
  X[0]=TabNiewiadomych[1]/TabNiewiadomych[0];
  X[1]=TabNiewiadomych[2]/TabNiewiadomych[0];
  X[2]=TabNiewiadomych[3]/TabNiewiadomych[0];
}


void Macierz:: WypiszMacierz()
{

	int i=0,j=0;


	for ( i=0;i<ROZMIAR;i++)
	{
		for ( j=0;j<ROZMIAR;j++)
			{cout << (*this)(i,j)<< "  ";}


		cout << "Linia "<< i<< endl;
	}
	cout<< "\n"<< endl;
}

float MacierzoweSzarady(Macierz M,float & wyz)
{
  int wiersz=0,kolumna=0;
  // Macierz Mpomoc;
  
  while(wiersz<ROZMIAR)
    {
	  M.Zjedynkuj(wiersz);
	 // cout << " po jedynkowaniu : \n"<< endl;

	  M.Wyzerujprawo(wiersz);
	  //cout << "po zerowaniu : \n"<< endl;



     wiersz++;
    }

  cout << LiczWyzn(M,wyz)<< "   - Wyznacznik... macierz : "<< endl;
  M.WypiszMacierz();

    return wyz;
}





/*
int main ()
{

}
*/
