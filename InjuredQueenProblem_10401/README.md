# [Injured Queen Problem](https://vjudge.net/problem/UVA-10401)

Easy / Medium problem. 

This is solved by dp programming.

Consider dp[i][j] = # of ways to arrange the queens on the table, given that a queen is set on (i, j)
We consider that the values from column 0 -> i - 1 are precomputed.

Let boardConfig be the configuration of the board that was given as input. The formula is quite easy to see:
```
  if '?' == boardConfig[j] 
  then  {
    we can put the queen wherever we want on column j
    If we put a queen on cell (i, j) we cannot have any queen on cells (i - 1, j - 1), (i - 1, j), (i - 1, j + 1)
    
    for all j from 0 -> N
      dp[i][j] = sum of all elements from dp[i - 1][0] -> dp[i - 1][j - 2] and all elements from dp[i - 1][j + 2] -> dp[i - 1][N - 1]
  }
  else  {
    let idx = be row where we have to to put the queen, as given by boardConfig[j]
    
     we cannot put the queen wherever we want. We can only put it on column j, row idx.
     This means that from column i - 1 we cannot use cells (i - 1, idx - 1), (i - 1, idx), (i - 1, idx + 1)
    
     dp[i][all j] = 0
     dp[i][idx] = sum of all elements from dp[i - 1][0] -> dp[i - 1][idx - 2] and all elements from dp[i - 1][idx + 2] -> dp[i - 1][N - 1]  
  }
  ```
  
