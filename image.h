#ifndef IMAGE_H
#define IMAGE_H

#include "QtGui/qcolor.h"
#include "QtGui/qwindowdefs.h"
#include <QVector>
#include <QLabel>
#include <QString>
enum Lines

{
    BRESENHAMCIRCLE,
    BRESENHAMLINE,
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
