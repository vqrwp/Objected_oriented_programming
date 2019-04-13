#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_But_Load_clicked();

    void on_Scaling_clicked();

    void on_But_clockwise_clicked();

    void on_But_Up_clicked();

    void on_But_anticlockwise_clicked();

    void on_But_Left_clicked();

    void on_But_Right_clicked();

    void on_But_Down_clicked();

    void on_Transfer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
