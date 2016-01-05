#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <QDialog>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QTime>


namespace Ui {
class Randomizer;
}

class Randomizer : public QDialog
{
    Q_OBJECT

public:
    explicit Randomizer(QWidget *parent = 0);
    ~Randomizer();
    void setList(QStringList);
    int randInt(int, int);

private slots:
    void moveToNextTimeout();

    void on_selectWinnerPushButton_clicked();

private:
    Ui::Randomizer *ui;
    QTimer *moveToNextTimer;
    int loopsDone;
    int listCount;
    int winner;
};

#endif // RANDOMIZER_H
