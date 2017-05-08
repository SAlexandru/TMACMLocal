# [Dynamic Frog](https://vjudge.net/problem/UVA-11157)

Medium / Hard

The problem is solved by a greedy strategy. For the rest of the explication I'll consider that in the set of rocks we have one
that represent the left bank (i.e B-0) and one that represent the right bank (i.e B-D, for a value of D)

One observation that we can make is that if we eliminate the small rocks, the problem is easly solved (simply take the largest distance between any two rocks). Another important observation is that we can divde the problem into subproblems. A subproblem is: Given to consecutive big rocks and small rocks between them, find the smallest value of the longest jump. 

Lets solve the subproblems ! Because of the small rocks, we have to create two, partialy separated, paths, one to the right bank / stone and the other from the right bank / stone.
Lets say that we are between two big rock A and B and have some small rocks: s1 < s2 < s3 < s4. 
We can choose for the forward pass all the even numbered small rocks and for the backwards pass the remaining other.
I.e for the forward pass we would have rocks: A -> s2 -> s4 -> B and for the backwards pass we would have B -> s3 -> s1 -> A.
The maximum distance is given by: max (s2 - A, s4 - s2, B - s3, s3 - s1). We have ommited s1 - A and B - s4 as they will not
contribute to the answer as s1 - A < s2 - A 

Intuitively this is correct because if we jump on from A to s1, s1 cannot be used when we come back, so the maximum jump would be given by the distance from s2 (or other rock different from s1 ) to A.  
