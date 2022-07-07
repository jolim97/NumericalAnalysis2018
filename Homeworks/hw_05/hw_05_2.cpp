#include<stdio.h>
#include<math.h>
double func(double x)
{
	return exp(x)*sin(x);
}
int main()
{
	double a=0, b=M_PI/2;
	double h=(b-a)/4;
	double x[5]={0};
	int i;
	for(i=0;i<=4;i++)
	{
		x[i]=a+i*h;
	}
	double f[5]={0};
	for(i=0;i<=4;i++)
	{
		f[i]=func(x[i]);
		printf("f_%d=%lf\n",i,f[i]);
	}
	double I=2*h/45*(7*(f[0]+f[4])+32*(f[1]+f[3])+12*f[2]);
	printf("I=%lf",I);
}
