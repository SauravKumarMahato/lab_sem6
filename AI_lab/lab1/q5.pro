DOMAINS
List=integer*

PREDICATES
append_lists(List,List,List).

CLAUSES
append_lists([], List, List).

append_lists([Head|Tail1], List2, [Head|Result]) :-
    append_lists(Tail1, List2, Result).

GOAL
append_lists([4,2,6,7], [12,54,23],RESULTING_ARRAY).