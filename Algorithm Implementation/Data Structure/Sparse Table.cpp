#define LOG 18
#define MAX 100010

int n, q, lg[MAX], ar[MAX], dp[LOG][MAX];

int query(int i, int j) {
    int k = lg[j-i];
    int x = dp[k][i], y = dp[k][j-(1<<k)+1];
    return min(x, y);
}

void build() {
    int i, l, d, len;
    for(i=2, lg[0]=lg[1]=0; i<MAX; i++) lg[i] = lg[i>>1]+1;

    for(l=0; (l<<1)<=n; l++) {
        len = 1<<l, d = len>>1;
        for(i=0; (i+len)<=n; i++) {
            if(!l) dp[l][i] = ar[i];
            else dp[l][i] = min(dp[l-1][i], dp[l-1][i+d]);
        }
    }
}
