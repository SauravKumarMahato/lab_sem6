use bct_cd;

create table First (
id integer, 
name varchar(4)
);

create table Second(
id integer,
name varchar(4)
);

insert into First 
values
(1,'A'),
(2,'B'),
(3,'C'),
(4,'D');

select * from First;

insert into Second 
values 
(2,'B'),
(3,'C'),
(5, 'E'),
(6,'F');

Select * from Second;

select * from First union Select * from Second;

select * from First where id in(Select id from Second);

select * from First where id not in (Select id from Second);



