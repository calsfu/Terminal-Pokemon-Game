#include "Model.h"

Model::Model() { //constructr
    time = 0;
    //object_ptrs[10] = new GameObject[10];
    center_ptrs.push_back(new PokemonCenter(1, 1.0, 100, Point2D(1, 20))); //creates GameObject in heap
    center_ptrs.push_back(new PokemonCenter(2, 2, 200, Point2D(10, 20)));
    trainer_ptrs.push_back(new Trainer("Ash", 1, 'T', 2, Point2D(5,1)));
    trainer_ptrs.push_back(new Trainer("Misty", 2, 'T', 2, Point2D(10,1)));
    gym_ptrs.push_back(new PokemonGym(10, 1, 2, 3, 1, Point2D()));
    gym_ptrs.push_back(new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5)));
    wildpokemon_ptrs.push_back(new WildPokemon("Charizard",5, 4, false, 1, Point2D(10,12)));
    wildpokemon_ptrs.push_back(new WildPokemon("Machop", 3, 3, false, 2, Point2D(15, 5)));
    for(trainer_iter = trainer_ptrs.begin();trainer_iter != trainer_ptrs.end();trainer_iter++) {
        object_ptrs.push_back(*trainer_iter);
        active_ptrs.push_back(*trainer_iter);
    }
    for(center_iter = center_ptrs.begin();center_iter != center_ptrs.end();center_iter++) {
        object_ptrs.push_back(*center_iter);
        active_ptrs.push_back(*center_iter);
    }
    for(gym_iter = gym_ptrs.begin();gym_iter != gym_ptrs.end();gym_iter++) {
        object_ptrs.push_back(*gym_iter);
        active_ptrs.push_back(*gym_iter);
    }
    for(pokemon_iter = wildpokemon_ptrs.begin();pokemon_iter != wildpokemon_ptrs.end();pokemon_iter++) {
        object_ptrs.push_back(*pokemon_iter);
        active_ptrs.push_back(*pokemon_iter);
    }
    // for(game_object_iter = object_ptrs.begin();game_object_iter != object_ptrs.end();game_object_iter++) {
    //     char code = (*game_object_iter)->GetDisplayCode();
    //     active_ptrs.emplace_back(*game_object_iter);
    //     switch(code) {
    //         case 'T':
    //             trainer_ptrs.emplace_back((object_ptrs.front()));
    //             break;
            // case 'C':
            //     center_ptrs.emplace_back(*game_object_iter);
            //     break;
            // case 'G':
            //     gym_ptrs.emplace_back(*game_object_iter);
            //     break;
            // case 'W':
            //     wildpokemon_ptrs.emplace_back(*game_object_iter);
            //     break;
    //     }
    // }

    // object_ptrs.emplace_back(trainer_ptrs.begin());
    // object_ptrs.emplace_back(center_ptrs.begin());
    // object_ptrs.emplace_back(gym_ptrs);
    // object_ptrs.emplace_back(wildpokemon_ptrs);
    // active_ptrs.emplace_back(trainer_ptrs);
    // active_ptrs.emplace_back(center_ptrs);
    // active_ptrs.emplace_back(gym_ptrs);
    // active_ptrs.emplace_back(wildpokemon_ptrs);


    // center_ptrs.push_back(new PokemonCenter(1, 1.0, 100, Point2D(1, 20))); //creates GameObject in heap
    // center_ptrs.push_back(new PokemonCenter(2, 2, 200, Point2D(10, 20)));
    // trainer_ptrs.push_back(new Trainer("Ash", 1, 'T', 2, Point2D(5,1)));
    // trainer_ptrs.push_back(new Trainer("Misty", 2, 'T', 2, Point2D(10,1)));
    // gym_ptrs.push_back(new PokemonGym(10, 1, 2, 3, 1, Point2D()));
    // gym_ptrs.push_back(new PokemonGym(20, 5, 7.5, 4, 2, Point2D(5, 5)));
    // wildpokemon_ptrs.push_back(new WildPokemon("Charizard",5, 4, false, 1, Point2D(10,12)));
    // wildpokemon_ptrs.push_back(new WildPokemon("Machop", 3, 3, false, 2, Point2D(15, 5)));
    
    // object_ptrs.emplace_back(trainer_ptrs.begin());
    // object_ptrs.emplace_back(center_ptrs.begin());
    // object_ptrs.emplace_back(gym_ptrs);
    // object_ptrs.emplace_back(wildpokemon_ptrs);
    // active_ptrs.emplace_back(trainer_ptrs);
    // active_ptrs.emplace_back(center_ptrs);
    // active_ptrs.emplace_back(gym_ptrs);
    // active_ptrs.emplace_back(wildpokemon_ptrs);
    // for(int i = 0;i < 2;i++) {
    //     object_ptrs[i] = trainer_ptrs[i]; //sets object_ptr
    //     object_ptrs[i+2] = center_ptrs[i];
    //     object_ptrs[i+4] = gym_ptrs[i];
    //     object_ptrs[i+6] = wildpokemon_ptrs[i];
    // 
    cout << "Model default constructed" << endl;
}

Model::~Model() {
    for(game_object_iter = object_ptrs.begin();game_object_iter != object_ptrs.end();game_object_iter++) {
        delete *game_object_iter;
    }
    cout << "Model destructed" << endl;
}

void Model::AddTime() { 
    this->time++;
    return;
}

Trainer* Model::GetTrainerPtr(int id) { //finds a trainer_ptr with valid id. WARNING: will cause seg fault if not error checked in main
    for(trainer_iter = trainer_ptrs.begin();trainer_iter != trainer_ptrs.end();trainer_iter++) {
        if((*trainer_iter)->GetId() == id) {
            return *trainer_iter;
        }
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for(center_iter = center_ptrs.begin();center_iter != center_ptrs.end();center_iter++) {
        if((*center_iter)->GetId() == id) {
            return *center_iter;
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id) {
    for(gym_iter = gym_ptrs.begin();gym_iter != gym_ptrs.end();gym_iter++) {
        if((*gym_iter)->GetId() == id) {
            return *gym_iter;
        }
    }
    return 0;
}

void Model::NewObject(char type, int id, double x, double y) {
    //add try catch to see id ,x,y are not taken
    switch(toupper(type)) {
            case 'T':
                try {
                    for(trainer_iter = trainer_ptrs.begin();trainer_iter != trainer_ptrs.end();trainer_iter++) {
                        if(id == (**trainer_iter).GetId()) {
                            throw Invalid_Input("ID num taken");
                        }
                    }
                    trainer_ptrs.emplace_back(new Trainer("Ash2", id, 'T', 20, Point2D(x,y)));
                    object_ptrs.push_back(trainer_ptrs.back()); //currently puts it at the back which shouldnt matter? but may need to change
                    active_ptrs.push_back(trainer_ptrs.back());
                }
                catch(Invalid_Input& except) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Input - " << except.msg_ptr << endl;
                }
                
                break;
            case 'C':
                try {
                    for(trainer_iter = trainer_ptrs.begin();trainer_iter != trainer_ptrs.end();trainer_iter++) {
                        if((*trainer_iter)->GetId() == id) {
                            throw Invalid_Input("ID num taken");
                        }
                    }       
                    center_ptrs.emplace_back(new PokemonCenter(id, 2, 150, Point2D(x, y)));
                    object_ptrs.emplace_back(center_ptrs.back());
                    active_ptrs.emplace_back(center_ptrs.back());
                }
                catch(Invalid_Input& except) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Input - " << except.msg_ptr << endl;
                }
                break;
            case 'G':
                try {
                    for(gym_iter = gym_ptrs.begin();gym_iter != gym_ptrs.end();gym_iter++) {
                        if((*gym_iter)->GetId() == id) {
                            throw Invalid_Input("ID num taken");
                        }
                    }
                    gym_ptrs.emplace_back(new PokemonGym(10, 1, 2, 3, id, Point2D(x,y)));
                    object_ptrs.emplace_back(gym_ptrs.back());
                    active_ptrs.emplace_back(gym_ptrs.back());
                }
                catch(Invalid_Input& except) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Input - " << except.msg_ptr << endl;
                }
                break;
            case 'W':
                try {
                    for(pokemon_iter = wildpokemon_ptrs.begin();pokemon_iter != wildpokemon_ptrs.end();pokemon_iter++) {
                        if((*pokemon_iter)->GetId() == id) {
                            throw Invalid_Input("ID num taken");
                        }
                    }
                    wildpokemon_ptrs.emplace_back(new WildPokemon(id, Point2D(x,y)));
                    object_ptrs.emplace_back(wildpokemon_ptrs.back());
                    active_ptrs.push_back(wildpokemon_ptrs.back());
                }
                catch(Invalid_Input& except) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid Input - " << except.msg_ptr << endl;
                }
                break;
        }
}

bool Model::Update() {
    bool hasTrue = false; //checks if at least one update returns true
    bool gymsDefeated = true; 
    bool allDead = true; 
    time++;
    for(game_object_iter = active_ptrs.begin();game_object_iter != active_ptrs.end();game_object_iter++) {
        if((*game_object_iter)->GetDisplayCode() == 'T') { //trainers
            if((*game_object_iter)->Update())
                hasTrue = true;
            if((*game_object_iter)->GetState() != FAINTED) { //checks trainer is alive
                allDead = false; //if at least one trainer is alive, all dead will be false
            }
            else {
                game_object_iter = active_ptrs.erase(game_object_iter); //if the current trainer is dead, they are removed from active_ptrs. 
                game_object_iter--;
                cout << "Dead trainer removed" << endl;
            }
        }
        else if((*game_object_iter)->GetDisplayCode() == 'G') { //gyms
            if((*game_object_iter)->Update())
                hasTrue = true;
            if((*game_object_iter)->GetState() != DEFEATED) { //checks if at least one gym is standed
                gymsDefeated = false;
            }
        }
        else if((*game_object_iter)->GetDisplayCode() == 'W') {
            (*game_object_iter)->Update();
            if((*game_object_iter)->GetState() == DEAD) { //removes dead pokemon from active ptrs.
                game_object_iter = active_ptrs.erase(game_object_iter);
                game_object_iter--;
                cout << "Dead pokemon removed" << endl;
            }
        }
        else {
            if((*game_object_iter)->Update()) {
                hasTrue = true;
            }   
        } 
    }
    for(pokemon_iter = wildpokemon_ptrs.begin();pokemon_iter != wildpokemon_ptrs.end();pokemon_iter++) {
        for(trainer_iter = trainer_ptrs.begin();trainer_iter != trainer_ptrs.end();trainer_iter++) {
            if(GetDistanceBetween((*pokemon_iter)->GetLocation(),(*trainer_iter)->GetLocation()) <= (*pokemon_iter) -> GetProximity() && (((*pokemon_iter)->GetState() == IN_ENVIRONMENT) || (*pokemon_iter)->GetState() == IN_TRAINER)) {
                (*pokemon_iter) -> follow((*trainer_iter));
            }
        }
    }
    if(gymsDefeated) {
        cout << "GAME OVER: You win! All battles done!" << endl;
        exit(EXIT_SUCCESS);
    }
    if(allDead) {
        cout << "GAME OVER: You lose! All of you Trainers' pokemon have fainted!" << endl;
        exit(EXIT_FAILURE);
    }
    return hasTrue;
}

void Model::Display(View& view) {
    view.Clear(); //defaults the grid
    for(game_object_iter = active_ptrs.begin();game_object_iter != active_ptrs.end();game_object_iter++) { 
        view.Plot(*(game_object_iter)); //plots all active_ptrs
    }
    // for(int i = 1;i < 3;i++) { //replots GameObjects
    //     view.Plot(this->GetPokemonCenterPtr(i));
    //     view.Plot(this->GetPokemonGymPtr(i));
    //     view.Plot(this->GetTrainerPtr(i));
    // }
    view.Draw();
}

void Model::ShowStatus() { //shows status of all GameObjects
    for(game_object_iter = object_ptrs.begin();game_object_iter != object_ptrs.end();game_object_iter++) {
        (**(game_object_iter)).ShowStatus();
    }
    cout << "Time: " << this -> time << endl;
}