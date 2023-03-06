#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
#include "GameObject.h"
#include "Trainer.h"


enum WildPokemonStates {
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_TRAINER = 2
};

class WildPokemon: public GameObject {
    protected:
    double attack = 5;
    double health = 2;
    bool variant = false; //EXTRA CREDIT
    bool in_combat = false;
    double proximity = 2; 
    double speed;
    Point2D startingLoc;
    Point2D destination;
    Vector2D delta;
    string name;
    Trainer* current_trainer = 0;
    public:
    WildPokemon(unsigned int id, Point2D);
    WildPokemon(string, double, double, bool, int, Point2D);
    void AttackTrainer(Trainer* t);
    void follow(Trainer* t);
    bool takeDamage(double);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
    double GetProximity();
};

#endif