QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorization.cpp \
    case1.cpp \
    case2.cpp \
    case3.cpp \
    cases.cpp \
    delete_row.cpp \
    main.cpp \
    mainwindow.cpp \
    registration_window.cpp

HEADERS += \
    authorization.h \
    case1.h \
    case2.h \
    case3.h \
    cases.h \
    delete_row.h \
    mainwindow.h \
    registration_window.h

FORMS += \
    authorization.ui \
    case1.ui \
    case2.ui \
    case3.ui \
    cases.ui \
    delete_row.ui \
    mainwindow.ui \
    registration_window.ui

win32::RC_FILE = File.rc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
