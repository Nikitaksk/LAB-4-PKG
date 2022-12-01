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
#include <QGridLayout>
#include <QLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>
#include <cmath>


MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui -> setupUi(this);
    MainWindow::setMinimumSize(850, 600);

    QGridLayout* mainLayout = new QGridLayout();
    QHBoxLayout * paintingAreaLayout = new QHBoxLayout();
    QVBoxLayout * infoAreaLayout = new QVBoxLayout();

    QVBoxLayout * bresenhamCircleButtonLayout = new QVBoxLayout();
    QHBoxLayout * bresenhamEntryCenterLayout = new QHBoxLayout();

    QVBoxLayout * bresenhamLineLayout = new QVBoxLayout();
    QHBoxLayout * firstPointBresenhamLineLayout = new QHBoxLayout;
    QHBoxLayout * secondPointBresenhamLineLayout = new QHBoxLayout;

    infoAreaLayout -> addLayout(bresenhamCircleButtonLayout);
    infoAreaLayout -> addLayout(bresenhamLineLayout);

    bresenhamEntryCenterLayout -> setSpacing(1);

    QGridLayout* bresenhamCircleLayout = new QGridLayout();
    bresenhamCircleButton = new QRadioButton(QString("Bresenham (Circle)"), this);
    connect(bresenhamCircleButton, SIGNAL(clicked()), this, SLOT(refreshImageCircle()));

    QLabel * centerOfCircleLabel = new QLabel(this);
    centerOfCircleLabel -> setText("Center:");
    centerOfCircleLabel -> setFixedWidth(70);

    QLabel * xCenterLabel = new QLabel(this);
    xCenterLabel -> setText("X:");
    xCenterLabel -> setFixedWidth(this->width()/40);

    QLabel * emptyCenterLabel = new QLabel(this);
    emptyCenterLabel -> setText("    ");
    emptyCenterLabel -> setFixedWidth(20);

    QLabel * yCenterLabel = new QLabel(this);
    yCenterLabel -> setText("   Y:");
    yCenterLabel -> setFixedWidth(20);

    xCenterOfCircleSpinBox = new QSpinBox(this);
    xCenterOfCircleSpinBox -> setMaximum(17);
    xCenterOfCircleSpinBox -> setMinimum(-15);
    xCenterOfCircleSpinBox -> setFixedWidth(86);
    xCenterOfCircleSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    xCenterOfCircleSpinBox -> setFixedHeight(25);
    xCenterOfCircleSpinBox -> setFixedWidth(70);
    connect(xCenterOfCircleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInCircleChanged()));

    yCenterOfCircleSpinBox = new QSpinBox(this);
    yCenterOfCircleSpinBox -> setMaximum(17);
    yCenterOfCircleSpinBox -> setMinimum(-15);
    yCenterOfCircleSpinBox -> setFixedWidth(86);
    yCenterOfCircleSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    yCenterOfCircleSpinBox -> setFixedHeight(this->height()/24);
    yCenterOfCircleSpinBox -> setFixedWidth(70);
    connect(yCenterOfCircleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInCircleChanged()));

    QLabel * radiusCircleLabel = new QLabel(this);
    radiusCircleLabel -> setText("Radius:");
    radiusCircleLabel -> setFixedWidth(70);

    radiusSpinBox = new QSpinBox(this);
    radiusSpinBox -> setMaximum(17);
    radiusSpinBox -> setMinimum(0);
    radiusSpinBox -> setFixedWidth(80);
    radiusSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    connect(radiusSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInCircleChanged()));

    bresenhamCircleButtonLayout -> setSpacing(10);
    bresenhamCircleButtonLayout -> addWidget(bresenhamCircleButton, 1, Qt::AlignTop);
    bresenhamCircleButtonLayout -> addWidget(centerOfCircleLabel, 1, Qt::AlignTop);
    bresenhamCircleButtonLayout -> addLayout(bresenhamEntryCenterLayout);
    bresenhamEntryCenterLayout -> addWidget(xCenterLabel, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout -> addWidget(xCenterOfCircleSpinBox, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout -> addWidget(yCenterLabel, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout -> addWidget(yCenterOfCircleSpinBox, 0, Qt::AlignLeft);
    bresenhamEntryCenterLayout -> addWidget(emptyCenterLabel, 1, Qt::AlignLeft);
    bresenhamCircleButtonLayout -> addWidget(radiusCircleLabel, 1, Qt::AlignLeft);
    bresenhamCircleButtonLayout -> addWidget(radiusSpinBox, 1, Qt::AlignLeft);




    bresenhamLineButton = new QRadioButton(QString("Bresenham (Line)"), this);
    connect(bresenhamLineButton, SIGNAL(clicked()), this, SLOT(refreshImageLine()));

    QLabel * xOfFirstPointLabel = new QLabel(this);
    xOfFirstPointLabel -> setText("X1:");
    xOfFirstPointLabel -> setFixedWidth(25);
    xOfFirstPointLabel -> setFixedHeight(25);

    QLabel * yOfFirstPointLabel = new QLabel(this);
    yOfFirstPointLabel -> setText("   Y1 : ");
    yOfFirstPointLabel -> setFixedWidth(25);
    yOfFirstPointLabel -> setFixedHeight(27);

    QLabel * zOfFirstPointLabel = new QLabel(this);
    zOfFirstPointLabel -> setText("  ");
    zOfFirstPointLabel -> setFixedWidth(25);
    zOfFirstPointLabel -> setFixedHeight(25);


    xOfFirstPointSpinBox = new QSpinBox(this);
    xOfFirstPointSpinBox -> setMaximum(17);
    xOfFirstPointSpinBox -> setMinimum(-15);
    xOfFirstPointSpinBox -> setFixedWidth(86);
    xOfFirstPointSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    xOfFirstPointSpinBox -> setFixedHeight(25);
    xOfFirstPointSpinBox -> setFixedWidth(70);
    connect(xOfFirstPointSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInLinesChanged()));


    yOfFirstPointSpinBox = new QSpinBox(this);
    yOfFirstPointSpinBox -> setMaximum(17);
    yOfFirstPointSpinBox -> setMinimum(-15);
    yOfFirstPointSpinBox -> setFixedWidth(86);
    yOfFirstPointSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    yOfFirstPointSpinBox -> setFixedHeight(25);
    yOfFirstPointSpinBox -> setFixedWidth(70);
    connect(yOfFirstPointSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInLinesChanged()));


    bresenhamLineLayout -> addWidget(bresenhamLineButton);

    firstPointBresenhamLineLayout -> setSpacing(10);
    firstPointBresenhamLineLayout -> addWidget(xOfFirstPointLabel, 0);
    firstPointBresenhamLineLayout -> addWidget(xOfFirstPointSpinBox, 0, Qt::AlignLeft);
    firstPointBresenhamLineLayout -> addWidget(yOfFirstPointLabel, 0, Qt::AlignLeft);
    firstPointBresenhamLineLayout -> addWidget(yOfFirstPointSpinBox, 0, Qt::AlignLeft);
    firstPointBresenhamLineLayout -> addWidget(zOfFirstPointLabel, 1, Qt::AlignLeft);

    QLabel * xOfSecondPointLabel = new QLabel(this);
    xOfSecondPointLabel -> setText("X2:");
    xOfSecondPointLabel -> setFixedWidth(25);
    xOfSecondPointLabel -> setFixedHeight(27);

    QLabel * yOfSecondPointLabel = new QLabel(this);
    yOfSecondPointLabel -> setText("   Y2 : ");
    yOfSecondPointLabel -> setFixedWidth(27);
    yOfSecondPointLabel -> setFixedHeight(25);

    QLabel * zOfSecondPointLabel = new QLabel(this);
    zOfSecondPointLabel -> setText("  ");
    //    zOfSecondPointLabel -> setFrameStyle(QFrame::Box | QFrame::Plain);
    //    zOfSecondPointLabel -> setLineWidth(5);
    zOfSecondPointLabel -> setFixedWidth(25);
    zOfSecondPointLabel -> setFixedHeight(1);

    xOfSecondPointSpinBox = new QSpinBox(this);
    xOfSecondPointSpinBox -> setMaximum(17);
    xOfSecondPointSpinBox -> setMinimum(-15);
    xOfSecondPointSpinBox -> setFixedWidth(86);
    xOfSecondPointSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    xOfSecondPointSpinBox -> setFixedHeight(25);
    xOfSecondPointSpinBox -> setFixedWidth(70);
    connect(xOfSecondPointSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInLinesChanged()));


    yOfSecondPointSpinBox = new QSpinBox(this);
    yOfSecondPointSpinBox -> setMaximum(17);
    yOfSecondPointSpinBox -> setMinimum(-15);
    yOfSecondPointSpinBox -> setFixedWidth(86);
    yOfSecondPointSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    yOfSecondPointSpinBox -> setFixedHeight(25);
    yOfSecondPointSpinBox -> setFixedWidth(70);

    connect(yOfSecondPointSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInLinesChanged()));


    secondPointBresenhamLineLayout -> setSpacing(10);
    secondPointBresenhamLineLayout -> addWidget(xOfSecondPointLabel, 1, Qt::AlignLeft);
    secondPointBresenhamLineLayout -> addWidget(xOfSecondPointSpinBox, 0, Qt::AlignLeft);
    secondPointBresenhamLineLayout -> addWidget(yOfSecondPointLabel, 1, Qt::AlignLeft);
    secondPointBresenhamLineLayout -> addWidget(yOfSecondPointSpinBox, 0, Qt::AlignLeft);
    secondPointBresenhamLineLayout -> addWidget(zOfSecondPointLabel, 1, Qt::AlignRight);

    bresenhamLineLayout -> addLayout(firstPointBresenhamLineLayout);
    bresenhamLineLayout -> addLayout(secondPointBresenhamLineLayout);



    QGridLayout * stepAlgorythm = new QGridLayout();
    QLabel * xOfFirstPointLabelStep = new QLabel(this);
    xOfFirstPointLabelStep -> setText("X1:");
    xOfFirstPointLabelStep -> setFixedWidth(25);
    xOfFirstPointLabelStep -> setFixedHeight(25);

    QLabel * yOfFirstPointLabelStep = new QLabel(this);
    yOfFirstPointLabelStep -> setText("Y1:");
    yOfFirstPointLabelStep -> setFixedWidth(25);
    yOfFirstPointLabelStep -> setFixedHeight(27);

    QLabel * xOfSecondPointLabelStep = new QLabel(this);
    xOfSecondPointLabelStep -> setText("X2:");
    xOfSecondPointLabelStep -> setFixedWidth(25);
    xOfSecondPointLabelStep -> setFixedHeight(25);

    QLabel * yOfSecondPointLabelStep = new QLabel(this);
    yOfSecondPointLabelStep -> setText("Y2:");
    yOfSecondPointLabelStep -> setFixedWidth(25);
    yOfSecondPointLabelStep -> setFixedHeight(27);


    x1StepSpinBox = new QSpinBox(this);
    x1StepSpinBox -> setMaximum(17);
    x1StepSpinBox -> setMinimum(-15);
    x1StepSpinBox -> setFixedWidth(86);
    x1StepSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    x1StepSpinBox -> setFixedHeight(25);
    x1StepSpinBox -> setFixedWidth(70);
    connect(x1StepSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInStepChanged()));


    y1StepSpinBox = new QSpinBox(this);
    y1StepSpinBox -> setMaximum(17);
    y1StepSpinBox -> setMinimum(-15);
    y1StepSpinBox -> setFixedWidth(86);
    y1StepSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    y1StepSpinBox -> setFixedHeight(25);
    y1StepSpinBox -> setFixedWidth(70);
    connect(y1StepSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInStepChanged()));

    x2StepSpinBox = new QSpinBox(this);
    x2StepSpinBox -> setMaximum(17);
    x2StepSpinBox -> setMinimum(-15);
    x2StepSpinBox -> setFixedWidth(86);
    x2StepSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    x2StepSpinBox -> setFixedHeight(25);
    x2StepSpinBox -> setFixedWidth(70);
    connect( x2StepSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInStepChanged()));


    y2StepSpinBox = new QSpinBox(this);
    y2StepSpinBox -> setMaximum(17);
    y2StepSpinBox -> setMinimum(-15);
    y2StepSpinBox -> setFixedWidth(86);
    y2StepSpinBox -> setButtonSymbols(QAbstractSpinBox::NoButtons);
    y2StepSpinBox -> setFixedHeight(25);
    y2StepSpinBox -> setFixedWidth(70);
    connect( y2StepSpinBox, SIGNAL(valueChanged(int)), this, SLOT(valueInStepChanged()));

    stepLineButton = new QRadioButton(QString("Step"), this);
    connect(stepLineButton, SIGNAL(clicked()), this, SLOT(refreshImageStepLine()));
    stepAlgorythm->addWidget(stepLineButton,0,0);
    stepAlgorythm->addWidget(xOfFirstPointLabelStep,1,0, Qt::AlignLeft);
    stepAlgorythm->addWidget(x1StepSpinBox,1,1, Qt::AlignLeft);
    stepAlgorythm->addWidget(yOfFirstPointLabelStep,1,2);
    stepAlgorythm->addWidget(y1StepSpinBox,1,3);
    stepAlgorythm->setColumnMinimumWidth(0,10);
    stepAlgorythm->addWidget(xOfSecondPointLabelStep,2,0, Qt::AlignLeft);
    stepAlgorythm->addWidget(x2StepSpinBox,2,1, Qt::AlignLeft);
    stepAlgorythm->addWidget(yOfSecondPointLabelStep,2,2);
    stepAlgorythm->addWidget(y2StepSpinBox,2,3);


    mainLayout->addLayout(paintingAreaLayout,0, 0, Qt::AlignLeft);
    mainLayout->addLayout(infoAreaLayout, 0, 1, Qt::AlignLeft);
    mainLayout->addLayout(stepAlgorythm,1,1 , {Qt::AlignLeft, Qt::AlignTop});
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(1, 0);
    mainLayout->setColumnStretch(2, 0);

    mainLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->setColumnMinimumWidth(0, 650);
    mainLayout->setRowMinimumHeight(1,900);



//    MainWindow::setLayout(infoAreaLayout);
    centralWidget()->setLayout(mainLayout);



    repaint();
}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::paintEvent(QPaintEvent * ) {
    QPainter painter(this);


    // x: 550 = this->width() * 0.6875;

    painter.setPen(QPen(Qt::black, image.getPenWidth()));
//    510 из 550 из 800 клеточки
    image.setPenWidth(3);
    painter.setPen(QPen(Qt::black, image.getPenWidth()));
    painter.drawLine(this->width() * 0.6875, 0, this->width() * 0.6875, this->height());

    painter.drawLine(this->width() * 0.34375, 5, this->width() * 0.34375, this->height());
    painter.drawLine(this->width() * 0.34375,5,this->width() * 0.34375 + this->width() * 0.00625, 10);
    painter.drawLine(this->width() * 0.34375, 5, this->width() * 0.34375 - this->width() * 0.00625, 10);
//    painter.drawText(280, 10, QString("Y"));


    painter.drawLine(0, this->height() / 2, this->width() * 0.6875, this->height() / 2);
    painter.drawLine(this->width() * 0.6875, this->height() / 2, this->width() * 0.6875 - this->width() * 0.01, this->height() / 2 + this->height() / 90);
    painter.drawLine(this->width() * 0.6875, this->height() / 2, this->width() * 0.6875 - this->width() * 0.01, this->height() / 2 - this->height() / 90);

//    painter.drawText(535, 290, QString("X"));
//    image.setPenWidth(1);



    int cellSize = this->height()/40;
//    int counter = -17;
//    for (int i = this->width()/160 + cellSize; i < this->width() * 0.6875 - cellSize; i += cellSize) {
//        painter.drawLine(i, this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/300);
//        image.setPenWidth(1);

//        QFont font("Courier New");
//        font.setStyleHint(QFont::Monospace);
//        font.setPixelSize(this->height()/70);
//        painter.setFont(font);
//        if(counter < -11){
//            painter.drawText(QRect(i , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
//        } else {
//            painter.drawText(QRect(i + 3 , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
//        }


//        painter.setPen(QPen(Qt::black, image.getPenWidth()));
//        counter++;

//        painter.drawLine(i, this->height()/60, i, this->height() - this->height()/60);
//        image.setPenWidth(3);
//        painter.setPen(QPen(Qt::black, image.getPenWidth()));
//    }
    int counter = 0;
    image.setPenWidth(1);
    QFont font("Courier New");
    font.setStyleHint(QFont::Monospace);
    font.setPixelSize(this->height()/70);
    painter.setFont(font);

    painter.setPen(QPen(Qt::black, image.getPenWidth()));
    for (int i = this->width() * 0.34375 ; i > this->width()/160 ; i -= cellSize) {

        if(counter < -11){
            painter.drawText(QRect(i , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
        } else {
            painter.drawText(QRect(i + 3 , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
        }
        painter.drawLine(i, this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/300);

        painter.drawLine(i, this->height()/30, i, this->height() - this->height()/30);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
        counter--;
    }
    counter = 0;
    for (int i = this->width() * 0.34375; i < this->width() * 0.6875 - cellSize; i += cellSize) {
        if(counter < -11){
            painter.drawText(QRect(i , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
        } else {
            painter.drawText(QRect(i + 3 , this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/600), QString::number(counter));
        }
        painter.drawLine(i, this->height()/2 + this->height()/300, i, this->height()/2 - this->height()/300);
        painter.drawLine(i, this->height()/30, i, this->height() - this->height()/30);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));
        counter++;
    }
     counter = 0;
    for (int i = this->height() / 2; i > cellSize + this->height()/200; i -= cellSize) {
//        painter.drawLine(273, i, 277, i);
//        image.setPenWidth(1);
//        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        painter.drawText(QRect(this->width() * 0.3475, i + 3, this->width() * 0.3475 - 1, i), QString::number(counter));
        counter++;

        painter.drawLine(this->width() / 90, i, this->width() * 0.6875 - this->width() / 90, i);
    }
    counter = 1;
    for (int i = this->height() / 2; i < this->height() -  this->height()/300 - cellSize; i += cellSize) {
//        painter.awLine(273, i, 277, i);
//        image.setPenWidth(1);
//        painter.setPen(QPen(Qt::black, image.getPenWidth()));

//        painter.drawText(QRect(278, i + 3, 277, i), QString::number(counter));
        counter--;
        painter.drawText(QRect(this->width() * 0.3475, i + 3, this->width() * 0.3475 - 1, i), QString::number(counter));

        painter.drawLine(this->width() / 90, i, this->width() * 0.6875- this->width() / 90, i);

    }
    painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern));
    image.setPenWidth(3);
    painter.setPen(QPen(Qt::black, image.getPenWidth()));

    if (image.currentLine == BRESENHAMCIRCLE) {
        int radius = image.radiusOfCircle;
        int x0 = this->width() * 0.6875 / 2 + image.centerOfCircleX * cellSize;
        int y0 = this->height() / 2 - image.centerOfCircleY * cellSize;
        painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern));
        int x = radius;
        int y = 0;
        int radiusError = 1 - x;
        image.setPenWidth(3);
        painter.setPen(QPen(Qt::black, image.getPenWidth()));

        if (radius != 0) {
            while (x >= y) {
                painter.drawRect(x * cellSize + x0, y * cellSize + y0, cellSize, cellSize);
                painter.drawRect(y * cellSize + x0, x * cellSize + y0, cellSize, cellSize);
                painter.drawRect(-x * cellSize + x0, y * cellSize + y0, cellSize, cellSize);
                painter.drawRect(-y * cellSize + x0, x * cellSize + y0, cellSize, cellSize);
                painter.drawRect(-x * cellSize + x0, -y * cellSize + y0, cellSize, cellSize);
                painter.drawRect(-y * cellSize + x0, -x * cellSize + y0, cellSize, cellSize);
                painter.drawRect(x * cellSize + x0, -y * cellSize + y0, cellSize, cellSize);
                painter.drawRect(y * cellSize + x0, -x * cellSize + y0, cellSize, cellSize);
                y++;
                if (radiusError < 0) {
                    radiusError += 2 * y + 1;
                } else {
                    x--;
                    radiusError += 2 * (y - x + 1);
                }
            }
        }
    }

    if (image.currentLine == BRESENHAMLINE) {

//        painter.setPen(QPen(Qt::red, image.getPenWidth()));

        int x1 = (this->width() * 0.6875 / 2 + image.bresenhamLineX1 * cellSize);
        int y1 = (this->height() / 2 - image.bresenhamLineY1 * cellSize);

        int x2 = (this->width() * 0.6875 / 2 + (image.bresenhamLineX2) * cellSize);
        int y2 = (this->height() / 2 - (image.bresenhamLineY2) * cellSize);

        const int deltaX = abs(x2 - x1);
        const int deltaY = abs(y2 - y1);
        const int signX = x1 < x2 ? 15 : -15;
        const int signY = y1 < y2 ? 15 : -15;
        int error = deltaX - deltaY;
////        painter.drawPoint(x2,y2);
        painter.drawRect(x2, y2 - cellSize, cellSize, cellSize);
        while(x1 != x2 || y1 != y2)
       {
////            painter.drawPoint(x1,y1);
            painter.drawRect(x1 , y1 - cellSize, cellSize, cellSize);
            int error2 = error * 2;
            if(error2 > -deltaY)
            {
                error -= deltaY;
                x1 += signX;
            }
            if(error2 < deltaX)
            {
                error += deltaX;
                y1 += signY;
            }
        }

    }
    if(image.currentLine == STEPLINE){
        int x1 = (this->width() * 0.6875 / 2 + (image.bresenhamLineX1 * cellSize));


        int y1 = (this->height() / 2 - image.bresenhamLineY1 * cellSize);

        int x2 = (this->width() * 0.6875 / 2 + (image.bresenhamLineX2 * cellSize));
        int y2 = (this->height() / 2 - (image.bresenhamLineY2) * cellSize);



        if (x1 > x2)
            {
                std::swap(x1, x2);
                std::swap(y1, y2);
            }
            int dx = x2 - x1;

            int dy = y2 - y1;
            if (dx == 0 && dy == 0)
            {
                 painter.drawRect(x1, y1 - cellSize, cellSize, cellSize);
            }
            else
            {
                 if (std::abs(dx) > std::abs(dy)) {
                     for(int x = x1; x <= x2; x+=cellSize) {
                         int temp = y1 + dy * (x - x1) / dx;
                         painter.drawRect(x, ((temp - cellSize - 5 ) / cellSize) * cellSize, cellSize, cellSize);
                     }
                 }
                 else
                 {
                     if (y1 > y2)
                     {
                         std::swap(x1, x2);
                         std::swap(y1, y2);
                     }

                     for (int y = y1; y <= y2; y+=cellSize)
                     {
                         int temp = dx / dy * (y - y1) + x1;
                         painter.drawRect(temp, y - cellSize, cellSize, cellSize);
                     }
                 }
            }


    }
painter.setPen(QPen(Qt::black, image.getPenWidth()));

}

void MainWindow::valueInLinesChanged(){
//    image.currentLine = BRESENHAMLINE;
    bresenhamLineButton->setChecked(1);
    refreshImageLine();
}

void MainWindow::valueInCircleChanged(){
//    image.currentLine = BRESENHAMCIRCLE;
    bresenhamCircleButton->setChecked(1);
    refreshImageCircle();
}

void MainWindow::valueInStepChanged(){
//    image.currentLine = BRESENHAMCIRCLE;

    stepLineButton->setChecked(1);
    refreshImageStepLine();
}

void MainWindow::refreshImageCircle() {
    image.currentLine = BRESENHAMCIRCLE;
    int x = xCenterOfCircleSpinBox -> value();
    int y = yCenterOfCircleSpinBox -> value();
    int r = radiusSpinBox -> value();

    image.setCirceRadius(r);
    image.setCirceCenterX(x);
    image.setCirceCenterY(y);
    repaint();
}

void MainWindow::refreshImageLine() {
    image.currentLine = BRESENHAMLINE;
    int X1 = xOfFirstPointSpinBox -> value();
    int Y1 = yOfFirstPointSpinBox -> value();
    int X2 = xOfSecondPointSpinBox -> value();
    int Y2 = yOfSecondPointSpinBox -> value();


    image.bresenhamLineX1 = X1;
    image.bresenhamLineY1 = Y1;
    image.bresenhamLineX2 = X2;
    image.bresenhamLineY2 = Y2;
    repaint();
}

void MainWindow::refreshImageStepLine() {
    image.currentLine = BRESENHAMLINE;

    int X1 = x1StepSpinBox -> value();
    int Y1 = y1StepSpinBox -> value();
    int X2 = x2StepSpinBox -> value();
    int Y2 = y2StepSpinBox -> value();


    image.bresenhamLineX1 = X1;
    image.bresenhamLineY1 = Y1;
    image.bresenhamLineX2 = X2;
    image.bresenhamLineY2 = Y2;
    repaint();
}

void MainWindow::resizeEvent(QResizeEvent * /*resizeEvent*/) {
    int containerWidth = this->width();
    int containerHeight = this->height();

    int contentsHeight = containerHeight ;
    int contentsWidth = containerHeight * 1.333333;
    if (contentsWidth > containerWidth ) {
        contentsWidth = containerWidth ;
        contentsHeight = containerWidth / 1.33333;
    }

    MainWindow::resize(contentsWidth, contentsHeight);

//    paintingAreaLayout -> setGeometry(QRect(0, 0, this->width() * 0.6875, this->height()));
//    infoAreaLayout -> setGeometry(QRect(this->width() * 0.69375, 0, this->width() * 0.2875, 595));
//    bresenhamCircleButtonLayout -> setGeometry(QRect(this->width() * 0.7, 20, this->width() * 0.3125, this->height() * 0.233333333));

//    bresenhamLineLayout -> setGeometry(QRect(this->width() * 0.69375, this->height() * 0.2833333, 230, this->height() * 0.233333333));
//    firstPointBresenhamLineLayout -> setGeometry(QRect(this->width() * 0.7, this->height() * 0.25833333, this->width() * 0.3125, this->height() * 0.233333333));
//    secondPointBresenhamLineLayout -> setGeometry(QRect(this->width() * 0.7, this->height() * 0.3, this->width() * 0.3125, this->height() * 0.233333333));
}



void MainWindow::refresh() {
    if (bresenhamCircleButton -> isChecked()) {
        std::cout << "YA DOLZHEN RISOVAT KRUG BLYAT" << std::endl;
        image.currentLine = BRESENHAMCIRCLE;
        refreshImageCircle();
    }

    if (bresenhamLineButton -> isChecked()) {
        std::cout << "YA DOLZHEN RISOVAT LINIU" << std::endl;
        image.currentLine = BRESENHAMLINE;
        refreshImageLine();
    }
    repaint();
}

