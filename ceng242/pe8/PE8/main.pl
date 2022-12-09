:- module(main, [is_movie_directed_by/2, total_awards_nominated/2, all_movies_directed_by/2, total_movies_released_in/3, all_movies_released_between/4]).
:- [kb].

% DO NOT CHANGE THE UPPER CONTENT, WRITE YOUR CODE AFTER THIS LINE

is_movie_directed_by(Title, Director) :- movie(Title, Director, _, _, _, _).

total_awards_nominated(Title, Nominations) :- movie(Title, _, _, OscarNoms, EmmyNoms, GoldenGlobeNoms), Nominations is OscarNoms + EmmyNoms + GoldenGlobeNoms.

all_movies_directed_by(Director, Movies) :- findall(X, movie(X, Director, _, _, _, _), Movies).

total_movies_released_in([], _, Count) :- Count = 0.
total_movies_released_in([Head|Tail], Year, Count) :- movie(Head, _, Year, _, _, _), total_movies_released_in(Tail, Year, CountR), Count is CountR + 1.
total_movies_released_in([Head|Tail], Year, Count) :- not(movie(Head, _, Year, _, _, _)), total_movies_released_in(Tail, Year, Count).

all_movies_released_between([], _, _, MoviesBetweenGivenYears) :- MoviesBetweenGivenYears = [].
all_movies_released_between([Head|Tail], MinYear, MaxYear, MoviesBetweenGivenYears) :- movie(Head, _, Year, _, _, _), Year =< MaxYear, Year >= MinYear, all_movies_released_between(Tail, MinYear, MaxYear, MoviesBetweenGivenYearsR), MoviesBetweenGivenYears = [Head|MoviesBetweenGivenYearsR].
all_movies_released_between([Head|Tail], MinYear, MaxYear, MoviesBetweenGivenYears) :- movie(Head, _, Year, _, _, _), (Year > MaxYear; Year < MinYear), all_movies_released_between(Tail, MinYear, MaxYear, MoviesBetweenGivenYears).
