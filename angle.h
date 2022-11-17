#ifndef ANGLE_H
#define ANGLE_H

#include <QWidget>

namespace Ui {
class Angle;
}

class Angle : public QWidget
{
    Q_OBJECT

public:
    explicit Angle(QWidget *parent = nullptr);
    ~Angle();

private:
    void setFontSize(const QString&);
private slots:
    void clear_angle();
    void digitsNumber_angle();
    void on_dot_clicked();
    void on_pushButton_plusminus_clicked();
    void comboBox_second(int index);
    void comboBox_first();

private:
    Ui::Angle *ui;
};

#endif // ANGLE_H

