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

    ATTENTION: If a sub-puzzle member does not include any Piece, namely,
    if its piece is NULL, then do NOT construct it. In other words, do
    NOT construct subpuzzles unless they are required.
*/
Puzzle::Puzzle(int size, int first_row, int first_column) : size(size), first_row(first_row), first_column(first_column), top_left(NULL), top_right(NULL), bottom_left(NULL), bottom_right(NULL), piece(NULL) {}

/* Destructor  : It should destruct its sub-puzzles, yet it is NOT responsible
   of the destruction of its Piece member.
*/
Puzzle::~Puzzle()
{
    delete top_left;
    delete top_right;
    delete bottom_left;
    delete bottom_right;
    top_left = NULL;
    top_right = NULL;
    bottom_left = NULL;
    bottom_right = NULL;
    piece = NULL;
}

/* Copy constructor : It totally applies deep copy except the Piece
   member part. Do not deep copy Piece objects of the puzzle, instead
   do shallow copy for Pieces.
*/
Puzzle::Puzzle(const Puzzle &puzzle)
{
    delete top_left;
    delete top_right;
    delete bottom_left;
    delete bottom_right;
    *top_left = *puzzle.top_left;
    *top_right = *puzzle.top_right;
    *bottom_left = *puzzle.bottom_left;
    *bottom_right = *puzzle.bottom_right;
    size = puzzle.size;
    first_row = puzzle.first_row;
    first_column = puzzle.first_column;
    piece = puzzle.piece;
}

/* Assignment operator : It totally applies shallow copy.
 */
Puzzle &Puzzle::operator=(const Puzzle &puzzle)
{
    top_left = puzzle.top_left;
    top_right = puzzle.top_right;
    bottom_left = puzzle.bottom_left;
    bottom_right = puzzle.bottom_right;
    size = puzzle.size;
    first_row = puzzle.first_row;
    first_column = puzzle.first_column;
    piece = puzzle.piece;
    return *this;
}

/* This method directly assigns (without copying) the given Piece object to
   the corresponding sub-puzzle (cell) whose indices given in the second
   argument in array form as follows <row_id, column_id>.

    ATTENTION: If a sub-puzzle member does not include any Piece, namely,
    if its piece is NULL, then do NOT construct it. In other words, do
    NOT construct subpuzzles unless they are required.
*/
void Puzzle::placePiece(const Piece &piece, int coordinate[2])
{
    if (size == 1)
    {
        this->piece = &piece;
        return;
    }
    bool top_flag = coordinate[0] < first_row + size / 2;
    bool left_flag = coordinate[1] < first_column + size / 2;
    if (top_flag && left_flag)
    {
        if (top_left == NULL)
        {
            top_left = new Puzzle(size / 2, first_row, first_column);
        }
        top_left->placePiece(piece, coordinate);
    }
    else if (top_flag && !left_flag)
    {
        if (top_right == NULL)
        {
            top_right = new Puzzle(size / 2, first_row, first_column + size / 2);
        }
        top_right->placePiece(piece, coordinate);
    }
    else if (!top_flag && left_flag)
    {
        if (bottom_left == NULL)
        {
            bottom_left = new Puzzle(size / 2, first_row + size / 2, first_column);
        }
        bottom_left->placePiece(piece, coordinate);
    }
    else
    {
        if (bottom_right == NULL)
        {
            bottom_right = new Puzzle(size / 2, first_row + size / 2, first_column + size / 2);
        }
        bottom_right->placePiece(piece, coordinate);
    }
}

/* It returns directly the piece object located in the sub-puzzle (cell)
   whose row id and column id are given in the first and second elements of
   2D array as argument, respectively. If there is no piece in the requested
   indices, then this method throws an EmptyCellRequest exception defined in
   Exception.h file.
*/
const Piece &Puzzle::getPiece(int coordinate[2]) const
{
    if (size == 1)
    {
        if (piece == NULL)
        {
            throw EmptyCellRequest();
        }
        return *piece;
    }
    bool top_flag = coordinate[0] < first_row + size / 2;
    bool left_flag = coordinate[1] < first_column + size / 2;
    if (top_flag && left_flag)
    {
        if (top_left == NULL)
        {
            throw EmptyCellRequest();
        }
        return top_left->getPiece(coordinate);
    }
    else if (top_flag && !left_flag)
    {
        if (top_right == NULL)
        {
            throw EmptyCellRequest();
        }
        return top_right->getPiece(coordinate);
    }
    else if (!top_flag && left_flag)
    {
        if (bottom_left == NULL)
        {
            throw EmptyCellRequest();
        }
        return bottom_left->getPiece(coordinate);
    }
    else
    {
        if (bottom_right == NULL)
        {
            throw EmptyCellRequest();
        }
        return bottom_right->getPiece(coordinate);
    }
}

/* This method returns the sub-puzzle whose initial and final row-column ids
   are given in the first and second arguments, respectively. The indices
   given in the arguments will be given as an exact correspondence to one of
   the sub-puzzles of the current puzzle object.

   ATTENTION: The sub-puzzle to be cropped may correspond to a NULL part of the
   Puzzle object. In that case, it is enough to you to create a new Puzzle
   object that satisfies the asked properties and return it. OF course, do NOT
   forget to do this operation by escaping from memory leaks!!!
*/
Puzzle Puzzle::crop(int from[2], int to[2]) const
{
    if ((from[0] == first_row) && (from[1] == first_column) && (to[0] == first_row + size - 1) && (to[1] == first_column + size - 1))
    {
        return *this;
    }

    bool top_flag = from[0] < first_row + size / 2;
    bool left_flag = from[1] < first_column + size / 2;
    if (top_flag && left_flag)
    {
        if (top_left)
        {
            return top_left->crop(from, to);
        }
    }
    else if (top_flag && !left_flag)
    {
        if (top_right)
        {
            return top_right->crop(from, to);
        }
    }
    else if (!top_flag && left_flag)
    {
        if (bottom_left)
        {
            return bottom_left->crop(from, to);
        }
    }
    else
    {
        if (bottom_right)
        {
            return bottom_right->crop(from, to);
        }
    }
    return Puzzle(to[0] - from[0] + 1, from[0], from[1]);
}

/****************************************************/
/*        THE BELOW PART WILL NOT BE GRADED.        */
/*      YOU CAN IMPLEMENT IF YOU WOULD LIKE TO.     */
/****************************************************/
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
void Puzzle::patch(const Puzzle &)
{
    // TODO
}
