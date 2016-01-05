#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include "randomizer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_parsePushButton_clicked();

    void on_selectorPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Randomizer *mrandomizer;
};

#endif // MAINWINDOW_H
