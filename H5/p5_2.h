#ifndef P5H2_H
#define P5H2_H
using namespace std;


int liida(int massiiv[], int n);
int liidaP1(int* p_massiiv, int n); // kasuta indekseid
int liidaP2(int* p_massiiv, int n); // kasuta viitade aritmeetikat
int* liida(int* p_massiiv, int  n, int* summ); // kasuta viitade aritmeetikat, kolmas parameeter on summa jaoks
int& liida(int* p_massiiv, int n, int& summ); // kasuta viitade aritmeetikat, kolmas parameeter on summa jaoks

/*Näiteks, koodijupi
int massiiv[]{0, 1, 2, 3, 4, 6};
cout << "liida = " << liida(massiiv, 6) << '\n';

tulemusena kuvatakse ekraanile 6.

Katseta kõiki funktsioone main funktsioonis. */

#endif