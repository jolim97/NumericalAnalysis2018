#include<stdio.h>
#include<math.h>
#include<time.h>
float func(float x)
{
	return pow(x,4)-8*pow(x,3)+24*pow(x,2)-28*x+10;
}
int main()
{
	//Incremental-Search Method
	int i,j;
	j=0;
	double a,b,c;
	double x[4]; 
	for(i=-20;i<=20;i++)
	{
		if(func(i)*func(i+1)<0)
		{
			x[j]=(double)i;
			printf("root is between %d and %d\n",i,i+1);
			j++;
		}
	}
	printf("\n");
	//Linear Interpolation Method
	double error=0.5/pow(10,3);
	clock_t start,end;
	start=clock();
	for(i=0;i<=1;i++)
	{
		a=x[i]; b=x[i]+1;
		for(j=0;j<=100;j++)
		{
			c=b-(b-a)/(func(b)-func(a))*func(b);
			if(func(a)*func(c)<0)
			{
				
				printf("Root of section [%.0lf,%.0lf] is %lf and error is %lf\n",x[i],x[i]+1,c,fabs((b-c)/c*100));
				if(j!=0)
				{
					if(fabs((b-c)/c*100)<error) break;
				}
				b=c;
			}
			else
			{
				
				printf("Root of section [%.0lf,%.0lf] is %lf and error is %lf\n",x[i],x[i]+1,c,fabs((a-c)/c*100));
				if(j!=0)
				{
					if(fabs((a-c)/c*100)<error) break;
				}
				a=c;
			}
		}
		printf("\n");
	}
	end=clock();
	printf("%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
