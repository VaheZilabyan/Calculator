#include "angle.h"
#include "ui_angle.h"

Angle::Angle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Angle)
{
    ui->setupUi(this);
    connect(ui->pushButton_0a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_1a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_2a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_3a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_4a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_5a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_6a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_7a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_8a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle
    connect(ui->pushButton_9a, SIGNAL(clicked()), this, SLOT(digitsNumber_angle())); //angle

    connect(ui->pushButton_Ca, SIGNAL(clicked()), this, SLOT(clear_angle())); //angle
    connect(ui->pushButton_backspacea, SIGNAL(clicked()), this, SLOT(clear_angle())); //angle
    connect(ui->comboBox_second, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBox_second(int))); //angle
    connect(ui->comboBox_first, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBox_first())); //angle

    ui->comboBox_second->setPlaceholderText(QStringLiteral("--SELECT--"));
    ui->comboBox_second->setCurrentIndex(-1);
}

void Angle::comboBox_second(int index)
{
    double first = ui->label->text().toDouble();
    if (ui->comboBox_first->currentText() == ui->comboBox_second->currentText()) {
        ui->label_2->setText(ui->label->text());
    }

    if (index == 0) {
        if (ui->comboBox_first->currentText() == "Radians") {
            first = qRadiansToDegrees(first);
        } else if (ui->comboBox_first->currentText() == "--SELECT--") {

        }
    } else if (index == 1) {
        if (ui->comboBox_first->currentText() == "Degrees") {
            first = qDegreesToRadians(first);
        }
    }

    ui->label_2->setText(QString::number(first, 'g', 16));
    setFontSize(ui->label->text());
    setFontSize(ui->label_2->text());
}

void Angle::comboBox_first()
{
    ui->comboBox_second->setCurrentIndex(-1);
}

void Angle::digitsNumber_angle()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    double numbers = (ui->label->text() + button->text()).toDouble();
    QString new_label = QString::number(numbers, 'g', 16);

    if (ui->label->text().contains(".") && button->text() == "0") {
        new_label = ui->label->text() + button->text();
    } else {
        setFontSize(new_label);
    }
    ui->label->setText(new_label);
    setFontSize(new_label);
}

void Angle::setFontSize(const QString& label) {
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

void Angle::clear_angle()
{
    QPushButton *button = static_cast<QPushButton*>(sender());

    if (button->text() == "C" || button->text() == "CE") {
        ui->label->setText("0");
        ui->comboBox_second->setCurrentIndex(-1);
    } else if (!ui->label->text().contains("e")){    // <=
        if (ui->label->text().contains("i")) {
            ui->label->setText("0");
        }
        ui->label->setText(ui->label->text().remove(ui->label->text().length()-1, 1));
        if (ui->label->text().length() == 0) {
            ui->label->setText("0");
            ui->comboBox_second->setCurrentIndex(-1);
        }
    }
    ui->label_2->setText("0");
    setFontSize(ui->label->text());
}

void Angle::on_dot_clicked()
{
    if (!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + '.');
}

void Angle::on_pushButton_plusminus_clicked()
{
    double numbers = (ui->label->text()).toDouble() * (-1);
    QString new_label = QString::number(numbers, 'g', 16);
    ui->label->setText(new_label);
    setFontSize(ui->label->text());
}

Angle::~Angle()
{
    delete ui;
}
