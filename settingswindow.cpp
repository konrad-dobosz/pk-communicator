#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(SettingsData &form_data, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow),
    m_form_data(&form_data)
{
    ui->setupUi(this);

    connect(this, SIGNAL(finished(int)), this, SLOT(on_finished(int)));
}

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    connect(this, SIGNAL(finished(int)), this, SLOT(on_finished(int)));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::on_finished(int result) {
    Q_UNUSED(result);

    if (m_form_data != nullptr) {
        m_form_data->serverIP = ui->lineEdit_serverip->text();
    }
}
