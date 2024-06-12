#include "Light.hpp"

Light::Light(QObject *parent) : Light(parent, Brightness::High, COLOR_WHITE) {
    // Delegating constructor: Initialize light as high brightness and white color
}

Light::Light(Brightness brightness, const QString &color, QObject *parent)
    : QObject(parent), m_brightness(brightness), m_color(color) {
    // Constructor with parameters: Initialize light with specified brightness and color
}

Brightness Light::brightness() const {
    return m_brightness;
}

void Light::setBrightness(Brightness level) {
    if (m_brightness != level) {
        m_brightness = level;
        emit stateChanged(m_brightness, m_color);  // Emit signal indicating state change
    }
}

QString Light::color() const {
    return m_color;
}

void Light::setColor(const QString &color) {
    if (m_color != color) {
        m_color = color;
        emit stateChanged(m_brightness, m_color);  // Emit signal indicating state change
    }
}
