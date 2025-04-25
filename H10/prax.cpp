#include "prax.h"
#include <fstream>
#include <sstream>
#include <set>

void Tudeng::add_points(string subject_name, int subject_points){
    points[subject_name] = subject_points;
}

ostream& operator<<(ostream& os, Tudeng& a){
    os << a.get_nimi() << ' ' << a.get_id() << ' ';
    for (auto& paar : a.get_points()){
        os << paar.first << ' ' << paar.second << ' ';
    }
    return os << endl;
}

void read_from_file(vector<Tudeng>& v, string file_name){
    fstream file(file_name);
    if(!file){
        cout << "midagi on valesti" << endl;
    } else {

        string line;
        string nimi;
        string perenimi;
        string id;
        string word;
        string sub;
        string p;
        while(getline(file, line)){
            stringstream liness(line);
            getline(liness, nimi, ' ');
            getline(liness, perenimi, ' ');
            getline(liness, id, ' ');
            nimi = nimi + " " + perenimi;
            Tudeng tudeng(nimi, id);
            while(getline(liness, sub, ' ')){
                getline(liness, p, ' ');
                tudeng.add_points(sub, stoi(p));
            }
            v.push_back(tudeng);
        }
    }
}

void eemalda_tudeng(vector<Tudeng>& v, string id) {
    for (auto i = v.begin(); i != v.end(); i++) {
        if (i->get_id() == id) {
            v.erase(i);
            i = v.end() - 1;
        }
    }
}

void kuva_ainekoodid(vector<Tudeng>& v) {
    set<string> ainekoodid;
    for (Tudeng i : v) {
        for (auto paar : i.get_points()) {
            ainekoodid.insert(paar.first);
        }
    }
    for (string i : ainekoodid) {
        cout << i << endl;
    }
    cout << endl;
}

int main(){
    string f_name = "test.txt";
    vector<Tudeng> v;
    read_from_file(v, f_name);
    for (Tudeng i : v) {
        cout << i;
    }
    eemalda_tudeng(v, "A238");
    cout << endl;
    for (Tudeng i : v) {
        cout << i;
    }
    cout << endl;
    kuva_ainekoodid(v);
    return 0;
}

//Carl Cask A246 MTAT.01.001 56 MTAT.01.002 65 MTAT.01.003 83 MTAT.01.004 100 MTAT.01.005 45