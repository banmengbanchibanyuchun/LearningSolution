#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include "mytitlebar.h"
#include "FremlessWidget_global.h"

class FREMLESSWIDGET_EXPORT BaseWindow : public QWidget
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

protected:
    void initTitleBar();
    void paintEvent(QPaintEvent *event);
    void loadStyleSheet(const QString &sheetName);

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    MyTitleBar* m_titleBar;

};
#endif // BASEWINDOW_H
