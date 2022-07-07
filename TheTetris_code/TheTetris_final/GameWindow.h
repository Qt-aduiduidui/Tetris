#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

protected:
    void keyPressEvent(QKeyEvent *e);

private slots:
    void slotUpdateScore(int nScore);
    void slotUpdateSpeed(int nSpeed);
    void on_Pause_clicked();

private:
    Ui::GameWindow *ui;
    int Speed;
};

#endif // GAMEWINDOW_H
