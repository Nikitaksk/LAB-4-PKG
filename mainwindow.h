#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>
#include <QVBoxLayout>
#include <QMenuBar>
#include <chrono>

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

    QMenu *fileMenu;
    QMenu *colorMenu;
    QMenu *helpMenu;

    QAction *openAction;
    QAction *saveAsAction;
    QAction *closeAction;
    QAction *exitAction;

    QAction *setPenColorAction;
    QAction *setBrushColorAction;

    QAction *callAboutAction;


    QLabel *infoLabel;

protected:
    void paintEvent(QPaintEvent*) override;

private slots:


    void setPenColor();
    void setBrushColor();

    void callAbout();

private:
    bool wannaSave();


};
#endif // MAINWINDOW_H
