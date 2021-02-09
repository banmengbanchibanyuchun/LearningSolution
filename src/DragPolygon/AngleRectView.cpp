#include "anglerectview.h"
#include <QPainter>
#include <QtMath>
#include <qmath.h>

AngleRectView::AngleRectView(QWidget *parent)
    : QWidget(parent)
{
    setMouseTracking(true);
}

AngleRectView::~AngleRectView()
{
}

void AngleRectView::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event)
    QPainter painter(this);
    //draw bg
    QRect frame_rect = this->rect();
    painter.fillRect(frame_rect, QBrush(QColor(54, 54, 54)));
    int x1 = frame_rect.width()/2;
    int y1 = frame_rect.height()/2;
    int x2 = mouse_current_move_pos_.x();
    int y2 = mouse_current_move_pos_.y();
    int derection = CalcMoveDirection(x1, y1, x2, y2);
    DrawRegionBlock(painter, x1, y1, x2, y2, 50, derection);
}

void AngleRectView::mouseMoveEvent(QMouseEvent *event) {
    Q_UNUSED(event)
    mouse_current_move_pos_ = event->pos();
    update();
}

void AngleRectView::DrawRegionBlock(QPainter &painter, int x1, int y1, int x2, int y2,
                                       double step_width, int derection) {

    int radius = qRound(step_width / 5);
    if(radius > 2) {
        int distance = static_cast<int>(CalcDistance(QPoint(x1, y1), QPoint(x2, y2)));

        distance += radius;
        QRect rect;

        painter.resetTransform();
        int angle = GetAngleOfCurrentAngleRotateToZoroAngleByDirection(derection);

        painter.translate(x1, y1);//trans 0,0 to x1, y1
        painter.rotate(angle); //rotate to angle 0

        rect.setX(0 - radius);
        rect.setY(0 - radius);
        rect.setHeight(radius*2);
        rect.setWidth(distance);
        painter.fillRect(rect, QBrush(QColor(146, 251, 91, 128)));
        //draw outline
        QPen backup_temp_pen = painter.pen();
        painter.setPen(Qt::white);
        painter.drawLine(rect.left(), rect.top(), rect.right(), rect.top());
        painter.drawLine(rect.left(), rect.bottom(), rect.right(), rect.bottom());
        painter.drawLine(rect.left(), rect.top(), rect.left(), rect.bottom());
        painter.setPen(backup_temp_pen);
        painter.resetTransform();
    }
}

double AngleRectView::CalcDistance(const QPoint& pt1, const QPoint& pt2) {
    return qSqrt(double(qPow(pt2.x() - pt1.x(), 2) + qPow(pt2.y() - pt1.y(), 2) ));
}

int AngleRectView::GetAngleOfCurrentAngleRotateToZoroAngleByDirection(int direction) {
    switch (direction) {
    case Right: { return 0;}
    case DownRight:{ return 45;}
    case Down:{ return 90; }
    case DownLeft:{ return 135; }
    case Left:{ return 180; }
    case UpLeft:{ return -135; }
    case Up:{ return -90; }
    case UpRight:{ return -45; }
    }
    return 0;
}

int AngleRectView::CalcMoveDirection(int x1, int y1, int x2, int y2) {
       double rr = qAtan2(y2 - y1, x2 - x1);
       int angle = static_cast<int>(180/M_PI * rr);
       if(angle > 0) {
           angle = 360 - angle;
       } else {
           angle = angle * -1;
       }
       if(angle >= 23 && angle < 68) {
           return UpRight;
       } else if(angle >= 68 && angle < 113) {
           return Up;
       } else if(angle >= 113 && angle < 158) {
           return UpLeft;
       } else if(angle >= 158 && angle < 203) {
           return Left;
       } else if(angle >= 203 && angle < 248) {
           return DownLeft;
       } else if(angle >= 248 && angle < 293) {
           return Down;
       } else if(angle >= 293 && angle < 338) {
           return DownRight;
       } else if((angle >= 338 && angle < 360) ||
                    (angle >= 0 && angle < 23)) {
           return Right;
       }
       return 0;
}
;//empty line
;//empty line
;//empty line
;//empty line
;//empty line
;//empty line
;//empty line
;//empty line

