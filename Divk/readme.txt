Problem: DivK
Difficulty: 1
Solving Method: Dynamic Programming
Related Problem: Number of Subarrays divisible by K
                 http://stackoverflow.com/questions/16605991/number-of-subarrays-divisible-by-k
                 (insight: for subarrays of all lengths we are interested in all combinations of starting and ending terms that have the same remainder => C(n,2) = n(n-1)/2)

Hints:
    Create partial Sum vector. S[i] containing sum of elements 1 to i;
    Insight: Sum of seq i-A+1 to i is S[i] - S[i-A]
    
    Since we are interested only in subseqences in which the sum is divisible by K, we %K the whole S array.
    Insight: if S[i-A] % K == S[i] % K then S[i]-S[i-A] divisible by K => seq from i-A+1 to i is the one we want.

    Remains to filter out sequences of undesired length. We create a frequency array containing the remainders of the sequences in the interval.
    For each i we update the frequency array so it includes the i-A element and excludes the i-B-1.
    If the remainder of S[i] has value x(=freq[S[i]]) in the frequency array, then there are x subarrays ending in num[i] divisible by K!
    
