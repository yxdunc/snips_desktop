#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    m_mqttSetupWidget(new MqttSetupWidget(this)),
    m_knownHostListWidget(new QListView(this)),
    m_knownHostListModel(new RemoteHostCredentials(this))
{
    setCentralWidget(m_knownHostListWidget);
    setMenuWidget(m_mqttSetupWidget);

    QObject::connect(m_mqttSetupWidget, SIGNAL(newHost(QString, QString)), m_knownHostListModel, SLOT(appendRow(QString,QString)));

    m_knownHostListWidget->setModel(m_knownHostListModel);
}

MainWindow::~MainWindow()
{

}
