#include <MqttSetupWidget.h>

MqttSetupWidget::MqttSetupWidget(QWidget *parent) :
    QWidget(parent),
    m_hostNameTextField(new QLineEdit(this)),
    m_portTextField(new QLineEdit(this))
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(m_hostNameTextField);
    layout->addWidget(m_portTextField);
    layout->setMargin(6);

    m_hostNameTextField->setText("raspi-rgp-qa.local");
    m_portTextField->setText("1883");

    setLayout(layout);
}
