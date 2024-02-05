#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatwindow.h"
#include "qlistwidget.h"
#include "settingswindow.h"
#include "socketdata/socketmessage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ChatWindow *chatw, QWidget *parent = 0);
    ~MainWindow();

signals:
//    void addFriend(QString friendIP);
//    void updateSettings(SettingsData &data);
    void connectToFriend(QString username, QHostAddress serverIp, QHostAddress friendIp);

private slots:
//    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

//    void on_btn_settings_clicked();

//    void on_btn_add_friend_clicked();

    void on_btn_write_clicked();

private:
    Ui::MainWindow *ui;
    ChatWindow *_chatw;
};

#endif // MAINWINDOW_H
