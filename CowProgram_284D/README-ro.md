# [Cow program](https://vjudge.net/problem/CodeForces-284D)

Putem privi secventa de numere ca fiind un graf orientat cu `N + 1` noduri in
care fiecare nod are gradul de iesire `1` (presupunem ca valoarea `A[1]` este
fixata si ca exista un nod fictiv `NIL` corespunzator valorilor mai mici decat
`1` sau mai mari decat `N`). Nodul `NIL` va fi singurul nod cu grad de iesire
`0`.

Pentru nodul `X`, muchia de iesire va fi `G[X] = X + A[X] - A[X + A[X]]` daca
atat `X + A[X]`, cat si `X + A[X] - A[X + A[X]]` se incadreaza in intervalul
`[1, N]`, sau va fi `G[X] = NIL` in caz contrar. Costul asociat acestei muchii
va fi `A[X] + A[X + A[X]]` daca `X + A[X]` se incadreaza in intervalul `[1, N]`,
sau doar `A[X]` in caz contrar.

Cerinta problemei este sa se determine costul lantului care porneste din nodul
`1`, sau sa se afiseze `-1` daca acesta formeaza un ciclu, pentru fiecare
valoare a lui `A[1]` din intervalul `[1, N - 1]`.

Observam ca daca exista un nod diferit de `1` care are muchie catre `1`, acesta
sigur va forma un ciclu. Asadar, putem preprocesa costul lanturilor care pornesc
din fiecare nod diferit de `1`, dar si ciclurile care se formeaza, printr-o
simpla parcurgere a grafului, ignorand nodul `1`. Avand aceste informatii,
pentru fiecare valoare a lui `A[1]` este suficient sa analizam doar muchia de
iesire din nodul `1` corespunzatoare valorii fixate.

Complexitatea de timp va fi `O(N)`, iar cea de spatiu `O(N)`.
