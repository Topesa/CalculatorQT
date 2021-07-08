#include "mainwindow.h"
#include "ui_mainwindow.h"

double calValue = 0;
double additionTrigger = false;
double subtractionTrigger = false;
double multiplyTrigger = false;
double divisionTrigger = false;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->display->setText(QString::number(calValue));
    QPushButton *numberButton[10];

   for (unsigned int i = 0; i < (sizeof(numberButton)/sizeof(numberButton[0])); i++)
    {
       QString buttonName = "button" + QString::number(i);
       numberButton[i] = MainWindow::findChild<QPushButton *> (buttonName);
       connect(numberButton[i], SIGNAL(released()), this, SLOT(NumberPressed()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumberPressed()
{
    QPushButton *btn = (QPushButton *) sender();
    QString btnValue = btn->text();
    QString displayValue = ui->display->text();

    if (displayValue.toDouble() == 0 || (displayValue.toDouble() == 0.0))
    {
        ui->display->setText(btnValue);
    }
    else
    {
        QString newValue = displayValue + btnValue;
        double newValueDouble = newValue.toDouble();

        ui->display->setText(QString::number(newValueDouble, 'g', 16));
    }
}

void MainWindow::on_dot_released()
{
        QString txt = ui->display->text();

        if (!txt.contains('.', Qt::CaseSensitive))
        {
            ui->display->setText(txt + ".");
        }
}

