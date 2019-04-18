#include "matriceview.h"

/*
 * ID=1 Matrice
 * ID=2 MatriceTriangolare Sup
 * ID=3 MatriceTriangolare Inf
 * ID=4 MatriceUnitaira
 * */

MatriceView::MatriceView(QVBoxLayout* v, int i): GeneralView(v),id(i){
    if(id==1){
        add=new QPushButton("Add row");
        add->setStyleSheet(style);
        add2=new QPushButton("Add column");
        add2->setStyleSheet(style);
        minus=new QPushButton("-");
        minus->setStyleSheet(style);
        supView->addWidget(add);
        supView->addWidget(add2);
        supView->addWidget(minus);
        connect(add2, SIGNAL(clicked()), SLOT(addColumn()));
        m=new Matrice(0,3,3);
    }
    else{
        add=new QPushButton("+");
        add->setStyleSheet(style);
        minus=new QPushButton("-");
        minus->setStyleSheet(style);
        supView->addWidget(add);
        supView->addWidget(minus);
        if(id==2)
            m=new MatriceTriangolare(0,'s',3);
        else if(id==3)
            m=new MatriceTriangolare(0,'i',3);
        else
            m=new MatriceUnitaria(0,3);
    }
    connect(add, SIGNAL(clicked()), SLOT(addRow()));
    connect(minus, SIGNAL(clicked()), SLOT(minusCells()));

    creaGriglia(3,3);
}

MatriceView::MatriceView(QVBoxLayout* v, Matrice* mat): GeneralView(v), m(mat){
    for(int i=0; i<m->getDimAt(0); i++){
        for(int j=0; j<m->getDimAt(1); j++){
			QString val = QString::number(m->getValue(i,j));
			contLabel.append(new QLabel(val));
			contLabel.at(i*m->getDimAt(1)+j)->setFont(font);
			g->addWidget(contLabel.at(i*m->getDimAt(1)+j), i, j);
        }
    }
}

Matrice* MatriceView::getStruttura(){
    double* val=new double[cont.count()];
    for(int i=0; i<cont.count(); i++){
        if(cont.at(i)->text()=="")
			val[i]=0;
        else
            val[i]=cont.at(i)->text().toDouble();
    }
    m->insertValue(val);
    return m;
}

void MatriceView::addRow(){
    cancellaGriglia();
    if(id==1)
        m->setDimAt(0,m->getDimAt(0)+1);
    else{
        m->setDimAt(0,m->getDimAt(0)+1);
        m->setDimAt(1,m->getDimAt(1)+1);
    }
    creaGriglia(m->getDimAt(0),m->getDimAt(1));
}

void MatriceView::addColumn(){
    cancellaGriglia();
    m->setDimAt(1,m->getDimAt(1)+1);
    creaGriglia(m->getDimAt(0),m->getDimAt(1));
}

void MatriceView::minusCells(){
    if(m->getDimAt(0)>1 && m->getDimAt(1)>1){
        GeneralView::cancellaGriglia();
        m->setDimAt(0,m->getDimAt(0)-1);
        m->setDimAt(1,m->getDimAt(1)-1);
        creaGriglia(m->getDimAt(0),m->getDimAt(1));
     }
}

void MatriceView::creaGriglia(int d1,int d2){
    for(int i=0; i<d1*d2; i++){
        cont.append(new QLineEdit(""));
        cont.at(i)->setPlaceholderText("0");
        cont.at(i)->setStyleSheet("font-size: 20px;");
    }
    
    if(id==2){
       int p=d1;
       for(int i=0; i<d1; i++){
		    for(int j=0; j<d2-p; j++){
				cont.at(i*d1+j)->setEnabled(false);
			}
			p--;
       }
    }
    else if(id==3){
        int p=1;
        for(int i=0; i<d1; i++){
            for(int j=p; j<d2; j++){
               cont.at(i*d1+j)->setEnabled(false);
            }
            p++;
        }
    }
    else if(id==4){
        for(int i=0; i<d1; i++){
            for(int j=0; j<d2; j++){
                if(i!=j)
                   cont.at(i*d1+j)->setEnabled(false);
            }
        }
    }


    for(int p=0; p<d1;p++){
        for(int j=0; j<d2;j++)
            g->addWidget(cont.at(p*d2+j), p, j);
    }

}

MatriceView::~MatriceView(){
    delete m;
    cancellaGriglia();
    if(id==1)
       delete add2;
}


