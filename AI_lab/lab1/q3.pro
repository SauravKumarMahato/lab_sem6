DOMAINS
list = integer*

PREDICATES
add(list,integer)

CLAUSES

add([H|T],SUM) :-
    add(T,SUM1),
    SUM=SUM1+H.

add([],0).

GOAL
add([1,2,3,4,5],RESULT).
    