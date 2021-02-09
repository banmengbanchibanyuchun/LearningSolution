#ifndef DRAWTEXT_H
#define DRAWTEXT_H

#include <QWidget>

namespace Ui {
class DrawText;
}

class DrawText : public QWidget
{
    Q_OBJECT

public:
    explicit DrawText(QWidget *parent = nullptr);
    ~DrawText();

protected:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mousePressEvent(QMouseEvent *event);//鼠标单击事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件

public slots:
    void on_pushButton_clicked();

private:
    //绘制边框
    void DrawEdging( QPainter & painter );
    //绘制控制点1
    void DrawMovePoint(  QPainter & painter );
    //绘制缩放点
    void DrawScalPoint(  QPainter & painter );
private:
    Ui::DrawText *ui;

    QPoint  pointtri;
    QPoint  pointPosition;
    int m_mouse_style;
    QPoint  PriPosition;
    int width,height;

    QString _text;
    QString _Font;
    QString _Family;
    int _FontSize;


};

#endif // DRAWTEXT_H
