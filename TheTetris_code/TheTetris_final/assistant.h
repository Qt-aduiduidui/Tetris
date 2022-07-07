#ifndef ASSISTANT_H
#define ASSISTANT_H

#include <QDialog>

namespace Ui {
class assistant;
}

class assistant : public QDialog
{
    Q_OBJECT

public:
    explicit assistant(QWidget *parent = 0);
    ~assistant();

private:
    Ui::assistant *ui;
};

#endif // ASSISTANT_H
