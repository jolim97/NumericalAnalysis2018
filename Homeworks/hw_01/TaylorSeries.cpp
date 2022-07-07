#include<stdio.h>
#include<math.h>
double factorial(double n)//n is for n!.
{
	int i;
	int x=1;
	for(i=1;i<=n;i++)
	{
		x=x*i;
	}
	return x;
}
float exponential(float x, float c)//c is the number of the terms of taylor series.
{
	int i;
	double d;
	double sum=0;
	x=1;
	for(i=0;i<=100;i++)
	{
		d=pow(x,i)/factorial(i);
		sum=sum+d;
		printf("%lf\n",sum);
	}
	return sum;
}

int main()
{
	//printf("%lf\n",factorial(5));
	printf("n차항까지의 e의 값 = %lf",exponential(1,10));
}
