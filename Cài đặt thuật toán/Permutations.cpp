// Cách 1: chuẩn bị O(n^2), truy vấn O(1), modulo bất kì
#define MAX   5050
int comb[MAX][MAX];

// chuẩn bị
for (int i = 0; i < MAX; i++) {
  comb[0][i] = 1;
	comb[i][0] = 0;
}
comb[0][0] = 1;

for (int i = 1; i < MAX; i++) for (int j = 1; j < MAX; j++) {
	if (i > j) comb[i][j] = 0;
	if (i == j) comb[i][j] = 1;
	if (i < j) {
		comb[i][j] = comb[i][j - 1] + comb[i - 1][j - 1];
		if (comb[i][j] >= MOD) comb[i][j] -= MOD;
  	}
}

// Cách 2: chuẩn bị O(n), truy vấn O(1), modulo nguyên tố lớn
#define MAX   1000100
int frac[MAX], finv[MAX];

// chuẩn bị
frac[0] = 1;
for (int i = 1; i < MAX; i++) frac[i] = 1LL * frac[i - 1] * i % MOD;
finv[MAX - 1] = pw(frac[MAX - 1], MOD - 2);
for (int i = MAX - 2; i >= 0; i--) finv[i] = 1LL * finv[i + 1] * (i + 1) % MOD;
int comb(int k, int n) {
	return k > n ? 0 : 1LL * frac[n] * finv[k] % MOD * finv[n - k] % MOD;
}

// Cách 3: chuẩn bị O(k), truy vấn O(k), modulo nguyên tố > k
// chuẩn bị: tính mảng finv[k] giống như trong cách 2
int comb(int k, long long n) {
	int res = finv[k];
	for (int i = 0; i < k; i++) res = 1LL * (n - i) % MOD * res % MOD;
	return res;
}

// Cách 4: chuẩn bị O(n), truy vấn O(n/ln(n)), modulo bất kì
#define MAX   1000100
bool notPrime[MAX];
vector<int> primes;

// sàng số nguyên tố
notPrime[0] = notPrime[1] = true;
for (int i = 2; 1LL * i * i < MAX; i++) if (!notPrime[i])
	for (int j = i * i; j < MAX; j += i) notPrime[j] = true;
for (int i = 2; i < MAX; i++) if (!notPrime[i]) primes.push_back(i);

int comb(int k, int n) {
	if (k > n) return 0;

	int res = 1;
	for (int p : primes) {
		if (p > n) break;
		int exp = 0; // tính số mũ của p
		for (long long tmp = p; tmp <= n; tmp *= p)
			exp += n / tmp - k / tmp - (n - k) / tmp;
		res = 1LL * res * pw(p, exp) % MOD;
  }

	return res;
}
