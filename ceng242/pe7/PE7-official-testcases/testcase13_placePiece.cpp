#include "submain.h"

int main() {

	StraightEdge edge1(1010);
	InwardsEdge edge2(2020);
	InwardsEdge edge3(3030);
	OutwardsEdge edge4(4040);
	Edge* edges[4] = {&edge1, &edge2, &edge3, &edge4};

	Piece* piece = new Piece(edges);

	Puzzle* puzzle = new Puzzle(2, 0, 0);
	int location[2] = {1, 0};
	puzzle->placePiece(*piece, location);
	cout << *puzzle << endl;

	delete piece;
	delete puzzle;

	return 0;
}