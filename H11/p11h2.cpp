#include "p11h2.h"

#include <iostream>

using namespace std;

int Ratsionaalarv::get_lugeja(){
    return m_lugeja.get();
}
int Ratsionaalarv::get_nimetaja(){
    return m_nimetaja.get();
}
void Ratsionaalarv::set_lugeja(int arv){
    m_lugeja.set(arv);
}
void Ratsionaalarv::set_nimetaja(int arv){
    m_nimetaja.set(arv);
}

Ratsionaalarv::Ratsionaalarv(PahupidiArv arv){
    m_lugeja = arv;
    m_nimetaja = PahupidiArv(1);
}
Ratsionaalarv::Ratsionaalarv(PahupidiArv arv1, PahupidiArv arv2){
    m_lugeja = arv1;
    if (arv2.get() == 0){
        m_nimetaja = PahupidiArv(1);
    } else { m_nimetaja = arv2;}
}

Ratsionaalarv::~Ratsionaalarv(){
    cout << this;
}

Ratsionaalarv::Ratsionaalarv(Ratsionaalarv& ra){
    m_lugeja = ra.get_lugeja();
    m_nimetaja = ra.get_nimetaja();
}

Ratsionaalarv::Ratsionaalarv(Ratsionaalarv&& ra){
    m_lugeja = ra.get_lugeja();
    m_nimetaja = ra.get_nimetaja();
    ra.set_lugeja(0);
    ra.set_nimetaja(1);
}
PahupidiArv::PahupidiArv(PahupidiArv&& ra) {
    arv = ra.get();
    ra.set(0);
}