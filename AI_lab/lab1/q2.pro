PREDICATES
mother(STRING,STRING)
son(STRING,STRING)

CLAUSES
mother("Kaushalya","Ram").
mother("Kaikai","Bharat").
mother("Sumitra","Laxman").

son(A,C):-mother(C,A).

Goal
son(SON,"Kaikai").