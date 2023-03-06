#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"
using namespace std;
class Building: public GameObject {
    private:
    unsigned int trainer_count = 0;
    public:
    Building() : GameObject('B') {
        cout << "Building default constructed" << endl;
    }
    Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code) {
        cout << "Building constructed" << endl;
    }
    void AddOneTrainer();
    void RemoveOneTrainer();
    virtual bool Update() = 0;
    void ShowStatus();
    bool ShouldBeVisible();    
};
#endif
