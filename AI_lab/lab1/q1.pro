PREDICATES
nondeterm hcf(integer,integer,integer)
nondeterm find_hcf(integer,integer,integer)

CLAUSES
find_hcf(A, B, HCF) :-
    A >= B,
    hcf(A, B, HCF).

find_hcf(A, B, HCF) :-
    A < B,
    hcf(B, A, HCF).
    
hcf(X, Y, HCF) :-
    Y > 0,
    Z = X mod Y,
    hcf(Y, Z, HCF).
    
hcf(X, 0, X).

GOAL
find_hcf(12,18,HCF).