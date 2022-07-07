#include<stdio.h>
#include<math.h>
float factorial(float n)
{
	int i,x;
	x=1;
	if(i=0)
	{
		return 1;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			x=x*i;
		}
		return x;
	}
}
int main()
{
	int i;
	double x,b,c,error;
	double sum=0;
	x=M_PI/4;
	error=0.5/pow(10,3);
	printf("Âü°ª = %lf\n",cos(x)); 
	for(i=0;i<=100;i++)
	{
		c=pow(-1,i)*pow(x,2*i)/factorial(2*i);
		sum=sum+c;
		printf("order=%d cos(pi/4)=%lf error=%lf\n",i,sum,c);
		if(i!=1)
		{
			if(fabs(c)<error)
			break;
		}
	}
}
