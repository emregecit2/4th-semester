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
	OutwardsEdge edge11(2121);
	StraightEdge edge12(3131);
	Edge* edges3[4] = {&edge9, &edge10, &edge11, &edge12};

	Piece* piece3 = new Piece(edges3);

	// Piece-4
	StraightEdge edge13(4141);
	InwardsEdge edge14(5151);
	OutwardsEdge edge15(6161);
	StraightEdge edge16(7171);
	Edge* edges4[4] = {&edge13, &edge14, &edge15, &edge16};

	Piece* piece4 = new Piece(edges4);


	Puzzle* puzzle = new Puzzle(16, 0, 0);
	int location1[2] = {1, 6};
	puzzle->placePiece(*piece1, location1);
	
	int location2[2] = {3, 7};
	puzzle->placePiece(*piece2, location2);
	
	int location3[2] = {7, 9};
	puzzle->placePiece(*piece3, location3);

	cout << *puzzle << endl;

	int from[2] = {0, 4};
	int to[2] = {3, 7};
	Puzzle cropped_part = puzzle->crop(from, to);
	cout << cropped_part << endl << endl;

	int location4[2] = {3, 5};
	cropped_part.placePiece(*piece4, location4);

	try {
		const Piece& piece = cropped_part.getPiece(location4);
		cout << "The following piece has been found:" << endl;
		cout << piece << endl;
	}
	catch(exception& e) {
		cout << e.what() << endl << endl;
	}

	try {
		const Piece& piece = puzzle->getPiece(location4);
		cout << "The following piece has been found:" << endl;
		cout << piece << endl;
	}
	catch(exception& e) {
		cout << e.what() << endl << endl;
	}

	cout << cropped_part << endl << endl;


	delete piece1;
	delete piece2;
	delete piece3;
	delete piece4;
	delete puzzle;

	return 0;
}