#include "image.h"
#include <iostream>
Image::Image() {
    generateData();
    this->penWidth = 3;
    centerOfCircleX = 0;
    centerOfCircleY = 0;
    radiusOfCircle = 0;
}

void Image::generateData() {
    int vectorSize = arc4random() % 4 + 2;
    for (int i = 0; i < vectorSize; i++) {
        data.push_back( 1 + arc4random() % 100);
        labels.resize(vectorSize);
    }
}
void Image::setPenWidth(int pw){
    this->penWidth = pw;
}
int Image::getPenWidth(){
    return this->penWidth;
}

void Image::setCirceCenterX(int x){
    this->centerOfCircleX = x;
}
void Image::setCirceCenterY(int y){
    this->centerOfCircleY = y;
}
void Image::setCirceRadius(int r){
    this->radiusOfCircle = r;
}

int Image::getCirceCenterX(){
    return this->centerOfCircleX;
}
int Image::getCirceCenterY(){
    return this->centerOfCircleY;
}
int Image::getCirceRadius(){
    return this->radiusOfCircle;
}

