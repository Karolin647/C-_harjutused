#include <iostream>
#include <string>
using namespace std;

void tagurpidi (size_t arv, string massiiv[]) {
    string p_sone;
    string v_sone;
    for (int i{0}; i < (arv+1)/2; i++) {
        v_sone = "";
        for(char j : massiiv[i]) {
            v_sone = j + v_sone;
        }
        p_sone = "";
        for(char j : massiiv[arv-1-i]) {
            p_sone = j + p_sone;
        }
        massiiv[i] = p_sone;
        massiiv[arv-1-i] = v_sone;
    }
}

int main() {
    string massiiv[] = {"kaks", "kolm", "neli", "viis"};
    tagurpidi(4, massiiv);
    for (int i = 0; i < 4; i++) {
        cout << massiiv[i] << endl;
    }
}