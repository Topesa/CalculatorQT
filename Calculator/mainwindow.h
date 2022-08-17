#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QAbstractButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum Operation
{
    Add,
    Sub,
    Mul,
    Div,    
    None
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    double calValue = 0;
    Operation operation;

private slots:
    void NumberPressed();           // 0-9
    void AddPressed();              // +
    void SubPressed();              // -
    void MulPressed();              // *
    void DivPressed();              // /
    void ChangeSignPressed();       // +/_
    void PercantagePressed();       // %
    void EqualPressed();            // =
    void DotPressed();              // .
    void ClearPressed();            // C
    void BackspacePressed();        // <-    
    void SetCheckableTrue();
    void SetCheckedFalse();
    void Calculate();   
};
#endif // MAINWINDOW_H
