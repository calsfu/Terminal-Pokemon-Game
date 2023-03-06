#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <iostream>

using namespace std;

int main() {
    PokemonCenter pc1;
    PokemonGym pg1;
    
    pc1.AddOneTrainer();
    pc1.ShowStatus();
    pg1.Update();
    pg1.ShowStatus();
}