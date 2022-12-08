#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>
#include <chrono>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QRadioButton>
#include <QSpinBox>
#include <QPushButton>
#include "image.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

    protected:
        #ifndef QT_NO_CONTEXTMENU

    #endif // QT_NO_CONTEXTMENU

    private:
        Ui::MainWindow * ui;

    Image image;

    QRadioButton * bresenhamCircleButton;
    QSpinBox * radiusSpinBox;
    QSpinBox * xCenterOfCircleSpinBox;
    QSpinBox * yCenterOfCircleSpinBox;

    QRadioButton * bresenhamLineButton;
    QRadioButton * DDALineButton;

    QSpinBox * xOfFirstPointSpinBox;
    QSpinBox * yOfFirstPointSpinBox;

    QRadioButton * stepLineButton;
    QSpinBox * x1StepSpinBox;
    QSpinBox * y1StepSpinBox;
    QSpinBox * x2StepSpinBox;
    QSpinBox * y2StepSpinBox;

    QSpinBox * x1DDASpinBox;
    QSpinBox * x2DDASpinBox;
    QSpinBox * y1DDASpinBox;
    QSpinBox * y2DDASpinBox;

    QSpinBox * xOfSecondPointSpinBox;
    QSpinBox * yOfSecondPointSpinBox;

    QHBoxLayout * paintingAreaLayout;
    QVBoxLayout * infoAreaLayout;
    QVBoxLayout * bresenhamCircleButtonLayout;
    QHBoxLayout * bresenhamEntryCenterLayout;
    QVBoxLayout * bresenhamLineLayout;
    QHBoxLayout * firstPointBresenhamLineLayout;
    QHBoxLayout * secondPointBresenhamLineLayout;

    protected:
    void paintEvent(QPaintEvent * ) override;
    void resizeEvent(QResizeEvent * ) override;

    public slots:

    void refresh();

    void refreshImageCircle();
    void valueInCircleChanged();

    void refreshImageLine();
    void valueInLinesChanged();

    void valueInStepChanged();
    void refreshImageStepLine();

    void valueInDDAChanged();
    void refreshImageDDALine();

    private:
        bool wannaSave();
};
#endif // MAINWINDOW_H
