domains
int_list = integer*
 predicates
nondeterm delete(integer, int_list, int_list)
 clauses
delete(_, [], []).
 % If the head of the list is the element to be deleted, skip it and recursively process the tail.
delete(X, [X | Tail], Result) :-
    delete(X, Tail, Result),
    !.  
 % If the head of the list is not the element to be deleted, include it in the result and recursively process the tail.
delete(X, [Head | Tail], [Head | Result]) :-
    delete(X, Tail, Result).
goal
delete(5, [1,2,3,4,5], List).

