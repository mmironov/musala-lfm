/*CREATE TABLE Customers (
    id serial PRIMARY KEY,
    first_name varchar(20),
    last_name varchar(20),
    email varchar(50) NOT NULL UNIQUE,
    address varchar(50)
);*/

/*CREATE TABLE Products (
    id serial PRIMARY KEY,
    name varchar(50) NOT NULL,
    description text,
    price real NOT NULL
);*/

/*CREATE TABLE Purchases (
    id serial PRIMARY KEY,
    customer_id integer REFERENCES Customers(id),
    product_id integer REFERENCES Products(id),
    quantity integer NOT NULL CHECK(quantity > 0),
    date timestamp NOT NULL
);*/