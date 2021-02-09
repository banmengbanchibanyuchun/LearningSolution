#ifndef FREMLESS_H
#define FREMLESS_H

#include <QWidget>
#include <../FremlessWidget/basewindow.h>

namespace Ui {
class Fremless;
}

class Fremless : public BaseWindow
{
    Q_OBJECT

public:
    explicit Fremless(QWidget *parent = nullptr);
    ~Fremless();

    void initTitleBar();
public slots:
    void on_pushButton_clicked();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::Fremless *ui;
};

#endif // FREMLESS_H
