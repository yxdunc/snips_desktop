#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MqttSetupWidget.h>
#include <QListView>
#include <RemoteHostCredentials.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MqttSetupWidget* const m_mqttSetupWidget;
    QListView* const m_knownHostListWidget;

    RemoteHostCredentials* const m_knownHostListModel;
};

#endif // MAINWINDOW_H
