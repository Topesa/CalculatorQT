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

   SetCheckableTrue();

   connect(ui->add, SIGNAL(released()), this, SLOT(AddPressed()));
   connect(ui->sub, SIGNAL(released()), this, SLOT(SubPressed()));
   connect(ui->multiply, SIGNAL(released()), this, SLOT(MulPressed()));
   connect(ui->div, SIGNAL(released()), this, SLOT(DivPressed()));
   connect(ui->dot, SIGNAL(released()), this, SLOT(DotPressed()));
   connect(ui->changesign, SIGNAL(released()), this, SLOT(ChangeSignPressed()));
   connect(ui->perc, SIGNAL(released()), this, SLOT(PercantagePressed()));
   connect(ui->equal, SIGNAL(released()), this, SLOT(EqualPressed()));
   connect(ui->backspace, SIGNAL(released()), this, SLOT(BackspacePressed()));
   connect(ui->clear, SIGNAL(released()), this, SLOT(ClearPressed()));   
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetCheckableTrue()
{
    ui->add->setCheckable(true);
    ui->sub->setCheckable(true);
    ui->div->setCheckable(true);
    ui->multiply->setCheckable(true);
    ui->equal->setCheckable(true);
}

void MainWindow::SetCheckedFalse()
{
    ui->add->setChecked(false);
    ui->sub->setChecked(false);
    ui->multiply->setChecked(false);
    ui->div->setChecked(false);
    ui->equal->setChecked(false);    
}

void MainWindow::NumberPressed()
{
    QPushButton * btn = (QPushButton*)sender();

    QString displayValue;

    if (ui->display->text() == "0" || ui->add->isChecked() || ui->sub->isChecked() || ui->multiply->isChecked() || ui->div->isChecked()  || ui->equal->isChecked())
    {
        displayValue = btn->text();
        SetCheckedFalse();
    }
    else
    {
       displayValue = ui->display->text() + btn->text();
    }

    ui->display->setText(displayValue);
}

void MainWindow::Calculate()
{
    double displayValue = ui->display->text().toDouble();

    switch (operation)
    {
        case (Add):
        {
            displayValue += calValue;
            break;
        }
        case (Sub):
        {
            displayValue -= calValue;
            break;
        }
        case (Mul):
        {
            displayValue *= calValue;
            break;
        }
        case (Div):
        {
            displayValue = calValue / displayValue;
            break;
        }
        case (None):
        {
            break;
        }
    }

    calValue = displayValue;

    ui->display->setText(QString::number(displayValue,'g',15));
}

void MainWindow::AddPressed()
{
    Calculate();
    operation = Add;
}

void MainWindow::SubPressed()
{
    Calculate();
    operation = Sub;    
}

void MainWindow::MulPressed()
{
    Calculate();
    operation = Mul;   
}

void MainWindow::DivPressed()
{
    Calculate();
    operation = Div;    
}

void MainWindow::EqualPressed()
{
    Calculate();
    operation = None;
}

void MainWindow::ChangeSignPressed()
{
    double displayValue;  
    displayValue = ui->display->text().toDouble();

    displayValue *= -1;

    ui->display->setText(QString::number(displayValue,'g',15));
}

void MainWindow::PercantagePressed()
{
    double displayValue;  
    displayValue = ui->display->text().toDouble();

    displayValue *= 0.01;

    ui->display->setText(QString::number(displayValue,'g',15));
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

    if (displayValue.length() == 0)
    {
         ui->display->setText("0");
    }
}

void MainWindow::ClearPressed()
{
    if (ui->display->text() == "0")
    {
        operation = None;
        calValue = 0;
    }

    SetCheckedFalse();

    ui->display->setText("0");
}
