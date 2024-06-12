#ifndef LIGHT_H
#define LIGHT_H

#include <QObject>
#include <QString>

// Enum to define different brightness levels
enum class Brightness {
    Off,
    Low,
    Medium,
    High
};

// Define colors
#define COLOR_RED    "#FF0000"
#define COLOR_GREEN  "#00FF00"
#define COLOR_BLUE   "#0000FF"
#define COLOR_WHITE  "#FFFFFF"

class Light : public QObject {
    Q_OBJECT

public:
    explicit Light(QObject *parent = nullptr);  // Constructor
    Light(Brightness brightness, const QString &color, QObject *parent = nullptr); // Constructor with parameters
    Light(QObject *parent = nullptr, Brightness brightness = Brightness::High, const QString &color = COLOR_WHITE); // Improved constructor

    Brightness brightness() const;              // Method to get current brightness level
    void setBrightness(Brightness level);       // Method to set brightness level
    QString color() const;                      // Method to get current color
    void setColor(const QString &color);        // Method to set color

signals:
    void stateChanged(Brightness brightness, const QString &color);  // Signal emitted when state changes

private:
    Brightness m_brightness;  // Member variable to hold current brightness level
    QString m_color;          // Member variable to hold current color
};

#endif // LIGHT_H
