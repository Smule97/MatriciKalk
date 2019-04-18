#include "vettore.h"

Vettore::Vettore(double* val, int d1) : Struttura(d1,0), value(val){
    setId(4);
}

Vettore::~Vettore(){
    delete [] value;
}

double Vettore::getValue(int x) const{
    return value[x];
}

void Vettore::setValue(int x, double val){
    value[x]=val;
}

void Vettore::insertValue(double*& v){
    value=v;
}

Vettore* Vettore::somma(Struttura* v) const{
    Vettore* vet=static_cast<Vettore*>(v);
    if(getDimAt(0)==vet->getDimAt(0)){
        double* ris=new double[getDimAt(0)];
        for(int i=0; i<getDimAt(0);i++){
            ris[i]=getValue(i)+vet->getValue(i);
        }
        return new Vettore(ris,getDimAt(0));
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Vettore* Vettore::differenza(Struttura* v) const{
    Vettore* vet=static_cast<Vettore*>(v);
    if(getDimAt(0)==vet->getDimAt(0)){
        double* ris=new double[getDimAt(0)];
        for(int i=0; i<getDimAt(0);i++){
            ris[i]=getValue(i)-vet->getValue(i);
        }
        return new Vettore(ris,getDimAt(0));
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Vettore* Vettore::moltiplicazione(Struttura* v) const{
    Vettore* vet=static_cast<Vettore*>(v);
    if(getDimAt(0)==vet->getDimAt(0)){
        double* ris=new     double[0];
        ris[0]=0;
        for(int i=0; i<getDimAt(0);i++){
            ris[0]+=getValue(i)*vet->getValue(i);
        }
        return new Vettore(ris,1);
    }
    else{
        throw Exception("Dimensioni non valide. Devono essere uguali.");
    }
}

Vettore* Vettore::potenza(int exp) const{
    double* ris=new double[getDimAt(0)];
    for(int i=0; i<getDimAt(0);i++){
        ris[i]=qPow(getValue(i) , exp);
    }
    return new Vettore(ris,getDimAt(0));
}
