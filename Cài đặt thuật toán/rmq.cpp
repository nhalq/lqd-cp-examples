#define MASK(i) (1 << (i))
#define MAX 400400
#define LOG 19

int arr[MAX], n;
int f[MAX][LOG + 1];

void init(){
    for(int i = 1; i <= n; i++) f[i][0] = arr[i];
    for(int j = 1; j <= LOG; j++) for (int i = 1; i <= n - MASK(j) + 1; i++)
        f[i][j] = min(f[i][j - 1], f[i + MASK(j - 1)][j - 1]);
}

int getMin(int l, int r){
	int k = log2(r - l + 1);
	return min(f[l][k], f[r - MASK(k) + 1][k]);
}