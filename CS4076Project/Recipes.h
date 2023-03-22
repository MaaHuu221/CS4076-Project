#ifndef RECIPES_H
#define RECIPES_H
#include <vector>
#include <stdlib.h>

using namespace std;
class Recipe
{
    string rName;
    int calories;
    bool vegan;
    vector<string> steps;

public:
    Recipe(string rName, int calories, bool vegan){
        this->rName = rName;
        this->calories = calories;
        this->vegan = vegan;
    }

    string getName(){
        return rName;
    }

    int getCalories(){
        return calories;
    }

    bool getVegan(){
        return vegan;
    }

    void addStep(string s){
        steps.push_back(s);
    }


};

#endif // RECIPES_H
