    import java.util.*;
    import java.io.*;
     
    class TestClass {
        public static void main(String args[] ) throws Exception {
            
            Scanner in = new Scanner(System.in);
            
            int n = in.nextInt();
            
            int m = in.nextInt();
            
            int a[] = new int[m+1];
            
            while(n > 0)
            {
                int p = in.nextInt();
                int b = in.nextInt();
                
                if(a[b] < p)    
                    a[b] = p;
                
                n--;
            }
            
            int ans = 0;
            
            for(int i = 0; i < a.length; i++)
                ans = ans + a[i];
                
            System.out.print(ans);
        }
    }
