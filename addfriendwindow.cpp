#include "addfriendwindow.h"
#include "ui_addfriendwindow.h"

AddFriendWindow::AddFriendWindow(AddFriendData &form_data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriendWindow),
    m_form_data(&form_data)
{
    ui->setupUi(this);

    connect(this, SIGNAL(finished(int)), this, SLOT(on_finished(int)));
}

AddFriendWindow::AddFriendWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFriendWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(finished(int)), this, SLOT(on_finished(int)));
}


AddFriendWindow::~AddFriendWindow()
{
    delete ui;
}

void AddFriendWindow::on_finished(int result) {
    Q_UNUSED(result);

    if (m_form_data != nullptr) {
        m_form_data->friendIP = ui->lineEdit_friendip->text();
    }
}
