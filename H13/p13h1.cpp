#include "p13h1.h"
#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <sstream>
using namespace std;

vector<int> Arvulugeja::getVector(string word) {
    string part;
    vector<int> v;
        
    stringstream word_ss (word);
    while(getline(word_ss, part, ',')){
        int arv;
        try{
            if(part == ""){
                throw ArvuPole("arvu pole");
            }
            try{
                 arv = stoi(part);
            } catch(...) {
                throw PoleArv("pole arv");
            }
            v.push_back(arv);
            cout << "panin arvu - " << arv << endl;
        } catch(ArvuPole& e) {
            cout << e.sonum << endl;
        }
        catch(PoleArv& e) {
            cout << e.sonum << endl;
        }
    }
    return v;
}

void viska(int x) {
    if (x == 1) {
        throw 1;
    } else if (x == 2) {
        throw (string)"paar";
    }
}

int main() {
    /*vector<int> arvud{0, 1, 2, 3};
    for (int i : arvud) {
        try {
            cout << i << ' ';
            viska(i);
            cout << "korras" << endl;
        } catch (int& e) {
            cout << "Viga: int " << e << endl;
        } catch (string& e) {
            cout << "Viga: s6ne " << e << endl;
        }
    }*/

    string word;
    cout << "sisestage: " << endl;
    cin >> word;
    Arvulugeja lugeja(word);
    vector<int> v = lugeja.getVector(word);
    for(auto& x : v){
        cout << x << endl;
    }
    return 0;
}