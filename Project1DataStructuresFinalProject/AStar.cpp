/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Final Project A* Pathfinding
*Date Assigned:		11-16-2018
*Due Date:			12-06-2018 11:59pm
*
*Description:		This file includes the AStar class and Map class declarations.
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
#include "Node.h"
#include "AStar.h"

/**************************
		AStar Class
***************************/
AStar::AStar()
{
	// Setup all the neighboring nodes.
	neighbors[0] = Location(-1, -1);
	neighbors[1] = Location(1, -1);
	neighbors[2] = Location(-1, 1);
	neighbors[3] = Location(1, 1);
	neighbors[4] = Location(0, -1);
	neighbors[5] = Location(-1, 0);
	neighbors[6] = Location(0, 1);
	neighbors[7] = Location(1, 0);
	return;
}

// Calculate the distance to a destination from the current position.
int AStar::calculateDistance(Location& _destination)
{
	int x = end.x - _destination.x;
	int y = end.y - _destination.y;
	return(x * x + y * y);
}

// Make sure the location is inside the map perimeter.
bool AStar::isValid(Location& _location)
{
	return (_location.x > -1 && _location.y > -1 && _location.x < map.getWidth() && _location.y < map.getHeight());
}

// Check if the position has been traversed to yet.
bool AStar::positionExists(Location& _location, int _cost)
{
	std::list<Node>::iterator iter;

	iter = std::find(closed.begin(), closed.end(), _location);
	if (iter != closed.end())
	{
		if ((*iter).getCost() + (*iter).getDistance() < _cost)
		{
			return true;
		}
		else
		{
			closed.erase(iter);
			return false;
		}
	}
	iter = std::find(open.begin(), open.end(), _location);
	if (iter != open.end())
	{
		if ((*iter).getCost() + (*iter).getDistance() < _cost)
		{
			return true;
		}
		else
		{
			open.erase(iter);
			return false;
		}
	}
	return false;
}

// Add nodes to the open list.
bool AStar::fillOpen(Node& _node)
{
	// Cost the move to the new location.
	int stepCost = 1;
	// Cost to continue the path to the new node.
	int nodeCost = 0;
	// Get the distance to the new location.
	int distance = 0;
	// Position of the the node's neighbors.
	Location neighbor;

	// Loop through all the neighbors.
	for (int x = 0; x < 8; x++)
	{
		neighbor = _node.getPosition() + neighbors[x];
		if (neighbor == end)
		{
			return true;
		}

		// Make sure the neighbor is in the map and isn't an obstacle.
		if (isValid(neighbor) && map(neighbor.x, neighbor.y) != 1)
		{
			// Setup the cost and distance of the neighbor.
			nodeCost = stepCost +_node.getCost();
			distance = calculateDistance(neighbor);

			if (!positionExists(neighbor, nodeCost + distance))
			{
				// Create a new node to add to the list.
				Node newNode;
				newNode.setCost(nodeCost);
				newNode.setDistance(distance);
				newNode.setPosition(neighbor);
				newNode.setParent(_node.getPosition());
				open.push_back(newNode);
			}
		}
	}
	return false;
}

// Start searching the nodes of the map for a path.
bool AStar::search(Location& _start, Location& _end, Map& _map)
{
	Node node;
	end = _end;
	start = _start;
	map = _map;
	node.setCost(0);
	node.setPosition(start);
	node.setParent(0);
	node.setDistance(calculateDistance(start));
	open.push_back(node);

	while (!open.empty())
	{
		Node node = open.front();
		open.pop_front();
		closed.push_back(node);
		if (fillOpen(node))
		{
			return true;
		}
	}
	return false;
}

// Reverse the found path for traversal from start to finish.
int AStar::path(std::list<Location>& _path)
{
	_path.push_front(end);
	int pathCost = 1 + closed.back().getCost();
	_path.push_front(closed.back().getPosition());
	Location parent = closed.back().getParent();

	for (std::list<Node>::reverse_iterator iter = closed.rbegin(); iter != closed.rend(); iter++)
	{
		if ((*iter).getPosition() == parent && !((*iter).getPosition() == start))
		{
			_path.push_front((*iter).getPosition());
			parent = (*iter).getParent();
		}
	}
	_path.push_front(start);
	return pathCost;
}
// Reset the path to create a new one.
void AStar::resetPath()
{
	open.clear();
	closed.clear();
	return;
}
/******************************
		END AStar Class
*******************************/


/************************
		Map Class
*************************/
int Map::getWidth()
{
	return width;
}

int Map::getHeight()
{
	return height;
}
// Check that the coordinates are not in an obstacle and within the map.
bool Map::isValid(Location _position)
{
	if (map[_position.x][_position.y] == 1 || _position.x < 0 || _position.x >= width || _position.y < 0 || _position.y >= height)
	{
		return false;
	}

	return true;
}

/****************************
		END Map Class
*****************************/