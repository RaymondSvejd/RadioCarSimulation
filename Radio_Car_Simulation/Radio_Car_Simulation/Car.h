#pragma once
#include <iostream>

class Car
{
private:

	// Variables
	
	// Cars current positions
	int PosX = 0;
	int PosY = 0;

	// Cars current rotation
	char direction = 'N';

public:

	// Constructor
	Car();

	// Commands
	void moveForward();
	void moveBackward();
	void rotateRight();
	void rotateLeft();

	// Accessors
	// Location
	void setCarTransform(int newPosX, int newPosY, char newDir);
	void setCarPosX(int newPosX);
	void setCarPosY( int newPosY);
	int getCarPosX();
	int getCarPosY();

	// Direction
	void setDirection(char newDirection);
	char getDirection();
};

