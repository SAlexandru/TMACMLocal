# [Bits equalizer](https://vjudge.net/problem/UVA-12545)

Daca numarul caracterelor de `1` din `S` este mai mare decat numarul
caracterelor de `1` din `T`, deoarece nu exista nicio operatie care sa
transforme un `1` intr-un `0`, nu va exista solutie. In caz contrar, vom folosi
o strategie greedy pentru a obtine un numar minim de operatii.

Cata vreme `S` contine mai putine caractere `1` decat `T`:
- vom transforma o pereche de caractere `(S[i], T[i])` cu valorile `(?, 1)` in
perechea `(1, 1)`
- daca nu este posibil, atunci vom transforma o pereche de caractere
`(S[i], T[i])` cu valorile `(0, 1)` in perechea `(1, 1)`
- daca nu este posibil, atunci vom transforma o pereche de caractere
`(S[i], T[i])` cu valorile `(?, 0)` in perechea `(1, 0)`

Observam ca primele doua operatii in ordinea prioritatii fac caracterele de pe
pozitia `i` din `S`, respectiv `T` egale printr-o singura operatie, si in
acelasi timp, creste numarul caracterelor de `1` din `S`, astfel ca ele sunt
optime. In caz contrar, pentru ca trebuie crescut numarul de caractere de `1`
din `S`, efectuam a treia operatie, urmand ca perechea `(1, 0)` rezultata sa fie
rezolvata ulterior printr-o interschimbare.

In continuare, vom transforma perechile de caractere `(S[i], T[i])` cu valorile
`(?, 0)` in perechea `(0, 0)`. Toate caracterele `?` trebuie eliminate, iar in
acest fel, facem caracterele de pe pozitia `i` egale printr-o singura operatie,
si in acelasi timp, scadem numarul caracterelor `?`, aceasta operatie fiind
optima.

Perechile de caractere `(S[i], T[i])` cu valorile `(?, 1)` vor fi transformate
in perechea `(0, 1)`, urmand ca acestea sa fie rezolvate ulterior prin operatii
de interschimbare. Acest lucru se datoreaza faptului ca nu mai putem crea alte
caractere `1` in `S`, deoarece nu ar mai exista solutie pentru sirul rezultat.

In final, vom interschimba perechile de caractere `(S[i], T[i])` cu valorile
`(0, 1)` cu perechile de caractere `(S[j], T[j])` cu valorile `(1, 0)`, pentru
a face cele doua siruri egale.

Nu este necesara simularea operatiilor pe cele doua siruri, ci doar pe numarul
de perechi de caractere `(S[i], T[i])` cu valorile `(0, 1)`, `(1, 0)`, `(?, 0)`
sau `(?, 1)`. O astfel de solutie are complexitatea de timp si spatiu
`O(|S| + |T|)`.
