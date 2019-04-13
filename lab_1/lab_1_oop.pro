#-------------------------------------------------
#
# Project created by QtCreator 2019-03-31T14:44:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_1_oop
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    error_messages.cpp \
    frame.cpp \
    turn_xyz.cpp \
    grafics.cpp \
    scale.cpp \
    read_one_node.cpp \
    read_array_nodes.cpp \
    check_array_nodes.cpp \
    transfer.cpp \
    read_from_file.cpp \
    draw_line.cpp \
    my_scanf.cpp \
    draw.cpp \
    check_len.cpp \
    points.cpp \
    turn_by_coords.cpp \
    entering_point.cpp

HEADERS += \
        mainwindow.h \
    error_codes.h \
    error_messages.h \
    points_and_edges.h \
    frame.h \
    turn_xyz.h \
    grafics.h \
    scale.h \
    read_one_node.h \
    read_array_nodes.h \
    check_array_nodes.h \
    transfer.h \
    read_from_file.h \
    draw_line.h \
    my_scanf.h \
    draw.h \
    check_len.h \
    points.h \
    turn_by_coords.h \
    entering_point.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    coub_1.txt \
    coub_3.txt
