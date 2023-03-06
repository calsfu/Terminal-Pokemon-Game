#ifndef TRAINER_H
#define TRAINER_H
#include <string.h>
#include <iostream>
#include <time.h>
#include <string>
#include "PokemonCenter.h"
#include "Point2D.h"
#include "PokemonGym.h"
#include "Vector2D.h"

using namespace std;

enum TrainerStates {
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
    };

class Trainer: public GameObject{
    public:
    Trainer();
    Trainer(char);
    Trainer(string, int, char, unsigned int, Point2D);
    virtual ~Trainer();
    string GetName();
    void StartMoving(Point2D);
    void StartMovingToGym(PokemonGym*);
    void StartMovingToCenter(PokemonCenter*);
    void StartBattling(unsigned int);
    void StartRecoveringHealth(unsigned int);
    void Stop();
    bool HasFainted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    void addExperience();
    void loseHealth(double);
    PokemonGym GetCurrentGym();
    double GetExperience();
    double getHealth();
    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D);
    private:
    double damage;
    double speed;
    bool is_at_center;
    bool is_IN_GYM;
    unsigned int health = 20;
    unsigned int experience = 0;
    double PokeDollars = 0.0;
    unsigned int battles_to_buy = 0;
    unsigned int potions_to_buy = 0;
    string name;
    PokemonCenter* current_center = 0;
    PokemonGym* current_gym = 0;
    Point2D destination;
    Vector2D delta;
};

static  double GetRandomAmountOfPokeDollars();

#endif