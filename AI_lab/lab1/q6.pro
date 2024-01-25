domains
int_list = integer*
 predicates
nondeterm ones_and_twos(int_list, int_list)
 clauses
ones_and_twos([], []).
 % Include 1 or 2, then recursively process the tail of the list.
ones_and_twos([1 | Tail], [1 | Result]) :-
    ones_and_twos(Tail, Result),
    !.
 ones_and_twos([2 | Tail], [2 | Result]) :-
    ones_and_twos(Tail, Result),
    !.
 % Exclude other elements.
ones_and_twos([_ | Tail], Result) :-
    ones_and_twos(Tail, Result),
    !.
 goal
ones_and_twos([1,2,4,5,2,4,5,1,1], List).
