#include <MqttSetupWidget.h>

MqttSetupWidget::MqttSetupWidget(QWidget *parent) :
    QWidget(parent),
    m_hostNameTextField(new QLineEdit(this)),
    m_portTextField(new QLineEdit(this)),
    m_enterButton(new QPushButton("Add Host",this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(m_hostNameTextField);
    layout->addWidget(m_portTextField);
    layout->addWidget(m_enterButton);
    layout->setMargin(6);

    m_hostNameTextField->setText("raspi-rgp-qa.local");
    m_portTextField->setText("1883");

     QObject::connect(m_enterButton, SIGNAL(clicked(bool)), this, SLOT(addHost(bool)));

     setLayout(layout);
}

void MqttSetupWidget::addHost(bool checked)
{
    Q_UNUSED(checked)

    QString const hostname = m_hostNameTextField->text();
    QString const port = m_portTextField->text();

    if (hostname != "" && port != "")
    {
        emit newHost(hostname, port);
    }
}
