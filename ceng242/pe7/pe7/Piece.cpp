#include "Piece.h"


/****************************************************/
/****               *** PIECE ***                ****/

/* Contsructor : initializes <edges> of the object to the those given in the
   argument. The edges given in the argument array should be cloned first,
   and its clones should be reserved, not the edges themselves.
   Note that the ordering of the given edges will always be as follows:
   edges[0]: Left side edge, 
   edges[1]: Bottom side edge, 
   edges[2]: Right side edge, 
   edges[3]: Top side edge.
*/
Piece::Piece(Edge* edges_arg[4]) {
    edges[0] = edges_arg[0]->clone();
    edges[1] = edges_arg[1]->clone();
    edges[2] = edges_arg[2]->clone();
    edges[3] = edges_arg[3]->clone();
}

/* Destructor  : It should destruct its edges too.
*/
Piece::~Piece() {
    delete edges[0];
    delete edges[1];
    delete edges[2];
    delete edges[3];
}

/* Copy constructor : Apply deep copy.
*/
Piece::Piece(const Piece& piece) {
    edges[0] = piece.edges[0]->clone();
    edges[1] = piece.edges[1]->clone();
    edges[2] = piece.edges[2]->clone();
    edges[3] = piece.edges[3]->clone();
}

// This is already implemented for you, do NOT change it!
ostream& operator<< (ostream& os, const Piece& piece) {

	for (int i = 0; i < 4; i++)
		os << piece.edges[i]->getId() << "  \n";
	return os;
}
