#ifndef WRONGACCESS_H
#define WRONGACCESS_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class WrongAccess;
}

class WrongAccess : public QDialog
{
    Q_OBJECT

public:
    explicit WrongAccess(QWidget *parent = nullptr);
    ~WrongAccess();

private:
    Ui::WrongAccess *ui;
};

#endif // WRONGACCESS_H
