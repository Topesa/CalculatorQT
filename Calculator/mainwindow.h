#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    double calValue = 0.0;
    double additionFlag = false;
    double subtractionFlag = false;
    double multiplyFlag= false;
    double divisionFlag = false;


private slots:
    void NumberPressed();                   // 0-9
    void OperationPressed();                // + - * /
    void ChangeSignOrPercentagePressed();   // +/_ and %
    void EqualPressed();                    // =
    void DotPressed();                      // .
    void ClearPressed();                    // C
    void BackspacePressed();                // <-

};
#endif // MAINWINDOW_H
