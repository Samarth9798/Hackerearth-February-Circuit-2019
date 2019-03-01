#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
typedef long long int ll;
int main()
{
    fast
    int n;
    scanf("%d",&n);
 
    int a[n+1][501];
    memset(a, 0,sizeof(a));
    
    set<int> s;
    
    int p[501];
    p[1] = 1;
    p[2] = 2;
    int id = 3;
    for(int i = 3; i <= 500; i++)
    {
        int f = 0;
        for(int j = 2; j <= sqrt(i); j++)
        {
            if(i%j == 0)
            {
                f = 1;
                break;
            }
        }
        if(f == 0)
        {
            p[id] = i;
            id++;
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d",&k);
        
        while(k--)
        {
            int x;
            scanf("%d",&x);
            
            int j = 2;
            while(x > 1)
            {
                if(x%p[j] == 0)
                {
                    x = x/p[j];
                    a[i][p[j]]++; 
                    s.insert(p[j]);
                }
                else 
                    j++;
            }
        }
    }
 
    map<vector<int>,ll> m2;
    vector<int> ss(s.size());
    ss.clear();
    set<int>::iterator it;
    int i,j,temp;
    
    for(i = 1; i <= n; i++)
    {
        for(it = s.begin(); it != s.begin(); it++)
        {
            temp = a[i][*it];
            temp = temp - (temp/3)*3;
            a[i][*it] = temp;
            if(a[i][*it] == 0)
                a[i][*it] = 3;
        }
    }
    
    ll ans = 0,c = 0;
    int f = 0;
    for(i = n-2; i > 1; i--)
    {
        if(f == 0)
            c  = c + i - 1;
        if(c > 275000 and ans == 0)
            break;
        else if(c > 275000 and ans > 0 and f == 0) c = 0, f = 1;
        
        for( j = i+2; j <= n; j++){
            for(it = s.begin(); it != s.end(); it++){
                temp = (a[i+1][*it] + a[j][*it])%3;
                temp = (3 - temp)%3;
                ss.push_back(temp); 
            }
            m2[ss]++;
            ss.clear();
        }
        
        for(j = 1; j < i; j++){
            for(it = s.begin(); it != s.end(); it++){
                temp = (a[i][*it] + a[j][*it])%3;
                ss.push_back(temp);
            }
            temp = m2[ss];
            ans = ans + temp; 
            ss.clear();
        }
        
    }
    
    printf("%lld",ans);
}
