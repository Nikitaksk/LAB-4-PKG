#ifndef IMAGE_H
#define IMAGE_H

#include "QtGui/qcolor.h"
#include "QtGui/qwindowdefs.h"
#include <QVector>
#include <QLabel>
#include <QString>

class Image {
private:
    QColor penColor = QColorConstants::Black;
    QColor brushColor = QColorConstants::Blue;
    int penWidth;

public:
    Image();
    QVector<int> data;
    std::vector<QLabel*> labels;
    int vectorSize;
    void generateData();
    void setPenWidth(int pw);
    int getPenWidth();

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);


};

#endif // IMAGE_H
