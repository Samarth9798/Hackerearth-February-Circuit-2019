    n,m = map(int,input().split())
     
    a = [0]*(m+1)
     
    while n:
        p,b = map(int,input().split())
        
        if a[b] < p:
            a[b] = p
        n-=1
        
    ans = 0
     
    for i in range(0,m+1):
        ans = ans + a[i]
        
    print(ans)
