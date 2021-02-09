#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct item{
    virtual void a (){};

    int _value;
};

struct Fitem:public item
{
    virtual void a (){};
    int _mvalue;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();   //初始化数据的函数

    int * GetInt();
protected:
    void paintEvent(QPaintEvent *event);  //绘图事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mousePressEvent(QMouseEvent *event);//鼠标单击事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件
    void mouseDoubleClickEvent(QMouseEvent *event);//鼠标双击事件
private:
    Ui::MainWindow *ui;
    int x[5]={17,89,199,277,100};
    int y[5]={150,93,49,127,300};  //定义多边形的5个点
    int m;
    int m_mouse_style;
    int j;

    item * _aPtr;
};
#endif // MAINWINDOW_H
