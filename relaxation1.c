#include<stdio.h>
#include<math.h>
typedef float newvar[100][100];

void main (){
    int i,j,k,n,l;
    int xgridsize, ygridsize;
    newvar si, oldsi;
    float temp,rfactor, dx,dy;

    printf("enter number of iterations \n");
    scanf("%d",&n);

    printf("enter xgridsize \n");
    scanf("%d",&xgridsize);

    printf("enter xgridsize \n");
    scanf("%d",&xgridsize);

    printf("enter ygridsize \n");
    scanf("%d",&ygridsize);

    printf("enter relaxation factor\n");
    scanf("%f",&rfactor);

    printf("Enter dx\n");
    scanf("%f",&dx);

    printf("Enter dy\n");
    scanf("%f",&dy);

    // entering boundary conditions
    for(j=0;j<ygridsize;j++){
        for(i=0;i<xgridsize;i++){
            if(j==ygridsize-1 || i==xgridsize-1 || i==0 || j==0){
                    printf("for x = %d and y = %d \n",i,j);
                        scanf("%f", &si[j][i]);
                }
        }
    }

    for(k=0;k<n;k++){
        for(j=1;j<ygridsize-1;j++){
            for(i=1;i<xgridsize-1;i++){
                temp = ((dx*dx*dy*dy)/(2*(dx*dx+dy*dy))) * ( ((si[j][i-1]+si[j][i+1])/(dx*dx)) + ((si[j-1][i]+si[j+1][i])/(dy*dy)) );
                oldsi[j][i] = si[j][i];
                si[j][i] = si[j][i]  +  rfactor * (temp - si[j][i]);
            }
        }
    }

}