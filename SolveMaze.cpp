#include <QtWidgets>
#include <QScreen>
#include <QScrollArea>
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "SolveMaze.h"

// Constructor.
SolveMaze::SolveMaze(QWidget *parent) : QMainWindow(parent)
{
    this->show();
}

SolveMaze::SolveMaze(int height, int width, NutnDS_Maze::Element map[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth], const Point* startPos)
{
    // Print info.
    QMessageBox* qm = new QMessageBox;

    qm->setFont(QFont("Arial", 12));
    qm->setWindowTitle("Message - Maze Solver");
    qm->setText("[ Maze Info ]\nSize : " + QString::number(height) + " x " + QString::number(width) + "\nStart : (" + QString::number(startPos->getI()+1) + ", " + QString::number(startPos->getJ()+1) + ")");
    qm->show();

    // Set window title.
    this->setWindowTitle("Solved - Maze Solver");

    // Use namespace.
    using namespace NutnDS_Maze;

    // Solve maze.
    Maze* question = new Maze(height, width, map);
    NutnDS_Point::PointSet solutionPath;
    Element solution[kMaxHeight][kMaxWidth];
    int steps[kMaxHeight][kMaxWidth];

    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            solution[i][j] = wall;
            steps[i][j] = 0;
        }
    }

    question->setMap(startPos->getI(), startPos->getJ(), road);
    question->solve(startPos->getI(), startPos->getJ());

    // Has solution. Convert solution path to map.
    if(question->getNumSolution() > 0)
    {
        solutionPath = question->getSolution(0);

        for(int i=0; i<solutionPath.getSize(); ++i)
        {
            solution[solutionPath.getPointI(i)][solutionPath.getPointJ(i)] = road;
            steps[solutionPath.getPointI(i)][solutionPath.getPointJ(i)] = i+1;
        }
    }

    // Generate solution map buttons.
    const int kButtonSize = 30;
    QPushButton* solutionGui[kMaxHeight][kMaxWidth];
    QHBoxLayout* hBoxLayout_row[kMaxHeight];
    QVBoxLayout* vBoxLayout_main = new QVBoxLayout;
    QPalette palette;

    vBoxLayout_main->setSpacing(0);
    vBoxLayout_main->setContentsMargins(0, 0, 0, 0);

    for(int i=0; i<height; ++i)
    {
        hBoxLayout_row[i] = new QHBoxLayout;
        hBoxLayout_row[i]->setSpacing(0);
        vBoxLayout_main->addLayout(hBoxLayout_row[i]);

        for(int j=0; j<width; ++j)
        {
            solutionGui[i][j] = new QPushButton;
            solutionGui[i][j]->setMinimumSize(*(new QSize(kButtonSize, kButtonSize)));
            solutionGui[i][j]->setMaximumSize(*(new QSize(kButtonSize, kButtonSize)));
            solutionGui[i][j]->setFlat(true);
            solutionGui[i][j]->setAutoFillBackground(true);

            if(solution[i][j] == road)
            {
                solutionGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/road.png); color:#ffffff;");
                solutionGui[i][j]->setText(QString::number(steps[i][j]));
            }
            else
                solutionGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/wall.png);");

            hBoxLayout_row[i]->addWidget(solutionGui[i][j]);
        }
    }

    // Generate status bar.
    statusbar_readme = new QStatusBar;
    vBoxLayout_main->addWidget(statusbar_readme);

    if(question->getNumSolution() > 0)
        statusbar_readme->showMessage(" >> Solution found : " + QString::number(solutionPath.getSize()) + " step(s).");
    else
        statusbar_readme->showMessage(" >> Solution not found.");

    // Generate widget to be attached by solution map.
    QWidget* widget = new QWidget;
    widget->setLayout(vBoxLayout_main);

    // Setup window size.
    const int kMaxWindowSize = int(QGuiApplication::primaryScreen()->geometry().height() * 0.9);
    int windowWidth = (kButtonSize*width<=kMaxWindowSize) ? kButtonSize*width : kMaxWindowSize;
    int windowHeight = (kButtonSize*height+20<=kMaxWindowSize) ? kButtonSize*height+20 : kMaxWindowSize;

    // Generate scroll bar.
    QScrollArea* scroller = new QScrollArea;
    if(windowHeight==kMaxWindowSize || windowWidth==kMaxWindowSize)
    {
        scroller->setWidget(widget);
        scroller->setWidgetResizable(false);

        this->setMaximumSize(*(new QSize(windowWidth, windowHeight)));
        this->setMinimumSize(*(new QSize(windowWidth, windowHeight)));

        // Setup solved maze window.
        this->setCentralWidget(scroller);
        this->show();
    }
    else
    {
        this->setMaximumSize(*(new QSize(windowWidth, windowHeight)));
        this->setMinimumSize(*(new QSize(windowWidth, windowHeight)));

        // Setup solved maze window.
        this->setCentralWidget(widget);
        this->show();
    }
}

// Destructor.
SolveMaze::~SolveMaze()
{
    delete statusbar_readme;
}

