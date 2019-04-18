#ifndef MATRICETRIANGOLARE_H
#define MATRICETRIANGOLARE_H

#include"matrice.h"

class MatriceTriangolare : public Matrice{
private:
    char tipo; //Può essere s=superiore o i=inferiore
public:
    char getTipo()const;
    MatriceTriangolare(double*, char, int=1);
    ~MatriceTriangolare();
    MatriceTriangolare* somma(Struttura* mat) const;
    MatriceTriangolare* differenza(Struttura* mat) const;
    MatriceTriangolare* potenza(int exp) const;

};

#endif // MATRICETRIANGOLARE_H
