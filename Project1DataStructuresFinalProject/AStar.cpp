#include <list>
#include "Node.h"
#include "AStar.h"

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

void Map::createStarterMap()
{
	char starterMap[8][8] =
	{
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};

	width = 8;
	height = 8;

	for (int row = 0; row < height; row++)
	{
		for (int column = 0; column < width; column++)
		{
			map[column][row] = starterMap[row][column];
		}
	}
}
/****************************
		END Map Class
*****************************/


/**************************
		AStar Class
***************************/
AStar::AStar()
{
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

int AStar::calculateDistance(Location& _location)
{
	int x = end.x - _location.x, y = end.y - _location.y;
	return(x * x + y * y);
}

bool AStar::isValid(Location& _location)
{
	return (_location.x > -1 && _location.y > -1 && _location.x < map.getWidth() && _location.y < map.getHeight());
}

bool AStar::existPoint(Location& _location, int _cost)
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

bool AStar::fillOpen(Node& _node)
{
	int stepCost;
	int nodeCost;
	int distance;
	Location neighbor;

	for (int x = 0; x < 8; x++)
	{
		// one can make diagonals have different cost
		stepCost = x < 4 ? 1 : 1;
		neighbor = _node.getPosition() + neighbors[x];
		if (neighbor == end)
		{
			return true;
		}

		if (isValid(neighbor) && map(neighbor.x, neighbor.y) != 1)
		{
			nodeCost = stepCost + _node.getCost();
			distance = calculateDistance(neighbor);
			if (!existPoint(neighbor, nodeCost + distance))
			{
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
		//open.sort();
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
/******************************
		END AStar Class
*******************************/