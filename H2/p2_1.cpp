#include <iostream>
#include <cmath>
using namespace std;

float sqrt_algorithm (float alg, int n) {
    float r = n / alg;
    alg = (alg + r) / 2;
    return alg;
}

int main(){
    int n;
    cout <<  "Sisestage n" << endl;
    cin >> n ;
    float alg = n/2.0;
    float prev_alg = alg;
    alg = sqrt_algorithm (alg, n);
    while ((prev_alg - alg) >= alg*0.01) {
        prev_alg = alg;
        alg = sqrt_algorithm (alg, n);
    }
    cout <<  "Ruutujuur: " << round(alg * 100) / 100 << endl;
}