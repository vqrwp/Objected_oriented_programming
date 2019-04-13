#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entering_point.h"
#include "error_messages.h"
#include "cstdio"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    arguments args;
    args.act = QUIT;
    enter_point(args);
    delete ui;
}

void MainWindow::on_But_Load_clicked()
{
    arguments args;
    args.act = LOAD_FILE;
    loading_file File_Name;

    QByteArray byte_array = ui->Line_File->text().toLocal8Bit();
    File_Name.filename = byte_array.data();
    args.load_file = File_Name;
    errors err = (errors)enter_point(args);
    if (err)
    {
        error_messages(err);
    }
    else
    {
        drawing draw;
        draw.gV = ui->graphicsView;
        draw.height = ui->graphicsView->height();
        draw.width = ui->graphicsView->width();
        draw.length = 800;

        args.act = DRAW;
        args.draw = draw;
        draw.gV->setSceneRect(560,470,1,1);
        err = (errors) enter_point(args);
        if (err)
        {
            error_messages(err);
        }
    }
}

void MainWindow::on_Scaling_clicked()
{
    arguments args;
    args.act = SCALE;
    scaling scale;
    scale.scale = ui->doubleSpinBox->value();
    args.scale = scale;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;


    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_But_clockwise_clicked()
{
    arguments args;
    args.act = Z_TURN;

    turning turn;
    turn.angle = -(ui->angle->value());
    args.turn = turn;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;

    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}


void MainWindow::on_But_anticlockwise_clicked()
{
    arguments args;
    args.act = Z_TURN;

    turning turn;
    turn.angle = ui->angle->value();
    args.turn = turn;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;

    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_But_Left_clicked()
{
    arguments args;
    args.act = Y_TURN;

    turning turn;
    turn.angle = -(ui->angle->value());
    args.turn = turn;
    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;
    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_But_Right_clicked()
{
    arguments args;
    args.act = Y_TURN;

    turning turn;
    turn.angle = ui->angle->value();
    args.turn = turn;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;

    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_But_Down_clicked()
{
    arguments args;
    args.act = X_TURN;

    turning turn;
    turn.angle = ui->angle->value();
    args.turn = turn;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;

    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_But_Up_clicked()
{
    arguments args;
    args.act = X_TURN;

    turning turn;
    turn.angle = -(ui->angle->value());
    args.turn = turn;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;

    args.act = DRAW;
    args.draw = draw;

    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}

void MainWindow::on_Transfer_clicked()
{
    arguments args;
    args.act = SCALE;
    scaling scale;
    scale.scale = 1 + ui->doubleSpinBox_4->value()/100;
    args.scale = scale;

    errors err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }

    args.act = TRANSFER;
    transfering transfer;
    transfer.x = ui->doubleSpinBox_2->value();
    transfer.y = -(ui->doubleSpinBox_3->value());
    transfer.z = ui->doubleSpinBox_4->value();
    args.transfer = transfer;
    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
    drawing draw;
    draw.gV = ui->graphicsView;
    draw.height = ui->graphicsView->height();
    draw.width = ui->graphicsView->width();
    draw.length = 800;
    args.act = DRAW;
    args.draw = draw;
    err = (errors) enter_point(args);
    if (err)
    {
        error_messages(err);
    }
}
