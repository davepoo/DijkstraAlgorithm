Djkstra's Path Finding Algorithm in C++
==========================

*Djkstra's Algorithm* is used to find the best path between the nodes of a directed graph. This could be used to find directions between places on a map, routing network traffic or to direct AI controlled entities in video games.

There are faster ways to calculate paths (such as the A* algorithm) but they are variations on this Algorithm, so if you can understand this then you should not have too much trouble adapting it to better Algorithms.

## Source Code

This code is a very crude example of Djkstra's path finding Algorithm in C++ (Visual Studio 2010 / CodeBlocks GCC Projects)

* `cGraph` - The graph containing all nodes
* `cNode` - A node in the Graph
* `cEdge` - An edge that joins one node to another with a "cost" value

## Program output

The program creates a simple graph in `main.cpp` and calculate a few paths between some of the nodes in the graph.
It will then print out the path to get to that node backwards.

`

	-= Example using Djkstra's Algorithm to calculate paths between connected nodes =
	----------------
	Calculated path from A to D
	D <- A
	----------------
	----------------
	Calculated path from D to A
	A <- C <- D
	----------------
	----------------
	Calculated path from A to E
	NOT REACHABLE
	----------------
	----------------
	Calculated path from A to A
	A
	----------------
`

## Implementation notes

This is implemented quite crudely but serves as a simple and easy to follow example of how to implement this Algorithm in code.

Tested it compiling and running as a console app on Win32 in Visual Studio 2010 or CodeBlocks IDE using GCC compiler on Linux Ubuntu.

* It doesn't maintain a "Fringe" list of nodes to check, it just checks all unvisted nodes every time
* It's not thread safe as it's storing path values in the cNode class
* The resulting path is simply printed out backwards, you could implement a stack to push it onto it if you wanted
* Isn't robust - doesn't do any checking for null parameters to functions

## Links

* Dijkstra Algorithm Example - https://www.youtube.com/watch?v=0nVYi3o161A
* Wikipedia Entry - http://en.wikipedia.org/wiki/Dijkstra's_algorithm





