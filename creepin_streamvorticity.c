#include<stdio.h>
typedef float newvar[100][100];
//viscous flow of low Re number flow

void main(){
    newvar si;
    int size; // using a square grid 
    int i,j,k,n;
    float a,b,c;

    //accept values of size from user 
    printf("Enter the size of the squre grid \n");
    scanf("%d",&size);

    // enter number of iterations 

    printf("Enter number of iterations \n");
    scanf("%d",&n);

    //enter boundary conditions

    printf("Enter x values of si when y = 0\n");
    for(i = 0;i<size;i++){
        scanf("%f",&si[0][i]);
    }

    printf("Enter x values of si when y = %d \n",size -1);
    for(i = 0;i<size;i++){
        scanf("%f",&si[size-1][i]);
    }

    printf("Enter y values of si when x = %d \n",0);
    for(i = 1;i<size-1;i++){
        scanf("%f",&si[i][0]);
    }

    printf("Enter y values of si when x = %d \n",size - 1);
    for(i = 1;i<size-1;i++){
        scanf("%f",&si[i][size - 1]);
    }

    // display the matrix 

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%f\t",si[i][j]);
        }
        printf("\n");
    }

int test = 0 ;
for(k=0; k < n; k++){
    for(i=1;i<size-1;i++){
        for(j=1;j<size-1;j++){
            a = si[j+1][i] + si[j-1][i] + si[j][i-1] ; 
            b = si[j+1][i+1] + si[j-1][i+1] + si[j+1][i-1] + si[j-1][i-1] ;

            // dsi/dn = 0 so setting points not on matrix (imaginary)

            if(i+2 >= size && j+2 >=size && test == 0){
                c = si[j][i] * si[j-2][i] + si[j][i] + si[j][i-2] ;
                test = 1;
            }
            if(i+2 >= size && j-2 < 0 && test == 0){
                c = si[j+2][i] * si[j][i] + si[j][i] + si[j][i-2] ;
                test = 1;
            }
            if(j+2 >= size && i-2 < 0 && test == 0){
                c = si[j][i] * si[j-2][i] + si[j][i+2] + si[j][i] ;
                test = 1;
            }
            if(j-2 < 0 && i-2 < 0 && test == 0){
                c = si[j+2][i] * si[j][i] + si[j][i+2] + si[j][i] ; 
                test = 1;
            }
            if(j-2 < 0 && test == 0){
                c = si[j+2][i] * si[j][i] + si[j][i+2] + si[j][i-2] ; 
                test = 1;
            }
            if(j+2 >= size && test == 0){
                c = si[j][i] * si[j-2][i] + si[j][i+2] + si[j][i-2] ; 
                test = 1;
            }
            if(i-2 < 0 && test == 0){
                c = si[j+2][i] * si[j-2][i] + si[j][i+2] + si[j][i] ; 
                test = 1;
            }
            if(i+2 >= size && test == 0){
                c = si[j+2][i] * si[j-2][i] + si[j][i] + si[j][i-2] ; 
                test = 1;
            }
            if(test == 0){
                c = si[j+2][i] * si[j-2][i] + si[j][i+2] + si[j][i-2] ; 
                test = 1;
            }
            si[i][j] == (8*a - 2*b + c) / 20;
        }
        test = 0 ;
    }
}
    // display the matrix 

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%f\t",si[i][j]);
        }
        printf("\n");
    }

}