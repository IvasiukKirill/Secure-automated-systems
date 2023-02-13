#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "QMessageBox"
#include <QPixmap>
#include "secondwindow.h"
#include "wrongaccess.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QPixmap pix(":/resources/img/home.png");
            int w = ui->image->width();
            int h = ui->image->height();

            ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    second = new secondwindow();
    connect(second,&secondwindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString password = ui->pass->text();


    if(password == "test"){
        ui->statusbar->showMessage("Вы успешно авторизовались!");
        second->show();
        this->close();


    } else {
        ui->statusbar->showMessage("Вы не успешно авторизовались");
        WrongAccess wrong;
        wrong.setModal(true);
        wrong.exec();

    }


}


