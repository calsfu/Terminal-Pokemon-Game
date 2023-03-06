#include "PokemonGym.h"


// PokemonGym::~PokemonGym() {
//     cout << "PokemonGym destructed" << endl;
// }

double PokemonGym:: GetPokeDollarCost(unsigned int battle_qty) {
    return PokeDollar_cost_per_battle * battle_qty;
}

unsigned int PokemonGym:: GetHealthCost(unsigned int battle_qty) {
    return health_cost_per_battle * battle_qty;
}

unsigned int PokemonGym:: GetNumBattlesRemaining() {
    return num_battle_remaining;
}

bool PokemonGym:: IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health) {
    if(budget >= battle_qty * PokeDollar_cost_per_battle && health >= battle_qty * health_cost_per_battle) 
        return true;
    return false;
}

unsigned int PokemonGym:: TrainPokemon(unsigned int battle_units) {
    if(battle_units < num_battle_remaining) {
        num_battle_remaining -= battle_units;
        return battle_units * experience_per_battle;
    }
    else {
        unsigned int temp = num_battle_remaining;
        num_battle_remaining = 0;
        return temp * experience_per_battle;
    }
}

bool PokemonGym:: Update() {
    if(num_battle_remaining == 0 && state != DEFEATED) {
        state = DEFEATED;
        cout << display_code << id_num << " has been beaten" << endl;
        display_code = 'g';
        return true;
    }
    return false;
}

bool PokemonGym:: passed() {
    if(num_battle_remaining == 0) {
        return true;
    }
    return false;
}

void PokemonGym:: ShowStatus() {
    cout << "PokemonGym Status: " << endl;
    Building::ShowStatus();
    cout << "Max number of battles: " << max_number_of_battles << endl;
    cout << "Health cost per battle: " << health_cost_per_battle << endl;
    cout << "PokeDollar per battle: " << PokeDollar_cost_per_battle << endl;
    cout << "Experience per battle: " << experience_per_battle << endl;
    cout << num_battle_remaining << " battles are remaining for this PokemonGym" << endl;
}