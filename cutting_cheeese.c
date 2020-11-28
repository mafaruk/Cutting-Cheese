
#include<stdio.h>
#define PI 3.142857143
double slice(double R, double z, double h)
{
  	if((2*R)&&(h-(z-R))<0)//cond 1. no sphere inside the slice
	{
		h=0.0;
	}
	else
	{
		if((2*R) > (h-(z-R)))
		{
			h=h-(z-R);//cond 2. sperical cap
		}
		else
		{
			h=(2*R);//cond 3. whole sphere is inside the slice 
		}
	}
	return PI*h*h*(R-h/3);	// area of sperical cap
}
int main()
{	
	int N,S,i,j,k;
	//	LOOP:printf("enter the no of holes\n");
 		scanf("%d",&N);
/*	if(N<0||N>10000)
	{
		printf("enter valid choice\n"); 
		goto LOOP;
	}*/
	//	loop1:printf("enter the no of slice\n");
		scanf("%d",&S);
/*	if(1>S||S>100)
	{
		printf("enter valid data\n");
 		goto loop1;
	}*/
	double r[N],x[N],y[N],z[N],sum;
	double volume=1e15;//cubic micrometre		
 	for(i=1;i<=N;i++)
	{
	//	printf("enter the radius & x y z co-ordinates of %d sphere/hole \n",i);
		scanf( "%lf%lf%lf%lf",&r[i],&x[i],&y[i],&z[i]);
		sum = (4.0*PI*r[i]*r[i]*r[i])/3.0;
  		volume-=sum;
	}
//	printf("\nthickness of slices equal in weight\n");	
	double last=0.0;//we are starting cutting of cheese from z=0
	for ( j = 1; j <= S; j++) 
	{
	      	double vols1 = volume*(j)/S;
		//printf("vols1=\n%lf\n",goal);
		double lo = last, hi = 100000.0;// value is in micrometre
		while (hi-lo > 1)//slice must be greater than 1 milimt
		{	
	        	double h = (hi+lo)/2, vols2 = h*1e10;
	        	for ( k = 1; k <= N; k++) 
			{
				vols2 -= slice(r[k], z[k], h);
				//printf("vols2=%lf\n",cur);
			}
	       		if (vols2 > vols1) 	
			{hi = h;} 
			else 
			{lo = h;}
			
     		}
	      double h = (hi+lo)/2;
	      printf("%.9lf\n", (h-last)/1000);
	      last = h;
    	}
}
