#ifndef ANGLERECTVIEW_H
#define ANGLERECTVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPoint>
#include <QList>
#include <QMenu>
#include <QApplication>

class AngleRectView : public QWidget
{
    Q_OBJECT
public:
    explicit AngleRectView(QWidget *parent);
    ~AngleRectView() override;

    enum MoveDirection {
        Up,
        UpRight,
        Right,
        DownRight,
        Down,
        DownLeft,
        Left,
        UpLeft
    };
protected:
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private:
    double CalcDistance(const QPoint& pt1, const QPoint& pt2);
    int GetAngleOfCurrentAngleRotateToZoroAngleByDirection(int direction);
    void DrawRegionBlock(QPainter &painter, int x1, int y1, int x2, int y2,
                                           double step_width, int derection);
    int CalcMoveDirection(int x1, int y1, int x2, int y2);
private:
    QPoint mouse_current_move_pos_;
};
#endif // ANGLERECTVIEW_H
;//empty line
;//empty line

