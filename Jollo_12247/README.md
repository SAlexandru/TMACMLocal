# [Jollo 12247](https://vjudge.net/problem/UVA-12247)

This problem is easy. 
It only take a bit of logic. 

Lets suppouse we store the cards of the prince in the **prince** array and the cards of the princess in the **princess** array.
Also, I'll consider that the arrays are storted in ascending order.

The logic is based on how many cards of the prince are bigger than the princess's cards.
 
`if prince[0] > princess[2]` 
  In this case, all the cards from the prince are bigger than all the princess's cards. Basically we don't really care what
  card the prince will receive, he will win no matter what.
  So, pick the first card from 1 to 52 that isn't currently used. 
  
`if prince[0] > princess[1]`
  In this case, the princess has a bigger card than all of the prince's cards! We cannot choose just any card because if
 we choose a card with a value < princess[1] we have a serious chance of loosing. 
   So, we should pick the first card from princess[1] + 1 to 52 that isn't currently used.
   
`if prince[1] > princess[2]`
 In this case the prince has a card which is smaller than all of the princess's cards! Our only solution is to find a card
 that is bigger than princess[2], otherwise we have a serious chance of loosing.

In any other case the prince will loose because all of his cards are smaller than all of the princess's card

If we cannot pick a card than there is no solution.
