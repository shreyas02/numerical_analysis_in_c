#include<stdio.h>
#include<stdlib.h>
#define MAX 50  

void main(){
    float a[MAX][MAX];
    float x[MAX]; 
    int i,j,k,n,l;
    int size;
    float ratio,sum;

    printf("Enter no of equations in matrix A - \n");
    scanf("%d",&size);

    // matrix A input 

    printf("Input matrix A \n");

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%f",&a[i][j]);
        }
    }

    // matrix c input augmented in matrix A

    printf("Input matrix c \n");

     for(i=0;i<size;i++){
        scanf("%f",&a[i][size]);
    }

    //print matrix a

    for(i=0;i<size;i++){
        for(j=0;j<size +1 ;j++){
          printf("%f ",a[i][j]);   
        }
        printf("\n");
    }

    //convertion to upper triangular matrix 

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(j>i){
                ratio =a[j][i]/a[i][i];
                for(k=0;k<size + 1;k++){
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }

    //print matrix Upper triangular a

    for(i=0;i<size;i++){
        for(j=0;j<size +1 ;j++){
          printf("%f ",a[i][j]);   
        }
        printf("\n");
    }

    // last x vector value we already know so putting that in x[]

    x[size-1] = a[size-1][size]/a[size-1][size-1];

    //back substitution

    for(i=size-2;i>=0;i--){
        sum = 0;
        for(j=i+1; j<size ; j++){
            sum = sum + a[i][j]*x[j];
        }
        x[i]= (a[i][size] - sum)/a[i][i];
    }

    //Printing values of X 

    for(i=0;i<size;i++){
        printf("%f ",x[i]);
    }
    printf("\n");
}