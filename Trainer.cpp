#include "Trainer.h"
#include <math.h>
using namespace std;
Trainer::Trainer(): GameObject('T') {
    speed = 5;
    std::cout << "Trainer default constructed." << endl;
}
Trainer::Trainer(char in_code): GameObject(in_code) {
    speed = 5;
    state = STOPPED;
    std::cout << "Trainer constructed" << endl;
}
Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code) {
    speed = in_speed;
    name = in_name;
    display_code = in_code;
    location = in_loc;
    id_num = in_id;
    std::cout << "Trainer constructed." << endl;
}
Trainer::~Trainer() {
    cout << "Trainer object destructed" << endl;
}

string Trainer::GetName() { //need for a part in GameCommand
    return this -> name;
}

PokemonGym Trainer::GetCurrentGym() {
    return *current_gym;
}

void Trainer::StartMoving(Point2D dest) { 
    if(GetDistanceBetween(location, dest) == 0) { //checks if already there
        cout << display_code << id_num << ": I'm already there. See?" << endl;
        return;
    }    
    if(state == AT_CENTER) { //if start moving from center, trainer must be removed from that center
        is_at_center = false;
        current_center -> RemoveOneTrainer();
    }
    else if(state == IN_GYM) { //same as center
        is_IN_GYM = false;
        current_gym -> RemoveOneTrainer();
    }
    SetupDestination(dest); 
    state = MOVING;
    if(HasFainted()) { //checks if fainted
        cout << display_code << id_num << ": My Pokemon have fainted. I may move but you cannot see me." << endl;
    }
    else {
        cout << display_code << id_num << ": On my way." << endl;
    }
}

double Trainer::getHealth() {
    return this->health;
}

void Trainer::loseHealth(double d) {
    health -= d;
}

void Trainer::addExperience() {
    this->experience += 5;
}

double Trainer::GetExperience() {
    return experience;
}

void Trainer::StartMovingToGym(PokemonGym* gym) { //pretty much same as StartMoving, except HasFainted() needs to be first
    if(HasFainted()) { //Dead trainers can only move to points
        cout << display_code << id_num << ": My Pokemon have fainted so I can't move to gym..." << endl;
    }
    else if(GetDistanceBetween(gym->GetLocation(), this->location) == 0) {
        cout << display_code << id_num << ": I am already at the PokemonGym!" << endl;
    }
    else {
        if(state == AT_CENTER) {
            is_at_center = false;
            current_center -> RemoveOneTrainer();
        }
        else if(state == IN_GYM) {
            is_IN_GYM = false;
            current_gym -> RemoveOneTrainer();
        }
        cout << display_code << id_num << ": on my way to gym " << gym -> GetId() << endl;
        current_gym = gym;
        SetupDestination(gym->GetLocation());
        state = MOVING_TO_GYM;
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center) { //same as gym
    if(HasFainted()) {
        cout << display_code << id_num << ": My pokemon have fainted so I should have gone to the center.." << endl;
    }
    else if(GetDistanceBetween(center -> GetLocation(), location) == 0) {
        cout << display_code << id_num << ": I am already at the Center!" << endl;
    }
    else {
        if(state == AT_CENTER) {
            is_at_center = false;
            current_center -> RemoveOneTrainer();
        }
        else if(state == IN_GYM) {
            is_IN_GYM = false;
            current_gym -> RemoveOneTrainer();
        }
        this->state = MOVING_TO_CENTER;
        current_center = center;
        SetupDestination(center -> GetLocation());
        cout << display_code << id_num << ": On my way to Center " << center->GetId() << endl;
    }
}

void Trainer::StartBattling(unsigned int num_battles) { //need to fix num_battles > battles remaining in gym
    cout  << display_code << id_num << ": ";
    if(HasFainted()) {
        cout << "My Pokemon have fainted so no more battles for me..." << endl;
    }
    else if(!is_IN_GYM) {
        cout << "I can only battle in a PokemonGym!" << endl; 
    }
    else if(current_gym -> GetPokeDollarCost(num_battles) > PokeDollars) {
        cout << "Not enough money for battles" << endl;
    }
    else if(current_gym -> passed()) { //checls if gym has trainers. 
        cout << "Cannot battle! This PokemonGym has no more trainers to battle!" << endl;
    }
    else {
        state = BATTLING_IN_GYM;
        if(current_gym->GetNumBattlesRemaining() < num_battles) {
            cout << "Less battles in the gym then amount requested. Using max amount of battles. " << endl;
            battles_to_buy = current_gym->GetNumBattlesRemaining();
        }
        else {
            battles_to_buy = num_battles;
        }
        cout << "Started to battle at the PokemonGym " << current_gym -> GetId() << " with " << battles_to_buy << " battles" << endl;
    }
}

void Trainer::StartRecoveringHealth(unsigned int num_potions) {
    cout << display_code  << id_num << ": ";
    if(!current_center->CanAffordPotion(num_potions, PokeDollars)) {
        cout << "Not enough money to recover health" << endl;
    }
    else if(!current_center->HasPotions()) {
        cout << "Cannot recover! No potion remaining in this Pokemon Center" << endl;
    }
    else if(!is_at_center) {
        cout << "I can only recover health at a Pokemon Center!" << endl;
    }
    else {
        state = RECOVERING_HEALTH;
        potions_to_buy = current_center -> DistributePotion(num_potions);
        cout << "Started recovering " << potions_to_buy << " potions at Pokemon Center" << current_center -> GetId() << endl; 
    }
}

void Trainer::Stop() { //add how to stop
    state = STOPPED;
    cout  << display_code << id_num << ": Stopping.." << endl;
}

bool Trainer::HasFainted() {
    if(health <= 0) 
        return true;
    return false;
}

bool Trainer::ShouldBeVisible() {
    if(HasFainted()) 
        return false;
    return true;
}



void Trainer::ShowStatus() {
    cout <<  name << " status: " << endl;
    GameObject::ShowStatus();
    switch(state) {
        case STOPPED:
            cout << " stopped";
            break;
        case MOVING:
            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << ".";
            break;
        case MOVING_TO_GYM:
            cout << " heading to PokemonGym " << current_gym -> GetId() << " at a speed of " << speed << " at each step of " << delta;
            break;
        case MOVING_TO_CENTER: 
            cout << " heading to Pokemon Center " << current_center -> GetId() << " at a speed of " << speed << " at each step of " << delta;
            break;
        case IN_GYM: {
            cout << " inside PokemonGym " << current_gym -> GetId();
            break;
        }
        case AT_CENTER:
            cout << " inside Pokemon Center " << current_center -> GetId();
            break;
        case BATTLING_IN_GYM:
            cout << " battling PokemonGym " << current_gym -> GetId();
            break;
        case RECOVERING_HEALTH:
            cout << " recovering health in Pokemon Center " << current_center -> GetId();
            break;
    }
    cout << endl;
    cout << "Health: " << health << endl;
    cout << "PokeDollars: " << PokeDollars << endl;
    cout << "Experience: " << experience << endl;
}

/*slight issue with Update(). When the trainer reaches 0 health, it doesnt change to fainted until
update is run again. Could be fixed by placing if(hasFainted()) in each source health loss, but will get messy if more sources are added
*/

bool Trainer::Update() {
    if(HasFainted()) { 
        cout << name << " is out of health and cannot move" << endl;
        state = FAINTED;
    }
    else {
        switch(state) {
        case STOPPED:
            return false;
            break;
        case MOVING:
            UpdateLocation();
            if(GetDistanceBetween(location, destination) == 0) {
                state = STOPPED;
                return true;
            }
            return false;
            break;
        case MOVING_TO_GYM:
            if(UpdateLocation()) {
                current_gym -> AddOneTrainer();
                is_IN_GYM = true;
                state = IN_GYM;
                return true;
            }
            return false;
            break;
        case MOVING_TO_CENTER: 
            if(UpdateLocation()) {
                current_center -> AddOneTrainer();
                is_at_center = true;
                state = AT_CENTER;
                return true;
            }
            return false;
            break;
        case IN_GYM:
            return false;
            break;
        case AT_CENTER:
            return false;
            break;
        case BATTLING_IN_GYM:
        {
            unsigned int exp_gain = current_gym -> TrainPokemon(battles_to_buy);
            health -= current_gym -> GetHealthCost(battles_to_buy);
            experience += exp_gain;
            PokeDollars -= current_gym -> GetPokeDollarCost(battles_to_buy);
            cout << "** " << name << " completed " << battles_to_buy << " battle(s)! **" << endl;
            cout << "** " << name << " gained " << exp_gain<< " experience! **" << endl;
            state = IN_GYM;
            return true;
            break;
        }
        case RECOVERING_HEALTH: //must run a or r in order to fully heal.
            health += potions_to_buy*5;
            PokeDollars -= current_center->GetPokeDollarCost(potions_to_buy);
            cout << "** " << name << " recovered " << potions_to_buy*5 << " health! **" << endl;
            cout << "** " << name << " bought " << potions_to_buy << " potions(s)! **" << endl;
            state = AT_CENTER;
            return true;
            break;
    }
    
    }
    return false;
}

bool Trainer::UpdateLocation() {
    Vector2D dist = destination - location;
    dist.x = fabs(dist.x);
    dist.y = fabs(dist.y);
    health--; //lowers health by one 
    PokeDollars += GetRandomAmountOfPokeDollars();
    if(dist.x <= fabs(delta.x) && dist.y <= fabs(delta.y)) {
        location = destination;
        cout  << display_code << id_num << " has arrived" << endl;
        return true;
    }
    location = location + delta;
    return false;
}

void Trainer::SetupDestination(Point2D dest) {
    this->destination = dest;
    delta = (this->destination - this->location) * (this->speed) / (GetDistanceBetween(this->destination, this->location));
}

static double GetRandomAmountOfPokeDollars() {
    srand(time(NULL));
    int temp = rand()%101; //returns an int between 0 and 100
    return temp/50.0; //min 0 to max 2.0
}