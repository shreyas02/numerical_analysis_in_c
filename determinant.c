#include<stdio.h>
#include<stdlib.h>
#define MAX 50  

void main(){
    float a[MAX][MAX];
    int i,j,k,n,l;
    int size;
    float ratio,det;

    printf("Enter no of equations in matrix A - \n");
    scanf("%d",&size);

    // matrix A input 

    printf("Input matrix A \n");

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%f",&a[i][j]);
        }
    }

    //print matrix a

    for(i=0;i<size;i++){
        for(j=0;j<size ;j++){
          printf("%f ",a[i][j]);   
        }
        printf("\n");
    }

    //convertion to upper triangular matrix 

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(j>i){
                ratio =a[j][i]/a[i][i];
                for(k=0;k<size;k++){
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }

    //print matrix a

    for(i=0;i<size;i++){
        for(j=0;j<size ;j++){
          printf("%f ",a[i][j]);   
        }
        printf("\n");
    }

    // determinant of a matrix 

    det = 0;
    for(i=0;i<size;i++){
        det = det = a[i][i];
    }

    printf("The determinant of the matrix is %f \n",det);
}