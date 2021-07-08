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

private slots:
    void NumberPressed();       // 0-9
//    void OperationPressed();    // + - * /
//    void ChangeSignPressed();   // +/_
//    void EqualPressed();        // =
    void on_dot_released();       // .
//    void ClearPressed();        // C
//    void BackspacePressed();    // <-

};
#endif // MAINWINDOW_H
