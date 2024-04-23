#pragma once
class Room
{

private:

// Variables
// Room Size
	int roomWidth = 0;
	int roomDepth = 0;

public:
    Room();

    // Setters for Room dimensions.
    void setRoomWidth(int newWidth);
    void setRoomDepth(int newDepth);

    // Getters for Room dimensions.
    int getRoomWidth();
    int getRoomDepth();
};

