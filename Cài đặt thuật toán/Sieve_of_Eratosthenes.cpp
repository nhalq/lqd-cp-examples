/*   /\_/\     notPrime[i] == true  => i không phải số nguyên tố
    (= ._.)    notPrime[i] == false => i là số nguyên tố
    / >?  \>$
*/
void Sieve_of_Eratosthenes(int n) {
   vector<bool> notPrime(n+1);
   notPrime[0] = notPrime[1] = true;
   for (int i = 2, maxi = sqrt(n); i <= maxi; ++i)
   if (!notPrime[i]) {
      for (int j = i*i; j <= n; j += i)
         notPrime[j] = true;
   }
}
