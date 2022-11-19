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
    painter.drawLine(200,5,200,300);
    painter.drawLine(200,5,195,15);
    painter.drawLine(200,5,205,15);

    painter.drawLine(0,150,400,150);
    painter.drawLine(400,150,390,155);
    painter.drawLine(400,150,390,145);

    int cellSize = 15;

    for(int i = 5 + cellSize; i < 400 - cellSize; i+=cellSize){
        painter.drawLine(i,152,i,148);
        image.setPenWidth(1);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        painter.drawLine(i, 2 *cellSize - 5, i, 300 - 5);
        image.setPenWidth(3);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
    }

    for(int i = 300 - cellSize ; i >  cellSize; i-=cellSize){
        painter.drawLine(198,i,202,i);
        image.setPenWidth(1);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        painter.drawLine(cellSize, i, 400 - cellSize, i);
        image.setPenWidth(3);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
    }
    int radius = 8;
    int x0 = 200;
    int y0 = 150;
    painter.setBrush(QBrush(Qt::black,Qt::BDiagPattern));
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    image.setPenWidth(3);
    painter.setPen(QPen(Qt::black, image.getPenWidth()));


    while (x >= y)
    {
        painter.drawRect( x * cellSize + x0,  y * cellSize + y0, cellSize, cellSize);
        std::this_thread::sleep_for (std::chrono::milliseconds(1000));
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


