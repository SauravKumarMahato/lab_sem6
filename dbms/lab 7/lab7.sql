 
CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    salary int
);

CREATE TABLE students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(100)
);

CREATE TABLE grades (
    grade_id INT PRIMARY KEY,
    student_id INT,
    score INT
);

CREATE TABLE sales (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    revenue int
);

CREATE TABLE products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    price int,
    category VARCHAR(50)
);

-- Inserting data into the sales table
INSERT INTO sales VALUES (1, 'heater', 'Electronics', 1500);
INSERT INTO sales VALUES (2, 'ethernet cable', 'Electronics', 800);
INSERT INTO sales VALUES (3, 'blazer', 'Clothing', 1200);
INSERT INTO sales VALUES (4, 'sari', 'Clothing', 5000);

-- Inserting data into the employees table
INSERT INTO employees VALUES (1, 'SASA', 'SINGH', 60000);
INSERT INTO employees VALUES (2, 'SUJAN', 'KAPALI', 75000);
INSERT INTO employees VALUES (3, 'ROHAN', 'MAHARJAN', 60000);
INSERT INTO employees VALUES (4, 'SUBHAN', 'SHRESTHA', 75000);

-- Inserting data into the students and grades tables
INSERT INTO students VALUES (1, 'Sujan');
INSERT INTO students VALUES (2, 'Hari');

INSERT INTO grades VALUES (1, 1, 85);
INSERT INTO grades VALUES (2, 2, 92);

-- Inserting data into the products table
INSERT INTO products VALUES (1, 'Laptop', 1200.00, 'Electronics');
INSERT INTO products VALUES (2, 'Smartphone', 500.00, 'Electronics');
INSERT INTO products VALUES (3, 'Shirt', 30.00, 'Clothing');



-- Find the total revenue for each category, only including categories with total revenue greater than $5000
SELECT category, SUM(revenue) as total_revenue
FROM sales
GROUP BY category
HAVING total_revenue >  100;


-- Retrieve all students who have at least one grade
SELECT student_id, student_name
FROM students
WHERE EXISTS (SELECT 1 FROM grades WHERE students.student_id = grades.student_id);


-- Find all products whose price is lower than the price of every product in the 'Electronics' category
SELECT *
FROM products
WHERE price < ALL (SELECT price FROM products WHERE category = 'Electronics');


-- Find all employees who earn higer than at least one product having category 'Electronics' 
SELECT *
FROM employees
WHERE salary > SOME (SELECT price FROM products WHERE category = 'Electronics');


-- Assuming you have a 'sales' table
CREATE TABLE selling (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100),
    category VARCHAR(50),
    revenue int
);

-- Inserting sample data into the sales table
INSERT INTO selling VALUES (1, 'hair drier', 'Electronics', 2000);
INSERT INTO selling VALUES (2, 'fan', 'Electronics', 1000);
INSERT INTO selling VALUES (3, 'induction', 'Clothing', 5000);

-- Creating a view named 'top_earning_products'
CREATE VIEW productRevenue AS
SELECT product_name, revenue
FROM selling
WHERE revenue > 500;

-- Displaying records from the view
SELECT * FROM productRevenue;

-- Dropping the view
DROP VIEW productRevenue;
