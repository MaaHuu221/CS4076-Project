#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "Recipes.h"
#include <vector>
#include <stdlib.h>

using namespace std;

int calories = 0;
bool vegan = false;
vector <Recipe> r;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->partTwo->hide();
    Recipe lasagne("Lasagne", 135, false);
    r.push_back(lasagne);
    Recipe steak("Steak & Chips", 534, false);
    r.push_back(steak);
    Recipe burger("Beef Burger", 225, false);
    r.push_back(burger);
    Recipe vBurger("Vegan Burger",177, true);
    r.push_back(vBurger);
    Recipe curry("Chicken Curry", 110, false);
    r.push_back(curry);
    Recipe vCurry("Vegetable Curry", 188, true);
    r.push_back(vCurry);
    ui->vegFalse->clicked();
    ui->stepButt->hide();
   //this->setCentralWidget(ui->textEdit);
}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_vegTrue_clicked()
{
    vegan = true;
}


void MainWindow::on_vegFalse_clicked()
{
    vegan = false;
}


void MainWindow::on_calSlider_sliderReleased()
{
    calories = ui->calSlider->value();
    const QString s = QString::number(calories);
    ui->calLabel->setText("Max Calories " + s);
}


void MainWindow::on_recipeButt_clicked()
{
    ui->partTwo->show();
    for(int i = 0; i < r.size(); i++){
        if(r[i].getVegan() == vegan && r[i].getCalories() <= calories)
        //if(1 == 1)
        {
            const QString s = QString::fromStdString(r[i].getName());
            ui->recipeBox->addItem(s);
        }
    }
}




void MainWindow::on_TaCBox_stateChanged(int arg1)
{
    if(ui->TaCBox->isChecked()){
        ui->stepButt->show();
    }
}

