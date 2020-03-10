QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_alg.cpp \
    dialog_alg_2.cpp \
    dialog_alg_3.cpp \
    dialog_contact.cpp \
    dialog_invest.cpp \
    dialog_login.cpp \
    dialog_signup.cpp \
    main.cpp \
    mainwindow.cpp \
    prediction.cpp \
    variabile.cpp

HEADERS += \
    dialog_alg.h \
    dialog_alg_2.h \
    dialog_alg_3.h \
    dialog_contact.h \
    dialog_invest.h \
    dialog_login.h \
    dialog_signup.h \
    mainwindow.h \
    variabile.h

FORMS += \
    dialog_alg.ui \
    dialog_alg_2.ui \
    dialog_alg_3.ui \
    dialog_contact.ui \
    dialog_invest.ui \
    dialog_login.ui \
    dialog_signup.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resurse.qrc
