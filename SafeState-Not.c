#include <stdio.h> 
int main() 
{ 
    // P0, P1, P2, P3, P4 ... are the Process names here 
  
    int n, m, i, j, k; 
    printf("Enter Number of Processes :");
    scanf("%d",&n);
    printf("Enter Number of Resources :"); 
    scanf("%d",&m);
     
    int alloc[5][4]; 
    int o=0;
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
                 printf("Enter P%d R%d for Allocation Matrix :",i,j+1);
                 scanf("%d",&o);
                 alloc[i][j]=o;
     }
     }
    int max[5][4];  
    for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
                 printf("Enter P%d R%d for MAX Matrix :",i,j+1);
                 scanf("%d",&o);
                 max[i][j]=o;
     }
     }    
 
    int avail[4];  
    for(int i=0;i<m;i++){
       printf("Enter R%d Available Resources :",i+1);
       scanf("%d",&o);
       avail[i]=o;
}
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    } 
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]) 
                        flag = 1; 
                    break; 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  
    printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
  
    return (0); 
   
} 
