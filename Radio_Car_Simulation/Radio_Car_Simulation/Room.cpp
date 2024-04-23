#include "Room.h"

// Default constructor for the Room class
Room::Room()
{
    // Constructor body, potentially initializing default values for roomWidth and roomDepth
}

// Sets the width of the room
void Room::setRoomWidth(int newWidth)
{
    // Assign the new width to the roomWidth member variable
    this->roomWidth = newWidth;
}

// Sets the depth of the room
void Room::setRoomDepth(int newDepth)
{
    // Assign the new depth to the roomDepth member variable
    this->roomDepth = newDepth;
}

// Returns the current width of the room
int Room::getRoomWidth()
{
    // Return the value of the roomWidth member variable
    return this->roomWidth;
}

// Returns the current depth of the room
int Room::getRoomDepth()
{
    // Return the value of the roomDepth member variable
    return this->roomDepth;
}
