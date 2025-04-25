#ifndef PRAX_H
#define PRAX_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Tudeng
{
private:
    /* data */
    string nimi;
    string id;
    map <string, int> points;
public:
    Tudeng(string nimi_, string id_) : nimi(nimi_), id(id_){};
    Tudeng() : nimi(""), id(""){};
    void add_points(string subject_name, int points);
    friend ostream& operator<<(ostream& os, Tudeng& a);
    string get_nimi(){
        return nimi;
    }
    string get_id(){
        return id;
    }
    map <string, int> get_points () {
        return points;
    }
};



void read_from_file(vector<Tudeng>& v, string file_name);


#endif