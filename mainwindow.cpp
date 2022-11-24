#include "mainwindow.h"
#include "QtGui/qaction.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPainter>
#include <QPaintEvent>
#include <QPaintEngine>
#include <QRect>
#include <QPainterPath>
#include <QSize>
#include <QLabel>
#include<QMessageBox>
#include <QFileDialog>
#include <chrono>
#include <thread>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    MainWindow::setFixedSize(800,600);

    repaint();
}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, image.getPenWidth()));

    painter.drawLine(550,0,550,600);

    painter.drawLine(275,5,275,600);
    painter.drawLine(275,5,270,10);
    painter.drawLine(275,5,280,10);


    painter.drawLine(0,300,550,300);
    painter.drawLine(550,300,545,305);
    painter.drawLine(550,300,545,295);

    int cellSize = 15;

    for(int i = 5 + cellSize; i < 550 - cellSize; i+=cellSize){
        painter.drawLine(i,302,i,298);
        image.setPenWidth(1);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        painter.drawLine(i, 10, i, 600 - 10);
        image.setPenWidth(3);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
    }

    for(int i = 600 - cellSize ; i > 1; i-=cellSize){
        painter.drawLine(273,i,277,i);
        image.setPenWidth(1);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        painter.drawLine(cellSize, i, 550-cellSize, i);
        image.setPenWidth(3);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
    }
    int radius = 16;
    int x0 = 275;
    int y0 = 300;
    painter.setBrush(QBrush(Qt::black,Qt::BDiagPattern));
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    image.setPenWidth(3);
    painter.setPen(QPen(Qt::black, image.getPenWidth()));


    while (x >= y)
    {
        painter.drawRect( x * cellSize + x0,  y * cellSize + y0, cellSize, cellSize);
        painter.drawRect( y * cellSize + x0,  x * cellSize + y0, cellSize, cellSize);
        painter.drawRect(-x * cellSize + x0,  y * cellSize + y0, cellSize, cellSize);
        painter.drawRect(-y * cellSize + x0,  x * cellSize + y0, cellSize, cellSize);
        painter.drawRect(-x * cellSize + x0, -y * cellSize + y0, cellSize, cellSize);
        painter.drawRect(-y * cellSize + x0, -x * cellSize + y0, cellSize, cellSize);
        painter.drawRect( x * cellSize + x0, -y * cellSize + y0, cellSize, cellSize);
        painter.drawRect( y * cellSize + x0, -x * cellSize + y0, cellSize, cellSize);
        y++;
        if (radiusError < 0)
        {
            radiusError += 2 * y + 1;
        }
        else
        {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }




}



// Color
void MainWindow::setPenColor() {
    return;
}
void MainWindow::setBrushColor() {
    return;
}

// Help
void MainWindow::callAbout() {
    return;
}


