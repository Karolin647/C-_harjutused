#include "p5h2.h"
#include <iostream>
using namespace std;

int liida(int massiiv[], int n){
    int summ{0};
    for(int i{0}; i<n; i+= 2){
        summ += massiiv[i];
    }
    return summ;
}

int liidaP1(int* p_massiiv, int n){
    int summ{0};
    for(int i{0}; i<n; i+=2){
        summ += p_massiiv[i];
    }
    return summ;
} // kasuta indekseid

int liidaP2(int* p_massiiv, int n){
    int summ{0};
    for(int i{0}; i<n; i+=2){
        summ += *(p_massiiv + i);
    }
    return summ;
} // kasuta viitade aritmeetikat

int* liida(int* p_massiiv, int  n, int* summ){
    for(int i{0}; i<n; i+=2){
        *summ += *(p_massiiv + i);
    }
    return summ;
} // kasuta viitade aritmeetikat, kolmas parameeter on summa jaoks

int& liida(int* p_massiiv, int n, int& summ){
    for(int i{0}; i<n; i+=2){
        summ += *(p_massiiv + i);
    }
    return summ;
} // kasuta viitade aritmeetikat, kolmas parameeter on summa jaoks

int main(){
    int massiiv[]{0, 1, 2, 3, 4, 6};
    int summa1{0};
    int summa2{0};
    int* p_s1{&summa1};
    int& p_s2{summa2};
    cout << "liida = " << liida(massiiv, 6) << '\n';
    cout << "liida = " << liidaP1(massiiv, 6) << '\n';
    cout << "liida = " << liidaP2(massiiv, 6) << '\n';
    cout << "liida = " << *(liida(massiiv, 6, p_s1)) << '\n';
    cout << "liida = " << liida(massiiv, 6, p_s2) << '\n';
    return 0;
}