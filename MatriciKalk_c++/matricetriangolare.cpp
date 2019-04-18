#include "matricetriangolare.h"
#include "matrice.h"

MatriceTriangolare::MatriceTriangolare(double* val,char t, int d1) : Matrice(val,d1,d1), tipo(t){
    setId(2);
}

MatriceTriangolare::~MatriceTriangolare() {}

char MatriceTriangolare::getTipo()const{
    return tipo;
}

MatriceTriangolare* MatriceTriangolare::somma(Struttura* m) const{
    MatriceTriangolare* mat=static_cast<MatriceTriangolare*>(m);
    if(mat->getDimAt(0)==getDimAt(0)){
        double* ris=new double[getDimAt(0)*getDimAt(0)];
        int cont=0;
        if(tipo==mat->getTipo()){
            if(tipo=='s'){
                for(int i=0; i<getDimAt(0);i++){
                    for(int j=0; j<getDimAt(1);j++){
                        j+=cont;
                        ris[j+i*getDimAt(0)]=getValue(i,j) + mat->getValue(i,j);
                    }
                    cont++;
                }
            }
            else if(tipo=='i'){
                cont=getDimAt(1)-1;
                for(int i=0; i<getDimAt(0);i++){
                    for(int j=getDimAt(1); j>0;j--){
                        j-=cont;
                        ris[j+i*getDimAt(0)]=getValue(i,j) + mat->getValue(i,j);
                    }
                    cont--;
                }
            }
            return new MatriceTriangolare(ris,tipo,getDimAt(0));
        }
        else{
           Matrice::somma(m);
        }
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

MatriceTriangolare* MatriceTriangolare::differenza(Struttura* m) const{
    MatriceTriangolare* mat=static_cast<MatriceTriangolare*>(m);
    if(mat->getDimAt(0)==getDimAt(0)){
        double* ris=new double[getDimAt(0)*getDimAt(0)];
        int cont=0;
        if(tipo==mat->getTipo()){
            if(tipo=='s'){
                for(int i=0; i<getDimAt(0);i++){
                    for(int j=0; j<getDimAt(1);j++){
                        j+=cont;
                        ris[j+i*getDimAt(1)]=getValue(i,j) - mat->getValue(i,j);
                    }
                    cont++;
                }
            }
            else if(tipo=='i'){
                cont=getDimAt(1)-1;
                for(int i=0; i<getDimAt(0);i++){
                    for(int j=getDimAt(1); j>0;j--){
                        j-=cont;
                        ris[j+i*getDimAt(1)]=getValue(i,j) - mat->getValue(i,j);
                    }
                    cont--;
                }
            }
            return new MatriceTriangolare(ris,tipo,getDimAt(0));
        }
        else{
           Matrice::differenza(m);
        }
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

MatriceTriangolare* MatriceTriangolare::potenza(int exp) const{
    double* ris=new double[getDimAt(0)*getDimAt(0)];
    for(int i=0; i<getDimAt(0)*getDimAt(0);i++)
        ris[i]=0;

    if(tipo=='s'){
        for(int i=0; i<getDimAt(0);i++){
            for(int j=i; j<getDimAt(1);j++){
                ris[j+i*getDimAt(0)]=qPow(getValue(i,j) , exp);
            }
        }
    }
    else if(tipo=='i'){
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0; j<i+1;j++){
                ris[j+i*getDimAt(0)]=qPow(getValue(i,j) , exp);
            }
        }
    }
     return new MatriceTriangolare(ris,tipo,getDimAt(0));
}
