#include "generalview.h"
const QFont GeneralView::font( "Arial", 18, QFont::Bold);
const QString GeneralView::style="background-color: rgb(255,13,13);"
                          " border-style: outset;"
                           "border-radius: 25px;"
                          "border-width: 3px;"
                         "color: white;"
                         "font-size: 15px;"
                         "padding: 15px;";
GeneralView::GeneralView(QVBoxLayout*& v): view(v){
    g=new QGridLayout;
    supView=new QHBoxLayout;
    view->addLayout(supView);
    view->addLayout(g);
}

GeneralView::~GeneralView(){
    if(add){
        delete add;
        delete minus;
        delete g;
        delete supView;
    }
}

void GeneralView::cancellaGriglia(){
    for(int i=0; i<cont.count(); i++){
          g->removeWidget(cont.at(i));
          cont.at(i)->deleteLater();
      }
      for(int i=0; i<contLabel.count(); i++){
          g->removeWidget(contLabel.at(i));
          contLabel.at(i)->deleteLater();
      }
         cont.clear();
         contLabel.clear();
}
