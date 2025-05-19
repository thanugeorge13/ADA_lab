#include <stdio.h>
#include <stdbool.h>

bool place(int x[10], int k){
    int i;
    for(i=1;i<k;i++){
        if((x[i]==x[k])||(i-x[i]==k-x[k])||(i+x[i]==k+x[k]))
            return false;
    }
    return true;
}

void printSolution(int x[10], int n){
    int i;
    for(i=1;i<=n;i++)
        printf("%d ", x[i]);
    printf("\n");
}

void nQueens(int n){
    int x[10];
    int count=0,k=1;
    printf("Solution found\n");
    while(k!=0){
        x[k]=x[k]+1;
        while(x[k]<=n && !place(x,k)){
            x[k]=x[k]+1;
        }
        if(x[k]<=n){
            if(k==n){
                printSolution(x, n);
                count++;
            }else{
                k++;
                x[k]=0;
            }
        }else
            k--;
        }
    printf("Total solutions: %d\n", count);
}

int main(){
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    nQueens(n);
    return 0;
}

