#include<stdio.h>
#define MAX 50 

void main(){
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int arows, acolumns, brows, bcolumns;
    int i,j,k;

    printf("Enter number of rows and columns of matrix a -\n");
    scanf("%d %d", &arows, &acolumns);

    printf ("Input Matrix A \n");

    for(i=0; i<arows; i++){
        for(j=0; j<acolumns; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("Enter number of rows and columns of matrix b -\n");
    scanf("%d %d", &brows, &bcolumns);
    printf ("Input Matrix B \n");

    for(i=0; i<brows; i++){
        for(j=0; j<bcolumns; j++){
            scanf("%d",&b[i][j]);
        }
    }

    // print matrix A
    for(i=0; i<arows; i++){
        for(j=0; j<acolumns;j++){
            printf("%d",a[i][j]);
        }
    printf("\n");
    }

    // print matrix B
    for(i=0; i<brows; i++){
        for(j=0; j<bcolumns;j++){
            printf("%d",b[i][j]);
        }
    printf("\n");
    }

    //check condition for matrix multiplication
    if(acolumns != brows){
        printf("Multiplication not possible :(");
    }
    else{
        // multiply code
    int sum = 0;
    for(i=0;i<arows;i++){
        for(j=0;j<bcolumns;j++){ 
            for (k=0; k<brows; k++){
                sum = sum + a[i][k] * b[k][j]; 
            } 
            c[i][j] = sum;
            sum=0;
        }
    }
    // print matrix c
    printf("Mtrix C is \n");
    for(i=0; i<arows; i++){
        for(j=0; j<bcolumns;j++){
            printf("%d ",c[i][j]);
        }
    printf("\n");
    }

    } 
}