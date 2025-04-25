#ifndef PRAX_H
#define PRAX_H

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>

template <typename T1, typename T2, typename T3>
void yhisosa(T1& esimene, T2& teine, T3& kolmas){
    std::vector<int> tem_arr;
    std::vector<int> arr;
    std::vector<int> cnt_arr;
    for (auto it = esimene.begin(); it != esimene.end(); it++){
        if(std::find(tem_arr.begin(), tem_arr.end(), *it) == tem_arr.end()){
            tem_arr.push_back(*it);
            auto iter = std::find(arr.begin(), arr.end(), *it);
            if(iter == arr.end()) {
                arr.push_back(*it);
                cnt_arr.push_back(1);
            } else {
                cnt_arr.at(iter-arr.begin()) = cnt_arr.at(iter-arr.begin()) + 1;
            }
    }}

    tem_arr.clear();

    for (auto it = teine.begin(); it != teine.end(); it++){
        if(std::find(tem_arr.begin(), tem_arr.end(), *it) == tem_arr.end()){
            tem_arr.push_back(*it);
            auto iter = std::find(arr.begin(), arr.end(), *it);
            if(iter == arr.end()) {
                arr.push_back(*it);
                cnt_arr.push_back(1);
            } else {
                cnt_arr.at(iter-arr.begin()) = cnt_arr.at(iter-arr.begin()) + 1;
            }
    }}


    for (auto it = cnt_arr.begin(); it != cnt_arr.end(); it++){
        if(*it == 2){
            kolmas.push_back(arr.at(it-cnt_arr.begin()));
        }
    }

}

template <typename T1, typename T2, typename T3>
void yhend(T1& esimene, T2& teine, T3& kolmas) {
    for (auto it{esimene.begin()}; it < esimene.end(); it++) {
        bool onolemas{false};
        for (auto it2{kolmas.begin()}; it2 < kolmas.end(); it2++) {
            if (*it == *it2) {
                onolemas = true;
            }
        }
        if (!onolemas)
            kolmas.push_back(*it);
    }

    for (auto it{teine.begin()}; it < teine.end(); it++) {
        bool onolemas{false};
        for (auto it2{kolmas.begin()}; it2 < kolmas.end(); it2++) {
            if (*it == *it2) {
                onolemas = true;
            }
        }
        if (!onolemas)
            kolmas.push_back(*it);
    }
}

template <typename T1, typename T2, typename T3>
void vahe(T1& esimene, T2& teine, T3& kolmas) {
    for (auto it{esimene.begin()}; it < esimene.end(); it++) {
        bool onolemas{false};
        for (auto it2{kolmas.begin()}; it2 < kolmas.end(); it2++) {
            if (*it == *it2) {
                onolemas = true;
            }
        }
        if (onolemas) continue;
        for (auto it2{teine.begin()}; it2 < teine.end(); it2++) {
            if (*it == *it2) {
                onolemas = true;
            }
        }
        if (!onolemas)
            kolmas.push_back(*it);
    }
}
void tryki(std::vector<int> v1);

#endif