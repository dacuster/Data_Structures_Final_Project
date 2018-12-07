#include <list>
#include <iostream>
#include "Node.h"
#include "AStar.h"

int main()
{
    Map map;
	Location start;
	Location end(7, 7);
    AStar aStar;
 
    if (aStar.search(start, end, map))
	{
        std::list<Location> path;
        int pathCost = aStar.path(path);
        
		for (int y = -1; y < 9; y++)
		{
            for (int x = -1; x < 9; x++)
			{
				if (x < 0 || y < 0 || x > 7 || y > 7 || map(x, y) == 1)
				{
					std::cout << char(0xdb);
				}
                else
				{
					if (std::find(path.begin(), path.end(), Location(x, y)) != path.end())
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

        for (std::list<Location>::iterator iter = path.begin(); iter != path.end(); iter++)
		{
            std::cout << "(" << (*iter).x << ", " << (*iter).y << ") ";
        }
    }
    std::cout << "\n\n";
	
	system("pause");
    
	return 0;
}
