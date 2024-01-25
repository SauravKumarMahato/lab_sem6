DOMAINS
int_list=integer*

PREDICATES
nondeterm solution(int_list)
nondeterm member(integer, int_list)

CLAUSES
solution([]).
solution([F,O,R,T,Y,E,N,X,I,S]):-
	member(C1,[0,1,2]),
	member(C2,[0,1,2]),
	member(C3,[0,1,2]),
	member(C4,[0,1,2]),
	%c1, c2 ,c3,c4 will have either 0 or 1 or 2.
	member(F,[0,1,2,3,4,5,6,7,8,9]),
	member(O,[0,1,2,3,4,5,6,7,8,9]),
	member(R,[0,1,2,3,4,5,6,7,8,9]),
	%member(T,[0,1,2,3,4,5,6,7,8,9]),
	T=8,
	member(Y,[0,1,2,3,4,5,6,7,8,9]),
	member(E,[0,1,2,3,4,5,6,7,8,9]),
	%member(N,[0,1,2,3,4,5,6,7,8,9]),
	N=0,
	member(X,[0,1,2,3,4,5,6,7,8,9]),
	member(I,[0,1,2,3,4,5,6,7,8,9]),
	member(S,[0,1,2,3,4,5,6,7,8,9]),
	% F,O,R,T,Y,E,N,X,I,S will have value betweenm 0 to 9 
	% The value of F,O,R,T,Y,E,N,X,I,S must not be equal to each other
	
	
	F<>O, F<>R,F<>T, F<>Y,F<>E, F<>N,F<>X, F<>I,F<>S,
	O<>R,O<>T, O<>Y,O<>E, O<>N,O<>X,O<>I,O<>S,
	R<>T, R<>Y,R<>E, R<>N,R<>X,R<>I,R<>S,
	T<>Y,T<>E, T<>N,T<>X,T<>I,T<>S,
	Y<>E, Y<>N,Y<>X,Y<>I,Y<>S,
	E<>N,E<>X,E<>I,E<>S,
	N<>X,N<>I,N<>S,
	X<>I,X<>S,
	I<>S,
	
	% Computation for solution
	Y+N+N=Y+10*C1,
	C1+T+2*E=T+10*C2,
	C2+R+2*T=X+10*C3,
	C3+O=I+10*C4,
	C4+F=S.
	
member(X,[X|_]).
member(X,[_| Z]) :-
	member(X,Z).
	
GOAL
solution([F,O,R,T,Y,E,N,X,I,S]).