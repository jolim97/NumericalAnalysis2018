#include<stdio.h>
#include<math.h>
double func(double x)
{
	return 3*pow((1-pow(x,2)/16),0.5);
}
int main()
{
	int i,j;
	double a=0, b=4;
	double I[10]={0};
	double x[100][100]={0};
	double f[100][100]={0};
	for(i=1;i<=100;i++)
	{
		double h=(b-a)/pow(2,i);
		for(j=0;j<=pow(2,i);j++)
		{
			x[i-1][j]=a+h*j;
			f[i-1][j]=func(x[i-1][j]);
		}
		for(j=0;j<=pow(2,i-1)-1;j++)
		{
			I[i-1]=I[i-1]+h/3*(f[i-1][2*j]+4*f[i-1][2*j+1]+f[i-1][2*(j+1)]);
		}
		printf("%d %lf\n",i,I[i-1]);
		if(i!=1)
		{
			if(fabs(I[i-1]-I[i-2])/fabs(I[i-1])<0.0005) break;
		}
	}
	printf("Area of Ellipse=%lf",4*I[i-1]);
}
