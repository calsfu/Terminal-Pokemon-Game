#include "PokemonCenter.h"

// PokemonCenter::~PokemonCenter() {
//     cout << "PokemonCenter destructed" << endl;
// }

PokemonCenter::PokemonCenter():Building()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc) : Building()
{
    display_code = 'C';
    id_num = in_id;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    num_potions_remaining = potion_capacity;
    location = in_loc;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

bool PokemonCenter :: HasPotions() {
    if(num_potions_remaining > 0)
        return true;
    return false;
}
unsigned int PokemonCenter :: GetNumPotionRemaining() {
    return num_potions_remaining;
}
bool PokemonCenter :: CanAffordPotion(unsigned int potion, double budget) {
    if(budget >= potion * pokedollar_cost_per_potion)
        return true;
    return false;
}
double PokemonCenter :: GetPokeDollarCost(unsigned int potion) {
    return pokedollar_cost_per_potion * potion;
}
unsigned int PokemonCenter :: DistributePotion(unsigned int potion_needed) {
    if(num_potions_remaining >= potion_needed) {
        num_potions_remaining -= potion_needed;
        return potion_needed;
    }
    else {
        unsigned int temp = num_potions_remaining;
        num_potions_remaining = 0;
        return temp;
    }
}
bool PokemonCenter :: Update() {
    
    if(num_potions_remaining == 0 && state != NO_POTIONS_AVAILABLE) {
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of potions." << endl;
        return true;
    }
    return false;
}
void PokemonCenter :: ShowStatus() {
    cout << "PokemonCenter Status: " << endl;
    Building::ShowStatus();
    cout << "PokeDollars per potion: " << pokedollar_cost_per_potion << endl;
    cout << this->GetDisplayCode() << this->GetId() << " has " << num_potions_remaining << " potion";
    if(num_potions_remaining == 1) {
        cout << " remaining. " << endl;
        return;
    }
    cout << "s remaining. " << endl;
    return;
}