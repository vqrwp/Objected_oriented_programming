#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "Лифт находится на первом этаже, двери закрыты.\n"
                "Лифт находится в режиме ожидания.";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_cabin_1_clicked()
{
    qDebug() << "В лифте нажали кнопку 1.";
    lift.add_call(1);
}

void MainWindow::on_button_cabin_2_clicked()
{
    qDebug() << "В лифте нажали кнопку 2.";
    lift.add_call(2);
}

void MainWindow::on_button_cabin_3_clicked()
{
    qDebug() << "В лифте нажали кнопку 3.";
    lift.add_call(3);
}

void MainWindow::on_button_cabin_4_clicked()
{
    qDebug() << "В лифте нажали кнопку 4.";
    lift.add_call(4);
}

void MainWindow::on_button_cabin_5_clicked()
{
    qDebug() << "В лифте нажали кнопку 5.";
    lift.add_call(5);
}

void MainWindow::on_button_cabin_6_clicked()
{
    qDebug() << "В лифте нажали кнопку 6.";
    lift.add_call(6);
}

void MainWindow::on_button_cabin_7_clicked()
{
    qDebug() << "В лифте нажали кнопку 7.";
    lift.add_call(7);
}

void MainWindow::on_button_cabin_8_clicked()
{
    qDebug() << "В лифте нажали кнопку 8.";
    lift.add_call(8);
}

void MainWindow::on_button_cabin_9_clicked()
{
    qDebug() << "В лифте нажали кнопку 9.";
    lift.add_call(9);
}

void MainWindow::on_button_cabin_10_clicked()
{
    qDebug() << "В лифте нажали кнопку 10.";
    lift.add_call(10);
}

void MainWindow::on_button_floor_1_clicked()
{
    qDebug() << "На 1 этаже был вызван лифт.";
    lift.add_call(1);
}

void MainWindow::on_button_floor_2_clicked()
{
    qDebug() << "На 2 этаже был вызван лифт.";
    lift.add_call(2);
}

void MainWindow::on_button_floor_3_clicked()
{
    qDebug() << "На 3 этаже был вызван лифт.";
    lift.add_call(3);
}

void MainWindow::on_button_floor_4_clicked()
{
    qDebug() << "На 4 этаже был вызван лифт.";
    lift.add_call(4);
}

void MainWindow::on_button_floor_5_clicked()
{
    qDebug() << "На 5 этаже был вызван лифт.";
    lift.add_call(5);
}

void MainWindow::on_button_floor_6_clicked()
{
    qDebug() << "На 6 этаже был вызван лифт.";
    lift.add_call(6);
}

void MainWindow::on_button_floor_7_clicked()
{
    qDebug() << "На 7 этаже был вызван лифт.";
    lift.add_call(7);
}

void MainWindow::on_button_floor_8_clicked()
{
    qDebug() << "На 8 этаже был вызван лифт.";
    lift.add_call(8);
}

void MainWindow::on_button_floor_9_clicked()
{
    qDebug() << "На 9 этаже был вызван лифт.";
    lift.add_call(9);
}

void MainWindow::on_button_floor_10_clicked()
{
    qDebug() << "На 10 этаже был вызван лифт.";
    lift.add_call(10);
}

