#include <QApplication>
#include "InputSize.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    InputSize* inputSize = new InputSize;

    // Do some works before user uses.
    inputSize->load();

    // Show input maze size window.
    inputSize->show();

    return a.exec();
}
