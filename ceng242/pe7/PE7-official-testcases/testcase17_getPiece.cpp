#include "submain.h"

int main() {

	Puzzle* puzzle = new Puzzle(4, 4, 4);
	
	try {
		int location[2] = {5, 5};
		const Piece& piece = puzzle->getPiece(location);
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}

	delete puzzle;

	return 0;
}