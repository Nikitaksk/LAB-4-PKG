#ifndef IMAGE_H
#define IMAGE_H

#include "QtGui/qcolor.h"
#include "QtGui/qwindowdefs.h"
#include <QVector>
#include <QLabel>
#include <QString>

enum Lines{
    BRESENHAMCIRCLE,
    BRESENHAMLINE,
    STEPLINE,
    DDALINE,
};

class Image {
private:
    QColor penColor = QColorConstants::Black;
    QColor brushColor = QColorConstants::Blue;
    int penWidth;

public:
    int centerOfCircleX;
    int centerOfCircleY;
    int radiusOfCircle;

    int bresenhamLineX1;
    int bresenhamLineY1;
    int bresenhamLineX2;
    int bresenhamLineY2;

    int stepLineX1;
    int stepLineY1;
    int stepLineX2;
    int stepLineY2;

    int ddaLineX1;
    int ddaLineY1;
    int ddaLineX2;
    int ddaLineY2;




    Lines currentLine;
    Image();
    QVector<int> data;
    std::vector<QLabel*> labels;
    int vectorSize;
    void generateData();
    void setPenWidth(int pw);
    int getPenWidth();

    void setCirceCenterX(int x);
    void setCirceCenterY(int y);
    void setCirceRadius(int r);

    int getCirceCenterX();
    int getCirceCenterY();
    int getCirceRadius();



};

#endif // IMAGE_H
