#ifndef P11H2_H
#define P11H2_H

#include "p1h1.h"
#include <ostream>
using namespace std;

class Ratsionaalarv{
    private:
        PahupidiArv m_lugeja{0};
        PahupidiArv m_nimetaja{1};
    public:
        PahupidiArv get_lugeja_pahupidi(){return m_lugeja;}
        PahupidiArv get_nimetaja_pahupidi(){return m_nimetaja;}
        int get_lugeja();
        int get_nimetaja();
        void set_lugeja(int arv);
        void set_nimetaja(int arv);

        Ratsionaalarv(PahupidiArv arv);
        Ratsionaalarv(PahupidiArv arv1, PahupidiArv arv2);
        Ratsionaalarv() = default;

        ~Ratsionaalarv();

        Ratsionaalarv(Ratsionaalarv& ra);
        Ratsionaalarv(Ratsionaalarv&& ra);

        friend ostream& operator<<(ostream& os, Ratsionaalarv& c){
            return os << c.get_lugeja() << "/" << c.get_nimetaja();
        }
        
        void operator*=(Ratsionaalarv teine){
            m_lugeja /= teine.get_lugeja_pahupidi();
            m_nimetaja /= teine.get_nimetaja_pahupidi();
        }
        void operator+=(Ratsionaalarv teine){
            
        }
        void operator+=(Ratsionaalarv c)
};
#endif