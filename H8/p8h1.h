#ifndef P8H1_H
#define P8H1_H

#include <vector>
#include <string>
#include <memory>
using namespace std;

unique_ptr<int[]> loo_andmed(int pikkus);
shared_ptr<vector<int>> loe_andmed(string* failinimi);
void tootle_andmeid(weak_ptr<int[]> andmed, int pikkus);
void tootle_andmeid_vektoris(weak_ptr<vector<int>> andmed);

#endif
