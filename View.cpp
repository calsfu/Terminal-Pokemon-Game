#include "View.h"
#include <iomanip>

View::View() {
    size = 11;
    scale = 2;
    origin = Point2D(0,0); 
}
void View::Clear() { //sets all values of grid to . or ' '
    for(int i = 0;i < view_maxsize;i++) {
        for(int j = 0;j < view_maxsize;j++) {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}
void View::Plot(GameObject * ptr) { //changes grid value for each GameObject
    int x, y;
    if(GetSubscripts(x, y, ptr->GetLocation())) { //checks if x and y are valid and puts values in x and y
        if(grid[x][y][0] == '.') { //checks if empty
            (*ptr).DrawSelf(grid[x][y]); //adds if empty
        }
    else if(grid[x][y][1] == ((*ptr).GetId() + '0') && grid[x][y][0] == (*ptr).GetDisplayCode()) {
        (*ptr).DrawSelf(grid[x][y]); //checks if filled by itself (happens if object did not move from last update)
    }
    else{ //changes to asteriks if two GameObjects occupy same space.
        grid[x][y][0] = '*';
        grid[x][y][1] = ' ';
    }
    // if(!ptr->ShouldBeVisible()) { //removing since we now have active_ptrs
    //     grid[x][y][0] = '.';
    //     grid[x][y][1] = ' ';
    // }
    }
}

void View::Draw() {
    // cout << "Size is " << size << endl; //said to add this in doc but dont think is necessary
    // cout << "Scale is " << scale << endl;
    // cout << "Origin is at " << origin << endl;
    for(int i = 0;i < size;i++) { //iterates through grid
        if((view_maxsize - i)%2 == 0) {
            //cout.width(2); // adds y axis labels
            if(view_maxsize - i*2 < 10) //A horrible way to do this, but leaving for now
                cout << (view_maxsize - i*2) << setw(2);
            else 
                cout << (view_maxsize - i*2);
        }
        else {
            cout << "  "; //space if no label
        }
        for(int j = 0;j < size;j++) {
            cout << grid[j][size - 1 - i][0] <<  grid[j][size - 1 - i][1]; //since printed from top to bottom and left to right, size - 1 - i must be used.
        }
        cout << endl;
    }
    cout << "  ";
    for(int i = 0;i <= view_maxsize;i += 4) { //prints bottom row
        if(i < 10) //needs to be changed due to amount of digits of value. should be done more general but works
            cout << i << setw(3) << ""; 
        else {
            cout << i << setw(2) << ""; 
        }
    }
    cout << endl;
}

bool View::GetSubscripts(int &out_x, int &out_y, Point2D location) {
    out_x = (location.x - origin.x)/scale;
    out_y = (location.y - origin.y)/scale;
    if(out_x >= origin.x && out_x <= size && out_y >= origin.y && out_y <= size) { //checks if coords fit in size
        return true;
    }
    cout << "An object is outside the display" << endl;
    return false;
}