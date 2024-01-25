use  bct_cd; 

create table Students(
studno integer primary key,
name varchar(50),
course varchar(4)
);

create table Courses(
courseno varchar(4) primary key,
name varchar(50)
);

insert into Students 
values
(100,'Fred','PH'),
(200,'Dave','CM'),
(300,'Bob','CM');

select * from Students;

insert into Courses 
values 
('PH','Pharmacy'),
('CM', 'Computing');

select * from Courses;

select * from Students, Courses;

select * from Students, Courses
where studno = 200 ;

select * from Students, Courses
where course = courseno;


