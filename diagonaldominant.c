//to check if a matrix is diagonalisable

#include<stdio.h>
#include<stdlib.h>
#define MAX 50 

//diagonally dominant matrix
void main(){
     int a[MAX][MAX];
     int a1[MAX][MAX];
     int b[MAX];
     int arows, acolumns;
     int i,j,k;

    //Matrix A input
    printf("Enter number of rows and columns of matrix a -\n");
    scanf("%d", &arows);

    acolumns = arows;

    printf ("Input Matrix A \n");

    for(i=0; i<arows; i++){
        for(j=0; j<acolumns; j++){
            scanf("%d",&a[i][j]);
        }
    }

//element checking
    int sum = 0;
    for(i=0; i<arows; i++){
        for(j=0; j<acolumns; j++){
                for(k=0; k<acolumns; k++){
                    if(k!=j){
                        sum = sum + abs(a[i][k]);
                    }
                }
            //use the sum here
            if(a[i][j]>=sum){
                printf("sum = %d and a[i][j] = %d  i = %d \n",sum,a[i][j],i);
                b[i]= j +1;
            }
            //sum is reinnitialised 
            sum =0;
            }
        }
    int test = 0;
    for(i=1; i<=arows; i++){
        for(j=0; j<arows; j++){
            if(b[j]==i){
                test = test +1;
            }
    }
    }
    
    for(i=0;i<arows;i++){
        printf("b is %d \n",b[i]);
    }

    printf("Test is %d \n",test);
int n ;
    if(test == arows){
        printf("Matrix can be diagonalisable \n");
        for(i=0;i<arows;i++){
            n=b[i]-1;
            for(j=0;j<arows;j++){
                a1[i][j]=a[n][j];
            }
        }
    //print diagonalised matrix  
    for(i=0;i<arows;i++){
        for(j=0;j<arows;j++){
          printf("%d ",a1[i][j]);   
        }
        printf("\n");
    }
    }
    else{
        printf("Sorry not possible \n");
    }
}

