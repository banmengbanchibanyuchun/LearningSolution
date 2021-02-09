#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;

    void init();
protected:
    void paintEvent(QPaintEvent *event);  //绘图事件
    void mouseReleaseEvent(QMouseEvent *event);//鼠标释放事件
    void mousePressEvent(QMouseEvent *event);//鼠标单击事件
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动事件

private:

    struct Point
    {
        int x;
        int y;
        Point()
        {
            x = 0;
            y = 0;
        }
    };


    Point start;

    // 是否修改样式 与 是否计算角度
    int judgeValue;

    // 鼠标样式
    int m_mouse_style;

    // 旋转角度值
    double RotateAngle;

    // 形状宽高, 正方形
    int width;

    /// 当前鼠标左键还是右键, false 右键
    bool keyValue;
};

#endif // FORM_H
