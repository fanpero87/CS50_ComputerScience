SELECT title FROM
stars JOIN people ON stars.person_id = people.id JOIN
movies ON movies.id = stars.movie_id JOIN
ratings ON ratings.movie_id = movies.id
WHERE  name = "Helena Bonham Carter"
INTERSECT
SELECT title FROM
stars JOIN people ON stars.person_id = people.id JOIN
movies ON movies.id = stars.movie_id JOIN
ratings ON ratings.movie_id = movies.id
WHERE  name = "Johnny Depp";