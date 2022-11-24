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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    MainWindow::setFixedSize(800,600);

//    QLabel * label1 = new QLabel(this);
//    label1->setText("1");
//    label1->setFrameStyle(QFrame::Box | QFrame::Plain);
//    label1->setLineWidth(5);



    QHBoxLayout *paintingAreaLayout = new QHBoxLayout();
    QVBoxLayout *infoAreaLayout = new QVBoxLayout();
    QVBoxLayout *bresenhamCircleButtonLayout = new QVBoxLayout();
    QHBoxLayout *bresenhamEntryCenterLayout = new QHBoxLayout();

    infoAreaLayout->addLayout(bresenhamCircleButtonLayout);

    bresenhamEntryCenterLayout->setSpacing(1);
    bresenhamCircleButton = new QRadioButton(QString("Bresenham (Circle)"), this);
    connect(bresenhamCircleButton, SIGNAL(toggled(bool)), this, SLOT(refreshImage()));

    QLabel * centerOfCircleLabel = new QLabel(this);
    centerOfCircleLabel->setText("Center:");
//    centerOfCircleLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
//    centerOfCircleLabel->setLineWidth(5);
    centerOfCircleLabel->setFixedWidth(70);

    QLabel * xCenterLabel = new QLabel(this);
    xCenterLabel->setText("X:");
//    xCenterLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
//    xCenterLabel->setLineWidth(5);
    xCenterLabel->setFixedWidth(20);

    QLabel * emptyCenterLabel = new QLabel(this);
    emptyCenterLabel->setText("    ");
//    emptyCenterLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
//    emptyCenterLabel->setLineWidth(5);
    emptyCenterLabel->setFixedWidth(20);

    QLabel * yCenterLabel = new QLabel(this);
    yCenterLabel->setText("Y:");
//    yCenterLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
//    yCenterLabel->setLineWidth(5);
    yCenterLabel->setFixedWidth(20);

    xSpinBox  = new QSpinBox(this);
    xSpinBox->setMaximum(17);
    xSpinBox->setMinimum(-15);
    xSpinBox->setFixedWidth(86);
    xSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    xSpinBox->setFixedHeight(25);
    xSpinBox->setFixedWidth(70);

    ySpinBox  = new QSpinBox(this);
    ySpinBox->setMaximum(17);
    ySpinBox->setMinimum(-15);
    ySpinBox->setFixedWidth(86);
    ySpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ySpinBox->setFixedHeight(25);
    ySpinBox->setFixedWidth(70);

    QLabel * radiusCircleLabel = new QLabel(this);
    radiusCircleLabel->setText("Radius:");
//    radiusCircleLabel->setFrameStyle(QFrame::Box | QFrame::Plain);
//    radiusCircleLabel->setLineWidth(5);
    radiusCircleLabel->setFixedWidth(70);

    radiusSpinBox  = new QSpinBox(this);
    radiusSpinBox->setMaximum(17);
    radiusSpinBox->setMinimum(0);
    radiusSpinBox->setFixedWidth(80);
    radiusSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    QPushButton* refreshPushButton = new QPushButton(QString("Refresh"), this);
    refreshPushButton->setFixedHeight(60);
    refreshPushButton->setFixedWidth(240);
    connect(refreshPushButton, SIGNAL(clicked()), this, SLOT(refreshImage()));

    bresenhamCircleButtonLayout->setSpacing(10);
    bresenhamCircleButtonLayout->addWidget(bresenhamCircleButton, 1, Qt::AlignTop);
    bresenhamCircleButtonLayout->addWidget(centerOfCircleLabel, 1, Qt::AlignTop);
    bresenhamCircleButtonLayout->addLayout(bresenhamEntryCenterLayout);
    bresenhamEntryCenterLayout->addWidget(xCenterLabel, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout->addWidget(xSpinBox, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout->addWidget(yCenterLabel, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout->addWidget(ySpinBox, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout->addWidget(emptyCenterLabel, 1, Qt::AlignLeft);
    bresenhamCircleButtonLayout->addWidget(radiusCircleLabel, 1, Qt::AlignLeft);
    bresenhamCircleButtonLayout->addWidget(radiusSpinBox, 1, Qt::AlignLeft);

    infoAreaLayout->addWidget(refreshPushButton, 0, Qt::AlignBottom);

    paintingAreaLayout->setGeometry(QRect(0, 0, 550, 600));
    infoAreaLayout->setGeometry(QRect(555, 0, 230, 595));
    bresenhamCircleButtonLayout->setGeometry(QRect(560, 20, 250, 140));





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

    painter.drawLine(0,300,545,300);
    painter.drawLine(545,300,540,305);
    painter.drawLine(545,300,540,295);

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

    int radius = image.radiusOfCircle;
    int x0 = 275 + image.centerOfCircleX * 15;
    int y0 = 300 - image.centerOfCircleY * 15;
    painter.setBrush(QBrush(Qt::black,Qt::BDiagPattern));
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;
    image.setPenWidth(3);
    painter.setPen(QPen(Qt::black, image.getPenWidth()));

    if(radius != 0){
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




}



// Color
void MainWindow::refreshImage() {
//    if(bresenhamCircleButton->isA)
    int x = xSpinBox->value();
    int y = ySpinBox->value();
    int r = radiusSpinBox->value();

    image.setCirceRadius(r);
    image.setCirceCenterX(x);
    image.setCirceCenterY(y);
    repaint();


}

