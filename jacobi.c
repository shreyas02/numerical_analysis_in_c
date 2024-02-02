#include<stdio.h>
#include<stdlib.h>
#define MAX 50 

void main(){
    float a[MAX][MAX];
    float x[MAX];
    float x1[MAX];
    float c[MAX];
    int size;
    int i,j,k,n,l;
    int iter;

    printf("Enter the size of the matrix A - \n");
    scanf("%d",&size);

    printf("Input matrix A \n");

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%f",&a[i][j]);
        }
    }

    printf("Input matrix c \n");

    for(i=0;i<size;i++){
            scanf("%f",&c[i]);
    }

    printf("Input initial conditions \n");

    for(i=0;i<size;i++){
            scanf("%f",&x[i]);
    }
    
    printf("Number of Iterations \n");
    scanf("%d",&iter);

int c1,n1;

for(k=0;k<iter;k++){
    for(i=0;i<size;i++){
        n1=a[i][i];
        x1[i] = c[i];
        for(j=0;j<size;j++){
            if(i!=j){
                x1[i] = x1[i] - x[j]*a[i][j];   
            }
        }
        x1[i]=x1[i]/n1;
    }
    for(l=0;l<size;l++){
        x[l]=x1[l];
        x1[l]=0;    
        }
printf("The vector x will be - \n");
for(i=0;i<size;i++){
    printf("%f ",x[i]);
}
printf("\n");

}

}