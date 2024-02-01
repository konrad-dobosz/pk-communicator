#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void addFriend(QString friendIP);
    void updateSettings(SettingsData &data);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_btn_settings_clicked();

    void on_btn_add_friend_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
