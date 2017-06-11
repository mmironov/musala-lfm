SELECT DISTINCT title, length
FROM film
ORDER BY length;


SELECT first_name, last_name
FROM actor
WHERE first_name LIKE '%N%';

SELECT title, length
FROM film
WHERE length > 50 AND release_year = 2006
ORDER BY title DESC;

SELECT first_name, last_name
FROM actor
WHERE NOT (first_name LIKE 'n%' OR last_name ILIKE '%n');

SELECT first_name, last_name
FROM actor
WHERE first_name LIKE '___' OR last_name NOT ILIKE '%q%'
ORDER BY last_name;

SELECT first_name, last_name
FROM actor
WHERE last_name IN
	(SELECT first_name
	FROM actor);
    
SELECT first_name, last_name
from actor
where first_name = last_name;
    
SELECT title, length
FROM film
WHERE length BETWEEN 50 AND 100;

SELECT *
FROM film
WHERE last_update BETWEEN '2013-01-01' AND '2013-12-31';

SELECT country, city
FROM city
JOIN country
ON city.country_id = country.country_id
ORDER BY country;

SELECT *
FROM film
JOIN language
ON film.language_id = language.language_id AND language.name = 'English';

SELECT name, title, description
FROM language l 
LEFT JOIN film f
ON l.language_id = f.language_id
WHERE l.name LIKE '_______';

SELECT city, address, phone
FROM city
JOIN address
ON address.city_id = city.city_id
WHERE city = 'London' AND phone LIKE '2%';

SELECT
DISTINCT ON (first_name, last_name, actor.actor_id)
first_name, last_name, title, length
FROM actor
JOIN film_actor
ON actor.actor_id = film_actor.actor_id
JOIN film
ON film.film_id = film_actor.film_id
ORDER BY first_name, last_name, actor.actor_id, length DESC;

SELECT DISTINCT
first_name, last_name
FROM actor
JOIN film_actor
ON actor.actor_id = film_actor.actor_id
JOIN film
ON film.film_id = film_actor.film_id
WHERE length IN (SELECT distinct length FROM film ORDER BY length DESC LIMIT 2)
ORDER BY first_name, last_name;

SELECT first.actor_id, first.first_name, first.last_name
FROM actor first
JOIN actor second
ON first.first_name = second.first_name AND first.last_name = second.last_name
WHERE first.actor_id != second.actor_id;

SELECT DISTINCT first_name, last_name
FROM customer
JOIN rental
ON customer.customer_id = rental.customer_id
JOIN inventory
ON rental.inventory_id = inventory.inventory_id
JOIN film
ON inventory.film_id = film.film_id
JOIN film_category
ON film.film_id = film_category.film_id
JOIN category
ON film_category.category_id = category.category_id
WHERE category.name = 'Comedy'
ORDER BY first_name, last_name