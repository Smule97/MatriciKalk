#ifndef GENERALVIEW_H
#define GENERALVIEW_H

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QWidget>

#include "struttura.h"

class GeneralView : public QWidget
{
    Q_OBJECT
public:
    explicit GeneralView(QVBoxLayout*&v);
    virtual ~GeneralView();
    virtual Struttura* getStruttura()=0;
    static const QFont font;
    static const QString style;
private slots:
    virtual void addRow()=0;
    virtual void addColumn()=0;
    virtual void minusCells()=0;

private:
    QVBoxLayout *view;


protected:
    QHBoxLayout *supView;
    QVector<QLineEdit*> cont;
    QVector<QLabel*> contLabel;
    QGridLayout *g;
    QPushButton *add=0;
    QPushButton *add2=0;
    QPushButton *minus=0;
    void cancellaGriglia();

};

#endif // GENERALVIEW_H
