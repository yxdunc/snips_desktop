#ifndef MQTT_SETUP_WIDGET_H
#define MQTT_SETUP_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>

class MqttSetupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MqttSetupWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    QLineEdit* const m_hostNameTextField;
    QLineEdit* const m_portTextField;
};

#endif // MQTT_SETUP_WIDGET_H
