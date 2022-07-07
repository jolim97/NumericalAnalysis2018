#include<stdio.h>
#include<math.h>
double factorial(double n)
{
	int i,x;
	x=1;
	for(i=1;i<=n;i++)
	{
		x=x*i;
	}
	return x;
	
}
int main()
{
	int i;
	double x,e,sum;
	x=9;
	sum=0;
	double error = 0.5/pow(10,5);
	printf("Âü°ª = %lf\n",exp(x));
	for(i=0;i<=100;i++)
	{
		e=pow(x,i)/factorial(i);
		sum=sum+e;
		printf("#=%d e^%0.lf=%lf sum=%lf error=%lf\n",i,x,e,sum,fabs(e));
		if(i!=1)
		{
			if(fabs(e)<error)
			break;
		}
	}
}
