/*
 * This contains an implementation of the Dijkstra's Shortest Path Routing Algorithm.
 */
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H

#include <set>
#include <map>
#include <string>
#include <limits>


/* The purpose of this data structure is to provide all input.
 *
 * This map contains keys of every city, and its values are maps of neighboring cities and the distances to them.
*/
// map<city name, map<neighboring cities, distance to>>
typedef   std::map<std::string, std::map<std::string, int> > distances_map_type;
/*
 * Input Data Model Example:
MIA
NYC 1500
WDC 700

NYC
MIA 1500
WDC 800

WDC
NYC 800
MIA 700
*/

/*
 * This data structure is a fundamental structure for this algorithm.  The purpose of this data structure is it
 * keeps track of unvisited node information while searching for the shortest path.
 *
 * As the algorithm "traverses" all of the distances, these tentative_distance (TD) are calculated.
 */
struct unvisited_node_type
{
  int tentative_distance;
  std::set<std::string> unvisited_neighbors;

  unvisited_node_type()
  {
	  tentative_distance = std::numeric_limits<int>::max();
  }
};
/*
 * This data structure provides the algorithm implementation.
 */
struct dijkstra
{
	/*
	 * This is a list of citiies that have been visited.
	 */
	typedef std::set<std::string> visited_set_type;

	/*
	 * This is a map of unvisited cities and their TDs and unvisited neighbors.
	 */
	typedef std::map<std::string, unvisited_node_type> unvisited_set_type;

	visited_set_type visited_set;
	unvisited_set_type unvisited_set;

	void CreateUnvisitedSet(const distances_map_type & all_cities_map)
	{

	}

	std::set<std::string> GetNodeUnvisitedNeighbors(std::string)
	{
		return std::set<std::string>();
	}

	void SetNodeTD(std::string, int to)
	{

	}

	dijkstra()
	{

	}

	std::string GetShortestPathFrom(std::string from)
	{
		std::string result;
		return result;
	}

};

/*
The following contains a description of Dijkstra's Algorithm (Wikipedia) as well as necessary operations that have been
identified thru the analysis of the algorithm.

    1. Initial Values

     Operation:
     1. SetAllNodesTD(int) default should be infinity
     2. SetNodesTD(string, int)

    2. Set the initial node as current. Mark all other nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.

     Operatoin:
      0. SetNodeVisited(string)
      1. SetNodeCurrent(string)
      2. SetAllNodesUnvisited

    3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances. Compare the newly calculated tentative 
    distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the 
    edge connecting it with a neighbor B has length 2, then the distance to B (through A) will be 6 + 2 = 8. If B was previously marked with 
    a distance greater than 8 then change it to 8. Otherwise, keep the current value.

    Operation:
      1. string GetNeightborsOfNode(string)
      2. int CalculateNeighborsTD
      3. Compare the newly calculated TD to the current assigned TD and assign the smaller one

    4. When we are done considering all of the neighbors of the current node, mark the current node as visited and remove it from the unvisited set.
    A visited node will never be checked again.

    Operation:
    1. SetNodeVisited(string)
    2. RemoveNodeFromUnvisitedSet(string)
    
    if current node visited == destination node then stop
    else select the unvisited node that is marked with the smallest TD and set it as the new current node

    5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity
    (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.

    6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

    Operation:
     1. GetUnvisitedNodeWithSmallestTD
     2. SetNodeCurrent(string)
     3. PrintVisitedSet

Citations:
Dijkstra's Algorithm (Wikipedia, "Dijkstra's Algorithm")

 * */
#endif


