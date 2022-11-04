#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

protected:
    Ui::MainWindow *ui;
    QPushButton *button;
    QPushButton *math;  //ogtagorcvum e erb yntacqum poxum enq nshany
    bool sec_time = false;
    double first_number;
    double second_number;
    double answer;
    void setFontSize(const QString&);
    unsigned int factorial(unsigned int);

protected slots:
    void about_clicked();
    void Professionalclicked();
    void Standardclicked();
    void Timeclicked();
    void digits_number();
    void on_pushButton_dot_clicked();
    void operations();
    void math_operations();
    void clear();
    void on_result_clicked();
};
#endif // MAINWINDOW_H
