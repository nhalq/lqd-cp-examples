/**
 * Sieve of Eratosthenes
 * Author  : camnguyenmeow
 * Modified: nhalq
 * Date    : Apr 21, 2022
 *
 *   /\_/\
 *  (= ._.)
 *  / >?  \>$
 */

void sieve(int n) {
	vector<bool> is_prime(n + 1, true);

	is_prime[0] = false;
	is_prime[1] = false;

	for (int u = 2, upper = sqrt(n); u <= upper; ++u) {
		if (is_prime[u]) {
			for (int v = u * u; v <= n; v += u) {
				is_prime[v] = false;
			}
		}
	}
}
