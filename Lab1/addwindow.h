#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include <QJsonObject>

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

private slots:
     void on_pushButton_clicked();

private:

    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
