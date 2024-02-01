#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include "socketdata/socketmessage.h"
#include <QDialog>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
    void appendMessage(QString &username, QString &message);

signals:
    void sendMessage(SocketMessage &msg);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChatWindow *ui;
};

#endif // CHATWINDOW_H
