#ifndef WIDGET_H
#define WIDGET_H

#include <QTcpSocket>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QTcpSocket socket_;
public slots:
    void doConnect();
    void doDisconnect();
    void onReadyRead();
    void on_pbConnect_clicked();
    void on_pbDisconnect_clicked();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
