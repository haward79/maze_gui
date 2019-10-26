#include <QtWidgets>
#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "InputMaze.h"

// Constructor.
InputMaze::InputMaze()
{
    startPos = new Point();
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

    // Setup start position.
    startPos = new Point();

    // Setup array.
    for(int i=0; i<height; ++i)
        for(int j=0; j<width; ++j)
            map[i][j] = wall;

    // Generate maze selection block.
    const int kButtonSize = 30;
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
            mapGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/wall.png);");

            hBoxLayout_row[i]->addWidget(mapGui[i][j]);

            // Connect events for each map selection button.
            connect(mapGui[i][j], SIGNAL(clicked()), this, SLOT(markMapSelection()));
            connect(mapGui[i][j], SIGNAL(rightClicked()), this, SLOT(markMapSatrtFinal()));
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
    statusbar_readme->showMessage(" >> Click blocks to mark wall, road, start, and final.");

    // Generate widget to be attached by map selection block.
    QWidget* widget = new QWidget;
    widget->setLayout(vBoxLayout_main);

    // Setup window size.
    const int kMaxWindowSize = int(QGuiApplication::primaryScreen()->geometry().height() * 0.9);
    int windowWidth = (kButtonSize*width<=kMaxWindowSize) ? kButtonSize*width : kMaxWindowSize;
    int windowHeight = (kButtonSize*height+30+20<=kMaxWindowSize) ? kButtonSize*height+30+20 : kMaxWindowSize;

    // Generate scroll bar.
    QScrollArea* scroller = new QScrollArea;
    if(windowHeight==kMaxWindowSize || windowWidth==kMaxWindowSize)
    {
        scroller->setWidget(widget);
        scroller->setWidgetResizable(false);

        this->setMaximumSize(*(new QSize(windowWidth, windowHeight)));
        this->setMinimumSize(*(new QSize(windowWidth, windowHeight)));

        // Setup input maze window.
        this->setCentralWidget(scroller);
        this->show();
    }
    else
    {
        this->setMaximumSize(*(new QSize(windowWidth, windowHeight)));
        this->setMinimumSize(*(new QSize(windowWidth, windowHeight)));

        // Setup input maze window.
        this->setCentralWidget(widget);
        this->show();
    }
}

// Destructor.
InputMaze::~InputMaze()
{
    delete statusbar_readme;
    delete startPos;
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
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/road.png);");
    }
    else
    {
        map[indexI][indexJ] = NutnDS_Maze::wall;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/wall.png);");
    }
}

void InputMaze::markMapSatrtFinal()
{
    QPushButton* obj = static_cast<QPushButton*>(sender());
    int indexI = obj->objectName().replace(0, 23, "").split("-").at(0).toInt();
    int indexJ = obj->objectName().replace(0, 23, "").split("-").at(1).toInt();

    if(map[indexI][indexJ] == NutnDS_Maze::start)
    {
        map[indexI][indexJ] = NutnDS_Maze::final;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/final.png);");
    }
    else
    {
        map[indexI][indexJ] = NutnDS_Maze::start;
        obj->setStyleSheet("border:1px solid #000000; background-image:url(:/start.png);");
    }
}

void InputMaze::solvingMaze()
{
    bool check = false;

    // Check if exact one start marked.
    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            if(map[i][j] == NutnDS_Maze::start)
            {
                if(check)
                {
                    i = -1;
                    break;
                }
                else
                {
                    check = true;
                    startPos->setI(i);
                    startPos->setJ(j);
                }
            }
        }

        if(i == -1)
        {
            check = false;
            break;
        }
    }

    if(!check)
    {
        statusbar_readme->showMessage(" >> None or more than one start marked.");
        return ;
    }

    // Check if final marked.
    check = false;
    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            if(map[i][j] == NutnDS_Maze::final)
            {
                check = true;
                break;
            }
        }

        if(check)
            break;
    }

    if(!check)
    {
        statusbar_readme->showMessage(" >> Please mark final.");
        return ;
    }

    // Open solving maze window.
    solveMaze = new SolveMaze(height, width, map, startPos);
}

