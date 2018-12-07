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
	// Position accessor.
	Location getPosition();
	// Parent position accessor.
	Location getParent();
	// Distance accessor.
	int getDistance();
	// Cost accessor.
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