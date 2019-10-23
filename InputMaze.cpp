#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "InputMaze.h"
#include "ui_InputMaze.h"

// Constructor.
InputMaze::InputMaze(QWidget *parent) : QMainWindow(parent), ui(new Ui::InputMaze)
{
    ui->setupUi(this);

    // Set window title.
    this->setWindowTitle("Input maze - Maze Solver");
    this->show();
}

InputMaze::InputMaze(int height, int width)
{
    // Set window title.
    this->setWindowTitle("Input maze - Maze Solver");

    // Setup array.
    using namespace NutnDS_Maze;

    for(int i=0; i<height; ++i)
        for(int j=0; j<width; ++j)
            map[i][j] = wall;

    // Generate maze selection block.
    QPushButton* mapGui[kMaxHeight][kMaxWidth];
    QHBoxLayout* hBoxLayout_row[kMaxWidth];
    QVBoxLayout* vBoxLayout_main = new QVBoxLayout;

    vBoxLayout_main->setSpacing(0);
    vBoxLayout_main->setMargin(0);

    for(int i=0; i<height; ++i)
    {
        hBoxLayout_row[i] = new QHBoxLayout;
        hBoxLayout_row[i]->setSpacing(0);
        vBoxLayout_main->addLayout(hBoxLayout_row[i]);

        for(int j=0; j<width; ++j)
        {
            mapGui[i][j] = new QPushButton;
            // mapGui[i][j]->setText(QString::number(i*width+j+1));
            mapGui[i][j]->setMinimumSize(*(new QSize(30, 30)));
            mapGui[i][j]->setMaximumSize(*(new QSize(30, 30)));
            mapGui[i][j]->setFlat(true);
            mapGui[i][j]->setStyleSheet("border:1px solid #000000;");

            hBoxLayout_row[i]->addWidget(mapGui[i][j]);
        }
    }

    // Generate widget to be attached by map selection block.
    QWidget* widget = new QWidget;
    widget->setLayout(vBoxLayout_main);
    widget->show();

    // Setup input maze window.
    //this->setCentralWidget(widget);
    //this->show();
}

// Destructor.
InputMaze::~InputMaze()
{
    delete ui;
}

