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
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU

#endif // QT_NO_CONTEXTMENU

private:
    Ui::MainWindow *ui;

    Image image;

    QRadioButton* bresenhamCircleButton;

    QSpinBox *radiusSpinBox;
    QSpinBox *xSpinBox;
    QSpinBox *ySpinBox;

protected:
    void paintEvent(QPaintEvent*) override;

private slots:

    void refreshImage();


private:
    bool wannaSave();
};
#endif // MAINWINDOW_H
