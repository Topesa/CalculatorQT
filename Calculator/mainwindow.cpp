#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size()); // disable window resize

    ui->display->setText(QString::number(calValue));
    QPushButton *numberButton[10];

   for (unsigned int i = 0; i < (sizeof(numberButton)/sizeof(numberButton[0])); i++)
    {
       QString buttonName = "button" + QString::number(i);
       numberButton[i] = MainWindow::findChild<QPushButton *> (buttonName);
       connect(numberButton[i], SIGNAL(released()), this, SLOT(NumberPressed()));
    }

   connect(ui->add, SIGNAL(released()), this, SLOT(OperationPressed()));
   connect(ui->sub, SIGNAL(released()), this, SLOT(OperationPressed()));
   connect(ui->multiply, SIGNAL(released()), this, SLOT(OperationPressed()));
   connect(ui->div, SIGNAL(released()), this, SLOT(OperationPressed()));
   connect(ui->dot, SIGNAL(released()), this, SLOT(DotPressed()));
   connect(ui->changesign, SIGNAL(released()), this, SLOT(ChangeSignOrPercentagePressed()));
   connect(ui->perc, SIGNAL(released()), this, SLOT(ChangeSignOrPercentagePressed()));
   connect(ui->equal, SIGNAL(released()), this, SLOT(EqualPressed()));
   connect(ui->backspace, SIGNAL(released()), this, SLOT(BackspacePressed()));
   connect(ui->clear, SIGNAL(released()), this, SLOT(ClearPressed()));
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

        ui->display->setText(QString::number(newValueDouble, 'g', 15));
    }
}

void MainWindow::OperationPressed()
{
     additionFlag = false;
     subtractionFlag = false;
     multiplyFlag= false;
     divisionFlag = false;

     QString displayValue = ui->display->text();
     calValue = displayValue.toDouble();

     QPushButton  *btn = (QPushButton *) sender();
     QString btnValue = btn->text();

     if (QString::compare(btnValue, "+", Qt::CaseInsensitive) == 0)
     {
         additionFlag = true;
     }
     else if (QString::compare(btnValue, "-", Qt::CaseInsensitive) == 0)
     {
         subtractionFlag = true;
     }
     else if (QString::compare(btnValue, "×", Qt::CaseInsensitive) == 0)
     {
         multiplyFlag= true;
     }
     else if (QString::compare(btnValue, "÷", Qt::CaseInsensitive) == 0)
     {
         divisionFlag = true;
     }

     ui->display->setText("");
}

void MainWindow::EqualPressed()
{
    double result = 0.0;
    QString displayValue = ui->display->text();
    double displayValueDouble = displayValue.toDouble();

    if (additionFlag || subtractionFlag|| multiplyFlag|| divisionFlag)
    {
        if (additionFlag)
        {
            result = calValue + displayValueDouble;
        }
        else if (subtractionFlag)
        {
            result = calValue - displayValueDouble;
        }
        else if (multiplyFlag)
        {
            result = calValue * displayValueDouble;
        }
        else
        {
            result = calValue / displayValueDouble;
        }
    }

    ui->display->setText((QString::number(result)));
}

void MainWindow::ChangeSignOrPercentagePressed()
{
    QPushButton *btn = (QPushButton*) sender();
    QString newDisplayNumber;
    double displayNumber;

    if (btn->text() == "+/_")
    {
        displayNumber = ui->display->text().toDouble();
        displayNumber *= -1;
        newDisplayNumber = QString::number(displayNumber, 'g', 15);
        ui->display->setText(newDisplayNumber);
    }

    if (btn->text() == "%")
    {
        displayNumber = ui->display->text().toDouble();
        displayNumber *= 0.01;
        newDisplayNumber = QString::number(displayNumber, 'g', 15);
        ui->display->setText(newDisplayNumber);
    }
}

void MainWindow::DotPressed()
{
    QString txt = ui->display->text();

    if (!txt.contains('.', Qt::CaseSensitive))
     {
        ui->display->setText(txt + ".");
     }
}

void MainWindow::BackspacePressed()
{
    QString displayValue = ui->display->text();

    displayValue.QString::chop(1);
    ui->display->setText(displayValue);

    if(displayValue.length() == 0)
    {
         ui->display->setText("0");
    }
}

void MainWindow::ClearPressed()
{
   ui->display->clear();
   ui->display->setText("0");
}





