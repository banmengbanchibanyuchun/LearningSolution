#include "form.h"
#include "ui_form.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QPen>
#include <math.h>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    setMouseTracking(true);
    init();
    width = 220;
    RotateAngle = 0;
    keyValue = false;



}

Form::~Form()
{
    delete ui;
}


void Form::init()
{
    judgeValue = 0;
    m_mouse_style = 0;

    start.x = 100;
    start.y = 100;
}

void Form::mouseMoveEvent(QMouseEvent *event)
{
    judgeValue = 0;

    if (fabs(event->pos().x() - start.x) <= 5 && fabs(event->pos().y() - start.y) <= 5)
    {
        judgeValue = judgeValue + 1;
    }

    if (judgeValue != 0)
    {
        setCursor(Qt::CrossCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }

    if (m_mouse_style == 1 && keyValue)
    {
        //改变点的位置

        Point stop;
        stop.x = event->pos().x();
        stop.y = event->pos().y();

        Point center;
        center.x = start.x + width / 2;
        center.y = start.y + width / 2;

        // 向量
        // 中心点和起始点向量
        Point cstart;
        cstart.x = start.x - center.x;
        cstart.y = start.y - center.y;

        // 中心点和结束点的向量
        Point cstop;
        cstop.x = stop.x - center.x;
        cstop.y = stop.y - center.y;

        // 计算叉乘,逆时针还是顺时针旋转
        int dircet = (cstart.x * cstop.y) - (cstart.y * cstop.x);

        /// 求夹角
        double lengthCstart = sqrt(pow(center.x - start.x, 2) +
            pow(center.y - start.y, 2));
        double lengthCstop = sqrt(pow(center.x - stop.x, 2) +
            pow(center.y - stop.y, 2));
        double lengthStartStop = sqrt(pow(start.x - stop.x, 2) +
            pow(start.y - stop.y, 2));

        //  方法1 余弦定理求出旋转角
        double cosr = (pow(lengthCstart, 2) + pow(lengthCstop, 2) - pow(lengthStartStop, 2)) /
            (2 * lengthCstart * lengthCstop);

        /// 方法2 使用向量计算
        //double cosr = (cstart.x* cstop.x + cstart.y * cstop.y) / (sqrt(pow(cstop.x, 2) + pow(cstop.y, 2)) * sqrt(pow(cstart.x, 2) + pow(cstart.y, 2)));

        double angle = acos(cosr) * 180 / 3.1415926;


        if (dircet < 0)
        {
            RotateAngle -= angle;
        }
        else
        {
            RotateAngle += angle;
        }

        /// 修改起始点
        start.x = stop.x;
        start.y = stop.y;


    }
    else if (m_mouse_style == 1 && !keyValue)
    {
        start.x = event->pos().x();
        start.y = event->pos().y();
    }

    update();
}
void Form::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton)
    {

        if (fabs(event->pos().x() - start.x) <= 5 && fabs(event->pos().y() - start.y) <= 5)
        {
            m_mouse_style = 1;
            setCursor(Qt::CrossCursor);
        }

        if (event->button() != Qt::LeftButton)
        {
            keyValue = false;
        }
        else
        {
            keyValue = true;
        }

    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}
void Form::mouseReleaseEvent(QMouseEvent *event)
{

    m_mouse_style = 0;
    setCursor(Qt::ArrowCursor);
    update();
}

void Form::paintEvent(QPaintEvent *event)
{
    QPainter painters(this);

    // 画操作点
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);
    painters.setPen(pen);
     painters.drawPoint(start.x, start.y);

    /// 画线
    QPen pen1;
    pen1.setWidth(2);
    pen1.setColor(Qt::blue);
    painters.setPen(pen1);

    int cx = start.x + width/2;
    int cy = start.y + width / 2;

    /// 画一个中心点
    painters.drawPoint(cx, cy);

    QRect rotatedRect(-width / 2, -width / 2, width, width);
    painters.save();
    painters.translate(QPoint(cx, cy));
    painters.rotate(RotateAngle);
    painters.drawRoundRect(rotatedRect, 50, 50);
    painters.restore();


}
