#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include <iomanip>

using namespace std;

int main() {
    Model m1;
    View view;
    m1.ShowStatus();
    m1.Display(view);
    while(DoPlayGame(m1, view)); //runs game until q is entered, both t's die, or beat gyms
    
}