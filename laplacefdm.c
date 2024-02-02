#include<stdio.h>
#include<math.h>
typedef float newvar[100][100];

void entrow(int i,int size,newvar u)
{
    int j;
    printf("\n Enter the value of new %d th row\n", i);
    for(j=0;j<size;j++){
        scanf("%f",&u[i][j]);
    }
}

void entcol(int j,int size,newvar u)
{
    int i;
    printf("Enter the value the of new %d th column\n",j);
    for(i=1;i<size-1;i++){
        scanf("%f",&u[i][j]);
    }
}

void oput(newvar u, int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++){
        printf("%f ",u[i][j]);
    }
    printf("\n");
    }
    printf("\n");
}

void main (){
    int i,j,k,n,l;
    int size;
    newvar a;
    int iter;

    printf("Enter the size of the grid - \n");
    scanf("%d",&size);
    
    //initialize the matrix grid

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            a[i][j] = 0;
        }
    }

    //enter boundary value conditions 

    entrow(0,size,a);
    entrow(size-1,size,a);
    entcol(0,size,a);
    entcol(size-1,size,a);
    oput(a,size);

// u[i][j] = (u[i-1][j]+u[i+1][j]+u[i][j+1]+u[i][j-1])/4 for laplace equation

    printf("No of iterations -\n");
    scanf("%d",&iter);

// gauss sidel method to solve 

    for(k=0;k<iter;k++){
        for(i=1;i< size -1;i++){
            for(j=1;j<size-1;j++){
                a[i][j] = (a[i-1][j]+a[i+1][j]+a[i][j+1]+a[i][j-1])/4;
            }
        }
    }

    printf("After iterations the matrix is -\n");
    oput(a,size);
}
