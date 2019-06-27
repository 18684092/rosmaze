#include "Place.h"

Place::Place()
{
    // Constructor
    x = -1;
    y = -1;
}

Place::Place(int row, int col)
{
    // Constructor
    x = col;
    y = row;
}

Place::~Place()
{
    // Destructor
}
