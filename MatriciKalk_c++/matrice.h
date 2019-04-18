#ifndef MATRICE_H
#define MATRICE_H

#include "struttura.h"
#include "vettore.h"
class Matrice:public Struttura{
private:
    double* value;
public:
    Matrice(double*, int=1, int=1);
    ~Matrice();
    double getValue(int, int) const;
    void setValue(int, int, double);
    void insertValue(double*&);

    Matrice* somma(Struttura* mat) const;
    Matrice* differenza(Struttura* mat) const;
    Matrice* moltiplicazione(Struttura* mat) const;
    Matrice* potenza(int exp) const;
    bool ortogonale();
    Vettore* moltiplicazioneMV(Vettore* v);
};

#endif // MATRICE_H
