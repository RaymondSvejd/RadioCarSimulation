#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "Room.h"
#include "MonsterTruck.h"

class Simulation
{
public:
    // Constructor
    Simulation();
    // Destructor set to default for proper memory deallocation.
    ~Simulation() = default;

    // Starts the main application
    void startSimulation();

    // Introduction to the application
    void introduction();

    // Initialization functions
    void selectRoomSize();
    void selectCarStartingPoint();
    void selectCarCommands();
    void exitApplication();

    // Simulates commands input by the user
    void simulateCommands();

    // Utility functions
    bool checkCollision(int newPosX, int newPosY, int newRoomWidth, int newRoomDepth);
    void displayCarPosition();

    // Validation functions
    bool validateRoomSize(int width, int depth);
    bool validateStartingPos(int x, int y, char dir);

private:
    // Pointers to room and car objects, instantiated using the initialization list of the Simulation class.
    // Smart pointers are chosen for safer memory management.
    std::unique_ptr<Room> room_ptr;
    std::unique_ptr<Car> monsterTruck_ptr;

    // Member variables
    std::string userCommands = "";
    const std::string allowedDirections = "NWSE";
    bool exitApp = false; 
};
