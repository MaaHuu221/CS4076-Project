#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_vegTrue_clicked();

    void on_vegFalse_clicked();

    void on_calSlider_sliderReleased();

    void on_recipeButt_clicked();

    void on_TaCBox_stateChanged(int arg1);

    void on_calSlider_valueChanged(int value);

    void on_actionQuit_2_triggered();

    void on_stepButt_clicked();

    void on_backButt_clicked();

    void on_nextButt_clicked();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
