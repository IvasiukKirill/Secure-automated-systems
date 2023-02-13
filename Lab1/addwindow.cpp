#include "addwindow.h"
#include "ui_addwindow.h"

#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QDir>

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_pushButton_clicked()
{


    QJsonObject textObject;
    QFile file("C:/Projects/Lab1/values.json");

    if (!file.open(QIODevice::ReadWrite)){
        return;
    }

    QByteArray saveText = file.readAll();
    QJsonDocument jsonDocument(QJsonDocument::fromJson(saveText));
    QJsonObject jsonDoc;
    jsonDoc = jsonDocument.object();
    file.close();

    textObject["site"] = ui->siteLineEdit->text();
    textObject["login"] = ui->loginLineEdit->text();
    textObject["password"] = ui->passwordLineEdit->text();
    QJsonArray textsArray = jsonDoc["texts"].toArray();
    textsArray.append(textObject);

    jsonDoc["texts"] = textsArray;


//    QByteArray jsonData = jsonDoc.toJson(QJsonDocument::Indented);

    if (!file.open(QIODevice::WriteOnly)){
        return;
    }
    file.write(QJsonDocument(jsonDoc).toJson(QJsonDocument::Compact));

    file.close();
    this->close();

}

