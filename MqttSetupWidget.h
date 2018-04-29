#ifndef MQTT_SETUP_WIDGET_H
#define MQTT_SETUP_WIDGET_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>

class MqttSetupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MqttSetupWidget(QWidget *parent = nullptr);

signals:
    void newHost(QString hostname, QString port);
public slots:
    void addHost(bool checked);
private:
    QLineEdit* const m_hostNameTextField;
    QLineEdit* const m_portTextField;
    QPushButton* const m_enterButton;
};

#endif // MQTT_SETUP_WIDGET_H
