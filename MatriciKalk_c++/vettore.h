#ifndef VETTORE_H
#define VETTORE_H

#include "struttura.h"

class Vettore: public Struttura{
private:
    double* value;
public:
    Vettore(double*, int);
    ~Vettore();
    double getValue(int) const;
    void setValue(int, double);
    void insertValue(double*&);

    Vettore* somma(Struttura* mat) const;
    Vettore* differenza(Struttura* mat) const;
    Vettore* moltiplicazione(Struttura* mat) const;
    Vettore* potenza(int exp) const;

};

#endif // VETTORE_H
