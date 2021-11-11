//
// Created by twak on 07/10/2019.
//

#include <QWidget>
#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>
#include <QScrollArea>
#include <QDialog>


// you should probably make extensive changes to this function
void ResponsiveLayout::setGeometry(const QRect &r ) { // our layout should fit inside r

    QLayout::setGeometry(r);
    int y_image=r.y()+90;
    int y_text=r.y()+90;

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());

            if (label == NULL) // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            else if (label -> text() == kNavTabs ) // headers go at the top
                label -> setGeometry(0+r.x(),40+r.y(),r.width(), 40);
            // only show a search button on small resolution, at the right of the window
            else if (label -> text() == kSButton  ){


                label->setGeometry(0.7*r.width(),r.y(),0.1*r.width(),40);





            }
            else if (label->text()==kSQuery){

                label -> setGeometry( (r.width()*0.1)+ r.x(),r.y(), 0.6*r.width(), 40);

            }

            else if(label->text()==kShoppingBasket){

                label->setGeometry(0.9*r.width(),r.y(),0.1*r.width(),40);

            }

            else if(label->text()==kSignIn){
                label->setGeometry(0.8*r.width(),r.y(),0.5*r.width(),40);
            }
            // fixme: the focus-group did not like this behaviour for the search result element.
            else if (label -> text() == kSResultImage ){


                label->setGeometry(r.x(),y_image,0.1*r.width(),0.1*r.width());


                y_image+=2*0.1*r.width();













                /*QScrollArea *scrollArea = new QScrollArea(widget_one);
                scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
          return QSize(320,320);               scrollArea->setWidgetResizable( true );
                 scrollArea->setGeometry( 10, 10, 200, 200 );*/

                /*QWidget *widget = new QWidget();
                 //scrollArea->setWidget( widget );



                 QVBoxLayout *layout = new QVBoxLayout();
                widget->setLayout( layout );

                 for (int i = 0; i < 10; i++)
                 {
                     ResponsiveLabel *button=new ResponsiveLabel(kSResultImage);
                     layout->addWidget( button );

                 }*/



            }


            else if (label->text()==kSResultText){


                label->setGeometry(r.x()+0.4*r.width(),y_text,0.1*r.width(),0.1*r.height());



                y_text+=2*0.1*r.width();










            }


            else // otherwise: disappear label by moving out of bounds
                label -> setGeometry (-1,-1,0,0);

        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }

        parentWidget()->parentWidget()->adjustSize();
    }
}

// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {

    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {

    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {

    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {

    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    int height = 0;
    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);
        height += o->sizeHint().height();
    }
    return QSize(320,height);
}

    QSize ResponsiveLayout::minimumSize() const {

        return QSize(320,320);
    }

    ResponsiveLayout::~ResponsiveLayout() {

        QLayoutItem *item;
        while ((item = takeAt(0)))
            delete item;
    }
