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
LEFT JOIN film_actor
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
WHERE length IN (SELECT distinct length FROM film ORDER BY length DESC LIMIT 1)
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
ORDER BY first_name, last_name;

SELECT
DISTINCT ON (title, film.film_id)
title, release_year, return_date
FROM film
LEFT JOIN inventory
ON film.film_id = inventory.film_id
LEFT JOIN rental
ON inventory.inventory_id = rental.inventory_id
ORDER by title, film.film_id, return_date DESC;

SELECT
DISTINCT ON (title, film.film_id)
title, release_year, return_date
FROM film
JOIN inventory
ON film.film_id = inventory.film_id
JOIN rental
ON inventory.inventory_id = rental.inventory_id
WHERE return_date IS NULL;

SELECT count(return_date) AS count_return_date, count(*) AS count_all
FROM rental;

SELECT
title, count(rental_date) AS rental_count
FROM film
LEFT JOIN inventory
ON film.film_id = inventory.film_id
LEFT JOIN rental
ON inventory.inventory_id = rental.inventory_id
GROUP BY film.film_id
HAVING count(rental_date) >= 20
ORDER BY rental_count;

SELECT title
FROM film
WHERE film_id IN
(SELECT inventory.inventory_id
FROM inventory
LEFT JOIN rental
ON inventory.inventory_id = rental.inventory_id
WHERE rental.inventory_id IS NULL);

SELECT DISTINCT inventory.inventory_id
FROM inventory
LEFT JOIN rental
ON inventory.inventory_id = rental.inventory_id
ORDER BY inventory.inventory_id;

SELECT
DISTINCT ON (t.actor_id, first_name, last_name)
t.actor_id, first_name, last_name, max_length, title
FROM
	(SELECT actor.actor_id, first_name, last_name, max(length) as max_length
	FROM film
	JOIN film_actor
	ON film.film_id = film_actor.film_id
	JOIN actor
	ON film_actor.actor_id = actor.actor_id
	GROUP BY actor.actor_id) t
JOIN film_actor
ON t.actor_id = film_actor.actor_id
JOIN film
ON film_actor.film_id = film.film_id AND t.max_length = film.length
ORDER BY first_name, last_name;

SELECT film.film_id, title, count(film_actor.actor_id) as count_actors
FROM film
LEFT JOIN film_actor
ON film.film_id = film_actor.film_id
GROUP BY film.film_id
ORDER BY count_actors, title;

SELECT count(DISTINCT first_name), count(DISTINCT last_name)
FROM actor;

SELECT * FROM payment
ORDER BY payment_date DESC;

SELECT customer.customer_id, first_name, last_name, sum(amount) as total
FROM customer
JOIN payment
ON customer.customer_id = payment.customer_id
GROUP BY customer.customer_id
ORDER BY total DESC
LIMIT 1;

SELECT category.category_id, name, film.title, count(rental.rental_id) AS total_rents
FROM rental
JOIN inventory
ON rental.inventory_id = inventory.inventory_id
JOIN film
ON inventory.film_id = film.film_id
JOIN film_category
ON film.film_id = film_category.film_id
RIGHT JOIN category
ON film_category.category_id = category.category_id
GROUP BY category.category_id, film.title
ORDER BY total_rents DESC;

select round(avg(rental_rate), 2)
from film;

SELECT actor.actor_id, first_name, last_name, round(avg(rental_rate), 2) AS avg_rating
FROM actor
JOIN film_actor
ON actor.actor_id = film_actor.actor_id
JOIN film
ON film_actor.film_id = film.film_id
GROUP BY actor.actor_id
ORDER BY avg_rating DESC
LIMIT 1
