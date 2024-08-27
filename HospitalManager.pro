TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Controllers/controller.cpp \
        Controllers/covidtestcontroller.cpp \
        Controllers/patientcontroller.cpp \
        UI/menu.cpp \
        UI/uidoctormenu.cpp \
        UI/uipatientmenu.cpp \
        main.cpp \
        models/covidtest.cpp \
        models/doctor.cpp \
        models/patient.cpp \
        models/user.cpp \
        shared/validacion.cpp

HEADERS += \
         Controllers/controller.h \
         Controllers/covidtestcontroller.h \
         Controllers/patientcontroller.h \
         UI/menu.h \
         UI/uidoctormenu.h \
         UI/uipatientmenu.h \
         models/covidtest.h \
         models/doctor.h \
         models/patient.h \
         models/user.h \
         shared/validacion.h
