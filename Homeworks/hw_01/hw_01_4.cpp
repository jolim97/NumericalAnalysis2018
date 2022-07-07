#include<stdio.h>
#include<math.h>
float factorial(float n)
{
	int i,x;
	for(i=1;i<=n;i++)
	{
		x=x*i;
	}
	return x;
}
int main()
{
	double x,s,error;
	double sum=0;
	int i;
	x=M_PI/4;
	error=0.5/pow(10,4);
	printf("Âü°ª = %lf\n",sin(x));
	for(i=0;i<=100;i++)
	{
		s=pow(-1,i)*pow(x,2*i+1)/factorial(2*i+1);
		sum=sum+s;
		printf("order=%d sin(pi/4)=%lf error(%%)=%lf\n",i,sum,fabs(s)*100);
		if(i!=1)
		{
			if(fabs(s)<error)
			break;
		}
	}
}
