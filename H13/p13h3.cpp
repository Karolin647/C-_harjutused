#include "p13h3.h"

#include <sstream>
#include <fstream>

ostream& operator<<(ostream& os, Tellimus &tellimus){
    os << tellimus.getTellija();
    for (Pitsa pitsa : tellimus.getPitsad()) {
        os << pitsa << ";";
    }
    return os;

}

float Tellimus::maksumus(){
    try {
        if (this->getOoteaeg() > 30) {
            throw LiigaPikkOotamineErind("Läks kaua!");
        }
        vector<Pitsa> pitsad = this->getPitsad();
        float summa = 0;
        for (Pitsa pitsa : pitsad) {
            summa += pitsa.getHind();
        }
        return summa;
    } catch (LiigaPikkOotamineErind& e){
        cout << e.teade;
        return 0;
    } catch (...) {
        cout << "tundmatu erind";
        return -1;
    }


}

void loe_failist(string file_name, vector<Tellimus>& vec) {
    ifstream f(file_name) ;
    string line;
    string tellijaNimi;
    string pitsa;
    string pitsaNimi;
    string pitsaHind;
    if(f){
        while(getline(f, line)){
            vector<Pitsa> pitsad;
            stringstream line_ss (line);
            getline(line_ss, tellijaNimi, ';');
            while (getline(line_ss, pitsa, ';')){
                stringstream pitsa_ss (pitsa);
                getline(pitsa_ss, pitsaNimi, '/');
                getline(pitsa_ss, pitsaHind);
                pitsad.push_back(Pitsa(pitsaNimi, stof(pitsaHind)));
            }
            vec.push_back(Tellimus(tellijaNimi, 25, pitsad));
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<Tellimus> jrk;
    return 0;
}
