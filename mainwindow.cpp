#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mrandomizer = new Randomizer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_parsePushButton_clicked()
{
    QStringList outList;

    foreach(QString tempString, QString(ui->plainTextEdit->toPlainText()).split(QRegExp("\n")))
        if ((tempString.contains("[–]")) && !(tempString.contains("BAUDR8")) && !(tempString.contains("[deleted]")) && !(tempString.contains("xkcd_transcriber")))
        {
            outList.append(tempString.mid(tempString.indexOf("]") + 1, tempString.indexOf(" ") - tempString.indexOf("]") - 1));
        }
    outList.removeDuplicates();
    QString bytesToWrite;
    foreach (QString tempString, outList)
        bytesToWrite.append(tempString + '\n');

    QFile outputFile("/home/hpham/Desktop/names.txt");
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Could not open input file for writing...");
        return;
    }

    outputFile.write(bytesToWrite.toLocal8Bit());
    outputFile.flush();
    outputFile.close();

    QMessageBox::information(this, "Success!", "Finished! Number of entries: " + QString::number(outList.size()));

    ui->plainTextEdit->setPlainText(bytesToWrite);
}

void MainWindow::on_selectorPushButton_clicked()
{
    QStringList sendList = QString(ui->plainTextEdit->toPlainText()).split(QRegExp("\n"));
    mrandomizer->setList(sendList);
    mrandomizer->exec();
}
