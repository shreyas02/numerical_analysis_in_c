#include<stdio.h>
#include<stdlib.h>
#define MAX 50  

void main(){
    float a[MAX][MAX];
    float x[MAX]; 
    int i,j,k,n,l;
    int size;
    float ratio;

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

    //convertion to diagonal matrix 

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(j!=i){
                ratio =a[j][i]/a[i][i];
                for(k=0;k<size + 1;k++){
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }

    //print matrix a

    for(i=0;i<size;i++){
        for(j=0;j<size +1 ;j++){
          printf("%f ",a[i][j]);   
        }
        printf("\n");
    }

    //compute x 

    for(i=0;i<size;i++){
        x[i]= a[i][size]/a[i][i];
    }

    //print x result

    for(i=0;i<size;i++){
        printf("%f ",x[i]);
    }
    printf("\n");

} 
