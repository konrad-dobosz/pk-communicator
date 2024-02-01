#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

namespace Ui {
class SettingsWindow;
}

struct SettingsData {
    QString serverIP;
};

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(SettingsData &form_data, QWidget *parent = nullptr);
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private slots:
    void on_finished(int result);

private:
    Ui::SettingsWindow *ui;
    SettingsData *m_form_data;
};

#endif // SETTINGSWINDOW_H
