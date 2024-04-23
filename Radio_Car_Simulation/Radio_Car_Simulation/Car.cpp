#include "Car.h"

// Default constructor
Car::Car()
{

}

// Moves the car forward based on its current facing direction
void Car::moveForward()
{
    switch (this->direction)
    {
    case 'N':
        this->PosY++;  // Move north (upward on the Y-axis)
        break;
    case 'S':
        this->PosY--;  // Move south (downward on the Y-axis)
        break;
    case 'E':
        this->PosX++;  // Move east (rightward on the X-axis)
        break;
    case 'W':
        this->PosX--;  // Move west (leftward on the X-axis)
        break;
    default:
        std::cout << "An error has occurred trying to move the car forward";
        break;
    }
}

// Moves the car backward based on its current facing direction
void Car::moveBackward()
{
    switch (this->direction)
    {
    case 'N':
        this->PosY--;  // Move opposite of north
        break;
    case 'S':
        this->PosY++;  // Move opposite of south
        break;
    case 'E':
        this->PosX--;  // Move opposite of east
        break;
    case 'W':
        this->PosX++;  // Move opposite of west
        break;
    default:
        std::cout << "An error has occurred trying to move the car backwards";
        break;
    }
}

// Rotates the car 90 degrees to the right
void Car::rotateRight()
{
    switch (this->direction)
    {
    case 'N':
        this->direction = 'E';  // North to East
        break;
    case 'S':
        this->direction = 'W';  // South to West
        break;
    case 'E':
        this->direction = 'S';  // East to South
        break;
    case 'W':
        this->direction = 'N';  // West to North
        break;
    default:
        std::cout << "An error has occurred when rotating the car to the right";
        break;
    }
}

// Rotates the car 90 degrees to the left
void Car::rotateLeft()
{
    switch (this->direction)
    {
    case 'N':
        this->direction = 'W';  // North to West
        break;
    case 'S':
        this->direction = 'E';  // South to East
        break;
    case 'E':
        this->direction = 'N';  // East to North
        break;
    case 'W':
        this->direction = 'S';  // West to South
        break;
    default:
        std::cout << "An error has occurred when rotating the car to the left";
        break;
    }
}

// Sets the car's position and facing direction
void Car::setCarTransform(int newPosX, int newPosY, char newDir)
{
    this->PosX = newPosX;
    this->PosY = newPosY;
    this->direction = newDir;
}

// Sets the car's X position
void Car::setCarPosX(int newPosX)
{
    this->PosX = newPosX;
}

// Sets the car's Y position
void Car::setCarPosY(int newPosY)
{
    this->PosY = newPosY;
}

// Returns the car's X position
int Car::getCarPosX()
{
    return this->PosX;
}

// Returns the car's Y position
int Car::getCarPosY()
{
    return this->PosY;
}

// Sets the car's direction
void Car::setDirection(char newDirection)
{
    this->direction = newDirection;
}

// Returns the car's current direction
char Car::getDirection()
{
    return this->direction;
}
