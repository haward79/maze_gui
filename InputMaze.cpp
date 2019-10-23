#include "InputMaze.h"
#include "ui_InputMaze.h"

InputMaze::InputMaze(QWidget *parent) : QMainWindow(parent), ui(new Ui::InputMaze)
{
    ui->setupUi(this);
}

InputMaze::~InputMaze()
{
    delete ui;
}

