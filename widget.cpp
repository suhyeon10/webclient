#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //socket_.connect();
    QObject::connect(&socket_, &QAbstractSocket ::connected, this, &Widget::doConnect);
    QObject::connect(&socket_, &QAbstractSocket ::disconnected, this, &Widget::doDisconnect);
    QObject::connect(&socket_, &QIODevice::readyRead, this, &Widget::onReadyRead);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doConnect(){
    QString msg = "connected\r\n";
    ui->pteMessage->insertPlainText(msg);
}

void Widget::doDisconnect(){
    QString msg = "disconnected\r\n";
    ui->pteMessage->insertPlainText(msg);
}

void Widget::on_pbConnect_clicked()
{
    QString host = ui->leHost->text();
    quint16 port = ui->lePort->text().toUShort();
    socket_.connectToHost(host, port);
}
void Widget::on_pbDisconnect_clicked()
{
    socket_.disconnectFromHost();
}
void Widget::onReadyRead()
{
    QByteArray data = socket_.readAll();
    ui->pteMessage->appendPlainText("📨 수신: " + QString::fromUtf8(data));
}
