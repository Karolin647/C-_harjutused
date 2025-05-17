#include "p14h1.h"

bool operator==( Raamat& lhs,  Raamat& rhs) {
    return (lhs.getAutor() == rhs.getAutor() && lhs.getPealkiri() == rhs.getPealkiri() && lhs.getSari() == rhs.getSari());
}

ostream& operator<<(ostream& os, const Raamat& obj) {
    return os << "Autor: " << obj.getAutor() << " Pealkiri: " << obj.getPealkiri() << " Sari: " << obj.getSari();
}

void Raamat::setSari(string _sari) {
    sari = _sari;
}

void Sari::lisaRaamat(Raamat& raamat) {
    if (raamat.getSari() == nimi)
        raamatud.push_back(raamat);
}

void Sari::kustutaRaamat(Raamat& raamat) {
    for (auto i = raamatud.begin(); i != raamatud.end(); i++) {
        if (raamat == *i) {
            raamatud.erase(i);
            break;
        }
    }
}

ostream& operator<<(ostream& os, Sari& sari) {
    os << sari.nimi << ": {";
    for (Raamat i : sari.raamatud) {
        os << i << ", ";
    }
    return os << "}";
}
void Sarjad::lisaRaamat(Raamat& raamat) {
    for (auto i : raamatud) {
        if (i.first == raamat.getSari()) {
            i.second->push_back(raamat);
            break;
        }
    }
}

void Sarjad::muudaSari(Raamat& raamat) {
    kustutaRaamat(raamat);
    string uusSari;
    cout << "Sisesta uus sari raamatule '" << raamat.getPealkiri() << "': ";
    cin >> uusSari;
    raamat.setSari(uusSari);
    lisaRaamat(raamat);
}


void Sarjad::kustutaRaamat(Raamat& raamat) {
    auto it = raamatud.find(raamat.getSari());
    auto& vec = *(it->second);
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        if (*i == raamat) {
            vec.erase(i);
            return;
        }
    }
}

void Sarjad::lisaSari(Sari& sari) {
    raamatud[sari.getNimi()] = &sari.getRaamatud();
}

void Sarjad::kustutaSari(Sari& sari) {
    raamatud.erase(sari.getNimi());
}

ostream& operator<<(ostream& os, Sarjad& sarjad) {
    os << "{ ";
    for (auto i : sarjad.raamatud) {
        os << i.first << ": {" << i.second << "}";
    }
    return os;
}
//Roberto Bolano. Metsikud detektiivid, Ajavaim,
//Jaan Kross. Kallid kaasteelised, Eesti mälu
int main() {
    Raamat r1("Metsikud detektiivid", "Roberto Bolano", "Ajavaim");
    Raamat r2("Kallid kaasteelised", "Jaan Kross", "Eesti mälu");
    Data<Raamat> d{};
    d.lisaObjekt(r1);
    d.lisaObjekt(r2);
    cout << d.getFromIndex(1)<<endl;
    cout << d.getFromObject(r1)<<endl;
    d.Kuva();
}