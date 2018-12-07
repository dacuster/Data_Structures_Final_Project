/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Final Project A* Pathfinding
*Date Assigned:		11-16-2018
*Due Date:			12-06-2018 11:59pm
*
*Description:		This file includes the main function.
*
*Certification of Authenticity:
*I certify that this is entirely my own work, except where I have given
*fully-documented references to the work of others. I understand the definition
*and consequences of plagiarism and acknowledge that the assessor of this
*assignment may, for the purpose of assessing this assignment: Reproduce this
*assignment and provide a copy to another member of academic staff; and/or
*Communicate a copy of this assignment to a plagiarism checking service (which
*may then retain a copy of this assignment on its database for the purpose of
*future plagiarism checking).
*/

#include <list>
#include <iostream>
#include <string>
#include <time.h>
#include "Node.h"
#include "AStar.h"

// Print the path to the sceen.
void printPath(AStar& _aStar, Map& _map, Location& _start, Location& _end);
// Print the map without a path.
void printMap(Map _map);
// Reset the start and end location on the path.
void reset(int& _startX, int& _startY, int& _endX, int& _endY);

int main()
{
    Map map;
    AStar aStar;
	int userX = -1;
	int userY = -1;
	Location start(userX, userY);
	Location end(userX, userY);
 
	std::cout << "A* pathfinding demonstration." << std::endl;
	std::cout << "Here is your map." << std::endl;
	printMap(map);
	std::cout << "Coordinates are from 0-9." << std::endl;
	std::cout << "Enter a starting position separated by a space 'x y'." << std::endl;
	
	while (!map.isValid(start))
	{
		// Get the starting x and y coordinates from the user.
		std::cin >> userX;
		std::cin >> userY;

		start = Location(userX, userY);

		if (!map.isValid(start))
		{
			std::cout << "You entered and invalid location. Please try again." << std::endl;
		}
	}

	std::cout << "Enter an ending position separated by a space 'x y'." << std::endl;
	
	while (!map.isValid(end))
	{
		// Get the ending x and y coordinates from the user.
		std::cin >> userX;
		std::cin >> userY;

		end = Location(userX, userY);

		if (!map.isValid(end))
		{
			std::cout << "You entered and invalid location. Please try again." << std::endl;
		}
	}

	std::cout << "Here is your path." << std::endl;

	// Make sure there's a path before printing.
    if (aStar.search(start, end, map))
	{
		printPath(aStar, map, start, end);
    }
	
	std::cin.ignore();

	std::cout << "Press enter to see 4 randomly generated paths." << std::endl;

	std::cin.ignore();

	int startX;
	int startY;
	int endX;
	int endY;

	// Create a random seed.
	std::srand(time(NULL));

	// Loop through 4 times to make random paths.
	for (int counter = 0; counter < 4; counter++)
	{
		aStar.resetPath();
		reset(startX, startY, endX, endY);

		std::cout << "Random path " << (counter + 1) << std::endl;
		while (!map.isValid(Location(startX, startY)))
		{
			startX = std::rand() % 10;
			startY = std::rand() % 10;
		}

		while (!map.isValid(Location(endX, endY)))
		{
			endX = std::rand() % 10;
			endY = std::rand() % 10;
		}
		start = Location(startX, startY);
		end = Location(endX, endY);

		if (aStar.search(start, end, map))
		{
			printPath(aStar, map, start, end);
		}

		std::cout << std::endl << std::endl;
		
		std::cout << "Press enter to continue." << std::endl;

		std::cin.ignore();
		
	}

	std::cin.ignore();
    
	return 0;
}

// Print the path to the sceen.
void printPath(AStar& _aStar, Map& _map, Location& _start, Location& _end)
{
	std::list<Location> path;
    int pathCost = _aStar.path(path);
	int height = _map.getHeight();
	int width = _map.getWidth();

	for (int y = -1; y <= height; y++)
	{
        for (int x = -1; x <= width; x++)
		{
			Location currentLocation = Location(x, y);

			// Draw the perimeter of the room using blocks.
			if (x < 0 || y < 0 || x >= width || y >= height || _map(x, y) == 1)
			{
				std::cout << char(0xdb);
			}
			else if (currentLocation == _start)
			{
				std::cout << "s";
			}
			else if (currentLocation == _end)
			{
				std::cout << "e";
			}
            else
			{
				if (std::find(path.begin(), path.end(), currentLocation) != path.end())
				{
					std::cout << "x";
				}
				else
				{
					std::cout << ".";
				}
            }
        }
        std::cout << "\n";
    }
 
    std::cout << "\nPath cost " << pathCost << ": ";

	// Print the coordinates for each node on the path.
    for (std::list<Location>::iterator iter = path.begin(); iter != path.end(); iter++)
	{
        std::cout << "(" << (*iter).x << ", " << (*iter).y << ") ";
    }

	// Create a space after each pathfinding printout.
	std::cout << std::endl << std::endl;

	return;
}

// Print the map without a path.
void printMap(Map _map)
{
	int height = _map.getHeight();
	int width = _map.getWidth();

	for (int y = -1; y <= height; y++)
	{
        for (int x = -1; x <= width; x++)
		{
			Location currentLocation = Location(x, y);

			// Draw the perimeter of the room using blocks.
			if (x < 0 || y < 0 || x >= width || y >= height || _map(x, y) == 1)
			{
				std::cout << char(0xdb);
			}
            else
			{
				std::cout << ".";
            }
        }
        std::cout << "\n";
    }
}

// Reset the start and end location on the path.
void reset(int& _startX, int& _startY, int& _endX, int& _endY)
{
	_startX = -1;
	_startY = -1;
	_endX = -1;
	_endY = -1;
	return;
}