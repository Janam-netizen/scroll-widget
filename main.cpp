#include<QtWidgets>

#include <QTextEdit>

#include <QScrollArea>

#include "responsive_label.h"

#include "responsive_layout.h"



int main(int argc,char*argv[]){


    QApplication app(argc, argv);




  QWidget *r= new QWidget();
   r->setGeometry(500, 500, 900, 900);


    QScrollArea *scrollArea = new QScrollArea(r);
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setWidgetResizable( true );


    scrollArea->setGeometry( 0, 0, 600, 400 );

    QWidget *rl= new QWidget();
    scrollArea->setWidget( rl );


   ResponsiveLayout *layout=new ResponsiveLayout();


   for(int i=0;i<17;i++){


    layout->addWidget(new ResponsiveLabel(kSResultImage));


   }











     //rl->setLayout( layout );

    rl->setLayout(layout);

    r->show();




return app.exec();

}
