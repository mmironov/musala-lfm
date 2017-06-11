SELECT *
FROM Customers;

INSERT INTO Customers (first_name, last_name, email)

SELECT first_name, last_name, 'miro@abv.bg' as email
FROM Customers;

UPDATE Customers
SET
	address = 'Bulgaria'
WHERE TRUE

INSERT INTO Products(name, price)
VALUES
('MacBook Air', 1000),
('iPhone 5s', 900),
('Acer Remote Control', 14.50),
('Acer Projector', 430);