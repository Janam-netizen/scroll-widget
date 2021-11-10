QT += core gui widgets

CONFIG += c++11

SOURCES += \
          
           
    responsive_label.cpp \
    responsive_layout.cpp \
           
            main.cpp

# Default rules for deployment.

qnx: target.path = /tmp/$${TARGET}/bin

else: unix:!android: target.path = /opt/$${TARGET}/bin

!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    asdf.qrc

HEADERS += \
    responsive_label.h \
    responsive_layout.h

