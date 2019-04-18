#ifndef STRUTTURA_H
#define STRUTTURA_H

#include "exception.h"
#include <QString>
#include <QVector>
#include <cstdlib>
#include <QtCore>


class Struttura{
private:
    QVector<int> dim;
    int id=0;
protected:
    void setId(int);
public:
    Struttura(int*, int);
    Struttura(int=0, int=0);
    virtual ~Struttura();
    int getDimAt(int) const;
    int getId()const ;
    void setDimAt(int, int);

    virtual Struttura* somma(Struttura* mat) const=0;
    virtual Struttura* differenza(Struttura* mat) const=0;
    virtual Struttura* moltiplicazione(Struttura* mat) const=0;
    virtual Struttura* potenza(int exp) const=0;
};

#endif // STRUTTURA_H
