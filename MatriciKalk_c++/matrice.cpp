#include "matrice.h"

Matrice::Matrice(double* val, int d1, int d2):Struttura(d1,d2),value(val){
    setId(1);
}

Matrice::~Matrice(){
        delete [] value;
}

double Matrice::getValue(int x, int y) const{
    return value[y+x*getDimAt(1)];
}

void Matrice::setValue(int x, int y,double val){
    value[y+x*getDimAt(1)]=val;
}

void Matrice::insertValue(double*& v){
    value=v;
}

Matrice* Matrice::somma(Struttura* m) const{
    Matrice* mat=static_cast<Matrice*>(m);
    if(getDimAt(0)==mat->getDimAt(0) && getDimAt(1)==mat->getDimAt(1)){
        double* ris=new double[getDimAt(0)*getDimAt(1)];
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0; j<getDimAt(1); j++){
                ris[j+i*getDimAt(0)]=getValue(i,j) + mat->getValue(i,j);
            }
        }
        return new Matrice(ris,getDimAt(0),getDimAt(1));
    }
    else{
       throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Matrice* Matrice::differenza(Struttura* m) const{
    Matrice* mat=static_cast<Matrice*>(m);
    if(getDimAt(0)==mat->getDimAt(0) && getDimAt(1)==mat->getDimAt(1)){
        double* ris=new double[getDimAt(0)*getDimAt(1)];
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0; j<getDimAt(1); j++){
                ris[j+i*getDimAt(0)]=getValue(i,j)-mat->getValue(i,j);
            }
        }
        return new Matrice(ris,getDimAt(0),getDimAt(1));
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Matrice* Matrice::moltiplicazione(Struttura* m) const{
    Matrice* mat=static_cast<Matrice*>(m);
    if(getDimAt(1)==mat->getDimAt(0) ){
        double* ris=new double[getDimAt(0)*mat->getDimAt(1)];
        int cont=0;

        for(int i=0; i<getDimAt(0); i++){
            for(int j=0; j<mat->getDimAt(1); j++){
                ris[cont]=0;
                for(int k=0; k<getDimAt(1); k++){
                    ris[cont] += mat->getValue(k,j) * getValue(i,k);
                }
                cont++;
            }
        }
        return new Matrice(ris,getDimAt(0),mat->getDimAt(1));
    }
    else{
       throw Exception("Dimensioni non valide.");
    }

}

Matrice* Matrice::potenza(int exp) const{
    double* ris=new double[getDimAt(0)*getDimAt(1)];
    for(int i=0; i<getDimAt(0);i++){
        for(int j=0; j<getDimAt(1); j++){
            ris[j+i*getDimAt(0)]=qPow(getValue(i,j) , exp);
        }
    }
    return new Matrice(ris,getDimAt(0),getDimAt(1));
}

bool Matrice::ortogonale(){
    double* trasposta=new double[getDimAt(0)*getDimAt(1)];

    int cont=0;
    if(getDimAt(0)==getDimAt(1)){
        for(int i=0;i<getDimAt(0);i++){
            for(int j=0;j<getDimAt(0);j++){
                trasposta[cont]=getValue(j,i);
                cont++;
            }
        }
        Matrice* tmp=moltiplicazione(new Matrice(trasposta,getDimAt(0),getDimAt(1)));
        bool veroZero=true, veroUno=true;;
        cont=0;
        for(int i=0; i<getDimAt(0);i++){
            for(int j=0;j<getDimAt(0);j++){
                if(i==j){
                    if(tmp->getValue(i,j)!=1)//Controllo siano tutti uno nella diagonale
                        veroUno=false;
                }
                else{
                    if(tmp->getValue(i,j)!=0)//Controllo siano tutti zeri al di fuori della diagonale
                        veroUno=false;
                }
            }
        }
        if(veroUno && veroZero){
            return true;
        }
        else{
            throw Exception("La matrice non e' ortogonale.");
        }
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Vettore* Matrice::moltiplicazioneMV(Vettore* v){
    Vettore* vet=static_cast<Vettore*>(v);
    if(getDimAt(1)==vet->getDimAt(0)){
        double* ris=new double[getDimAt(0)];

        for (int i=0;i<getDimAt(0);i++) {
            ris[i]=0;
            for (int j=0;j<getDimAt(1);j++) {
                ris[i]+=getValue(i,j) * vet->getValue(j);
            }
        }

        return new Vettore(ris,getDimAt(0));
    }
    else{
        throw Exception("Dimensioni non valide.");
    }

}
