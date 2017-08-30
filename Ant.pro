TEMPLATE = app

CONFIG += c++11

QT += qml quick

TARGET = Ant

SOURCES += \
    src/main.cpp \
    src/city.cpp \
    src/field.cpp \
    src/ant.cpp \
    src/interaction.cpp

HEADERS += \
    src/city.h \
    src/field.h \
    src/singleton.hpp \
    src/ant.h \
    src/interaction.h

RESOURCES += \
    qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

DEFINES += QT_DEPRECATED_WARNINGS

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
