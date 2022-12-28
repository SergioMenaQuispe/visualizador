QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arbolesdialog.cpp \
    colasdialog.cpp \
    graphdialog.cpp \
    hashdialog.cpp \
    kruskaldialog.cpp \
    lineal2dialog.cpp \
    linealdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    pilasdialog.cpp \
    primdialog.cpp \
    sparsedialog.cpp

HEADERS += \
    arbolb.h \
    arbolesdialog.h \
    cola.h \
    colasdialog.h \
    double_linked_list.h \
    grafo.h \
    graphdialog.h \
    hash.h \
    hashdialog.h \
    kruskal.h \
    kruskaldialog.h \
    lineal2dialog.h \
    linealdialog.h \
    listasimple.h \
    mainwindow.h \
    pilas.h \
    pilasdialog.h \
    prim.h \
    primdialog.h \
    sparse.h \
    sparsedialog.h

FORMS += \
    arbolesdialog.ui \
    colasdialog.ui \
    graphdialog.ui \
    hashdialog.ui \
    kruskaldialog.ui \
    lineal2dialog.ui \
    linealdialog.ui \
    mainwindow.ui \
    pilasdialog.ui \
    primdialog.ui \
    sparsedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
