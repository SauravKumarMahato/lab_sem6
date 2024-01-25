use  bct_cd; 

create table r(
a varchar(4),
b varchar(4)
);

create table s(
b varchar(4),
c varchar(4)
);

insert into r values
('a1','b1'),
('a2','b2'),
('a3', 'b3');

select * from r;

insert into s values
('b1','c1'),
('b2','c2'),
('b4', 'c4');

select * from s;

select * from r natural join s;

select a,r.b,s.c from r left join s on r.b = s.b;

select a,s.b,c from r right join s on r.b = s.b;

create view g as 
(select a,r.b, s.c from r left join s on r.b = s.b);

select * from g;

create view h as 
(select a,s.b,c from r right join s on r.b =s.b);

select * from h;

-- Focus here
select * from g union select * from h;

