#include<stdio.h>
#include<math.h>
float f(float x)
{
	return exp(x)*sin(x)+pow(cos(x),2);
}
int main()
{
	int i;
	double error, a, b,c,d;
	double x=M_PI/4;
	error=0.5/pow(10,5);
	printf("Âü°ª : %lf\n",exp(x)*(sin(x)+cos(x))-2*sin(x)*cos(x));
	for(i=0;i<=100000;i++)
	{
		a=f(x+1/pow(2,i))/(1/pow(2,i));
		b=f(x)/(1/pow(2,i));
		c=a-b;
		printf("h=1/%.0lf	f'%2d=%lf	error=%lf\n",pow(2,i),i+1,c,fabs(d-c));
		if(i!=1)
		{
			if(fabs(d-c)<error)
			break;
		}
		d=c;
	}
	return 0;
}
