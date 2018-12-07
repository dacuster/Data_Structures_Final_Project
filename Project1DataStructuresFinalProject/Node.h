/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Final Project A* Pathfinding
*Date Assigned:		11-16-2018
*Due Date:			12-06-2018 11:59pm
*
*Description:		This file includes the Node class and Location class definitions.
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

/*********************
	Location Class
**********************/
// Position coordinate information.
class Location
{
public:
	// Constructor.
	Location(int _x = 0, int _y = 0);
	// Copy constructor.
	Location(const Location& _newLocation);
    
	/***************************
		Operator overloading
	****************************/
	// Check if this object's coordinates are the same as the comparison's.
	bool operator== (const Location& _right);
	// Add the coordinates of this object and the given object together.
	Location operator+ (const Location& _right);

	/****************
		Variables
	*****************/
	// Coordinates
	int x;
	int y;
};
/*************************
	END Location Class
**************************/


/*****************
	Node Class
******************/
// Nodes for list storage to find an A* path.
class Node
{
public:
	/**************
		Getters
	***************/
	// Get this node's position.
	Location getPosition();
	// Get the this node's parent position.
	Location getParent();
	// Get the distance from the start node.
	int getDistance();
	// Get the cost to move to this node.
	int getCost();

	/**************
		Setters
	***************/
	// Set the position.
	void setPosition(Location _position);
	// Set the parent's location.
	void setParent(Location _parent);
	// Set the distance from the start.
	void setDistance(int _distance);
	// Set the cost to move to this node.
	void setCost(int _cost);

	/***************************
		Operator Overloading
	****************************/
	// Check if this objects position is the same as the comparison Node position.
	bool operator== (const Node& _right);
	// Check if this objects position is the same as the comparison position.
	bool operator== (const Location& _right);
	// Check if the distance and cost of this object is less than the comparison object's.
	bool operator< (const Node& _right);

private:
	/****************
		Variables
	*****************/
	// Node position.
	Location position;
	// Parent node for reverse traversal.
	Location parent;
	// Distance from start.
	int distance;
	// Cost to move to this node.
	int cost;
};
/*********************
	END Node Class
**********************/