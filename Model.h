#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "WildPokemon.h"
#include <list>
#include "Input_Handling.h"

class Model {
    private:
    int time;
    //GameObject* object_ptrs[10];
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<Trainer*> trainer_ptrs;
    list<PokemonCenter*> center_ptrs;
    list<PokemonGym*> gym_ptrs;
    list<WildPokemon*> wildpokemon_ptrs;
    list<GameObject*>::iterator game_object_iter;
    list<Trainer*>::iterator trainer_iter;
    list<PokemonCenter*>::iterator center_iter;
    list<PokemonGym*>::iterator gym_iter;
    list<WildPokemon*>::iterator pokemon_iter;
    public:
    Model();
    virtual ~Model();
    Trainer* GetTrainerPtr(int);
    PokemonCenter* GetPokemonCenterPtr(int);
    PokemonGym* GetPokemonGymPtr(int);
    bool Update();
    void Display(View&);
    void ShowStatus();
    void AddTime();
    void NewObject(char, int, double, double);
};


#endif