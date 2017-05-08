# [War](https://vjudge.net/problem/UVA-10158)

Medium. 

This problem is solved by using union-find in order to keep track of who is an enemy / friend. 
It is easy to see how we can use the union-find data structure in order to keep track of our **set** of friends. Unfortunatelly
this cannot be said about our **set** of enemies. 

The trick here is to remove the need of keeping track of enemies :)
Assume that every country in the war has another twin with a unique id and that the twins are mortal enemies. 
When we mark two countries, x and y, as friends, then their mortal enemies, enemyId(x) and enemyId(y), are friends also. This 
holds according to the properties mentioned in the text.
  * `Because the enemy of my friends are my enemies also my enemies` x ~ y and y * enemyId(y) => x * enemyId(y) and y * enemyId(x)
  * `A common enemy makes two people friends` x * enemyId(x) and x * enemyId(y) => enemyId(x) ~ enemyId(y)
  
Of course we have to pay attention not to unite x with it's mortal twin and vice-versa.  

When we mark two countries as foes, what we actually have to do is to mark one of them with the enemyId of the other
and vice-versa. Again, this holds due to the properties mentioned in the text. 
Also, we cannot mark two countries as foes, if they were previously marked as friends.

