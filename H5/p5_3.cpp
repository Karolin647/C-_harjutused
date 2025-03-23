#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void string_to_array(string& str, int massiiv[20]){
    int n = str.length();
    for(int i{0}; i<n; i++){
        massiiv[n - i - 1] = stoi(string(1, str[i]));
    }
}

void liida(int m1[], int m2[], int m_s[], int& carry){
    int arv=0;
    for(int i=0; i<= 20; i++){
        arv = m1[i] + m2[i] + carry;
        carry = 0;
        if(arv >= 10){
            carry = 1;
            arv %= 10;
        }
        m_s[20-i-1] = arv;
    }
}

void prindi(int massiiv[], int& carry){
    if(massiiv[0] != 0 && carry == 1){
        cout << "Summa on liiga suur.";
    }
    else{
        int k=0;
        for(int i=0; i<20;i++){
            if (massiiv[i] == 0 && k== 0){
                continue;
            }
            else{
                k=1;
                cout << massiiv[i];
            }
        }
    }
}

int main(){
    int carry = 0;
    int& p_carry{carry};
    int massiiv1[20];
    int massiiv2[20];
    int massiiv_s[20];
    for(int i=0; i<20; i++){
        massiiv1[i] = 0;
        massiiv2[i] = 0;
        massiiv_s[i] = 0;
    }

    string nimi = "nr.txt";
    fstream fail{nimi};
    if(!(fail)){
        cout << "Viga avamisel";
        return 0;
    }
    string nr1, nr2;
    fail >> nr1 >> nr2;
    cout << "Lugesin nr1 " << nr1 << '\n';
    cout << "Lugesin nr2 " << nr2 << '\n';
    string& p_nr1{nr1};
    string_to_array(p_nr1, massiiv1);
    string& p_nr2{nr2};
    string_to_array(p_nr2, massiiv2);
    liida(massiiv1, massiiv2, massiiv_s, p_carry);
    prindi(massiiv_s, p_carry);

    return 0;
}