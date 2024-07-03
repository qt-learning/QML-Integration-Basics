#include "ellipse.h"

Ellipse::Ellipse()
{
    connect(this, &Ellipse::borderChanged, this, &Ellipse::onPropertyChanged);
    connect(this, &Ellipse::colorChanged, this, &Ellipse::onPropertyChanged);
}

void Ellipse::setProperties(float newBorder, QColor newColor)
{
    setBorder(newBorder);
    
    if (m_color != newColor) {
        m_color = newColor;
        emit colorChanged();
    }
}

void Ellipse::paint(QPainter *painter)
{
    QPen pen(m_color, m_border);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawEllipse(QRect(m_border / 2, m_border / 2, width() - m_border, height() - m_border));
}

void Ellipse::ellipseInfo()
{
    qInfo() << QString("Ellipse's color: %1 - Ellipse's border: %2")
                   .arg(m_color.name())
                   .arg(m_border);
}

void Ellipse::onPropertyChanged()
{
    update();
}

float Ellipse::border() const
{
    return m_border;
}

void Ellipse::setBorder(float newBorder)
{
    if (qFuzzyCompare(m_border, newBorder))
        return;
    m_border = newBorder;
    emit borderChanged();
}
