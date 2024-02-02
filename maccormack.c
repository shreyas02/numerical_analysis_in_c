#include<stdio.h>
typedef float newvar[5][5][5];

void main(){
    newvar u,v,rho;
    newvar u1,v1,rho1;
    int xgridsize,ygridsize; 
    float dx,dy,dt;
    int timesteps;
    int i,j,k,n;
    float a,b,c;
    newvar drho,dv,du;
    newvar d1rho,d1v,d1u;

    //enter speed of sound

    printf("enter speed of sound\n");
    scanf("%f",&c);

    //accept values of size from user 

    printf("Enter the size of the grid in x direction\n");
    scanf("%d",&xgridsize);

    printf("Enter the size of the grid in y direction\n");
    scanf("%d",&ygridsize);

    //Set values of dx, dy and dt

    printf("Enter dx\n");
    scanf("%f",&dx);

    printf("Enter dy\n");
    scanf("%f",&dy);

    printf("Enter dt\n");
    scanf("%f",&dt);

    printf("Enter number of time steps\n");
    scanf("%d",&timesteps);

    //set initial conditions for u, v and rho   // for pressure using relation p = rho * c^2

    printf("Enter values for U \n");
    for(j=0;j<ygridsize;j++){
        for(i=0;i<xgridsize;i++){
            scanf("%f", &u[0][j][i]);
        }
    }

    printf("Enter values for V \n");
    for(j=0;j<ygridsize;j++){
        for(i=0;i<xgridsize;i++){
            scanf("%f", &v[0][j][i]);
        }
    }

    printf("Enter values for rho \n");
    for(j=0;j<ygridsize;j++){
        for(i=0;i<xgridsize;i++){
            scanf("%f", &rho[0][j][i]);
        }
    }

    //set boundary conditions

    for(k=1;k<timesteps;k++){
    printf("Enter  boundary values for U  for timestep %d \n",k+1);
        for(j=0;j<ygridsize;j++){
            for(i=0;i<xgridsize;i++){
                if(j==ygridsize-1 || i==xgridsize-1 || i==0 || j==0){
                    printf("for x = %d and y = %d \n",i,j);
                        scanf("%f", &u[k][j][i]);
                }
            }
        }
    }

    for(k=1;k<timesteps;k++){
    printf("Enter  boundary values for v  for timestep %d \n",k+1);
        for(j=0;j<ygridsize;j++){
            for(i=0;i<xgridsize;i++){
                if(j==ygridsize-1 || i==xgridsize-1 || i==0 || j==0){
                    printf("for x = %d and y = %d \n",i,j);
                        scanf("%f", &v[k][j][i]);
                }
            }
        }
    }

    for(k=1;k<timesteps;k++){
    printf("Enter  boundary values for rho  for timestep %d \n",k+1);
        for(j=0;j<ygridsize;j++){
            for(i=0;i<xgridsize;i++){
                if(j==ygridsize-1 || i==xgridsize-1 || i==0 || j==0){
                    printf("for x = %d and y = %d \n",i,j);
                        scanf("%f", &rho[k][j][i]);
                }
            }
        }
    }

    
    for(k=0;k<timesteps-1;k++){
        for(j=1;j<ygridsize-1;j++){
            for(i=1;i<xgridsize-1;i++){

                // predictor step

                drho[k][j][i] = -(rho[k][j][i] * ((u[k][j][i+1] - u[k][j][i])/dx)  +  u[k][j][i] * ((rho[k][j][i+1] - rho[k][j][i])/dx) + rho[k][j][i] * ((v[k][j+1][i] - v[k][j][i])/dy) + v[k][j][i] * ((rho[k][j+1][i] - rho[k][j][i])/dy));

                du[k][j][i] =   -(u[k][j][i] * ((u[k][j][i+1] - u[k][j][i])/dx) + v[k][j][i] * ((u[k][j+1][i] - u[k][j][i])/dy) + (1/rho[k][j][i]) * c *c * ((rho[k][j][i+1] - rho[k][j][i])/dx));

                dv[k][j][i] =   -(u[k][j][i] * ((v[k][j][i+1] - v[k][j][i])/dx) + v[k][j][i] * ((v[k][j+1][i] - v[k][j][i])/dy) + (1/rho[k][j][i]) * c *c * ((rho[k][j+1][i] - rho[k][j][i])/dy));

                rho1[k+1][j][i] = rho[k][j][i] + drho[k][j][i] * dt;
                u1[k+1][j][i] = u[k][j][i] + du[k][j][i] * dt;
                v1[k+1][j][i] = v[k][j][i] + dv[k][j][i] * dt;

                

            }
        }
    }

    for(k=1;k<timesteps;k++){
        for(j=1;j<ygridsize-1;j++){
            for(i=1;i<xgridsize-1;i++){

                // corrector step

                d1rho[k][j][i] = -(rho1[k][j][i] * ((u1[k][j][i] - u1[k][j][i-1])/dx)  +  u1[k][j][i] * ((rho1[k][j][i] - rho1[k][j][i-1])/dx) + rho1[k][j][i] * ((v1[k][j][i] - v1[k][j-1][i])/dy) + v1[k][j][i] * ((rho1[k][j][i] - rho1[k][j-1][i])/dy));

                d1u[k][j][i] =   -(u1[k][j][i] * ((u1[k][j][i] - u1[k][j][i-1])/dx) + v1[k][j][i] * ((u1[k][j][i] - u1[k][j-1][i])/dy) + (1/rho1[k][j][i]) * c *c * ((rho1[k][j][i] - rho1[k][j][i-1])/dx));

                d1v[k][j][i] =   -(u1[k][j][i] * ((v1[k][j][i] - v1[k][j][i-1])/dx) + v1[k][j][i] * ((v1[k][j][i] - v1[k][j-1][i])/dy) + (1/rho1[k][j][i]) * c *c * ((rho1[k][j][i] - rho1[k][j-1][i])/dy));

                rho[k+1][j][i] = rho[k][j][i] + ((drho[k-1][j][i] + d1rho[k][j][i])/2) * dt;
                u[k+1][j][i] = u[k][j][i] + ((du[k-1][j][i] + d1u[k][j][i])/2)  * dt;
                v[k+1][j][i] = v[k][j][i] + ((dv[k-1][j][i] + d1v[k][j][i])/2) * dt;
            }
        }
    }

}