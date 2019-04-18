#include "vettoreview.h"

VettoreView::VettoreView(QVBoxLayout* v):GeneralView(v){
    add=new QPushButton("+");
    add->setStyleSheet(style);
    minus=new QPushButton("-");
    minus->setStyleSheet(style);
    supView->addWidget(add);
    supView->addWidget(minus);
    creaGriglia(3);
    connect(add, SIGNAL(clicked()), SLOT(addRow()));
    connect(minus, SIGNAL(clicked()), SLOT(minusCells()));
    vect=new Vettore(0,3);
}

VettoreView::VettoreView(QVBoxLayout* v, Vettore* vt):GeneralView(v), vect(vt){
    for(int j=0; j<vect->getDimAt(0); j++){
       QString val = QString::number(vect->getValue(j));
       contLabel.append(new QLabel(val));
       contLabel.at(j)->setFont(font);
       g->addWidget(contLabel.at(j), j, 0);
    }
}

VettoreView::~VettoreView(){
    delete vect;
    cancellaGriglia();
}

Vettore* VettoreView::getStruttura(){
    double* val=new double[cont.count()];
    for(int i=0; i<cont.count(); i++)
        val[i]=cont.at(i)->text().toDouble();
    vect->insertValue(val);
    return vect;
}

void VettoreView::addRow(){
    cancellaGriglia();
    vect->setDimAt(0,vect->getDimAt(0)+1);
    creaGriglia(vect->getDimAt(0));
}


void VettoreView::minusCells(){
    if(vect->getDimAt(0)>1){
        cancellaGriglia();
        vect->setDimAt(0,vect->getDimAt(0)-1);
        creaGriglia(vect->getDimAt(0));
     }
}

void VettoreView::creaGriglia(int d1){
    for(int i=0; i<d1; i++){
        cont.append(new QLineEdit(""));
        cont.at(i)->setPlaceholderText("0");
        cont.at(i)->setStyleSheet("font-size: 20px;");
        g->addWidget(cont.at(i), i, 0);
    }
}

void VettoreView::addColumn(){}
