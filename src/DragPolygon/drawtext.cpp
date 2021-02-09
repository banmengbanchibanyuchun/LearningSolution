#include "drawtext.h"

#include <QPainter>
#include <QToolTip>
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QWhatsThis>
#include <QPen>
#include <math.h>

#include "ui_drawtext.h"

DrawText::DrawText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawText)
{
    ui->setupUi(this);
    pointPosition =QPoint(200,200);
    pointtri = QPoint(150,150);
    width = 50;
    height =50;

    QString aa =  QString( tr("发%1送")).arg( "sdfs ");
    ui->pushButton->setText( aa );
}

DrawText::~DrawText()
{
    delete ui;
}



void DrawText::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);//消锯齿

    DrawEdging(painter);
    DrawMovePoint(painter);
    DrawScalPoint(painter);
}

void DrawText::mouseMoveEvent(QMouseEvent *event)
{
    if(m_mouse_style==1){  //改变点的位置
        pointtri+=( event->pos() -PriPosition);
    }
    else if(m_mouse_style==2)
    {
        pointPosition +=( event->pos() -PriPosition);
    }
    else if(m_mouse_style==3)
    {
        width +=  event->pos().x() -PriPosition.x();
        height -= event->pos().y() -PriPosition.y();
    }
    else if(m_mouse_style==4)
    {
        width +=  event->pos().x() -PriPosition.x();
        height += event->pos().y() -PriPosition.y();
    }
    else if(m_mouse_style==5)
    {
        width -=  event->pos().x() -PriPosition.x();
        height += event->pos().y() -PriPosition.y();
    }
    else if(m_mouse_style==6)
    {
        pointPosition +=( event->pos() -PriPosition);
        pointtri +=( event->pos() -PriPosition);
    }
    else
    {
        return;
    }
    update();
    PriPosition =event->pos();

}

void DrawText::mousePressEvent(QMouseEvent *event)
{
    m_mouse_style  = 0;
    if(event->button()==Qt::LeftButton)
    {  //判断是否是左键点击

        setCursor(Qt::CrossCursor);

        QRectF rect( pointPosition , QSize( width,height ));
        if(  QRectF( pointtri.x() -5 ,pointtri.y() -5,10,10  ).contains( event->pos() ) )
        {
            m_mouse_style=1;//三角顶点
        }
        else  if(  QRectF( pointPosition.x() -5 ,pointPosition.y() -5,10,10  ).contains( event->pos() ) )
        {
            m_mouse_style=2;//矩形左上角
        }
        else  if(  QRectF( rect.topRight().x() -5 ,rect.topRight().y() -5,10,10  ).contains( event->pos() ) )
        {
            m_mouse_style=3;//矩形右上角
        }
        else  if(  QRectF( rect.bottomRight().x() -5 ,rect.bottomRight().y() -5,10,10  ).contains( event->pos() ) )
        {
            m_mouse_style=4;//矩形右下角
        }
        else  if(  QRectF( rect.bottomLeft().x() -5 , rect.bottomLeft().y() -5,10,10  ).contains( event->pos() ) )
        {
            m_mouse_style=5;//矩形左下角
        }
        else if(  rect.contains( event->pos() ) )
        {
            m_mouse_style=6;//矩形内
        }
        else
        {
            setCursor(Qt::ArrowCursor);
        }
        setCursor(Qt::CrossCursor);
        PriPosition = event->pos();
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}
void DrawText::mouseReleaseEvent(QMouseEvent *event)
{// 鼠标释放事件
       m_mouse_style=0;
       setCursor(Qt::ArrowCursor);
       update();
}

void DrawText::on_pushButton_clicked()
{
    _text = ui->textEdit->toPlainText();


    QTextDocument *doc = ui->textEdit->document();
    doc->adjustSize();  //这一步不能少

    double newW =  doc->size().rwidth()* 1.1;
    double newH =  doc->size().rheight()* 1.1;

    if( newW > 50 )
    {
        width =newW;
    }
    else
    {
        width = 50;
    }

    if( newH > 50 )
    {
        height =newH;
    }
    else
    {
        height = 50;
    }

    update( );
}

void DrawText::DrawEdging(QPainter &painter)
{
    QPen pen(Qt::black);
    painter.setPen( pen);

    QRectF rect( pointPosition , QSize( width,height ));

    /*                P
    p0---P1-----p2---------p3----p4---p5-----
    |                                 |
    |                                 p6
    p19                               |
    |                                 |
    |                                 P7
    P18                               |
    |                                 |
    p17                               p8
    |                                 |
    |                                 |
    p16                               p9
    |                                 |
    p15---p14---p13-------p12---p11---p10-----
    */

    QPointF p = pointtri;
    QPointF p0 =rect.topLeft();
    QPointF p5 =rect.topRight();
    QPointF p10 =rect.bottomRight();
    QPointF p15 =rect.bottomLeft();

    //字体框
    QVector< QPointF > points;
    points.push_back( p0 );
    points.push_back( p5 );
    points.push_back( p10 );
    points.push_back( p15 );
    QPolygonF Polygon(points);

    //三角框
    QPointF center = rect.center();
    int angle = atan2((p.y()-center.y()), (p.x()-center.x()))*(180.0/3.14159);
    int angle10 = atan2((p10.y()-center.y()), (p10.x()-center.x()))*(180.0/3.14159);
    int angle15 = atan2((p15.y()-center.y()), (p15.x()-center.x()))*(180.0/3.14159);
    int angle0 = atan2((p0.y()-center.y()), (p0.x()-center.x()))*(180.0/3.14159);
    int angle5 = atan2((p5.y()-center.y()), (p5.x()-center.x()))*(180.0/3.14159);
    QVector< QPointF > points1;
    points1.push_back( p );
    if( angle >= 0 && angle < angle10 )
    {
        points1.push_back( QPointF( rect.right() -1, center.y()  ));
        points1.push_back( QPointF( rect.right()-1 , (center.y() + p10.y())/2 ));
    }
    else  if( angle >= angle10 && angle < 90 )
    {
        points1.push_back( QPointF( center.x() , rect.bottom() -1));
        points1.push_back( QPointF( (center.x() + p10.x())/2 , rect.bottom() -1 ));
    }
    else  if( angle >= 90 && angle < angle15 )
    {
        points1.push_back( QPointF( center.x() , rect.bottom()-1 ));
        points1.push_back( QPointF( (center.x() + p15.x())/2 , rect.bottom()-1 ));
    }
    else  if( angle >= angle15 && angle < 180 )
    {
        points1.push_back( QPointF( rect.left() +1, center.y() ));
        points1.push_back( QPointF( rect.left() +1, (center.y() + p15.y())/2 ));
    }
    else  if( angle >= -180 && angle < angle0 )
    {
        points1.push_back( QPointF( rect.left() +1, center.y() ));
        points1.push_back( QPointF( rect.left() +1 , (center.y() + rect.topLeft().y())/2 ));
    }
    else  if( angle >= angle0 && angle < -90 )
    {
        points1.push_back( QPointF( rect.center().x() , rect.top() +1 ));
        points1.push_back( QPointF((rect.center().x() + rect.topLeft().x() )/2 , rect.top()+1 ));
    }
    else  if( angle >= -90 && angle < angle5 )
    {
        points1.push_back( QPointF( rect.center().x() , rect.top()+1 ));
        points1.push_back( QPointF((rect.center().x() + rect.topRight().x() )/2 , rect.top()+1 ));
    }
    else
    {
        points1.push_back( QPointF( rect.right()-1 , center.y() ));
        points1.push_back( QPointF( rect.right() -1, (center.y() + rect.topRight().y())/2 ));

    }
    qDebug()<<angle<<"  " <<angle10<<"  "<<angle15<<"  "<<angle0<<"  "<<angle5;
    QPolygonF Polygon1(points1);

    //组合字体框和三角框
    Polygon = Polygon.united( Polygon1 );
    painter.drawPolygon( Polygon );

    //绘制字体
    painter.drawText(  rect , _text );
}

void DrawText::DrawMovePoint(QPainter &painter)
{
    QPen pen(Qt::black);
    painter.setPen( pen);
    QBrush brush( Qt::darkRed );
    painter.setBrush( brush );

    painter.drawRect( QRectF( pointPosition.x() -5 ,pointPosition.y() -5,10,10  ) );
    painter.drawRect( QRectF( pointtri.x() -5 ,pointtri.y() -5,10,10  ) );
}

void DrawText::DrawScalPoint(QPainter &painter)
{
    QPen pen(Qt::black);
    painter.setPen( pen);
    QBrush brush( Qt::green );
    painter.setBrush( brush );

    QRectF rect( pointPosition , QSize( width,height ));

    painter.drawRect( QRectF( rect.topRight().x() -5 ,rect.topRight().y() -5,10,10  ) );
    painter.drawRect( QRectF( rect.bottomRight().x() -5 ,rect.bottomRight().y() -5,10,10  ) );
    painter.drawRect( QRectF( rect.bottomLeft().x() -5 ,rect.bottomLeft().y() -5,10,10  ) );
}

