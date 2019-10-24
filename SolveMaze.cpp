#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "SolveMaze.h"
#include "ui_SolveMaze.h"

// Constructor.
SolveMaze::SolveMaze(QWidget *parent) : QMainWindow(parent), ui(new Ui::SolveMaze)
{
    ui->setupUi(this);
    this->show();
}

SolveMaze::SolveMaze(int height, int width, NutnDS_Maze::Element map[NutnDS_Maze::kMaxHeight][NutnDS_Maze::kMaxWidth])
{
    // Set window title.
    this->setWindowTitle("Solved - Maze Solver");

    // Use namespace.
    using namespace NutnDS_Maze;

    // Solve maze.
    Maze* question = new Maze(height, width, map);
    NutnDS_Point::PointSet solutionPath;
    question->solve(0, 0);
    solutionPath = question->getSolution(0);

    // Convert solution path to map.
    Element solution[kMaxHeight][kMaxWidth];
    if(solutionPath.getSize() > 0)
    {
        for(int i=0; i<solutionPath.getSize(); ++i)
            solution[solutionPath.getPointI(i)][solutionPath.getPointJ(i)] = road;
    }

    //
    const int kButtonSize = 30;
    QPushButton* solutionGui[kMaxHeight][kMaxWidth];
    QHBoxLayout* hBoxLayout_row[kMaxWidth];
    QVBoxLayout* vBoxLayout_main = new QVBoxLayout;
    QPalette palette;

    vBoxLayout_main->setSpacing(0);
    vBoxLayout_main->setMargin(0);

    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            solutionGui[i][j] = new QPushButton;
            // solutionGui[i][j]->setText(QString::number(i*width+j+1));
            solutionGui[i][j]->setMinimumSize(*(new QSize(kButtonSize, kButtonSize)));
            solutionGui[i][j]->setMaximumSize(*(new QSize(kButtonSize, kButtonSize)));
            solutionGui[i][j]->setFlat(true);
            solutionGui[i][j]->setAutoFillBackground(true);

            if(solution[i][j] == road)
                solutionGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/road.jpg);");
            else
                solutionGui[i][j]->setStyleSheet("border:1px solid #000000; background-image:url(:/grass.png);");

            hBoxLayout_row[i]->addWidget(solutionGui[i][j]);
        }
    }

    // Generate status bar.
    statusbar_readme = new QStatusBar;
    vBoxLayout_main->addWidget(statusbar_readme);
    statusbar_readme->showMessage(" >> Solution" + ((solutionPath.getSize()>0)?QString::fromStdString(""):QString::fromStdString(" not")) + " found.");

    // Generate widget to be attached by solution map.
    QWidget* widget = new QWidget;
    widget->setLayout(vBoxLayout_main);

    // Setup input maze window.
    this->setCentralWidget(widget);
    this->setMaximumSize(*(new QSize(kButtonSize*width, kButtonSize*height+30+20)));
    this->setMinimumSize(*(new QSize(kButtonSize*width, kButtonSize*height+30+20)));
    this->show();
}

// Destructor.
SolveMaze::~SolveMaze()
{
    delete ui;
    delete statusbar_readme;
}
