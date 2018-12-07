#pragma once

// The map to find the start and end locations.
// Everywhere with a 1 is an obstacle.
// User input, programatically drawn randomly, and file input.
class Map
{
public:
    Map()
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

	int getWidth();
	int getHeight();

	void createStarterMap();

	int operator() (int x, int y) { return map[x][y]; }

private:
    char map[8][8];
	int width = 0;
	int height = 0;
};

class AStar
{
public:
	AStar();
 
	int calculateDistance(Location& _location);
 
	bool isValid(Location& _location);
 
	bool existPoint(Location& _location, int _cost);
 
	bool fillOpen(Node& _node);
 
	bool search(Location& _start, Location& _end, Map& _map);
 
	int path(std::list<Location>& _path);
 
private:
    Map map;
	Location end;
	Location start;
    Location neighbors[8];
    std::list<Node> open;
    std::list<Node> closed;
};
