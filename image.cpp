#include "image.h"
#include <iostream>
Image::Image() {
    generateData();
    this->penWidth = 3;
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

