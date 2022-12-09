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
Piece::Piece(Edge *e[4]) : edges{e[0]->clone(), e[1]->clone(), e[2]->clone(), e[3]->clone()} {}

/* Destructor  : It should destruct its edges too.
*/
Piece::~Piece() {
    for (auto e : edges)
        delete e;
}

/* Copy constructor : Apply deep copy.
*/
Piece::Piece(const Piece& piece) {
    for (size_t i = 0; i < 4; i++)
        edges[i] = piece.edges[i]->clone();
}

// This is already implemented for you, do NOT change it!
ostream& operator<< (ostream& os, const Piece& piece) {

	for (int i = 0; i < 4; i++)
		os << piece.edges[i]->getId() << "  \n";
	return os;
}
