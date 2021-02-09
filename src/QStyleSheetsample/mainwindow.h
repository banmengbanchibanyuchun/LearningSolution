#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <../FremlessWidget/basewindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public BaseWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    virtual void paintEvent(QPaintEvent *event);

    void initTitleBar();
public slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
