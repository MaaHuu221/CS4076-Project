#ifndef RECIPES_H
#define RECIPES_H
#include <vector>
#include <stdlib.h>

using namespace std;
class BasicRecipe{
protected :
    union{
        unsigned int vegan : 1;
    }s;

    virtual bool getVegan() = 0;
};
class Recipe : public BasicRecipe
{
    string rName;
    int calories;
    vector<string> steps;

public:
    Recipe(string rName, int calories, bool v){
        this->rName = rName;
        this->calories = calories;
        s.vegan = v;
    }

    ~Recipe(){

    }

    string getName(){
        return rName;
    }

    int getCalories(){
        return calories;
    }

    virtual bool getVegan(){
        return s.vegan;
    }

    void addStep(string s){
        steps.push_back(s);
    }

    vector<string> getSteps(){
        return steps;
    }

    friend void operator +(Recipe &r, string s);

};

void operator +(Recipe &r, string s){
    r.addStep(s);
}
#endif // RECIPES_H
