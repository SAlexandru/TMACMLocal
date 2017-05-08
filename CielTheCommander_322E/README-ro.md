# [Ciel the commander](https://vjudge.net/problem/CodeForces-322E)

Pentru a rezolva aceasta problema, vom folosi o abordare recursiva.

Daca trebuie sa rezolvam un arbore cu un singur nod, putem sa ii atribuim orice
rang. Daca arborele are mai mult de un nod, alegem un nod `X` (considerat
radacina arborelui) caruia ii atribuim rangul `'A'`. Evident, va exista un
singur nod cu rangul `'A'` in tot arborele. Ca urmare, subarborii `T1`, `T2`,
..., `Tk` ai nodului `X` vor putea folosi drept ranguri valorile `'B'`, `'C'`,
..., `'Z'`.

Observam ca orice drum care trece prin radacina `X` va avea restrictia impusa in
enunt satisfacuta, deoarece rangul lui `X` este strict mai mare decat rangul
oricarui alt nod dintr-un subarbore al lui `X`.  Asadar, mai este necesar ca
fiecare subarbore `T1`, `T2`, ... `Tk` al lui `X` sa respecte conditia din
enunt, insa acesti subarbori sunt independenti intre ei si pot fi rezolvati in
mod recursiv.

Problema este ca adancimea recursivitatii poate sa depaseasca `26` (numarul de
ranguri pe care le avem la dispozitie), insa alegerea nodului `X` ne poate
ajuta. Daca vom alege mereu acel nod `X` (numit centroid al arborelui) pentru
care dimensiunea maxima a unui subarbore este minima, atunci adancimea maxima a
recursivitatii va fi `log(N)`, care este mai mica decat `26`.

In continuare, vom demonstra ca pentru un arbore de dimensiune `N`, intotdeauna
exista un nod care, daca este sters, va transforma arborele intr-o padure in
care fiecare componenta conexa are dimensiunea cel mult `N / 2`.

Alegem un nod `X` din arbore in mod arbitrar. Daca acesta respecta conditia de
mai sus, atunci un astfel de nod exista. In caz contrar, in urma stergerii
acestui nod, va exista o singura componenta conexa cu dimensiunea mai mare decat
`N / 2`. Urmatorul nod ales va fi vecinul lui `X` care face parte din aceasta
componenta conexa. La acest pas, dimensiunea componentei precedente va scadea cu
`1`. Repetand procedeul, deoarece numarul de noduri din arbore este finit si
nu poate exista mai mult de o componenta conexa cu dimensiune mai mare decat
`N / 2`, vom ajunge la un nod care sa respecte conditia.

La fiecare pas din rezolvarea unui arbore de dimensiune `N`, dimensiunea maxima
a unei componente conexe rezultate in urma stergerii centroidului este `N / 2`,
de unde rezulta ca adancimea maxima a recursivitatii va fi `log(N)`.

In cel mai rau caz, la fiecare adancime din recursivitate, sunt parcurse toate
nodurile din arbore. Ca urmare, complexitatea totala de timp va fi
`O(N * logN)`, iar cea de spatiu `O(N)`.
