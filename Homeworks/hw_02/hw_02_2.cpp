#include<stdio.h>
#include<math.h>
#include<time.h>
float func(float x)
{
	return exp(-x)*(2*cos(2*x)+sin(2*x));
}
float diff(float y)
{
	return (func(y+0.0001)-func(y))/0.0001;
}
int main()
{
	//Incremental-Search Method
	int i,j;
	j=0;
	double x1,x2;
	for(i=0;i<=10;i++)
	{
		if(func(i)*func(i+1)<0)
		{
			x1=(double)i;
			j++;
			printf("Initial value : x=%.0lf\n\n",x1);
		}
		if(j==1) break;
	}
	double error=0.5/pow(10,5);
	//Newton Method
	clock_t start,end;
	start=clock();
	for(i=0;i<=100;i++)
	{
		x2=x1-func(x1)/diff(x1);
		printf("x1=%lf x2=%lf error=%lf\n",x1,x2,fabs((x2-x1)/x2));
		x1=x2;
		if(i!=0)
		{
			if(fabs((x2-x1)/x2)<error) break;
		}
	}
	end=clock();
	printf("\n%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
