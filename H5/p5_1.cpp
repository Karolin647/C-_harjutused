#include "p5_1.h"

int main (void){
    int x = 5, y = 7;
    vaheta_ref<int> (x, y);   // x = 7 ja y = 5
    cout << x << " " << y << endl;
    vaheta_ptr<int> (&x, &y); // x = 5 ja y = 7
    cout << x << " " << y << endl;
    return 0;
}