#ifndef ADDFRIENDWINDOW_H
#define ADDFRIENDWINDOW_H

#include <QDialog>

namespace Ui {
class AddFriendWindow;
}

struct AddFriendData {
    QString friendIP;
};

class AddFriendWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddFriendWindow(AddFriendData &form_data, QWidget *parent = nullptr);
    explicit AddFriendWindow(QWidget *parent = nullptr);
    ~AddFriendWindow();

private slots:
    void on_finished(int result);

private:
    Ui::AddFriendWindow *ui;
    AddFriendData *m_form_data;
};

#endif // ADDFRIENDWINDOW_H
