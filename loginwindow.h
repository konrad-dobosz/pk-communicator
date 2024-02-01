#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void login(QString& username, QString& password);
    void register_user(QString& username, QString& password);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
