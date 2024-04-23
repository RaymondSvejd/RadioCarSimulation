#include "Simulation.h"

// Constructor
Simulation::Simulation()
    : room_ptr(std::make_unique<Room>()), monsterTruck_ptr(std::make_unique<MonsterTruck>())
{
}

// Runs the simulation
void Simulation::startSimulation()
{
    while (!exitApp)
    {
        introduction();
        selectRoomSize();
        selectCarStartingPoint();
        selectCarCommands();
        simulateCommands();
        exitApplication();
    }
}

// Introduces the application to the user
void Simulation::introduction()
{
    std::system("CLS");
    std::cout << "Hello and welcome to this car simulation." << std::endl;
    std::cout << "First, choose the room size for this simulation." << std::endl;
    std::cout << "Type in the width, followed by a space and then the depth of the room in meters." << std::endl;
}

// Handles the room input
void Simulation::selectRoomSize()
{
    std::string roomInput;
    int width, depth;

    while (true)
    {
        std::getline(std::cin,roomInput);
        std::istringstream iss(roomInput);

        if (iss >> width >> depth && validateRoomSize(width, depth))
        {
            room_ptr->setRoomWidth(width);
            room_ptr->setRoomDepth(depth);

            std::cout << "A room has been created with dimensions:" << std::endl;
            std::cout << "Width: " << width << std::endl;
            std::cout << "Depth: " << depth << std::endl << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid input, please enter two dimensions separated by a space." << std::endl;
        }
    }
}

// Handles the starting point of the car
void Simulation::selectCarStartingPoint()
{
    std::cout << "Now select the car's starting position." << std::endl;
    std::cout << "Please enter the car's location using x and y coordinates, followed by its direction." << std::endl;
    std::cout << "For example, type '3 4 N' for a car located at x = 3, y = 4, facing north." << std::endl;

    int x, y;
    char dir;
    std::string input;
    bool inputValid = false;

    while (!inputValid)
    {
        std::getline(std::cin, input);
        std::istringstream iss(input);

        if (iss >> x >> y >> dir && validateStartingPos(x, y, std::toupper(dir)))
        {
            inputValid = true;
            monsterTruck_ptr->setCarTransform(x, y, std::toupper(dir));
            displayCarPosition();
        }
        else
        {
            std::cout << "\nError - invalid input" << std::endl;
            std::cout << "Check that the car is inside of the room's boundaries and has a valid facing." << std::endl;
            std::cout << "Your current room size is " << room_ptr->getRoomWidth() << " by " << room_ptr->getRoomDepth() << " meters." << std::endl;
            std::cout << "Please try again (example, type '3 4 N' for a car located at x = 3, y = 4, facing north)." << std::endl;
        }
    }
}

// Handles the command selections
void Simulation::selectCarCommands()
{
    std::cout << "Now please enter the commands you want the car to execute." << std::endl;
    std::cout << "The commands are as follows:" << std::endl;
    std::cout << "F - move the car forward, in its current direction." << std::endl;
    std::cout << "B - move the car backward, in its current direction." << std::endl;
    std::cout << "R - turn the car right" << std::endl;
    std::cout << "L - turn the car left" << std::endl;
    std::cout << std::endl;

    std::getline(std::cin, userCommands);
}

// Handles the ending of the program. 
void Simulation::exitApplication()
{
    while (true)
    {
        std::string input;
        std::cout << "\nWould you like to start a new simulation? Y/N" << std::endl;
        std::cin >> input;
        if (input == "Y" || input == "y")
        {
            std::cin.ignore();
            break;
        } 
        else if(input =="n" || input == "N")
        {
            this->exitApp = true;
            break;
        }
    }
}

// Executes the chosen commands 
void Simulation::simulateCommands()
{
    bool isSimulating = true;
    int roomWidth = room_ptr->getRoomWidth();
    int roomDepth = room_ptr->getRoomDepth();

    for (int i = 0; i < userCommands.length(); i++)
    {
        if (isSimulating)
        {
            int posX = monsterTruck_ptr->getCarPosX();
            int posY = monsterTruck_ptr->getCarPosY();
            char command = toupper(userCommands[i]);

            switch (command)
            {
            case 'F':
                monsterTruck_ptr->moveForward();
                isSimulating = checkCollision(posX, posY, roomWidth, roomDepth);
                break;
            case 'B':
                monsterTruck_ptr->moveBackward();
                isSimulating = checkCollision(posX, posY, roomWidth, roomDepth);
                break;
            case 'R':
                monsterTruck_ptr->rotateRight();
                break;
            case 'L':
                monsterTruck_ptr->rotateLeft();
                break;
            default:
                std::cout << "Invalid command" << std::endl;
                break;
            }

            if (isSimulating)
            {
                displayCarPosition();

                if (i == userCommands.length()-1)
                {
                    std::cout << "\nSimulation Finished!" << std::endl;

                    isSimulating = false;
                }
            }

        }
    }
}

// Checks for collision, return true if collion did "not" accure
bool Simulation::checkCollision(int newPosX, int newPosY, int newRoomWidth, int newRoomDepth)
{
    if (newPosX < 0)
    {
        std::cout << "\nSimulation stopped!" << std::endl;
        std::cout << "Car hit the west wall." << std::endl;
        std::cout << "At X: " << newPosX << " Y: " << newPosY << std::endl;
        return false;
    }
    else if (newPosX >= newRoomWidth)
    {
        std::cout << "\nSimulation stopped!" << std::endl;
        std::cout << "Car hit the east wall." << std::endl;
        std::cout << "At X: " << newPosX << " Y: " << newPosY << std::endl;
        return false;
    }
    else if (newPosY < 0)
    {
        std::cout << "\nSimulation stopped!" << std::endl;
        std::cout << "Car hit the south wall." << std::endl;
        std::cout << "At X: " << newPosX << " Y: " << newPosY << std::endl;
        return false;
    }
    else if (newPosY >= newRoomDepth)
    {
        std::cout << "\nSimulation stopped!" << std::endl;
        std::cout << "Car hit the north wall." << std::endl;
        std::cout << "At X: " << newPosX << " Y: " << newPosY << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

// Displays cars position
void Simulation::displayCarPosition()
{
    std::cout << "The car's coordinates are set to:" << std::endl;
    std::cout << "X = " << this->monsterTruck_ptr->getCarPosX() << std::endl;
    std::cout << "Y = " << this->monsterTruck_ptr->getCarPosY() << std::endl;

    switch (this->monsterTruck_ptr->getDirection())
    {
    case 'N':
        std::cout << "Facing north" << std::endl;
        break;
    case 'W':
        std::cout << "Facing west" << std::endl;
        break;
    case 'S':
        std::cout << "Facing south" << std::endl;
        break;
    case 'E':
        std::cout << "Facing east" << std::endl;
        break;
    default:
        std::cout << "Invalid facing" << std::endl;
        break;
    }
}

// Validates user iput
bool Simulation::validateRoomSize(int width, int depth)
{
    if (width > 0 && depth > 0)
    {
        return true;
    }
    else
    {
        std::cout << "Dimensions must be positive." << std::endl;
        return false;
    }
}

bool Simulation::validateStartingPos(int x, int y, char dir)
{
    return x >= 0 && y >= 0 && x < this->room_ptr->getRoomWidth() && y < this->room_ptr->getRoomDepth() && this->allowedDirections.find(std::toupper(dir)) != std::string::npos;
}


