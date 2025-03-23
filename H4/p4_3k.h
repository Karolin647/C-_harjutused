#ifndef P4_3K_H
#define P4_3K_H
#include <concepts>
#include <type_traits>
#include <string>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
requires  (is_same_v<T1, int> || is_same_v<T1, double> || is_same_v<T1, float>) &&
          (is_same_v<T2, int> || is_same_v<T2, double> || is_same_v<T2, float>)
double liida(T1 a, T2 b){
    return (a+b)*1.0;
}

template <typename T1, typename T2>
requires  (is_same_v<T1, string> || is_same_v<T1, char>) &&
          (is_same_v<T2, string> || is_same_v<T2, char>)
string liida(T1 a, T2 b){
    return a+b;
}

template <typename T3, typename T4>
requires (is_same_v<T3, int> || is_same_v<T3, double> || is_same_v<T3, float>) &&
         (is_same_v<T4, string> || is_same_v<T4, char>)
string liida(T3 a, T4 b){
    return to_string(a)+b;
}

template <typename T3, typename T4>
requires (is_same_v<T3, string> || is_same_v<T3, char>) &&
         (is_same_v<T4, int> || is_same_v<T4, double> || is_same_v<T4, float>)
string liida(T3 a, T4 b){
    return a + to_string(b);
}

template <size_t a>
bool OnVahemikus(int b, int c){
    return (b<=a && a<=c);
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
class Massiiv{
public:
    T massiiv[100];
    T getElement(int i);
    bool kasTais();
    int getSuurus();
    void print();
    void lisaElement(T el);
    void kustutaElement();
    void asendaElement(T el1, T el2);
    int vabuKohti();
    bool kasSisaldub(T el);
private:
    int n{0};
};

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
T Massiiv<T>::getElement(int i){
    if(n>i){
        return massiiv[i];
    }
    return -1111;
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
bool Massiiv<T>::kasTais(){
    return n==100;
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
int Massiiv<T>::getSuurus(){
    return n;
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
void Massiiv<T>::print(){
    for(int i=0; i<n; i++){
        cout << massiiv[i] << ", ";
    }
    cout << '\n';
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
void Massiiv<T>::lisaElement(T el){
    if(n<100){
        massiiv[n] = el;
        n++;
    }
    else{
        cout << "Massiiv on täis!\n";
    }
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
void Massiiv<T>::kustutaElement(){
    if(n>0){
        massiiv[n] = 0;
        n--;
    }
    else{
        cout << "Massiiv on tühi!\n";
    }
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
void Massiiv<T>::asendaElement(T el1, T el2){
    for(int i=0; i<n; i++){
        if(massiiv[i] == el1){
            massiiv[i] == el2;
        }
    }
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
int Massiiv<T>::vabuKohti(){
    return 100-n;
}

template <typename T>
requires  (is_same_v<T, int> || is_same_v<T, double> || is_same_v<T, float>)
bool Massiiv<T>::kasSisaldub(T el){
    for(int i=0; i<n; i++){
        if(massiiv[i]==el){
            return true;
        }
    }
    return false;
}

#endif