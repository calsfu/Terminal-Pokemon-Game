#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(char in_code) {
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code) {
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
}

GameObject::~GameObject() {
    cout << "GameObject deconstructed" << endl;
}

Point2D GameObject::GetLocation() {
    return location;
}

int GameObject:: GetId() {
    return id_num;
}

char GameObject:: GetState() {
    return state;
}

char GameObject::GetDisplayCode() {
    return display_code;
}

void GameObject:: ShowStatus() {
    cout << display_code  << id_num << " at " << location;
}

void GameObject::DrawSelf(char * ptr) {
    *ptr = display_code;
    *(ptr + 1) = id_num + '0';
}

