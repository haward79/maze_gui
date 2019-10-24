#include "QButton.h"

QButton::QButton(QWidget* parent) : QPushButton(parent)
{
    // Empty.
}

void QButton::mousePressEvent(QMouseEvent* e)
{
    if(e->button() == Qt::RightButton)
        emit rightClicked();
    else
        emit clicked();
}
