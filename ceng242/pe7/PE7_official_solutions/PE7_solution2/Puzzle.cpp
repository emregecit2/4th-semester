#include "Puzzle.h"


/****************************************************/
/****              *** PUZZLE ***                ****/

/* Contsructor : It takes three integers in the following order:
    The first argument is size of the puzzle which is 2^N for some N >= 0.
    The second argument is the initial row id of the puzzle.
    The third argument is the initial column id of the puzzle.
    
    After initialization with the above arguments, the necessary 
    pointers should be initialized to NULL.
    Note that the final row id in this puzzle is equal to: 
       initial_row_id + size - 1.
    Note that the final column id in this puzzle is equal to: 
       initial_column_id + size - 1.
*/
Puzzle::Puzzle(int sz, int rid, int cid) 
    : top_left(NULL), top_right(NULL), bottom_left(NULL), bottom_right(NULL),
      size(sz), first_row(rid), first_column(cid), piece(NULL)
{}

/* Destructor  : It should destruct its sub-puzzles, yet it is NOT responsible
   of the destruction of its Piece member.
*/
Puzzle::~Puzzle() {
    delete top_left;
    delete top_right;
    delete bottom_left;
    delete bottom_right;
}

// A little helper to make a copy if not NULL
template <typename T>
T *copyOrNull(const T *other)
{
    if (other)
        return new T(*other);
    else
        return NULL;
}

/* Copy constructor : It totally applies deep copy except the Piece
   member part. Do not deep copy Piece objects of the puzzle.
*/
Puzzle::Puzzle(const Puzzle &o) 
    : top_left(copyOrNull(o.top_left)), top_right(copyOrNull(o.top_right)),
      bottom_left(copyOrNull(o.bottom_left)), bottom_right(copyOrNull(o.bottom_right)),
      size(o.size), first_row(o.first_row), first_column(o.first_column), piece(o.piece)
{}

/* Assignment operator : It totally applies shallow copy.
*/
Puzzle& Puzzle::operator=(const Puzzle&) = default;

Puzzle *&Puzzle::getSubpuzzle(int c[2]) {
    // A simple lambda that just returns the given reference
    return funcSubpuzzle(c, [](Puzzle *&pp, int, int, int) -> Puzzle *& { 
        return pp; 
    });
}

Puzzle *&Puzzle::createOrGetSubpuzzle(int c[2]) {
    // A more advanced lambda that creates the subpuzzle if it does not exist
    return funcSubpuzzle(c, [](Puzzle *&pp, int sz, int fr, int fc) -> Puzzle *& {
        if (!pp)
            pp = new Puzzle(sz, fr, fc);
        return pp;
    });
}

// const-version of getSubpuzzle for const functions
Puzzle *const &Puzzle::getSubpuzzle(int c[2]) const
{
    // Use a bit of const_cast magic here to call the non-const getSubpuzzle. const_cast is
    // usually a code smell but here we can use it to avoid duplicating code, since we're sure
    // that getSubpuzzle will be const but can't prove it to the compiler.
    return const_cast<Puzzle *>(this)->getSubpuzzle(c);
}

// Do some stuff with the target subpuzzle. May return it directly, or create if not exists..
template <typename F>
Puzzle *&Puzzle::funcSubpuzzle(int c[2], F func) {
    int half = size >> 1;
    int row_mid = first_row + half;
    int col_mid = first_column + half;
    if (c[0] < row_mid) {
        if (c[1] < col_mid) 
            return func(top_left, half, first_row, first_column);
        else
            return func(top_right, half, first_row, col_mid);
    } else {
        if (c[1] < col_mid)
            return func(bottom_left, half, row_mid, first_column);
        else
            return func(bottom_right, half, row_mid, col_mid);
    }
}

/* This method directly assigns (without copying) the given Piece object to
   the corresponding sub-puzzle (cell) whose indices given in the second 
   argument in array form as follows <row_id, column_id>.
*/
void Puzzle::placePiece(const Piece &p, int c[2]) {
    if (size == 1)
        piece = &p;
    else
        createOrGetSubpuzzle(c)->placePiece(p, c);
}

bool Puzzle::tryRemovePiece(int c[2]) {
    if (size == 1) {
        piece = NULL;
        return true;
    } else {
        Puzzle *&sub = getSubpuzzle(c);
        if (!sub) // Give up if subpuzzle does not exist
            return false;
        if (sub->tryRemovePiece(c)) {
            delete sub; // Sub is clear, delete it
            sub = NULL; 
            // Can recursively clear if no subnodes exist
            return !top_left && !top_right && !bottom_left && !bottom_right;
        }
        return false;
    }
}

/* It returns directly the piece object located in the sub-puzzle (cell)
   whose row id and column id are given in the first and second elements of 
   2D array as argument, respectively. If there is no piece in the requested 
   indices, then this method throws an EmptyCellRequest exception defined in 
   Exception.h file.
*/
const Piece& Puzzle::getPiece(int c[2]) const {
    if (size == 1) {
        if (!piece)
            throw EmptyCellRequest();
        return *piece;
    } else {
        auto s = getSubpuzzle(c);
        if (!s)
            throw EmptyCellRequest();
        return s->getPiece(c);
    }
}

/* This method returns the sub-puzzle whose initial and final row-column ids 
   are given in the first and second arguments, respectively. The indices
   given in the arguments will be given as an exact correspondence to one of
   the sub-puzzles of the current puzzle object.
*/
Puzzle Puzzle::crop(int from[2], int to[2]) const {
    int target_size = to[0] - from[0] + 1;
    Puzzle copy = *this; // Initialization uses the copy-ctor, not the assignment op!
    return copy.cropHelper(from, target_size);
}

Puzzle Puzzle::cropHelper(int c[2], int target_size) {
    if (size == target_size && c[0] == first_row && c[1] == first_column)
        return *this;
    else
        return createOrGetSubpuzzle(c)->cropHelper(c, target_size);
}

/*
    This method puts (patches) the given puzzle onto the corresponding part
    of the current puzzle object. To which part it will be patched on could
    be determined by just checking the initial row-column indices and the size
    of the puzzle given in the argument. 
    Unlike crop() method, the puzzle given in the argument may not be an exact 
    correspondence of some sub-puzzle. It is ensured that the given argument will
    be located on some sub-space of the current puzzle, yet it may *partially* 
    overlap with some or more sub-puzzles (See the figure in the pdf).
    The patch operation requires deep-copy of the corresponding sub-puzzles
    whereas it requires shallow copy of the corresponding Piece objects.
    
    HINT: You may get benefit from placePiece() method and you may start your
    operation by clearing the corresponding parts of the current puzzle.
*/
void Puzzle::patch(const Puzzle &p) {
    // NOT TO BE GRADED. YOU CAN IMPLEMENT IF YOU WOULD LIKE TO.
    for (int ro = 0; ro < p.size; ro++) {
        for (int co = 0; co < p.size; co++) {
            int c[2] = { p.first_row + ro, p.first_column + co };
            try {
                const Piece &piece = p.getPiece(c);
                placePiece(piece, c);
            } catch (const EmptyCellRequest &) {
                tryRemovePiece(c);
            }
        }
    }
}


