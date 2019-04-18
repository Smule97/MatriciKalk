#include "matriceunitaria.h"
#include "matrice.h"

MatriceUnitaria::MatriceUnitaria(double* val, int d1) : Matrice(val,d1,d1) {setId(3);}

MatriceUnitaria::~MatriceUnitaria() {}

Matrice* MatriceUnitaria::somma(Struttura* m) const{
    Matrice* mat=static_cast<Matrice*>(m);
    if(getDimAt(0)==mat->getDimAt(0)){
        double* ris=new double[getDimAt(0)*getDimAt(1)];
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0; j<getDimAt(1); j++){
                if(i==j){
                    ris[j+i*getDimAt(0)]=getValue(i,j) + mat->getValue(i,j);
                }
                else{
                    ris[j+i*getDimAt(0)]=mat->getValue(i,j);
                }
            }
        }
        return new Matrice(ris,getDimAt(0),getDimAt(1));
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Matrice* MatriceUnitaria::differenza(Struttura* m) const{
    Matrice* mat=static_cast<Matrice*>(m);
    if(getDimAt(0)==mat->getDimAt(0) && getDimAt(1)==mat->getDimAt(1)){
        double* ris=new double[getDimAt(0)*getDimAt(1)];
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0; j<getDimAt(1); j++){
                if(i==j){
                    ris[j+i*getDimAt(0)]=getValue(i,j) - mat->getValue(i,j);
                }
                else{
                    ris[j+i*getDimAt(0)]=mat->getValue(i,j);
                }
            }
        }
        return new Matrice(ris,getDimAt(0),getDimAt(1));
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}


MatriceUnitaria* MatriceUnitaria::potenza(int exp) const{
    double* ris=new double[getDimAt(0)*getDimAt(1)];
    for(int i=0; i<getDimAt(0);i++){
        for(int j=0; j<getDimAt(1); j++){
            if(i==j)
                ris[j+i*getDimAt(0)]=qPow(getValue(i,j) , exp);
        }
    }
    return new MatriceUnitaria(ris,getDimAt(0));
}

