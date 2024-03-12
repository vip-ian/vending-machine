#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    buttonEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonEnabled()
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 200);
    ui->pbTang->setEnabled(money >= 300);
    ui->pbReset->setEnabled(money > 0);
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);

    buttonEnabled();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    QString a = "";
    int ten, fif, hun, fiv;
    fiv = money / 500;
    hun = (money - fiv * 500) / 100;
    fif = (money - hun * 100 + fiv * 500) / 50;
    ten = (money - fiv * 500 + hun * 100 + fif * 50) / 10;

    a += "five : " + QString::number(fiv) + "\n";
    a += "hundred : " + QString::number(hun) + "\n";
    a += "fif : " + QString::number(fif) + "\n";
    a += "ten : " + QString::number(ten) + "\n";

    money = 0;
    changeMoney(0);
    mb.information(nullptr, "Reset", a);
}

