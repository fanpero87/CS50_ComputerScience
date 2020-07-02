SELECT name FROM
stars JOIN people ON people.id = stars.person_id
WHERE movie_id IN
(SELECT movie_id FROM people JOIN stars ON people.id = stars.person_id
WHERE id = (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958"))
AND NOT name = "Kevin Bacon"
GROUP BY person_id;