#include<stdio.h>
#include<stdbool.h>

void main(){
    int v;
    printf("enter no of vertices\t");
    scanf("%d",&v);
    int G[v][v];
    printf("enter adjacency matrix\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            scanf("%d",&G[i][j]);
    }
    printf("EDGE  -  WEIGHT\n");
    int no_edges=0;
    int selected[v];
    memset(selected,false,sizeof(selected));
    selected[0]="true";
    int row,col;
    while(no_edges < v-1){
        int min=99999;
        row=0;col=0;
        for(int i=0;i<v;i++){
            if(selected[i]){
            for(int j=0;j<v;j++){
                if(!selected[j] && G[i][j]){
                    if(min> G[i][j]){
                        min=G[i][j];
                        row=i;
                        col=j;
                    }
                }
            }
        }
    }
    printf("%d - %d : %d\n", row, col, G[row][col]);
    selected[col] = true;
    no_edges++;
    }
}
