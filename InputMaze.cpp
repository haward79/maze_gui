#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
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
    // Set variable height and width in class.
    this->height = height;
    this->width = width;

    // Set window title.
    this->setWindowTitle("Input maze - Maze Solver");

    // Use namespace.
    using namespace NutnDS_Maze;

    // Setup array.
    for(int i=0; i<height; ++i)
        for(int j=0; j<width; ++j)
            map[i][j] = wall;

    // Generate maze selection block.
    const int kButtonSize = 30;
    QButton* mapGui[kMaxHeight][kMaxWidth];
    QHBoxLayout* hBoxLayout_row[kMaxWidth];
    QVBoxLayout* vBoxLayout_main = new QVBoxLayout;
    QPalette palette;

    vBoxLayout_main->setSpacing(0);
    vBoxLayout_main->setMargin(0);

    for(int i=0; i<height; ++i)
    {
        hBoxLayout_row[i] = new QHBoxLayout;
        hBoxLayout_row[i]->setSpacing(0);
        vBoxLayout_main->addLayout(hBoxLayout_row[i]);

        for(int j=0; j<width; ++j)
        {
            mapGui[i][j] = new QButton;
            mapGui[i][j]->setObjectName(QString::fromStdString("pushButton_mapSelection") + QString::number(i) + QString::fromStdString("-") + QString::number(j));
            // mapGui[i][j]->setText(QString::number(i*width+j+1));
            mapGui[i][j]->setMinimumSize(*(new QSize(kButtonSize, kButtonSize)));
            mapGui[i][j]->setMaximumSize(*(new QSize(kButtonSize, kButtonSize)));
            mapGui[i][j]->setFlat(true);
            mapGui[i][j]->setAutoFillBackground(true);
            mapGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/grass.png);");

            hBoxLayout_row[i]->addWidget(mapGui[i][j]);

            // Connect events for each map selection button.
            connect(mapGui[i][j], SIGNAL(clicked()), this, SLOT(markMapSelection()));
            connect(mapGui[i][j], SIGNAL(rightClicked()), this, SLOT(markMapFinal()));
        }
    }

    // Generate ok button.
    QPushButton* pushButton_ok = new QPushButton;
    pushButton_ok->setText("OK");
    pushButton_ok->setMinimumHeight(30);
    pushButton_ok->setMaximumHeight(30);
    vBoxLayout_main->addWidget(pushButton_ok);
    connect(pushButton_ok, SIGNAL(clicked()), this, SLOT(solvingMaze()));

    // Generate status bar.
    statusbar_readme = new QStatusBar;
    vBoxLayout_main->addWidget(statusbar_readme);
    statusbar_readme->showMessage(" >> Click blocks to mark wall, road, and final.");

    // Generate widget to be attached by map selection block.
    QWidget* widget = new QWidget;
    widget->setLayout(vBoxLayout_main);

    // Setup input maze window.
    this->setCentralWidget(widget);
    this->setMaximumSize(*(new QSize(kButtonSize*width, kButtonSize*height+30+20)));
    this->setMinimumSize(*(new QSize(kButtonSize*width, kButtonSize*height+30+20)));
    this->show();
}

// Destructor.
InputMaze::~InputMaze()
{
    delete ui;
    delete statusbar_readme;
}

// Method.
void InputMaze::markMapSelection()
{
    QPushButton* obj = static_cast<QPushButton*>(sender());
    int indexI = obj->objectName().replace(0, 23, "").split("-").at(0).toInt();
    int indexJ = obj->objectName().replace(0, 23, "").split("-").at(1).toInt();

    if(map[indexI][indexJ] == NutnDS_Maze::wall)
    {
        map[indexI][indexJ] = NutnDS_Maze::road;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/mud.jpg);");
    }
    else
    {
        map[indexI][indexJ] = NutnDS_Maze::wall;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/grass.png);");
    }
}

void InputMaze::markMapFinal()
{
    QPushButton* obj = static_cast<QPushButton*>(sender());
    int indexI = obj->objectName().replace(0, 23, "").split("-").at(0).toInt();
    int indexJ = obj->objectName().replace(0, 23, "").split("-").at(1).toInt();

    if(map[indexI][indexJ] == NutnDS_Maze::final)
    {
        map[indexI][indexJ] = NutnDS_Maze::wall;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/grass.png);");
    }
    else
    {
        map[indexI][indexJ] = NutnDS_Maze::final;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/flag.png);");
    }
}

void InputMaze::solvingMaze()
{
    // Check if final marked.
    bool hasFinal = false;
    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            if(map[i][j] == NutnDS_Maze::final)
            {
                hasFinal = true;
                break;
            }
        }

        if(hasFinal)
            break;
    }

    if(!hasFinal)
    {
        statusbar_readme->showMessage(" >> Please mark final.");
        return ;
    }

    // Open solving maze window.
    solveMaze = new SolveMaze(height, width, map);

    // Close input maze window.
    this->close();
}

