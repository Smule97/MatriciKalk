#include "grafica.h"
#include "ui_grafica.h"

#include <QMessageBox>

//#include "matrice.h"

const QString Grafica::style1="background-color: rgb(225,226,227);"
                " border-style: outset;"
                 "border-radius: 25px;"
                "border-width: 3px;"
               "border-color: rgb(240,121,43);"
               "font-size: 20px;"
               "padding: 25px;";

const QString Grafica::style2="background-color: rgb(86,82,83);"
                        " border-style: outset;"
                         "border-radius: 25px;"
                        "border-width: 3px;"
                        "border-color: rgb(253,37,13);"
                       "color: white;"
                       "font-size: 20px;"
                       "padding: 25px;";

Grafica::Grafica(QWidget *parent) :QWidget(parent),ui(new Ui::Grafica){
    ui->setupUi(this);
    p=new QHBoxLayout(this);
    view1=new QVBoxLayout;
    view2=new QVBoxLayout;
    view3=new QVBoxLayout;
    btn=new QGridLayout;
    p->addLayout(view1);
    p->addLayout(btn);
    p->addLayout(view2);
    p->addLayout(view3);

    sommaBtn=new QPushButton("+");
    sommaBtn->setStyleSheet(style1);
    difBtn=new QPushButton("-");
    difBtn->setStyleSheet(style1);
    moltBtn=new QPushButton("*");
    moltBtn->setStyleSheet(style1);
    potBtn=new QPushButton("^");
    potBtn->setStyleSheet(style1);
    ortBtn=new QPushButton("Ortogonale");
    ortBtn->setStyleSheet(style1);
    eraseBtn=new QPushButton("CANCEL");
    eraseBtn->setStyleSheet(style2);
    ugualeBtn=new QPushButton("=");
    ugualeBtn->setStyleSheet(style2);

    btn->addWidget(sommaBtn,0,0);
    connect(sommaBtn, SIGNAL(clicked()),this,SLOT(clickSomma()));
    btn->addWidget(difBtn,0,1);
    connect(difBtn, SIGNAL(clicked()),this,SLOT(clickDiff()));
    btn->addWidget(moltBtn,1,0);
    connect(moltBtn, SIGNAL(clicked()),this,SLOT(clickMolt()));
    btn->addWidget(potBtn,1,1);
    connect(potBtn, SIGNAL(clicked()),this,SLOT(clickPot()));
    btn->addWidget(ortBtn,2,0);
    connect(ortBtn, SIGNAL(clicked()),this,SLOT(clickOrt()));
    btn->addWidget(eraseBtn,3,1);
    connect(eraseBtn, SIGNAL(clicked()),this,SLOT(clickErase()));
    btn->addWidget(ugualeBtn,3,0);
    connect(ugualeBtn, SIGNAL(clicked()),this,SLOT(clickUguale()));

    str1=new QComboBox;
    str1->setStyleSheet("font-size: 20px;");
    view1->addWidget(str1, Qt::AlignTop);
    str1->insertSeparator(0);
    str1->insertItem(1,"Matrice");
    str1->insertItem(2,"Matrice Triangolare superiore");
    str1->insertItem(3,"Matrice Triangolare inferiore");
    str1->insertItem(4,"Matrice unitaria");
    str1->insertItem(5,"Vettore");
    connect(str1, SIGNAL(currentIndexChanged(int)),this,SLOT(creaStruttura1(int)));

    oper='0';
}

Grafica::~Grafica()
{
    delete ui;
}

void Grafica::showSecondView(){
    if(!str2){
        str2=new QComboBox;
        str2->setStyleSheet("font-size: 20px;");
        view2->addWidget(str2,Qt::AlignTop);
        str2->insertSeparator(0);
        str2->insertItem(1,"Matrice");
        str2->insertItem(2,"Matrice Triangolare superiore");
        str2->insertItem(3,"Matrice Triangolare inferiore");
        str2->insertItem(4,"Matrice unitaria");
        str2->insertItem(5,"Vettore");
       connect(str2, SIGNAL(currentIndexChanged(int)),this,SLOT(creaStruttura2(int)));
    }
}

void Grafica::creaStruttura1(int command){
    if(gv1)
        delete gv1;
    if(command==1)
        gv1=new MatriceView(view1,1);
    else if(command==2)
         gv1=new MatriceView(view1,2);
    else if(command==3)
         gv1=new MatriceView(view1,3);
    else if(command==4)
         gv1=new MatriceView(view1,4);
    else  if(command==5)
        gv1=new VettoreView(view1);

}

void Grafica::creaStruttura2(int command){
    if(gv2)
        delete gv2;
    if(command==1)
        gv2=new MatriceView(view2,1);
    else if(command==2)
         gv2=new MatriceView(view2,2);
    else if(command==3)
         gv2=new MatriceView(view2,3);
    else if(command==4)
         gv2=new MatriceView(view2,4);
    else  if(command==5)
        gv2=new VettoreView(view2);
}

void Grafica::clickSomma(){

    if(gv1){
        oper='+';
        showSecondView();
    }
    else
       QMessageBox::warning(this, tr("ERROR"),"Nessun dato inserito");
}

void Grafica::clickDiff(){
    if(gv1){
        oper='-';
        showSecondView();
    }
    else
       QMessageBox::warning(this, tr("ERROR"),"Nessun dato inserito");
}

void Grafica::clickMolt(){
    if(gv1){
        oper='*';
        showSecondView();
    }
    else
       QMessageBox::warning(this, tr("ERROR"),"Nessun dato inserito");
}

void Grafica::clickPot(){
    if(gv2){
        delete gv2;
        gv2=0;
        delete str2;
        str2=0;
    }
    if(gv1){
        oper='^';
        esponente=new QLineEdit(this);
        esponente->setPlaceholderText("0");
        btn->addWidget(esponente,1,3);
    }
    else
       QMessageBox::warning(this, tr("ERROR"),"Nessun dato inserito");
}

void Grafica::clickOrt(){
    if(gv1){
        oper='o';
        clickUguale();
    }
    else
       QMessageBox::warning(this, tr("ERROR"),"Nessun dato inserito");
}

void Grafica::clickUguale(){
    Matrice* mat;
       if(gv3){
           delete gv3;
           gv3=0;
       }
       try {
           if(gv1 && gv2){
                op1=gv1->getStruttura();
                op2=gv2->getStruttura();

                //CASO 1 steso tipo di dato
                if(op1->getId()==op2->getId()){
                    if(oper=='+')
                        op3=op1->somma(op2);
                    else if(oper=='-')
                        op3=op1->differenza(op2);
                    else if(oper=='*')
                        op3=op1->moltiplicazione(op2);
                 }
                //CASO 2 moltiplciazione vettore*matrice o viceversa
                 else if(op1->getId()==4 || op2->getId()==4){
                    if(oper=='*'){
                        if(op1->getId()!=4){
                            mat=static_cast<Matrice*>(op1);
                            op3=mat->moltiplicazioneMV(static_cast<Vettore*>(op2));
                        }
                        else{
                             mat=static_cast<Matrice*>(op2);
                             op3=mat->moltiplicazioneMV(static_cast<Vettore*>(op1));
                        }
                    }
                    else
                        throw Exception("Operazione non consentita.");
                }
                //CASO 3 +/- con una matriceUnitaria
                else if(op1->getId()==3 && (oper=='+' ||oper=='-')){
                    if(oper=='+')
                        op3= op1->somma(op2);
                    else{
                        mat=static_cast<Matrice*>(op1);
                        op3=mat->Matrice::differenza(op2);
                    }
               }
                //CASO 4 tutto il resto viene fatto con i metodi di matrice
              else{
                    mat=static_cast<Matrice*>(op1);
                    if(oper=='+')
                        op3=mat->Matrice::somma(op2);
                    else if(oper=='-')
                        op3=mat->Matrice::differenza(op2);
                    else if(oper=='*')
                        op3=mat->Matrice::moltiplicazione(op2);
             }
           }
           else if(gv1){
               op1=gv1->getStruttura();
               if(oper=='^'){
                   if(esponente){
                        op3=op1->potenza(esponente->text().toDouble());
                        delete esponente;
                        esponente=0;
                   }
                   else
                       throw Exception("Nessun esponente inserito.");

               }
               else if(oper=='o' && op1->getId()!=4){
                    mat=static_cast<Matrice*>(op1);
                    if(mat->ortogonale())
                        QMessageBox::information(this, tr("ORTOGONALE"),"La matrice è ortogonale");
               }
               else
                    throw Exception("Operazione non consentita su questa tipologia di dato");

           }
           else
               throw Exception("Nessun dato inserito.");

           if(op3->getId()!=4)
                  gv3=new MatriceView(view3,static_cast<Matrice*>(op3));
           else
                  gv3=new VettoreView(view3,static_cast<Vettore*>(op3));

       } catch (Exception e) {
             QMessageBox::warning(this, tr("ERRORE"),e.getError());
              clickErase();
       }
}

void Grafica::clickErase(){
    if(str2){
        delete str2;
        str2=0;
    }
    if(gv1){
        delete gv1;
        gv1=0;
        op1=0;
    }
    if(gv2){
        delete gv2;
        gv2=0;
        op2=0;
    }
    if(gv3){
        delete gv3;
        gv3=0;
        op3=0;
    }

}