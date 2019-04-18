#ifndef MATRICEUNITARIA_H
#define MATRICEUNITARIA_H

#include"matrice.h"

class MatriceUnitaria : public Matrice{
public:
    MatriceUnitaria(double*, int=1);
    ~MatriceUnitaria();
    Matrice* somma(Struttura* mat) const;
    Matrice* differenza(Struttura* mat) const;
    MatriceUnitaria* potenza(int exp) const;
};

#endif // MATRICEUNITARIA_H
