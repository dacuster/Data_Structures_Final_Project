/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Final Project A* Pathfinding
*Date Assigned:		11-16-2018
*Due Date:			12-06-2018 11:59pm
*
*Description:		This file includes the AStar class and Map class definitions.
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

#pragma once

// The map to find the start and end locations.
// Everywhere with a 1 is an obstacle.
class Map
{
public:
    Map() {	}

	int getWidth();
	int getHeight();

	// Check if the position is traversable.
	bool isValid(Location _position);

	// Get the value of the map position for obstacle checks.
	int operator() (int x, int y) { return map[x][y]; }

private:
	// Create a base map for traversing.
	char map[10][10] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	int width = 10;
	int height = 10;
};

class AStar
{
public:
	AStar();
 
	// Calculate the distance to a destination from the current position.
	int calculateDistance(Location& _destination);
	// Make sure the location is inside the map perimeter.
	bool isValid(Location& _location);
	// Check if the position has been traversed to yet.
	bool positionExists(Location& _location, int _cost);
	// Add nodes to the open list.
	bool fillOpen(Node& _node);
	// Look for a path.
	bool search(Location& _start, Location& _end, Map& _map);
	// Reverse the found path for traversal from start to finish.
	int path(std::list<Location>& _path);
	// Reset the path to create a new one.
	void resetPath();
 
private:
    Map map;
	Location end;
	Location start;
    Location neighbors[8];
    std::list<Node> open;
    std::list<Node> closed;
};
