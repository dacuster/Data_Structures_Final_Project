/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Final Project A* Pathfinding
*Date Assigned:		11-16-2018
*Due Date:			12-06-2018 11:59pm
*
*Description:		This file includes the Node class and Location class declarations.
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

#include "Node.h"

/*****************************
		Location Class 
******************************/

// Constructor.
Location::Location(int _x, int _y)
{
	x = _x;
	y = _y;
	return;
}
// Copy constructor.
Location::Location(const Location& _newLocation)
{
	x = _newLocation.x;
	y = _newLocation.y;
	return;
}

// Check if this object's coordinates are the same as the comparison's.
bool Location::operator== (const Location& _right)
{
	return _right.x == x && _right.y == y;
}
// Add the coordinates of this object and the given object together.
Location Location::operator+ (const Location& _right)
{
	return Location( _right.x + x, _right.y + y );
}
/*********************************
		END Locaiton Class 
**********************************/


/*************************
		Node Class 
**************************/

/**************
	Getters
***************/
// Get this node's position.
Location Node::getPosition()
{
	return position;
}

// Get the this node's parent position.
Location Node::getParent()
{
	return parent;
}

// Get the distance from the start node.
int Node::getDistance()
{
	return distance;
}

// Get the cost to move to this node.
int Node::getCost()
{
	return cost;
}

/**************
	Setters
***************/
// Set the position.
void Node::setPosition(Location _position)
{
	position = _position;
	return;
}
// Set the parent's location.
void Node::setParent(Location _parent)
{
	parent = _parent;
	return;
}
// Set the distance from the start.
void Node::setDistance(int _distance)
{
	distance = _distance;
	return;
}
// Set the cost to move to this node.
void Node::setCost(int _cost)
{
	cost = _cost;
	return;
}

/***************************
	Operator Overloading
****************************/

// Check if this objects position is the same as the comparison Node position.
bool Node::operator== (const Node& _right)
{
	return position == _right.position;
}

// Check if this objects position is the same as the comparison position.
bool Node::operator== (const Location& _right)
{
	return position == _right;
}

// Check if the distance and cost of this object is less than the comparison object's.
bool Node::operator< (const Node& _right)
{
	return distance + cost < _right.distance + _right.cost;
}
/*****************************
		END Node Class 
******************************/
