#include "p12h1.h"
#include <sstream>


Tulemus::Tulemus(string id_, string _competition_name, int _place) : id(id_), 
    competition_name(_competition_name), place(_place) {}

Tulemus::~Tulemus()
{
}

string Tulemus::getId(){
    return id;
}

string Tulemus::getCompetition_name(){
    return competition_name;
}

int Tulemus::getPlace(){
    return place;
}

ostream&operator<<(ostream& os, Tulemus obj){
    return os<< "id: " << obj.getId() << " nimi: " 
    << obj.getCompetition_name() << " koht: " << obj.getPlace();
}

string Osaleja::getId(){
    return id;
}

string Osaleja::getCompetitor(){
    return competitor;
}

vector<Tulemus> Osaleja::getTulemused(){
    return tulemused;
}

void Osaleja::lisaTulemused(vector<Tulemus> koik_tulemused){
    for(Tulemus tulemus : koik_tulemused){
        cout << tulemus.getId() << " " << id<< endl;
        if(tulemus.getId() == id){
            tulemused.push_back(tulemus);
        }
    }
}

ostream&operator<<(ostream& os, Osaleja obj){
    return os << "Osaleja nimi: " << obj.getCompetitor() << " Isikukood: "  << obj.getId() << " Tulemusi: " << obj.tulemusi() << " võite: " << obj.voite();
}

ostream&operator<<(ostream& os, Lapsosaleja& obj){
    return os << dynamic_cast<Osaleja&>(obj);
}

void loe_failist(string file_name, vector<Tulemus>& vec) {
    ifstream f(file_name) ;
    string line;
    string id;
    string nimi;
    string koht;
    if(f){
        while(getline(f, line)){
            stringstream line_ss (line);
            getline(line_ss, id, ';');
            getline(line_ss, nimi, ';');
            if(getline(line_ss, koht, ';')){
                Tulemus tulem(id, nimi, stoi(koht));
                vec.push_back(tulem);
            } else {
                Tulemus tulem(id, nimi, 1);
                vec.push_back(tulem);
            }   
        }
    }
}