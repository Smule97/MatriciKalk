#ifndef MATRICEVIEW_H
#define MATRICEVIEW_H

#include "generalview.h"
#include "matrice.h"
#include "matricetriangolare.h"
#include "matriceunitaria.h"

class MatriceView: public GeneralView{
public:
    MatriceView(QVBoxLayout* v,int id);
    MatriceView(QVBoxLayout* v,Matrice*);
    ~MatriceView();
    Matrice* getStruttura();
    
private slots:
    void addRow();
    void addColumn();
    void minusCells();
private:
    Matrice *m;
    void creaGriglia(int, int);
    int id;
};

#endif // MATRICEVIEW_H
