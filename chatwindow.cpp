#include "chatwindow.h"
#include "qdatetime.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle(_friendIp.toString());
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_pushButton_clicked()
{
    QString message = ui->plainTextEdit->toPlainText();

    if (!message.isEmpty())
    {
        SocketMessage msg(_friendIp, message, _username);

        emit sendMessage(msg);

        QString username = "Ty";
        appendMessage(username, message);
    }
    else
    {
        qDebug() << "Wiadomość jest pusta!";
    }
}

void ChatWindow::appendMessage(QString username, QString message) {
    QDateTime date;
    date = date.currentDateTime();

    ui->textBrowser->append(username + ": " + message + "<br>[" + date.toString() + "]<br>");
}
