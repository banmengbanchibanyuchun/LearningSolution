#include "fremless.h"
#include "ui_fremless.h"

#include "QFile"
#include "QMessageBox"
#include "QPainter"

Fremless::Fremless(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::Fremless)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground);

    QString runPath = QCoreApplication::applicationDirPath();
    runPath = ":/QSS/QSS/style.qss";

    QFile file(runPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, tr("提示"), runPath);
        return;
    }
    QString info;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        info.append(line);
    }
    //setStyleSheet(info);

    //ui->pushButton->setStyleSheet("background-color:green");
    initTitleBar();
}

Fremless::~Fremless()
{
    delete ui;
}


void Fremless::initTitleBar()
{

    // 设置标题栏跑马灯效果，可以不设置;
    m_titleBar->setTitleRoll();

    m_titleBar->setTitleIcon(":/Resources/titleicon.png");
    m_titleBar->setTitleContent(QStringLiteral("前行中的小猪-前行之路还需前行"));
    m_titleBar->setButtonType(MIN_MAX_BUTTON);
    m_titleBar->setTitleWidth(this->width());

}

void Fremless::paintEvent(QPaintEvent *event)
{
    //最后找到解决办法，继承自QWidget的自定义类中，重载 paintEvent方法，
    QPainter p(this);
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

    BaseWindow::paintEvent(event);
}

void Fremless::on_pushButton_clicked()
{
    static int  i = 0;

    int n = i%5;
    i ++;
    QString runPath = QCoreApplication::applicationDirPath();
    runPath = ":/commenstylesheet"+ QString::number(n)+ ".qss";

    QFile file(runPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, tr("提示"), runPath);
        return;
    }
    QString info;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        info.append(line);
    }
    setStyleSheet(info);
}
