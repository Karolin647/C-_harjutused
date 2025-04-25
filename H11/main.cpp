#include "p1h1.h"
#include "p1h1.cpp"

int main(){
    PahupidiArv arv1{30};
    PahupidiArv arv2 = PahupidiArv(10);
    cout << arv1 << " " << arv2 << endl;
    arv1 += arv2;
    cout << arv1 << " " << arv2 << endl;
    arv2 -= arv1;
    cout << arv1 << " " << arv2 << endl;
    arv1 *= arv2;
    cout << arv1 << " " << arv2 << endl;
    arv2 /= arv1;
    cout << arv1 << " " << arv2 << endl;
    PahupidiArv arv3 = arv2;
    cout << arv3 << endl;
}