#include<stdio.h>
#include<math.h>
typedef float newvar[100][100];

float power(float x,float y){

}

void main (){
    int i,j,k,n,l;
    int xsize, tsize;
    newvar a;
    float timestep, xstep;
    float s;
    float x[50], time[50];
    float pi = 3.141592653589793238;
    float e = 2.718281828459045;

    printf("Enter the size of the grid in x direction - \n");
    scanf("%d",&xsize);

    printf("Enter the size of the grid in t direction - \n");
    scanf("%d",&tsize);
    
    //enter x values 

    printf("Enter the value of xmin \n");
    scanf("%f",&x[0]);

    printf("Enter the value of xmax \n");
    scanf("%f",&x[xsize-1]);

    xstep = (x[xsize-1]-x[0])/(xsize -1);

    for(i=1;i<xsize-1;i++){
        x[i]=xstep+x[i-1];
    }

    //enter t values 

    printf("Enter the value of tmin \n");
    scanf("%f",&time[0]);

    printf("Enter the value of tmax \n");
    scanf("%f",&time[xsize-1]);

    timestep = (time[tsize-1]-time[0])/(tsize -1);

    for(i=1;i<tsize-1;i++){
        time[i]=timestep+time[i-1];
    }

    //initial conditions - 
    for(i=0;i<xsize;i++){
        a[0][i] = (1/sqrt(2*pi*time[0])) * (pow(e,-x[i]*x[i]/(2*time[0])));
    }
    
    s = timestep / (xstep * xstep);

    printf("s = %f \n",s);

    //boundary conditions for the borders - 

    for(i=1;i<tsize-1;i++){
        a[i][0] = 0;
    }

    for(i=1;i<tsize-1;i++){
        a[i][xsize-1] = 0;
    }

    //printing x values
    for(i=0;i<xsize;i++){
        printf("%f ",x[i]);
    }
    printf("\n");

    //printing a0 values
    for(i=0;i<xsize;i++){
        printf("%.3f ",a[0][i]);
    }
    printf("\n");

// solving in time step 

        for(i=1;i<tsize;i++){
            for(j=1;j<xsize-1;j++){
                a[i][j] = 0.5*s*(a[i-1][j+1] - 2 * a[i-1][j] + a[i-1][j+1]) + a[i-1][j] ;
            }
        }
   
// printing final matrix

    printf("After iterations the matrix is -\n");
    for(i=0;i<tsize;i++){
        for(j=0;j<xsize;j++){
            printf("%.10f ",a[i][j]);
        }
        printf("\n\n");
    }
}