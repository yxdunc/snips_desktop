#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    m_mqttSetupWidget(new MqttSetupWidget(this))
{
    setCentralWidget(m_mqttSetupWidget);
}

MainWindow::~MainWindow()
{

}
