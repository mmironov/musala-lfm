SELECT DISTINCT ON ( t2.city_id )
t2.city, t2.title,customer.first_name, customer.last_name, count(inventory.film_id) as total_count
FROM city
JOIN address
ON city.city_id = address.city_id
JOIN customer
ON address.address_id = customer.address_id
JOIN rental
ON customer.customer_id = rental.customer_id
JOIN inventory
ON rental.inventory_id = inventory.inventory_id

JOIN 

( SELECT DISTINCT ON (t.city_id)
t.city_id, t.city, film.film_id, film.title, film.rental_duration
FROM
       ( SELECT city.city_id, city.city, max(film.rental_duration) as max_duration
         FROM city
         JOIN address
         ON city.city_id = address.city_id
         JOIN customer
         ON address.address_id = customer.address_id
         JOIN rental
         ON customer.customer_id = rental.customer_id
         JOIN inventory
         ON rental.inventory_id = inventory.inventory_id
         JOIN film
         ON inventory.film_id = film.film_id
         GROUP BY city.city_id, city.city ) t
JOIN address
ON t.city_id = address.city_id
JOIN customer
ON address.address_id = customer.address_id
JOIN rental
ON customer.customer_id = rental.customer_id
JOIN inventory
ON rental.inventory_id = inventory.inventory_id
JOIN film
ON inventory.film_id = film.film_id
WHERE film.rental_duration = max_duration
ORDER BY t.city_id, film.film_id ) t2

ON t2.city_id = address.city_id AND t2.film_id = inventory.film_id
GROUP BY t2.city_id, t2.city, t2.title, t2.film_id, customer.customer_id
ORDER BY t2.city_id, total_count