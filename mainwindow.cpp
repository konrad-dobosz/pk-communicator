#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _socket(this)
{
    ui->setupUi(this);
    _socket.connectToHost(QHostAddress("127.0.0.1"), 4242);
    connect(&_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    //connect(do kogo wysyłasz, co tam uruchamiasz, to co wysyłasz, co właczasz tutaj jak to wysyłasz )
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onReadyRead()
{
    QByteArray datas = _socket.readAll();
    qDebug() << datas;
    //_socket.write(QByteArray("ok !\n"));
}




void MainWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText(); // Pobierz wiadomość z pola tekstowego

    if (!message.isEmpty())
    {
        QByteArray messageData = message.toUtf8();

        // Wysyłanie wiadomości do serwera
        _socket.write(messageData);
        _socket.waitForBytesWritten();

        // Obsługa własnej wysłanej wiadomości
        ui->textBrowser->append("You: " + message);
    }
    else
    {
        qDebug() << "Wiadomość jest pusta!";
    }

}

