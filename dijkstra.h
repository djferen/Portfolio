/*
 * Let the node at which we are starting be called the initial node. Let the distance of node Y be the distance from the initial node to Y. 

    1. Assign to every node a tentative distance value: set it to zero for our initial node and to infinity for all other nodes.

     (Initialization: One data value for tentative distance; settable in mass)

    2. Set the initial node as current. Mark all other nodes unvisited. Create a set of all the unvisited nodes called the unvisited set.

     (Initialization: Set the current node as visited and Save all nodes in unvisited set)

    3. For the current node, consider all of its unvisited neighbors and calculate their tentative distances. Compare the newly calculated tentative 
    distance to the current assigned value and assign the smaller one. For example, if the current node A is marked with a distance of 6, and the 
    edge connecting it with a neighbor B has length 2, then the distance to B (through A) will be 6 + 2 = 8. If B was previously marked with 
    a distance greater than 8 then change it to 8. Otherwise, keep the current value.

    (Data:  for a given node calculated all of its unviisted neightbors and calculate their tentative distances.  
             Compare the newly calcualted td to the current assigned value and assign the node the smaller one.
             a data structure for each node and all of its unvisited neighbors)

    4. When we are done considering all of the neighbors of the current node, mark the current node as visited and remove it from the unvisited set. A visited node will never be checked again.

    5. If the destination node has been marked visited (when planning a route between two specific nodes) or if the smallest tentative distance among the nodes in the unvisited set is infinity
    (when planning a complete traversal; occurs when there is no connection between the initial node and remaining unvisited nodes), then stop. The algorithm has finished.

    6. Otherwise, select the unvisited node that is marked with the smallest tentative distance, set it as the new "current node", and go back to step 3.

Attributions: Wikipedia

 * */
#ifndef _DIJKSTRA_H
#define _DIJKSTRA_H
/*
distance of node Y = distance from initial node to node Y

Change default data for all nodes except initial node

*/
#endif


