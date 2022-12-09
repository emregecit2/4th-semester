#include "submain.h"

int main() {

	// Piece-1
	StraightEdge edge1(1010);
	InwardsEdge edge2(2020);
	InwardsEdge edge3(3030);
	OutwardsEdge edge4(4040);
	Edge* edges1[4] = {&edge1, &edge2, &edge3, &edge4};

	Piece* piece1 = new Piece(edges1);

	// Piece-2
	InwardsEdge edge5(5050);
	OutwardsEdge edge6(6060);
	OutwardsEdge edge7(7070);
	InwardsEdge edge8(8080);
	Edge* edges2[4] = {&edge5, &edge6, &edge7, &edge8};

	Piece* piece2 = new Piece(edges2);

	// Piece-3
	StraightEdge edge9(9090);
	InwardsEdge edge10(1111);
	OutwardsEdge edge11(2222);
	StraightEdge edge12(3333);
	Edge* edges3[4] = {&edge9, &edge10, &edge11, &edge12};

	Piece* piece3 = new Piece(edges3);


	Puzzle* puzzle = new Puzzle(8, 0, 0);
	int location1[2] = {3, 2};
	puzzle->placePiece(*piece1, location1);
	
	int location2[2] = {6, 6};
	puzzle->placePiece(*piece2, location2);
	
	int location3[2] = {0, 4};
	puzzle->placePiece(*piece3, location3);

	cout << *puzzle << endl;

	delete piece1;
	delete piece2;
	delete piece3;
	delete puzzle;

	return 0;
}