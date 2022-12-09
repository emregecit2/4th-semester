#include "Edge.h"

#include <iostream>
#include <sstream>

int main() {

	Edge* edge1 = new InwardsEdge(623456);
	Edge* edge2 = new OutwardsEdge(732157);
	Edge* edge3 = new OutwardsEdge(813246);

	cout << (edge1->matchWith(*edge2) ? "true" : "false") << endl;		// true
	cout << edge1->getMatchingEdge()->getId() << endl;				
	cout << edge2->getMatchingEdge()->getId() << endl;				

	edge1->breakMatch();

	cout << (edge1->matchWith(*edge3) ? "true" : "false") << endl;		// true
	cout << edge1->getMatchingEdge()->getId() << endl;				
	Edge* edge = edge2->getMatchingEdge();
	if (edge == NULL)
		cout << "no partner" << endl;
	cout << edge3->getMatchingEdge()->getId() << endl;				

	delete edge1;
	delete edge2;
	delete edge3;

	return 0;
}