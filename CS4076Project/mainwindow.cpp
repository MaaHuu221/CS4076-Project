#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "Recipes.h"
#include <vector>
#include <stdlib.h>
#include <QPlainTextEdit>
#include <QString>
#include <iostream>

using namespace std;

int calories = 0;
bool vegan = false;
vector <Recipe> r;
int stepCheck = 0;
int currentRecipe = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->partTwo->hide();
    Recipe lasagne("Lasagna", 135, false);

    lasagne.addStep("Heat olive oil in pan in low heat.");
    lasagne.addStep("Dry vegetables for 5 minutes or \nuntil softened");
    lasagne.addStep("Add mince meat and fry until golden");
    lasagne.addStep("Layer up the baking dish by going \npasta then meat");
    lasagne.addStep("Top up with parmesan and mozzarella \nand then bake in oven for 40-45 mins");
    lasagne.addStep("Serve immediately and enjoy!");
    r.push_back(lasagne);

    Recipe steak("Steak & Chips", 534, false);
    steak.addStep("Prepare the steak with chile powder and herbs");
    steak.addStep("Whisk oil with anchovies, garlic, mustad and \nlemon zest. Stir in herbs and season to make \n the sauce.");
    steak.addStep("Cook steak on a hot grill until it is well \nbrowned on the outside");
    steak.addStep("Remove the steak from the grill and let it \nreset for 15 minutes.");
    steak.addStep("Slice the steak, serve immediately and enjoy!");
    r.push_back(steak);


    Recipe burger("Beef Burger", 225, false);
    burger.addStep("Tip 500g beef mince into a bowl");
    burger.addStep("Squeeze down to flatten the beef into patties");
    burger.addStep("Put on a plate, cover with cling film and leave in \nthe fridge to firm up for 30 mins");
    burger.addStep("Heat the barbecue to medium hot. Lightly brush one \nside of each burger with vegetable oil");
    burger.addStep("Place the burgers oil-side down. Cook for 5 mins \nuntil lightly charred.");
    burger.addStep("Cook either side for 5 minutes at a time each \nuntil cooked enough");
    burger + "Get out sauces";
    burger.addStep("Serve with sauce or other topics and enjoy!");
    r.push_back(burger);

    Recipe vBurger("Vegan Burger",177, true);
    vBurger.addStep("Drain the chickpeas and sweetcorn, then tip into \na food processor. Pick the coriander leaves, adding \nhalf the leaves and all the stalks to the processor.");
    vBurger.addStep("Add the spices, flour and a pinch of sea salt, \nfinely grate in the lemon zest, then pulse until combined, \nbut not smooth – you want to retain a bit of texture.");
    vBurger.addStep("On a flour-dusted surface, divide and shape the \nmixture into 4 equal-sized patties, roughly 2cm thick. \nPlace in the fridge for 30 minutes to firm up.");
    vBurger.addStep("Heat a splash of oil in a large frying pan over a \nmedium heat, add the patties and cook for 10 minutes, \nor until golden and cooked through, turning halfway.");
    vBurger.addStep("Meanwhile, click off, wash and spin-dry four nice \nlettuce leaves, then finely slice the tomatoes horizontally.");
    vBurger.addStep("Squeeze a large dollop of ketchup onto the base of each \nbun (toast them if you like), then top with the burgers. \nLayer over a couple of slices of tomato, a lettuce leaf, a few coriander leaves and finally the burger tops. \n Delicious served with a fresh green salad.");
    r.push_back(vBurger);

    Recipe curry("Chicken Curry", 110, false);
    curry.addStep("Heat the oil in a flameproof casserole dish or large frying pan \nover a medium heat.");
    curry.addStep("Add the onion and a generous pinch of salt and fry for 8-10 mins, \nor until the onion has turned golden brown and sticky.");
    curry.addStep("Add the garlic and ginger, cooking for a further minute.");
    curry.addStep("Chop the chicken into chunky 3cm pieces, add to the pan and fry for \n5 mins before stirring through the spice paste and tomatoes, \nalong with 250ml water.");
    curry.addStep("Bring to the boil, lower to a simmer and cook on a gentle heat \nuncovered for 25-30 mins or until rich and slightly reduced.");
    curry.addStep("Stir though the yogurt, coriander and ground almonds, season and \nserve with warm naan or fluffy basmati rice.");
    r.push_back(curry);

    Recipe vCurry("Vegetable Curry", 188, true);
    vCurry.addStep("Melt 1 tbsp coconut oil in a saucepan over a medium heat and soften \n1 chopped onion for 5 mins.");
    vCurry.addStep("Add 2 grated garlic cloves and a grated thumb-sized piece of ginger, \nand cook for 1 min until fragrant.");
    vCurry.addStep("Stir in 3 tbsp Thai red curry paste, 1 tbsp smooth peanut butter and \n500g sweet potato, peeled and cut into chunks, then add 400ml \ncoconut milk and 200ml water.");
    vCurry.addStep("Bring to the boil, turn down the heat and simmer, uncovered, for \n25-30 mins or until the sweet potato is soft.");
    vCurry.addStep("Stir through 200g spinach and the juice of 1 lime, and season well. \nServe with cooked rice, and if you want some crunch, sprinkle over \na few dry roasted peanuts.");
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

void MainWindow::on_stepButt_clicked()
{
    stepCheck = 0;
    int i;
    for(i = 0; i < r.size(); i++){
        if(ui->recipeBox->currentText().toStdString() == r[i].getName()){
            string s = r[i].getSteps()[stepCheck];
            int cal = r[i].getCalories();
            ui->steps->setText(QString::fromStdString(s));
            ui->calorieChecker->setText("Calories: " +QString::number(cal) );
            break;
        }
    }
    currentRecipe = i;
}


void MainWindow::on_recipeButt_clicked()
{
    ui->partTwo->show();
    for(int i = 0; i < r.size(); i++){
        if(r[i].getVegan() == vegan && r[i].getCalories() <= calories)
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
    } else {
        ui->stepButt->hide();
    }
}


void MainWindow::on_calSlider_valueChanged(int value)
{
    calories = ui->calSlider->value();
    const QString s = QString::number(calories);
    ui->calLabel->setText("Max Calories " + s);
}


void MainWindow::on_actionQuit_2_triggered()
{
    QApplication::quit();
}




void MainWindow::on_backButt_clicked()
{
    if(stepCheck != 0){
        stepCheck--;
        string s = r[currentRecipe].getSteps()[stepCheck];
        ui->steps->setText(QString::fromStdString(s));
    }
}


void MainWindow::on_nextButt_clicked()
{
    if(stepCheck != r[currentRecipe].getSteps().size()-1){
        stepCheck++;
        string s = r[currentRecipe].getSteps()[stepCheck];
        ui->steps->setText(QString::fromStdString(s));
    }
}


void MainWindow::on_actionAbout_2_triggered()
{
    QMessageBox::information(this, "About", "Hello my name is Max Huddlestan and welcome to my Recipe App\n Student ID 21324123 :D");
}


void MainWindow::on_actionTerms_and_Conditions_triggered()
{
    QMessageBox::information(this, "Terms and Conditions", "Do you agree to...\nUse these recipes for good and admit that\nfood poisoning may be because you did not\nread the instructions thoroughly?");
}

