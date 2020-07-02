SELECT name FROM
movies JOIN stars ON movies.id = stars.movie_id JOIN
people ON stars.person_id = people.id
WHERE year = 2004
GROUP BY people.id
ORDER BY birth DESC;