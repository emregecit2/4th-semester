#include "Edge.h"

#include <iostream>
#include <sstream>

int main() {
	
	Edge* edge1 = new OutwardsEdge(223456);
	Edge* edge2 = new InwardsEdge(532157);

	cout << (edge1->matchWith(*edge2) ? "true" : "false") << endl;		// true
	cout << edge1->getMatchingEdge()->getId() << endl;					
	cout << edge2->getMatchingEdge()->getId() << endl;					
	
	delete edge1;
	delete edge2;

	return 0;
}