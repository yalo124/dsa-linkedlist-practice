#include <stdio.h>

int main(){
    int A[3][3] = {8,2,5,
                    7,1,2,
                    4,3,6};
    //int *p;
    //p = &A[0][0];
    /*
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        for (int j = 0; j < sizeof(A) / sizeof(A[0]); j++)
        {
        printf("%d ", A[i][j]);
        }
        
    }
        */
    printf("%d", **A);

}