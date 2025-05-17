#ifndef P12H1_H
#define P12H1_H
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Tulemus
{
private:
    /* data */
    string id;
    string competition_name;
    int place;
public:
    Tulemus(string id_, string _competition_name, int _place);
    ~Tulemus();
    string getId();
    string getCompetition_name();
    int getPlace();
    friend ostream&operator<<(ostream& os, Tulemus obj);
};

class Osalenud {
    virtual int  voite() = 0;
    virtual int tulemusi() = 0; 
};

class Osaleja : public Osalenud {
private:
    string id;
    string competitor;
    vector<Tulemus> tulemused;
public:
    Osaleja(string _id, string _competitor) : id(_id), competitor(_competitor){}
    string getId();
    string getCompetitor();
    vector<Tulemus> getTulemused();
    void lisaTulemused(vector<Tulemus> koik_tulemused);
    virtual int voite() override{
        int i = 0;
        for(Tulemus tulemus : tulemused){
            if(tulemus.getPlace() == 1){
                i++;
            }
        }
        return i;
    }

    virtual int tulemusi() override{
        int i = 0;
        for(Tulemus tulemus : tulemused){
            i++;
        }
        return i;
    }

    friend ostream&operator<<(ostream& os, Osaleja obj);
};

class Lapsosaleja : public Osaleja {
    private:
        string vanem_id;
    public:
    Lapsosaleja(string nimi, string id, string _vanem_id): Osaleja(nimi, id), vanem_id(_vanem_id){};
    virtual int voite() override{
        return tulemusi();
    }
    friend ostream&operator<<(ostream& os, Lapsosaleja& obj);
};

void loe_failist(string file_name, vector<Tulemus>& vec);

#endif