#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QtMath>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_main->insertWidget(1, &time);

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(aboutClicked()));
    connect(ui->actionProfessional, SIGNAL(triggered()), this, SLOT(Professionalclicked()));
    connect(ui->actionStandard, SIGNAL(triggered()), this, SLOT(Standardclicked()));
    connect(ui->actionTime, SIGNAL(triggered()), this, SLOT(Timeclicked()));

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_number()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_number()));

    connect(ui->pushButton_backspace, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->pushButton_CE, SIGNAL(clicked()), this, SLOT(clear()));

    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));

    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_1x, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(operations()));

    ui->actionStandard->setCheckable(true);
    ui->actionProfessional->setCheckable(true);
    ui->actionTime->setCheckable(true);
}

void MainWindow::aboutClicked()
{
    QMessageBox::information(this, "About", "Calculator v1.0.0\n© 2022 Synopsys. All rights reserved.");
}

void MainWindow::Standardclicked()
{
    ui->label->setText("0");
    ui->history->setText("");
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);
    ui->actionStandard->setChecked(true);
    ui->actionProfessional->setChecked(false);
    ui->actionTime->setChecked(false);
}

void MainWindow::Professionalclicked()
{
    ui->label->setText("0");
    ui->history->setText("");
    ui->stackedWidget_main->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    ui->actionProfessional->setChecked(true);
    ui->actionStandard->setChecked(false);
    ui->actionTime->setChecked(false);
}

void MainWindow::Timeclicked()
{
    ui->label->setText("0");
    ui->history->setText("");
    ui->stackedWidget_main->setCurrentIndex(1);
    ui->actionTime->setChecked(true);
    ui->actionStandard->setChecked(false);
    ui->actionProfessional->setChecked(false);
}

void MainWindow::setFontSize(const QString& label) {
    if (label.length() < 10) {
        ui->label->setFont(QFont("Arial", 30));
    } else if (label.length() >= 10 && label.length() <= 14) {
        ui->label->setFont(QFont("Arial", 22));
    } else {
        ui->label->setFont(QFont("Arial", 18));
    }
}

unsigned int MainWindow::factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

void MainWindow::math_operations()
{
    button = static_cast<QPushButton*>(sender());
    if (!ui->history->text().isEmpty() && !ui->history->text().contains("=") && !ui->label->text().isEmpty()) { // erb anyndhat + enq nshum
        math = static_cast<QPushButton*>(sender());
        QString str = ui->history->text();
        QStringList tokens = str.split(button->text());
        QString first = tokens[0];

        double temp_answer = 0.0;
        if (button->text() == "+") {
            temp_answer = first.toDouble() + ui->label->text().toDouble();
        } else if (button->text() == "-") {
            temp_answer = first.toDouble() - ui->label->text().toDouble();
        } else if (button->text() == "*") {
            temp_answer = first.toDouble() * ui->label->text().toDouble();
        } else if (button->text() == "÷") {
            temp_answer = first.toDouble() / ui->label->text().toDouble();
        } else if (button->text() == "^") {
            temp_answer = pow(first.toDouble(), ui->label->text().toDouble());
        }
        ui->history->setText(QString::number(temp_answer, 'g', 16) + button->text());
        ui->label->setText("");
        sec_time = true;
    } else if (!ui->history->text().isEmpty() && ui->label->text().isEmpty()) {     //ete +ic heto dnum enq - kam *
        math = static_cast<QPushButton*>(sender());
        ui->history->setText(ui->history->text().remove(ui->history->text().length()-1, 1));
        ui->history->setText(ui->history->text() + button->text());
    } else {    // sovorakan gorcoxutyun,
        first_number = ui->label->text().toDouble();
        ui->history->setText(ui->label->text() + button->text());
        ui->label->setText("");
        sec_time = false;
    }
}

void MainWindow::on_result_clicked()
{
    if (ui->history->text().contains("/") || ui->history->text().contains("(")) {   //fix bug
        ui->history->setText("");
    } else if (!ui->history->text().contains("=")) {
        if (sec_time == true) {         // erb anyndhat +ic heto sexmum enq =
            QString str = ui->history->text();
            QStringList tokens = str.split(math->text());
            QString first = tokens[0];

            double temp_answer = 0.0;
            if (math->text() == "+") {
                temp_answer = first.toDouble() + ui->label->text().toDouble();
            } else if (math->text() == "-") {
                temp_answer = first.toDouble() - ui->label->text().toDouble();
            } else if (math->text() == "*") {
                temp_answer = first.toDouble() * ui->label->text().toDouble();
            } else if (math->text() == "÷") {
                temp_answer = first.toDouble() / ui->label->text().toDouble();
            }  else if (math->text() == "^") {
                temp_answer = pow(first.toDouble(), ui->label->text().toDouble());
            }
            ui->label->setText((QString::number(temp_answer, 'g', 16)));
            ui->history->setText("");

        } else {  // sovorakan erb 5 + 3 = 8
            if (ui->label->text() != "0" && ui->history->text() != "") {
                ui->history->setText(ui->history->text() + ui->label->text() + " =");
                second_number = ui->label->text().toDouble();
                if (button->text() == "+") {
                    answer = first_number + second_number;
                } else if (button->text() == "-") {
                    answer = first_number - second_number;
                } else if (button->text() == "*") {
                    answer = first_number * second_number;
                } else if (button->text() == "÷") {
                    answer = first_number / second_number;
                } else if (button->text() == "^") {
                    answer = pow(first_number, second_number);
                } else if (button->text() == "mod") {
                    answer = static_cast<int>(first_number) % static_cast<int>(second_number);
                }
                ui->label->setText(QString::number(answer, 'g', 16));
            }
        }
    } else {    // erb 5+3ic heto anyndhat = enq dnum 8+3, 11+3 ...
        ui->history->setText(QString::number(answer, 'g', 16) + button->text() + QString::number(second_number, 'g', 12) + " =");
        if (button->text() == "+") {
            answer = answer + second_number;
        } else if (button->text() == "-") {
            answer = answer - second_number;
        } else if (button->text() == "*") {
            answer = answer * second_number;
        } else if (button->text() == "÷") {
            answer = answer / second_number;
        } else if (button->text() == "^") {
            answer = pow(answer, second_number);
        }
        setFontSize(QString::number(answer, 'g', 16));
        ui->label->setText(QString::number(answer, 'g', 16));
    }
    setFontSize(ui->label->text());
    ui->comboBox_trigonometry->setCurrentIndex(-1);
    ui->comboBox_functions->setCurrentIndex(-1);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + '.');
}

void MainWindow::digits_number()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double numbers = (ui->label->text()+ button->text()).toDouble();
    QString new_label = QString::number(numbers, 'g', 16);

    if (ui->label->text().contains(".") && button->text() == "0") {
        new_label = ui->label->text() + button->text();
    } else {
        setFontSize(new_label);
    }
    ui->label->setText(new_label);
    setFontSize(new_label);
}

void MainWindow::operations()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    QString new_label;
    double numbers = 0.0;

    if (button->text() == "+/-") {
        numbers = (ui->label->text()).toDouble();
        numbers *= -1;
    } else if (button->text() == "%") {
        numbers = (ui->label->text()).toDouble();
        ui->history->setText(ui->label->text() + "/100");
        numbers *= 0.01;
    } else if (button->text() == "1/x") {
        numbers = (ui->label->text()).toDouble();
        ui->history->setText("1/" + ui->label->text());
        numbers = 1 / numbers;
    } else if (button->text() == "x^2") {
        numbers = (ui->label->text()).toDouble();
        ui->history->setText("pow(" + ui->label->text() +")");
        numbers *= numbers;
    } else if (button->text() == "√x") {
        numbers = (ui->label->text()).toDouble();
        ui->history->setText("sqrt(" + ui->label->text() + ")");
        numbers = sqrt(numbers);
    }
    new_label = QString::number(numbers, 'g', 16);
    setFontSize(new_label);
    ui->label->setText(new_label);
}

void MainWindow::clear()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    if (button->text() == "C" || button->text() == "CE") {
        ui->label->setText("0");
        ui->history->setText("");
        ui->comboBox_trigonometry->setCurrentIndex(-1);
        ui->comboBox_functions->setCurrentIndex(-1);
    } else if (!ui->label->text().contains("e")){    // <=
        if (ui->label->text().contains("n")) {
            ui->label->setText("0");
        }
        ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
        if (ui->label->text().length() == 0) {
            ui->label->setText("0");
            ui->comboBox_trigonometry->setCurrentIndex(-1);
            ui->comboBox_functions->setCurrentIndex(-1);
        }
    }
    setFontSize(ui->label->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}
