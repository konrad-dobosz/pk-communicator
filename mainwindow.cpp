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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText(); // Pobierz wiadomość z pola tekstowego

    if (!message.isEmpty())
    {
        QByteArray messageData = message.toUtf8();

        // Wysyłanie wiadomości do serwera
        emit sendMessage(messageData);

        // Obsługa własnej wysłanej wiadomości
        //appendMessage(message);
        ui->textBrowser->append("You: " + message);
    }
    else
    {
        qDebug() << "Wiadomość jest pusta!";
    }
}

void MainWindow::appendMessage(QString &message) {
    ui->textBrowser->append("Someone: " + message);
}

