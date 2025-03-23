#ifndef P4_4_H
#define P4_4_H
#include <concepts>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class Massiiv{
    public:
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
        T massiiv[100];
        int n{0};
};

template<typename T>
T Massiiv<T>::getElement(int i){
    if(i>n){
        return -1111;
    }
    return massiiv[i];
}

template<typename T>
bool Massiiv<T>::kasTais(){
    return n==100;
}

template<typename T>
int Massiiv<T>::getSuurus(){
    return n;
}

template<typename T>
void Massiiv<T>::print(){
    for(int i=0; i<n-1; i++){
        cout << massiiv[i] << ", ";
    }
    cout << massiiv[n-1] << '\n';
}

template<typename T>
void Massiiv<T>::lisaElement(T el){
    if(n<100){
        massiiv[n] = el;
        n++;
    }
    else{
        cout << "Massiiv on täis.\n";
    }
}

template<typename T>
void Massiiv<T>::kustutaElement(){
    if(n>0){
        massiiv[n-1] = 0;
        n--;
    }
    else{
        cout << "Massiiv on tühi.\n";
    }
}

template<typename T>
void Massiiv<T>::asendaElement(T el1, T el2){
    for(int i=0; i<n; i++){
        if(massiiv[i]==el1){
            massiiv[i] = el2;
        }
    }
}


template<typename T>
int Massiiv<T>::vabuKohti(){
    return 100-n;
}

template<typename T>
bool Massiiv<T>::kasSisaldub(T el){
    for(int i=0; i<n; i++){
        if(massiiv[i]==el){
            return true;
        }
    }
    return false;
}


#endif