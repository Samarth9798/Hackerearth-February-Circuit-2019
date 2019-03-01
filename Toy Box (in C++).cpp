#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int a[m+1]; 
    memset(a,0,sizeof(a));
    while(n--){
        int p,b;
        cin >> p >> b;
        if(a[b] == 0)
            a[b] = p;
        else if(p > a[b])
            a[b] = p;
    }
    int ans = 0;
    for(int i = 0; i <= m; i++)
        ans = ans + a[i];
    cout << ans;
}
