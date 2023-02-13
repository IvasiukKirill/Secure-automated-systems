#include "wrongaccess.h"
#include "ui_wrongaccess.h"

WrongAccess::WrongAccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WrongAccess)
{
    ui->setupUi(this);
}

WrongAccess::~WrongAccess()
{
    delete ui;
}
