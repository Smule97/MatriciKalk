#include "struttura.h"

Struttura::Struttura(int* d, int numDim){
    for(int i=0; i<numDim; i++){
         dim.append(*d);
         d++;
    }
}


Struttura::~Struttura(){
    QVector<int>::iterator it=dim.begin();
    for(;it!=dim.end();++it){
        it=dim.erase(it);
        it--;
    }
}

Struttura::Struttura(int d1, int d2){
    dim.append(d1);
    dim.append(d2);
}

int Struttura::getDimAt(int i) const{
    return dim.at(i);
}

void Struttura::setDimAt(int pos, int v){
    dim[pos]=v;
}

void Struttura::setId(int i) {
    id=i;
}

int Struttura::getId()const{
    return id;
}
