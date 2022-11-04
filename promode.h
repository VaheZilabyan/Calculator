#ifndef PROMODE_H
#define PROMODE_H

#include "mainwindow.h"

class ProMode : public MainWindow
{
    Q_OBJECT

public:
    ProMode(QWidget *parent = nullptr);
    ~ProMode();
private slots:
    void comboBox_Trigonometry(int index);
    void comboBox_Functions(int index);
};
#endif // PROMODE_H
