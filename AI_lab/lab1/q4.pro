DOMAINS
list_of_int=integer*

PREDICATES
length_of_list(list_of_int,integer)

CLAUSES
length_of_list([],0).

length_of_list([H|T],L):-
    length_of_list(T,L1),
    L=L1+1.
	
GOAL
length_of_list([23,43,44,56,23,53],LENGTH).