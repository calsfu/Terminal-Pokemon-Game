#include "WildPokemon.h"

WildPokemon::WildPokemon(unsigned int id, Point2D in_loc):GameObject(in_loc, id, 'W') {
    this->id_num = id;
    this->location = in_loc;
    this->startingLoc = location;
    speed = 3;
}

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'W') {
    this->name = name;
    this->attack = attack;
    this->health = health;
    this->variant = variant;
    this->id_num = id;
    this->location = in_loc;
    this->startingLoc = in_loc;
    speed = 3;
}

bool WildPokemon::takeDamage(double damage) {
    this -> health -= damage;
    if (health <= 0) {
        return true;
    }
    return false;
}

void WildPokemon::follow(Trainer* t) { //need to update trainer information aswell
    if(state != DEAD) {
        current_trainer = t;
        state = IN_TRAINER;
        cout << this->display_code << this->id_num << " (" << this->name << ") is following " << t->GetDisplayCode() << t->GetId() << " (" << t->GetName() << ")";
    }
}
bool WildPokemon::get_variant() {
    return variant; 
}
void WildPokemon::AttackTrainer(Trainer* t) {
    double damageTaken = t->GetExperience()*0.25 + 1.0;
    cout << t->GetDisplayCode()  << t->GetId() << ": dealt " << damageTaken << " to " << this->GetDisplayCode() << this->GetId() << endl;
    cout << t->GetDisplayCode()  << t->GetId() << ": took " << this->attack << " from " << this->GetDisplayCode() << this->GetId() << endl;
    this->health -= damageTaken;
    t->loseHealth(attack);
    if(this->health <= 0) {
        state = DEAD;
        cout << t->GetDisplayCode()  << t->GetId() << ": has defeated " << this->GetDisplayCode() << this->GetId() << endl;
        t->addExperience();
        cout << t->GetDisplayCode()  << t->GetId() << ": has gained 5 exp ";
    }
    if(t->HasFainted()) {
        cout << this-> name << " has defeated " << t->GetDisplayCode()  << t->GetId(); 
    }
}
double WildPokemon::get_attack() {
    return attack;
}
double WildPokemon::get_health() {
    return health;
}
bool WildPokemon::get_in_combat() {
    return in_combat;
}
//start following trainer
//Check if there is a trainer within x spaces,
//if there is, it will follow
//some pmon will be faster than trainer, so it will catch up .
//if mon walks into gym, pmon will go back to default location maybe??
//possibly have a despawn and return to set area/main spot for x amount of ticks
//think having it walk back will be jank and doesnt make sense
//add legendary pokemon with status effects (lower speed, teleportation like abra from smash bros????)
    
bool WildPokemon::Update() {
    if(!IsAlive()) {
        state = DEAD;
    }
    switch (state)
    {
    case IN_ENVIRONMENT:
        {
        Vector2D dist = destination - location;
        dist.x = fabs(dist.x);
        dist.y = fabs(dist.y);
        if(dist.x <= fabs(delta.x) && dist.y <= fabs(delta.y)) {
            location = destination;
            
        }
        else {
            location = location + delta;
        }
        return false;
        break;
        }
    case DEAD:
        return false;
        break;
    case IN_TRAINER:
        in_combat = true;
        AttackTrainer(current_trainer);
        if(current_trainer->GetState() == IN_GYM || current_trainer->GetState() == AT_CENTER || current_trainer->getHealth() <= 0) {
            state = IN_ENVIRONMENT;
            destination = startingLoc;
            delta = (destination - this->location) / (GetDistanceBetween(destination, this->location));
            in_combat = false;
            return true;
            break;
        }
        else{
            delta = (current_trainer->GetLocation()- this->location) * (this->speed) / (GetDistanceBetween(current_trainer->GetLocation(), this->location));
        }
        location = location + delta;
        
        return false;
        break;
    default:
        break;
    }
    return false;
}


double WildPokemon::GetProximity() {
    return proximity;
}

void WildPokemon::ShowStatus() {
    cout << "Wild Pokemon status: ";
    GameObject::ShowStatus();
    switch (state)
    {
    case IN_ENVIRONMENT:
        cout << "The WildPokemon is in the environment" << endl;
        break;
    case DEAD:
        cout <<"The WildPokemon is dead" << endl;
        break;
    case IN_TRAINER:
        cout << "The WildPokemon is following " << current_trainer->GetName() << endl;
        cout << " has " << health << " health" << endl;
        break;
    default:
        break;
    }
}
bool WildPokemon::IsAlive() {
    if(this->health > 0) {
        return true;
    }
    return false;
}

bool WildPokemon::ShouldBeVisible() {
    if(IsAlive()) {
        return true;
    }
    return false;
}