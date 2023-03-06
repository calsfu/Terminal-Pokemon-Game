#ifndef POKEMONGYM_H
#define POKEMONGYM_H
#include "Building.h"

enum PokemonGymStates {
NOT_DEFEATED = 0,
DEFEATED = 1
};

class PokemonGym: public Building {
    private:
    unsigned int num_battle_remaining;
    unsigned int max_number_of_battles;
    unsigned int health_cost_per_battle;
    double PokeDollar_cost_per_battle;
    unsigned int experience_per_battle;
    public:
    PokemonGym() 
    :Building()
    {
        display_code = 'G';
        state = NOT_DEFEATED;
        max_number_of_battles = 10;
        num_battle_remaining = max_number_of_battles;
        health_cost_per_battle = 1;
        PokeDollar_cost_per_battle = 1.0;
        experience_per_battle = 2;
        cout << "PokemonGym default constructed" << endl;
    }
    PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, 
    unsigned int exp_per_battle, int in_id, Point2D in_loc)
    :Building()
    {
        id_num = in_id;
        display_code = 'G';
        location = in_loc;
        max_number_of_battles = max_battle;
        num_battle_remaining = max_number_of_battles;
        health_cost_per_battle = health_loss;
        experience_per_battle = exp_per_battle;
        PokeDollar_cost_per_battle = PokeDollar_cost;
        cout << "PokemonGym constructed" << endl;
    }
    ~PokemonGym() {
        cout << "PokemonGym destructed" << endl;
    }
    double GetPokeDollarCost(unsigned int);
    unsigned int GetHealthCost(unsigned int);
    unsigned int GetNumBattlesRemaining();
    bool IsAbleToBattle(unsigned int, double, unsigned int);
    unsigned int TrainPokemon(unsigned int);
    bool Update();
    bool passed();
    void ShowStatus();
};
#endif