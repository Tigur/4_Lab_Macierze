#ifndef WEKTOR_H
#define WEKTOR_H

#include "rozmiar.h"
#include <iostream>



/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */





  float Wsp[ROZMIAR];

 public:
  float operator[]  (int Ind) const { return Wsp[Ind]; }
  float & operator[]  (int Ind) { return Wsp[Ind]; }
  float operator & (const Wektor& V2) const;
  float  IloczynSkal( const Wektor& V2 ) const;
 // float  operator * ( const Wektor & V1, const Wektor & V2) {return V1.IloczynSkal(V2);}

  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */

std::istream & operator >> (std::istream & wejscie, Wektor & W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */

std::ostream & operator << (std::ostream & wyjscie, const Wektor & W);


inline float  operator * ( const Wektor & V1, const Wektor & V2) {return V1.IloczynSkal(V2);}
// -------------------------------------------------------------------------------------------------------------------------------------

Wektor  operator * ( const Wektor & V1, const float d);


Wektor operator + (const Wektor & V1, const Wektor & V2);


//float operator + (const Wektor & V1, const float d);


Wektor operator - (const Wektor & V1, const Wektor & V2);


//float operator - (const Wektor & V1, const float d);


Wektor operator / (const Wektor & V1, const float d);



#endif

