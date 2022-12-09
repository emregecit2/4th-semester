#include "Edge.h"


/****************************************************/
/****                *** EDGE ***                ****/

/* Contsructor : initializes <id> of the object to the given integer
   and <password> of the object to the given Password object.   
*/
Edge::Edge(int i, Password p) : id(i), password(p), matchingEdge(NULL) {}

/* Destructor  : It is NOT responsible of the destruction of the matchingEdge!
*/
Edge::~Edge() = default;

/* Returns the <id> of the object
*/
int Edge::getId() const {
	return id;
}

/* Returns the pointer to the matching partner of the current edge.
   If the edge had not been matched before, it returns NULL.
*/
Edge* Edge::getMatchingEdge() const {
    return matchingEdge;
}

/* It tries to match the current Edge object with the one given in the argument.
   If the two edges are matchable then it does the matching by storing
   <matchingEdge> variables with each other, and returns true. Otherwise,
   it does not match and returns false.
   It applies the matching rules given in the pdf.
   Note that match operation is a mutual operation. Namely, if the current
   edge is matched, then its partner edge should be matched with the current 
   one too.
   HINT: It may need matchWithHelper(Password) method.
   
   Note: Of course, it would be nicer to overload this method for taking 
   different types of Edges as arguments, yet this design was preffered 
   specifically for you to discover mechanism of virtual. Helper method
   is given to the issue.
*/
bool Edge::matchWith(Edge &o) { 
    if (matchWithHelper(o.password)) {
        matchingEdge = &o;
        o.matchingEdge = this;
        return true;
    }
    return false;
}

/* If the current edge was matched with some edge before, then this method
   breaks the match, i.e. there is no match between those two edges anymore.
   Note that breaking match operation is a mutual operation. Namely, if the 
   matching of the current edge is broken, the matching recorded in its partner 
   edge should be broken too.
*/
void Edge::breakMatch() {
    if (matchingEdge)
        matchingEdge->matchingEdge = NULL;
    matchingEdge = NULL;
}

// A helper for cloning subclasses without pasting code.
// Kind of sad to have it in the base class but there's nowhere else!
template <typename E, typename M>
E *Edge::clonet() const {
    E *nc = new E(id);
    if (matchingEdge) {
        M *nm = new M(matchingEdge->id);
        nm->matchingEdge = nc;
        nc->matchingEdge = nm;
    }
    return nc;
}

/****************************************************/
/****            *** STRAIGHT EDGE ***           ****/

/* Contsructor : initializes <id> of the object to the given integer
   and <password> of the object.
   Note that Password variable has a fixed value which is SEND_ME_STRAIGHT,
   therefore it is not given as an argument.
*/
StraightEdge::StraightEdge(int i) : Edge(i, SEND_ME_STRAIGHT) {}

/* Destructor  : It is not responsible of the destruction of the matchingEdge!
*/
StraightEdge::~StraightEdge() = default;

/* This method clones the current object and returns the pointer to its clone.
   Cloning is actually a deep-copy operation, so you need to construct a new
   StraightEdge object.
   Note that if the current edge is matched with some other edge, then its
   matchingEdge should be cloned too and only the clones should be matched 
   with each other.
*/
Edge* StraightEdge::clone() const {
    return clonet<StraightEdge, StraightEdge>();
}

/* This method may be needed as a helper for the operation of matchWith(Edge&).
*/
bool StraightEdge::matchWithHelper(Password p)
{
    return p == SEND_ME_STRAIGHT;
}

/****************************************************/
/****            *** INWARDS EDGE ***            ****/

/* Contsructor : initializes <id> of the object to the given integer
   and <password> of the object.
   Note that Password variable has a fixed value which is SEND_ME_OUTWARDS,
   therefore it is not given as an argument.
*/
InwardsEdge::InwardsEdge(int i) : Edge(i, SEND_ME_OUTWARDS) {}

/* Destructor  : It is not responsible of the destruction of the matchingEdge!
*/
InwardsEdge::~InwardsEdge() = default;

/* This method clones the current object and returns the pointer to its clone.
   Cloning is actually a deep-copy operation, so you need to construct a new
   InwardsEdge object.
   Note that if the current edge is matched with some other edge, then its
   matchingEdge should be cloned too and only the clones should be matched 
   with each other.
*/
Edge* InwardsEdge::clone() const {
    return clonet<InwardsEdge, OutwardsEdge>();
}

/* This method may be needed as a helper for the operation of matchWith(Edge&).
*/
bool InwardsEdge::matchWithHelper(Password p) {
    return p == SEND_ME_INWARDS;
}

/****************************************************/
/****            *** OUTWARDS EDGE ***           ****/

/* Contsructor : initializes <id> of the object to the given integer
   and <password> of the object.
   Note that Password variable has a fixed value which is SEND_ME_INWARDS,
   therefore it is not given as an argument.
*/
OutwardsEdge::OutwardsEdge(int i) : Edge(i, SEND_ME_INWARDS) {}

/* Destructor  : It is not responsible of the destruction of the matchingEdge!
*/
OutwardsEdge::~OutwardsEdge() = default;

/* This method clones the current object and returns the pointer to its clone.
   Cloning is actually a deep-copy operation, so you need to construct a new
   OutwardsEdge object.
   Note that if the current edge is matched with some other edge, then its
   matchingEdge should be cloned too and only the clones should be matched 
   with each other.
*/
Edge* OutwardsEdge::clone() const {
    return clonet<OutwardsEdge, InwardsEdge>();
}

/* This method may be needed as a helper for the operation of matchWith(Edge&).
*/
bool OutwardsEdge::matchWithHelper(Password p) {
    return p == SEND_ME_OUTWARDS;
}

/****************************************************/
/*        THE BELOW PART WILL NOT BE GRADED.        */
/*      YOU CAN IMPLEMENT IF YOU WOULD LIKE TO.     */
/****************************************************/

/****************************************************/
/****            *** COMPOSITE EDGE ***          ****/

/* Contsructor : initializes <id> of the object to the given integer
   and <password> of the object.
   Note that Password variable has a fixed value which is SEND_ME_COMPLETING_COMPOSITE,
   therefore it is not given as an argument.
   Note that you may need to initialize matchIndex variable with some value
   so that you may benefit from that during any match operation.
*/
CompositeEdge::CompositeEdge(int i) 
    : Edge(i, SEND_ME_COMPLETING_COMPOSITE), edges(), matchIndex() {}

/* Destructor  : It is not responsible of the destruction of the matchingEdge!
*/
CompositeEdge::~CompositeEdge() {
   for (auto e : edges)
      delete e;
} 

/* This method clones the current object and returns the pointer to its clone.
   Cloning is actually a deep-copy operation, so you need to construct a new
   CompositeEdge object. During the construction, each member Edge object 
   should be cloned too, and the clone of the current CompositeEdge should
   include only the clones of the member edges.
   Note that if the current edge is matched with some other edge, then its
   matchingEdge should be cloned too and only the clones should be matched 
   with each other.
*/
Edge* CompositeEdge::clone() const {
    CompositeEdge *nc = new CompositeEdge(id);
    for (auto e : edges)
        nc->addEdge(e->clone());
    if (matchingEdge) {
        // Can use static cast to downcast since we're sure of the behavior
        CompositeEdge *nm = static_cast<CompositeEdge *>(matchingEdge->clone());
        nm->matchingEdge = nc;
        nc->matchingEdge = nm;
    }
    return static_cast<Edge *>(nc);
}

/* This method may be needed as a helper for the operation of matchWith(Edge&).
*/
bool CompositeEdge::matchWithHelper(Password p) {
    return p == SEND_ME_COMPLETING_COMPOSITE;
}

/* It tries to match the current CompositeEdge object with the one given in the 
   argument.
   If the two edges are matchable then it does the matching by storing
   <matchingEdge> variables with each other, and returns true. Otherwise,
   it does not match and returns false.
   It applies the matching rules given in the pdf.
   Note that match operation is a mutual operation. Namely, if the current
   edge is matched, then its partner edge should be matched with the current 
   one too.
   HINT: It may need matchWithHelper(Password) method.
   
   Note: Of course, it would be nicer to overload this method for taking 
   different types of Edges as arguments, yet this design was preffered 
   specifically for you to discover mechanism of virtual. Helper method
   is given to the issue.
*/
bool CompositeEdge::matchWith(Edge &other) {
    if (Edge::matchWith(other)) {
        // Guaranteed to be composite. Edge::matchWith also matches the two
        // automatically which is a pain, but I'll break it in case matches fail.
        if (edgesMatch(static_cast<CompositeEdge &>(other))) {
            return true; // Match complete! Excellent.
        } else { // Otherwise, have to break what we have so far 
            breakMatch();
        }
    }
    return false;
}

bool CompositeEdge::edgesMatch(CompositeEdge &other)
{
    if (edges.size() == other.edges.size()) {
        for (size_t i = 0; i < edges.size(); i++)
            if (!edges[i]->matchWith(*other.edges[i]))
                return false;
        return true;
    }
    return false;
}

/* If the current edge was matched with some edge before, then this method
   breaks the match, i.e. there is no match between those two edges anymore.
   Note that breaking match operation is a mutual operation. Namely, if the 
   matching of the current edge is broken, the matching recorded in its partner 
   edge should be broken too.
*/
void CompositeEdge::breakMatch() {
    for (auto e : edges)
        e->breakMatch();
    Edge::breakMatch();
}

/* This method pushes back the given edge in the argument into the end of the 
   member edges vector.
*/
CompositeEdge* CompositeEdge::addEdge(Edge* edge) {
    edges.push_back(edge);
    return this; 
}
