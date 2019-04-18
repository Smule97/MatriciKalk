#ifndef VETTOREVIEW_H
#define VETTOREVIEW_H

#include "generalview.h"
#include "vettore.h"


class VettoreView:public GeneralView{
public:
    VettoreView(QVBoxLayout* v);
     VettoreView(QVBoxLayout* v, Vettore*);
    ~VettoreView();
	Vettore* getStruttura();

private slots:
    void addRow();
    void addColumn();
    void minusCells();
private:
    Vettore *vect;
    void creaGriglia(int);
};

#endif // VETTOREVIEW_H
