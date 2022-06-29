#include "assistant.h"
#include "ui_assistant.h"

assistant::assistant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assistant)
{
    ui->setupUi(this);
    setWindowTitle("Assistance");
}

assistant::~assistant()
{
    delete ui;
}
