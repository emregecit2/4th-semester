:- module(main, [salad_type/2, person_can_eat/3, possible_order_options/3, count_per_type/2]).
:- [kb].

% DO NOT CHANGE THE UPPER CONTENT, WRITE YOUR CODE AFTER THIS LINE

salad_type([], vegan).
salad_type([Head|Tail], vegan) :- not(not_vegan(Head)), salad_type(Tail, vegan).
salad_type([], vegetarian).
salad_type([Head|Tail], vegetarian) :- not(not_vegetarian(Head)), salad_type(Tail, vegetarian).
salad_type(_, omnivorous):- true.

person_can_eat(Person, SaladList, Salad) :- member(Salad, SaladList),
    (
        (vegan(Person), salad_type(Salad, vegan));
        (vegetarian(Person), salad_type(Salad, vegetarian));
        (omnivorous(Person))
    ).
    
possible_order_options(Person, OrderString, ItemList) :- atom_chars(OrderString, OrderList),
    (
        (vegan(Person), vegan_order(OrderList, ItemList), is_set(ItemList));
        (vegetarian(Person), vegetarian_order(OrderList, ItemList), is_set(ItemList));
        (omnivorous(Person), omnivorous_order(OrderList, ItemList), is_set(ItemList))
    ).

vegan_order([], []).
vegan_order([Head|Tail], [Item|Rest]) :-
(
    (Head == b, base(Item));
    (Head == p, protein(Item));
    (Head == t, topping(Item));
    (Head == c, condiment(Item));
    (Head == s, sauce(Item))
), not(not_vegan(Item)),
vegan_order(Tail, Rest).

vegetarian_order([], []).
vegetarian_order([Head|Tail], [Item|Rest]) :-
(
(Head == b, base(Item));
(Head == p, protein(Item));
(Head == t, topping(Item));
(Head == c, condiment(Item));
(Head == s, sauce(Item))
), not(not_vegetarian(Item)),
vegetarian_order(Tail, Rest).

omnivorous_order([], []).
omnivorous_order([Head|Tail], [Item|Rest]) :-
(
(Head == b, base(Item));
(Head == p, protein(Item));
(Head == t, topping(Item));
(Head == c, condiment(Item));
(Head == s, sauce(Item))
), omnivorous_order(Tail, Rest).

count_per_type_helper([], [[vegan, 0], [vegetarian, 0], [omnivorous, 0]]).
count_per_type_helper([Head|Tail], [[vegan, VeganCount], [vegetarian, VegetarianCount], [omnivorous, OmnivorousCount]]) :- count_per_type_helper(Tail, TypeListR), nth0(0, TypeListR, VeganCountL), nth0(1, TypeListR, VegetarianCountL), nth0(2, TypeListR, OmnivorousCountL),
nth0(1, VeganCountL, VeganCountR), nth0(1, VegetarianCountL, VegetarianCountR), nth0(1, OmnivorousCountL, OmnivorousCountR),
(
(salad_type(Head, vegan), !, VeganCount is VeganCountR + 1, VegetarianCount is VegetarianCountR, OmnivorousCount is OmnivorousCountR);
(salad_type(Head, vegetarian), !, VeganCount is VeganCountR, VegetarianCount is VegetarianCountR + 1, OmnivorousCount is OmnivorousCountR);
(VeganCount is VeganCountR, VegetarianCount is VegetarianCountR, OmnivorousCount is OmnivorousCountR + 1)
).

count_per_type(SaladList, TypeList) :- count_per_type_helper(SaladList, TypeListR), 
(delete(TypeListR, [vegan, 0], TypeListS)),
(delete(TypeListS, [vegetarian, 0], TypeListT)),
(delete(TypeListT, [omnivorous, 0], TypeList)).