#include "Edge.h"

#include <iostream>
#include <sstream>

int main() {
	
	Edge* edge1 = new StraightEdge(223456);
	Edge* edge2 = new OutwardsEdge(532157);

	cout << (edge1->matchWith(*edge2) ? "true" : "false") << endl;		// false
	
	delete edge1;
	delete edge2;

	return 0;
}