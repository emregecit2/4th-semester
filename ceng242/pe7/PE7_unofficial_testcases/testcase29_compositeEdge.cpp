#include "submain.h"

int main() {
	
	Edge* edge1 = new InwardsEdge(123456);
	Edge* edge2 = new OutwardsEdge(432157);
	Edge* edge3 = new StraightEdge(513246);
	Edge* edge4 = new StraightEdge(654327);
	Edge* edge5 = new OutwardsEdge(562258);
	Edge* edge6 = new InwardsEdge(957585);

	// CompositeEdge
	CompositeEdge* edge7 = new CompositeEdge(87653487);
	CompositeEdge* edge8 = new CompositeEdge(15121304);
	edge7->addEdge(edge1)->addEdge(edge3)->addEdge(edge5);
	edge8->addEdge(edge2)->addEdge(edge4)->addEdge(edge6);

	cout << (edge7->matchWith(*edge8) ? "true" : "false") << endl;		// true
	cout << edge7->getMatchingEdge()->getId() << endl;					// 15121304
	cout << edge8->getMatchingEdge()->getId() << endl;					// 87653487
	
	delete edge7;
	delete edge8;
	return 0;
}