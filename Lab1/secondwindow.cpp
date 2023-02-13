#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "addwindow.h"

#include <QClipboard>
#include <QMimeData>
#include <QDebug>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QJsonValue>


secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
  AddWindow addpass;
  addpass.setModal(true);
  addpass.exec();

}



void secondwindow::on_tableWidget_cellClicked(int row, int column)
{


   QString text = ui->tableWidget->item(row,column)->data(Qt::UserRole).toString();
   qDebug() << text;
   QApplication::clipboard()->setText(text);
}


void secondwindow::on_findButton_clicked()
{
    QJsonObject textObject;
    QFile file("C:/Projects/Lab1/values.json");

    if (!file.open(QIODevice::ReadWrite))
    {
        return;
    }

    QByteArray saveText = file.readAll();
    QJsonDocument jsonDocument(QJsonDocument::fromJson(saveText));
    QJsonObject jsonDoc;
    jsonDoc = jsonDocument.object();

    //    int n = jsonDoc.value("texts").toArray().count();

        file.close();

        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("site"));
        ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("login"));
        ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("password"));
        for (int r=0 ; r < jsonDoc.value("texts").toArray().count(); r++){
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(jsonDoc.value("texts")[r].toObject().value("site").toString()));
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText("********");
            item->setData(Qt::UserRole, jsonDoc.value("texts")[r].toObject().value("login").toString());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, item );

            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setText("********");
            item2->setData(Qt::UserRole, jsonDoc.value("texts")[r].toObject().value("password").toString());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, item2 );
        }
        for (int var = 0; var < ui->tableWidget->rowCount(); ++var) {
            if(ui->tableWidget->item(var,0)->text().contains(ui->lineEdit->text()) == 0){
                ui->tableWidget->hideRow(var);
            }
        }

}

