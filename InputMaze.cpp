#include <QMessageBox>
#include "InputMaze.h"
#include "ui_InputMaze.h"

// Constructor.
InputMaze::InputMaze(QWidget *parent) : QMainWindow(parent), ui(new Ui::InputMaze)
{
    ui->setupUi(this);

    // Set window title.
    this->setWindowTitle("Input maze - Maze Solver");
}

InputMaze::InputMaze(int height, int width)
{
    // Set window title.
    this->setWindowTitle("Input maze - Maze Solver");

    // .
}

// Destructor.
InputMaze::~InputMaze()
{
    delete ui;
}

