SELECT name FROM
directors JOIN people ON directors.person_id = people.id JOIN
movies ON movies.id = directors.movie_id JOIN
ratings ON ratings.movie_id = movies.id
WHERE rating >= 9
GROUP BY directors.person_id;