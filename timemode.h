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
    void clear_timeMode();
    void digitsNumber_timeMode();
    void on_answer_clicked();
    void on_dot_clicked();
private:
    Ui::TimeMode *ui;
};

#endif // TIMEMODE_H
