#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT
signals:
   void firstWindow();
public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);


    void on_findButton_clicked();

private:
    Ui::secondwindow *ui;
};



#endif // SECONDWINDOW_H
