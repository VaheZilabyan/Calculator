#include "promode.h"
#include "ui_mainwindow.h"

#include <QtMath>
#include <QRandomGenerator>

ProMode::ProMode(QWidget *parent)
    : MainWindow(parent)
{
    connect(ui->pushButton_0p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_1p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_2p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_3p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_4p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_5p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_6p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_7p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_8p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro
    connect(ui->pushButton_9p, SIGNAL(clicked()), this, SLOT(digits_number())); //pro

    connect(ui->pushButton_backspacep, SIGNAL(clicked()), this, SLOT(clear()));  //pro
    connect(ui->pushButton_Cp, SIGNAL(clicked()), this, SLOT(clear()));          //pro

    connect(ui->pushButton_divp, SIGNAL(clicked()), this, SLOT(math_operations()));     //pro
    connect(ui->pushButton_mulp, SIGNAL(clicked()), this, SLOT(math_operations()));     //pro
    connect(ui->pushButton_plusp, SIGNAL(clicked()), this, SLOT(math_operations()));    //pro
    connect(ui->pushButton_minusp, SIGNAL(clicked()), this, SLOT(math_operations()));   //pro
    connect(ui->pushButton_xy, SIGNAL(clicked()), this, SLOT(math_operations()));       //pro
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operations()));      //pro

    connect(ui->pushButton_1xp, SIGNAL(clicked()), this, SLOT(operations()));           //pro
    connect(ui->pushButton_plus_minusp, SIGNAL(clicked()), this, SLOT(operations()));   //pro
    connect(ui->pushButton_powp, SIGNAL(clicked()), this, SLOT(operations()));          //pro
    connect(ui->pushButton_sqrtp, SIGNAL(clicked()), this, SLOT(operations()));         //pro
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(operations()));            //pro
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(operations()));           //pro
    connect(ui->pushButton_10x, SIGNAL(clicked()), this, SLOT(operations()));           //pro
    connect(ui->pushButton_factorial, SIGNAL(clicked()), this, SLOT(operations()));     //pro
    connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(operations()));           //pro
    connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(operations()));            //pro
    connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(operations()));             //pro
    connect(ui->pushButton_modul, SIGNAL(clicked()), this, SLOT(operations()));         //pro
    connect(ui->pushButton_2i_x, SIGNAL(clicked()), this, SLOT(operations()));          //pro
    connect(ui->pushButton_pow3, SIGNAL(clicked()), this, SLOT(operations()));          //pro
    connect(ui->pushButton_sqrt3, SIGNAL(clicked()), this, SLOT(operations()));          //pro

    connect(ui->pushButton_dotp, SIGNAL(clicked()), this, SLOT(on_pushButton_dot_clicked()));   //pro
    connect(ui->resultp, SIGNAL(clicked()), this, SLOT(on_result_clicked()));   //pro

    connect(ui->comboBox_trigonometry, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBox_Trigonometry(int)));
    connect(ui->comboBox_functions, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBox_Functions(int)));
    ui->comboBox_trigonometry->setPlaceholderText(QStringLiteral("Trigonometry"));
    ui->comboBox_trigonometry->setCurrentIndex(-1);
    ui->comboBox_functions->setPlaceholderText(QStringLiteral("Functions"));
    ui->comboBox_functions->setCurrentIndex(-1);
}

void ProMode::comboBox_Trigonometry(int index)
{
    if (index == 0) {
        double number = ui->label->text().toDouble();
        ui->history->setText("sin(" + ui->label->text() + ")=");
        ui->label->setText(QString::number(qSin(number * M_PI/180)));
    } else if (index == 1) {
        double number = ui->label->text().toDouble();
        ui->history->setText("cos(" + ui->label->text() + ")=");
        ui->label->setText(QString::number(qCos(number * M_PI/180)));
    } else if (index == 2) {
        double number = ui->label->text().toDouble();
        ui->history->setText("tan(" + ui->label->text() + ")=");
        ui->label->setText(QString::number(qTan(number * M_PI/180)));
    } else if (index == 3) {
        double number = ui->label->text().toDouble();
        ui->history->setText("cot(" + ui->label->text() + ")=");
        ui->label->setText(QString::number(1/qTan(number * M_PI/180)));
    }
}

void ProMode::comboBox_Functions(int index)
{
    if (index == 0) {
        double value = QRandomGenerator::global()->bounded(0, 10000000000);
        ui->history->setText("Random number");
        ui->label->setText(QString::number(value, 'g', 16));
    } else if (index == 1) {
        int value = qFloor(ui->label->text().toDouble());
        ui->history->setText("floor("+ui->label->text() + ")");
        ui->label->setText(QString::number(value, 'g', 16));
    } else if (index == 2) {
        int value = qCeil(ui->label->text().toDouble());
        ui->history->setText("ceil("+ui->label->text() + ")");
        ui->label->setText(QString::number(value, 'g', 16));
    }

    /*if (ui->history->text().contains("Random")) {
        ui->comboBox_functions->setCurrentIndex(-1);
    }*/
}

ProMode::~ProMode()
{
    //delete ui;
}
