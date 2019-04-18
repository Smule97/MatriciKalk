#ifndef GRAFICA_H
#define GRAFICA_H

#include "matriceview.h"
#include "vettoreview.h"
#include "matricetriangolare.h"
#include "exception.h"

#include <QWidget>

#include <QComboBox>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>



namespace Ui {
class Grafica;
}

class Grafica : public QWidget
{
    Q_OBJECT

public:
    explicit Grafica(QWidget *parent = 0);
    ~Grafica();
    const static QString style1;
    const static QString style2;

private slots:
    void creaStruttura1(int);
    void creaStruttura2(int);
    void clickUguale();
    void clickSomma();
    void clickDiff();
    void clickMolt();
    void clickPot();
    void clickOrt();
    void clickErase();

private:
    void showSecondView();

    Ui::Grafica *ui;
    QHBoxLayout *p;
    QVBoxLayout *view1;
    QVBoxLayout *view2;
    QVBoxLayout *view3;
    QGridLayout *btn;
    QComboBox *str1=0;
    QComboBox *str2=0;

    QPushButton *sommaBtn;
    QPushButton *difBtn;
    QPushButton *moltBtn;
    QPushButton *potBtn;
    QPushButton *ortBtn;
    QPushButton *eraseBtn;
    QPushButton *ugualeBtn;

    QLineEdit* esponente;

    GeneralView* gv1=0;
    GeneralView* gv2=0;
    GeneralView* gv3=0;
    Struttura* op1=0;
    Struttura* op2=0;
    Struttura* op3=0;
    char oper;
};

#endif // GRAFICA_H
