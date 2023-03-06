#include "GameCommand.h"
/*All functions use same start. if(model.GetGameObjectPtr(trainer_id) != 0) checks
if a speciifc game object with that id exists. Then uses it to run a function from its class
*/

void DoMoveCommand(Model& model, int trainer_id, Point2D p1) {
    if(model.GetTrainerPtr(trainer_id) != 0) { 
        (*model.GetTrainerPtr(trainer_id)).StartMoving(p1);
        cout << "Moving " << (*model.GetTrainerPtr(trainer_id)).GetName() << " to " << p1 << endl;
        return;
    }
    cout << "Error: Please enter a valid command" << endl;
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id) {
    if(model.GetTrainerPtr(trainer_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0) {
        (*model.GetTrainerPtr(trainer_id)).StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout << "Moving " << (*model.GetTrainerPtr(trainer_id)).GetName() << " to PokemonCenter " << (*model.GetPokemonCenterPtr(center_id)).GetId() << endl;
        return;
    }
    cout << "Error: Please enter a valid command" << endl;
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id) {
    if(model.GetTrainerPtr(trainer_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        (*model.GetTrainerPtr(trainer_id)).StartMovingToGym(model.GetPokemonGymPtr(gym_id));
        cout << "Moving " << (*model.GetTrainerPtr(trainer_id)).GetName() << " to gym " << (*model.GetPokemonCenterPtr(gym_id)).GetId() << endl;
        return;
    }
    cout << "Error: Please enter a valid command" << endl;
}

void DoStopCommand(Model& model, int trainer_id) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        (*model.GetTrainerPtr(trainer_id)).Stop();
        cout << "Stopping " << (*model.GetTrainerPtr(trainer_id)).GetId();
        return;
    }
    cout << "Error: Please enter a valid command" << endl;
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles) { //probaly need to use PokemonGym::isabletobattle
    if(model.GetTrainerPtr(trainer_id) != 0) {
        cout << (*model.GetTrainerPtr(trainer_id)).GetName() << " is battling" << endl;
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);
        return;
    }
    cout << "Error, please enter a valid command" << endl;
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed) {
    if(model.GetTrainerPtr(trainer_id) != 0) {
        model.GetTrainerPtr(trainer_id) -> StartRecoveringHealth(potions_needed);
        cout << "Recovering " << (*model.GetTrainerPtr(trainer_id)).GetName() << " Pokemon's health" << endl;
        return;
    }
    cout << "Error: Please enter a valid command" << endl;
}

void DoAdvanceCommand(Model& model, View& view) { 
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    int counter = 0;
    while(counter < 5 && !model.Update()) {
        counter++;
    }
    model.ShowStatus();
    model.Display(view); // reprints grid
}

void DoCreateNewObject(Model& model, char type, int id, double x, double y) {
    model.NewObject(type, id, x, y);
}

bool DoPlayGame(Model& model, View& view) { //custom function. loops in main and prompts and calls function.
    cout << "Enter the game command: ";
    cin.clear();    
    char com, type;
    int id, e1, e2;
    double x, y;
    
    //cin >> com;
    
    try {
        
        if(!(cin >> com)) {//might need a try catch for this?
            throw Invalid_Input("Was expecting a char");
        }
        com = tolower(com);
        switch (com) {
            case 'n':
                if(!(cin >> type)) {
                    throw Invalid_Input("Was expecting a character");
                }
                else if(!(cin >> id)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                else if(!(cin >> x >> y)) {
                    throw Invalid_Input("Was expecting a double");
                }
                DoCreateNewObject(model, type, id, x, y);
                break;
            case 'm': 
                if(!(cin >> id)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                if(!(cin >> x >> y)) {
                    throw Invalid_Input("Was expecting an double");
                }
                DoMoveCommand(model, id, Point2D(x, y));
                //return true;
                break;
            case 'c':
                if(!(cin >> id >> e1)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                DoMoveToCenterCommand(model, id, e1);
                break;
            case 'g':
                if(!(cin >> id >> e1)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                DoMoveToGymCommand(model, id, e1);
                break;
            case 's':
                if(!(cin >> id )) {
                    throw Invalid_Input("Was expecting an integer");
                }
                DoStopCommand(model, id);
                break;
            case 'p':
                if(!(cin >> id)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                DoRecoverInCenterCommand(model, id, e1);
                break;
            case 'b':
                if(!(cin >> id)) {
                    throw Invalid_Input("Was expecting an integer");
                }
                DoBattleCommand(model, id, e1);
                break;
            case 'a':
                DoAdvanceCommand(model, view);
                break;
            case 'r':
                DoRunCommand(model, view);
                break;
            case 'q': 
                return false;
                break;
        }
    }
    catch(Invalid_Input& except) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input - " << except.msg_ptr << endl;
    }

    return true;
}

