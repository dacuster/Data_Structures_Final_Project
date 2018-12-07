#include "Node.h"


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
// Set the position of this node.
void Node::setPosition(Location _position)
{
	position = _position;
	return;
}

void Node::setParent(Location _parent)
{
	parent = _parent;
	return;
}

void Node::setDistance(int _distance)
{
	distance = _distance;
	return;
}

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


/*****************************
		Locaiton Class 
******************************/

// Constructor.
Location::Location(int _x, int _y)
{
	x = _x;
	y = _y;
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