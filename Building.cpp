
#include "Building.h"

using namespace std;

void Building:: AddOneTrainer() {
    this -> trainer_count++;
}
void Building:: RemoveOneTrainer() {
    this -> trainer_count--;
}
void Building:: ShowStatus() {
    cout << display_code  << id_num << " located at " << location << endl;
    cout << trainer_count << " trainer";
    if(trainer_count != 1) 
        cout << "s are ";
    else
        cout << " is ";
    cout << "in this building" << endl;
}
bool Building:: ShouldBeVisible() {
    return true;
}