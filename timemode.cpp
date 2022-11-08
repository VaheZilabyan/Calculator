#include "timemode.h"
#include "ui_timemode.h"

TimeMode::TimeMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeMode)
{
    ui->setupUi(this);
    connect(ui->pushButton_0t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_1t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_2t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_3t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_4t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_5t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_6t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_7t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_8t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time
    connect(ui->pushButton_9t, SIGNAL(clicked()), this, SLOT(digitsNumber_timeMode())); //time

    connect(ui->pushButton_Ct, SIGNAL(clicked()), this, SLOT(clear_timeMode())); //time
    connect(ui->pushButton_backspacet, SIGNAL(clicked()), this, SLOT(clear_timeMode())); //time
}

void TimeMode::digitsNumber_timeMode()
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

void TimeMode::setFontSize(const QString& label) {
    if (label.length() < 10) {
        ui->label->setFont(QFont("Arial", 30));
        ui->label_2->setFont(QFont("Arial", 30));
    } else if (label.length() >= 10 && label.length() <= 14) {
        ui->label->setFont(QFont("Arial", 22));
        ui->label_2->setFont(QFont("Arial", 22));
    } else {
        ui->label->setFont(QFont("Arial", 18));
        ui->label_2->setFont(QFont("Arial", 18));
    }
}

void TimeMode::clear_timeMode()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    if (button->text() == "C" || button->text() == "CE") {
        ui->label->setFont(QFont("Arial", 28));
        ui->label->setText("0");
        ui->label_2->setText("");
    } else if (!ui->label->text().contains("e")){    // <=
        if (ui->label->text().indexOf('i') != -1) {
            ui->label->setText("0");
        }
        ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
        setFontSize(ui->label->text());
        if (ui->label->text().length() == 0) {
            ui->label->setText("0");
        }
    }
}

void TimeMode::on_answer_clicked()
{
    double first = ui->label->text().toDouble();

    if (ui->comboBox_first->currentText() == ui->comboBox_second->currentText()) {
        ui->label_2->setText(ui->label->text());
    }

    if (ui->comboBox_first->currentText() == "Microseconds") {
        if (ui->comboBox_second->currentText() == "Milliseconds") {
            first /= pow(10, 3);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first /= pow(10, 6);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first /= pow(10, 7) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first /= pow(10, 9) * 3.6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first /= pow(10, 10) * 8.64;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= pow(10, 11) * 6.048;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
        else if (ui->comboBox_second->currentText() == "Years") {
             first /= pow(10, 13) * 3.154;
             ui->label_2->setText(QString::number(first, 'g', 16));
             setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Milliseconds") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 3);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first /= pow(10, 3);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first /= pow(10, 4) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first /= pow(10, 6) * 3.6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first /= pow(10, 7) * 8.64;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= pow(10, 8) * 6.048;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
        else if (ui->comboBox_second->currentText() == "Years") {
             first /= pow(10, 10) * 3.154;
             ui->label_2->setText(QString::number(first, 'g', 16));
             setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Seconds") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 6);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 3);
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first /= pow(10, 1) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first /= pow(10, 3) * 3.6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first /= pow(10, 4) * 8.64;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= pow(10, 5) * 6.048;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
        else if (ui->comboBox_second->currentText() == "Years") {
             first /= pow(10, 7) * 3.154;
             ui->label_2->setText(QString::number(first, 'g', 16));
             setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Minutes") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 7) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 4) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first *= pow(10, 1) * 6;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first /= 60;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first /= 1440;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= 10080;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Years") {
            first /= 525600;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Hours") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 8) * 36;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 5) * 36;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first *= pow(10, 2) * 36;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first *= 60;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first /= 24;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= 168;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
        else if (ui->comboBox_second->currentText() == "Years") {
            first /= 8760;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Days") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 10) * 8.64;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 7) * 8.64;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first *= 86400;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first *= 1440;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first *= 24;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
            first /= 7;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
        else if (ui->comboBox_second->currentText() == "Years") {
            first /= 365;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Weeks") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 11) *  6.048;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 8) * 6.048;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first *= 604800;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first *= 10080;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first *= 168;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first *= 7;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Years") {
             first /= 52.143;
             ui->label_2->setText(QString::number(first, 'g', 16));
             setFontSize(ui->label_2->text());
        }
    } else if (ui->comboBox_first->currentText() == "Years") {
        if (ui->comboBox_second->currentText() == "Microseconds") {
            first *= pow(10, 13) *  3.154;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Milliseconds") {
            first *= pow(10, 10) * 3.154;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Seconds") {
            first *= pow(10, 7) * 3.154;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Minutes") {
            first *= 525600;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Hours") {
            first *= 8760;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Days") {
            first *= 365;
            ui->label_2->setText(QString::number(first, 'g', 16));
            setFontSize(ui->label_2->text());
        } else if (ui->comboBox_second->currentText() == "Weeks") {
             first *= 52.143;
             ui->label_2->setText(QString::number(first, 'g', 16));
             setFontSize(ui->label_2->text());
        }
    }
}


void TimeMode::on_dot_clicked()
{
    if (!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + '.');
}

TimeMode::~TimeMode()
{
    delete ui;
}
