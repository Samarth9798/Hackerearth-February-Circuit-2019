    #include<bits/stdc++.h> 
    using namespace std;
    typedef long long int ll;
    int main()
    {
        int t;
        cin >> t;
        
        ll a[1001][1001]; memset(a,0,sizeof(a)); 
        ll cc[1001]; memset(cc,0,sizeof(cc));
        
        ll seven[1001][1001] = {  {0,0,0,0,0,0,0,0},
                            {0,1,1,2,3,3,4,4},
                            {0,1,2,2,3,5,4,6},
                            {0,8,8,7,5,5,6,6},
                            {0,11,8,7,7,9,9,10},
                            {0,11,11,12,12,9,10,10},
                            {0,13,13,14,12,15,15,16},
                            {0,13,0,14,14,15,16,16}
                        };
        
        
        memcpy(a,seven,sizeof(a));
        cc[7] = 16; 
        ll c = 17;
        int i,j,k;
        for(k = 8; k < 1000; k+=2){
            i = 1;
            j = k;
            while(i <= k){
                a[i][j] = a[i][j+1] = a[i+1][j] = c;
                c++;
                i+=2;
            }
            a[i][j] = a[i][j+1] = a[i-1][j+1] = c;
            c++;
            
            i = k;
            j = 3;
            a[i][1] = a[i+1][1] = a[i+1][2] = c;
            c++;
            while(j <= k){
                a[i][j-1] = a[i][j] = a[i+1][j] = c;
                c++;
                j+=2;
            }
            
            cc[k+1] = c-1;
        }
        
        while(t--){
            int n;
            cin >> n;
            
            if(n == 1 or n == 3 or n == 5){
                cout << "-1" << endl;
            }
            else if(n%2 == 0){
                
                ll aa[n+1][n+1]; memset(aa,0,sizeof(aa));
                
                c = 1;
                
                for(i = 1; i <= n; i+=2){
                    for(j = 1; j <= n; j+=2){
                        aa[i][j] = aa[i][j + 1] = aa[i+1][j+1] = c;
                        c++;
                    }
                }
                
                cout << c-1 << endl;
                for(i = 1; i <= n; i++){
                    for(j = 1; j <= n; j++)
                        cout << aa[i][j] << ' ';
                    cout << endl;
                }
            }
            else{
                
                cout << cc[n] << endl;
                for(i = 1; i <= n; i++){
                    for(j = 1; j <= n; j++)
                        cout << a[i][j] << ' ';
                    cout << endl;
                }
            }
        }
    }
