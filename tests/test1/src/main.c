#include <stdio.h>
#include <stdlib.h>
 
void hello(int * a,int * b,int * c, int s);

#define MEM_SIZE (10)

int main(){   
    int a[MEM_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[MEM_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int r[MEM_SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    hello(a, b, r, MEM_SIZE);

    printf("\n\n and the results are:\n");
    for(int i=0; i < MEM_SIZE; i++)
        printf("r[%d] = %d\n", i, r[i]);

     
    return 0;
}

void hello(int * a,int * b,int * c, int s){
    for(int i=0; i < s; i++)
        c[i] = a[i]*b[i]+1;
}