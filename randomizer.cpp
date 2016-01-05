#include "randomizer.h"
#include "ui_randomizer.h"

Randomizer::Randomizer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Randomizer)
{
    ui->setupUi(this);
    loopsDone = 0;
    listCount = 0;
    moveToNextTimer = new QTimer(this);
    connect(moveToNextTimer, SIGNAL(timeout()), this, SLOT(moveToNextTimeout()));
}

Randomizer::~Randomizer()
{
    delete ui;
}

int Randomizer::randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

void Randomizer::setList(QStringList inputNames)
{
    ui->comboBox->clear();
    foreach(QString tempString, inputNames)
        ui->comboBox->addItem(tempString);
    ui->comboBox->setCurrentIndex(0);
    listCount = inputNames.size() - 1;
}

void Randomizer::moveToNextTimeout()
{
    if (ui->comboBox->currentIndex() < winner)
    {
        ui->comboBox->setCurrentIndex(ui->comboBox->currentIndex() + 1);
    }
    else
    {
        moveToNextTimer->stop();
        QMessageBox::information(this, "WINNER IS...", "Winner is: " + ui->comboBox->currentText());
    }
}

void Randomizer::on_selectWinnerPushButton_clicked()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    winner = randInt(0, listCount);
    moveToNextTimer->start(25);

}


