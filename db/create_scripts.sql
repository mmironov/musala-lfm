SELECT *
FROM Customers;

UPDATE Customers
SET
	last_name = 'Nikolaev',
    email = 'abv@abv.bg'
WHERE last_name = 'N'

SELECT *
FROM Purchases;

SELECT Purchases.id, first_name, last_name, name, price
FROM Customers
JOIN Purchases
ON Customers.id = Purchases.customer_id
JOIN Products
ON Products.id = Purchases.product_id

INSERT INTO Products(name, price)
VALUES
('Mac Mini', 2000),
('MacBook Pro', 2200)

SELECT * FROM Products;

INSERT INTO Purchases(customer_id, product_id, quantity, date)

SELECT Customers.id, Products.id, 1, now()
FROM Customers, Products
WHERE Customers.first_name = 'Petar' AND Products.name = 'Mac Mini'
LIMIT 1

DELETE FROM Product
WHERE 
-- ALTER TABLE Purchases ADD CONSTRAINT positive_quantity CHECK (quantity > 0);

ALTER TABLE Purchases DROP COLUMN Quantity;
ALTER TABLE Purchases ADD COLUMN Quantity integer DEFAULT 2;
ALTER TABLE Purchases DROP COLUMN id;
ALTER TABLE Purchases ADD COLUMN id serial PRIMARY KEY;
ALTER TABLE Products DROP COLUMN id;

SELECT * FROM Purchases;

DELETE FROM Purchases
WHERE id IN (
	SELECT Purchases.id
	FROM Purchases
	JOIN Customers
	ON Purchases.customer_id = Customers.id
	WHERE first_name = 'Miroslav'
	ORDER BY Purchases.id
	OFFSET 1)
    
DELETE FROM Purchases
WHERE id IN (
    			SELECT Purchases.id
    			FROM Purchases
    			JOIN Customers
    			ON Purchases.customer_id = Customers.id
    			JOIN Products
    			ON Purchases.product_id = Products.id
    			WHERE first_name = 'Miroslav' AND price < 500
    		)
            
UPDATE Products
SET
    price = price + price * 0.1,
    description = 'The previous price was ' || price || '$.'
WHERE name ilike 'mac%'

CREATE TYPE status AS ENUM ('delivery', 'delivered')