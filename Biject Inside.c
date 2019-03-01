    #include<stdio.h>
    typedef long long int ll;
    ll a[2][2],b[2][2];
    const ll mod = 1e9+7;
    void multiply1(){
        ll x = ((a[0][0]*a[0][0])%mod + (a[0][1]*a[1][0])%mod)%mod;
        ll y = ((a[0][0]*a[0][1])%mod + (a[0][1]*a[1][1])%mod)%mod;
        ll z = ((a[1][0]*a[0][0])%mod + (a[1][1]*a[1][0])%mod)%mod;
        ll w = ((a[1][0]*a[0][1])%mod + (a[1][1]*a[1][1])%mod)%mod;
        a[0][0] = x;
        a[0][1] = y;
        a[1][0] = z;
        a[1][1] = w;
    }
    void multiply2(){
        ll x = ((a[0][0]*b[0][0])%mod + (a[0][1]*b[1][0])%mod)%mod;
        ll y = ((a[0][0]*b[0][1])%mod + (a[0][1]*b[1][1])%mod)%mod;
        ll z = ((a[1][0]*b[0][0])%mod + (a[1][1]*b[1][0])%mod)%mod;
        ll w = ((a[1][0]*b[0][1])%mod + (a[1][1]*b[1][1])%mod)%mod;
        a[0][0] = x;
        a[0][1] = y;
        a[1][0] = z;
        a[1][1] = w;
    }
    void power(ll n){
        if(n == 1)
            return;
        power(n/2);
        multiply1();
        if(n%2 == 1)
            multiply2();
    }
    int main(){
        int t;
        ll n,y,z,p,fib,q,ans;
        scanf("%d",&t);
        while(t--){
            scanf("%lld",&n);
            if(n == 1)
                printf("500000004\n");
            else{
                y = 2;
                z = n;
                p = 1;
                while(z > 0){
                    if(z%2==1)
                        p = (p * y)%mod;
                    z = z/2;
                    y = (y * y)%mod;
                }
                a[0][0] = 1; a[0][1] = 1; a[1][0] = 1; a[1][1] = 0;
                b[0][0] = 1; b[0][1] = 1; b[1][0] = 1; b[1][1] = 0;
                power(n-1);
                fib = (a[0][0] + a[0][1])%mod;
                q = 1;
                y = p;
                z = mod - 2;
                while(z > 0){
                    if(z%2==1)
                        q = (q * y)%mod;
                    z = z/2;
                    y = (y * y)%mod;
                }
                ans = p - fib;
                if(ans < 0) 
                    ans = mod - (abs(ans)%mod);
                ans = (ans * q)%mod;
                printf("%lld\n",ans);
            }
        }
    }
