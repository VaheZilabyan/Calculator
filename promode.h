#ifndef PROMODE_H
#define PROMODE_H

#include "mainwindow.h"

class ProMode : public MainWindow
{
    Q_OBJECT

public:
    ProMode(ProMode &other) = delete;
    void operator=(const ProMode &) = delete;
    static ProMode *GetInstance();
    ~ProMode();
protected:
    ProMode(QWidget *parent = nullptr);
    static ProMode* instance_;
private slots:
    void comboBox_Trigonometry(int index);
    void comboBox_Functions(int index);
    void operations_pro();
};
#endif // PROMODE_H
