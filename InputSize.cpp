#include "InputSize.h"
#include "ui_InputSize.h"

InputSize::InputSize(QWidget *parent) : QMainWindow(parent), ui(new Ui::InputSize)
{
    ui->setupUi(this);
}

InputSize::~InputSize()
{
    delete ui;
}

void InputSize::load()
{
    // Print welcome message to status bar.
    ui->statusbar_message->showMessage(" >> Welcome to maze soler.");
}

bool InputSize::isDigit(QString str) const
{
    QRegExp regexp("\\d*");

    if(regexp.exactMatch(str))
        return true;
    else
        return false;
}

void InputSize::on_lineEdit_height_textEdited(const QString& content)
{
    if(isDigit(content) && content.toInt()>0)
        ui->statusbar_message->showMessage("");
    else
    {
        ui->statusbar_message->showMessage(" >> Invalid height value.");
        ui->lineEdit_height->setText("");
    }
}

void InputSize::on_lineEdit_width_textEdited(const QString& content)
{
    if(isDigit(content) && content.toInt()>0)
        ui->statusbar_message->showMessage("");
    else
    {
        ui->statusbar_message->showMessage(" >> Invalid width value.");
        ui->lineEdit_width->setText("");
    }
}

void InputSize::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_height->text()!="" && ui->lineEdit_width->text()!="")
    {
        // Open input maze window.
        inputMaze = new InputMaze;
        inputMaze->show();

        // Close input maze size window.
        this->close();
    }
    else
        ui->statusbar_message->showMessage(" >> Please fill height and width.");
}

