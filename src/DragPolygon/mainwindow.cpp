#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QWhatsThis>
#include <QPen>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMouseTracking(true);
    init();  //初始化数据

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init(){
    m=0;   //为所有的全局数据初始化 增加程序的鲁棒性
    m_mouse_style=0;
    j=0;
}

int *MainWindow::GetInt()
{
    return &m;
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){
    m=0;  //还应该在这在给m 赋一次值 为了清空鼠标上一次在某个点上留下的值
    QString zuo=QString("%1 %2").arg(event->pos().x()).arg(event->pos().y());
    QToolTip::showText(QPoint(event->globalPos()),zuo,this);  //显示鼠标坐标  更随鼠标用方框的形式
        //在mainwindows 这个类中用 mouseMoveEevent 事件只有点击拖动鼠标时才会有效 不知道是什么原因
    for(int i=0;i<5;i++){
        if(fabs(event->pos().x()-x[i])<=5&& fabs(event->pos().y()-y[i])<=5){
            //fabs()这个函数是用来去绝对值的
            m=m+1;
        }}
    if(m!=0)
    {
        setCursor(Qt::CrossCursor);  //改变鼠标的样式
        update();  //刷新
    }else {
         setCursor(Qt::ArrowCursor);
         update();
    }
    if(m_mouse_style==1){  //改变点的位置
        x[j]=event->pos().x();
        y[j]=event->pos().y();
        update();
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){  //判断是否是左键点击
        for(int i=0;i<5;i++){
            if(fabs(event->pos().x()-x[i])<=5&& fabs(event->pos().y()-y[i])<=5){
                //判断鼠标的位置
                j=i;
                m_mouse_style=1;
                 setCursor(Qt::CrossCursor);
                 break;
            }
        }
    }else {
        setCursor(Qt::ArrowCursor);
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){// 鼠标释放事件
       m_mouse_style=0;
       setCursor(Qt::ArrowCursor);
       update();
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event){
}
void MainWindow::paintEvent(QPaintEvent *event){


    QPainter painters(this);
    painters.save();
    QPen pen; //设置点的样式
    pen.setColor(Qt::red); //改变颜色
    pen.setWidth(2);  //改变点的宽度
    painters.setPen(pen);
    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painters.setBrush( brush);
    QPoint point;
    for(int i=0;i<5;i++){  //画出5个点
        //painters.drawPoint(x[i],y[i]);
             painters.drawRect( x[i]-5, y[i]-5,10,10);
    }

    painters.restore();
    QPen pen1; //设置线的样式
    pen1.setWidth(3);
    pen1.setColor(Qt::blue);
    painters.setPen(pen1);
    QPolygon ply;   //多边形
    ply.setPoints(5,x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3],x[4],y[4]);  //点的集合
    painters.drawConvexPolygon(ply);  //绘制出多边形

}

