#ifndef TIMEMODE_H
#define TIMEMODE_H

#include <QWidget>

namespace Ui {
class TimeMode;
}

class TimeMode : public QWidget
{
    Q_OBJECT

public:
    explicit TimeMode(QWidget *parent = nullptr);
    ~TimeMode();
private:
    void setFontSize(const QString&);
private slots:
    void clear();
    void digits_number();
    void on_answer_clicked();
    void on_pushButton_dott_clicked();

public:
    Ui::TimeMode *ui;
};

#endif // TIMEMODE_H
