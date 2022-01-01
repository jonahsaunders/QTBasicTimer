#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QTimer *updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, QOverload<>::of(&Dialog::update));
    timer.restart();
    updateTimer->start(1000);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_start_clicked()
{
    timer.restart();
    timer.start();
}

void Dialog::update(){
    ui->timerText->setText(QString::number((timer.elapsed()/1000)));
}

