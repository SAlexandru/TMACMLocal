# [Ideal path](https://vjudge.net/problem/UVA-1599)

Vom calcula lungimea minima a unui drum de la fiecare nod la destinatie (nodul
`N`) printr-o parcurgere in latima care porneste din nodul destinatie.

Fie `Dmin` lungimea minima a unui drum de la sursa (nodul `1`) la destinatie.
Pentru a reconstitui drumul de lungime minima si minim lexicografic, pentru
fiecare distanta `d` intre `1` si `Dmin`, vom construi multimea `V[d]` de noduri
care fac parte dintr-un drum de lungime minima de la sursa la destinatie, se
afla la distanta `d` de destinatie si au prefixul de lungime `Dmin - d` al
drumului minim lexicografic.

Initial, `V[Dmin] = {1}`. Avand multimea `V[d]` calculata, putem afla multimea
`V[d - 1]` in felul urmator:
- aflam muchiile `(u, v, c)` cu proprietatea ca `u` apartine lui `V[d]` si
lungimea minima a unui drum de la `v` la destinatie este `d - 1`
- retinem acele muchii care au culoarea `c` minima lexicografic
- multimea `V[d - 1]` va fi formata din nodurile `v` ale muchiilor aflate
anterior

Astfel, un drum de lungme minima si minim lexicografic va trece doar prin
nodurile din multimile `V[Dmin]`, `V[Dmin - 1]`, ..., `V[1]`, `{N}` (nodul
destinatie).

Complexitatea de timp si spatiu este `O(N + M)`.
