#include<stdio.h>
#include<math.h>
float f(float x)
{
	return log(x)*pow(sin(x),2);
}
int main()
{
	int i;
	double x = M_PI/4;
	double a, error, b;
	error = 0.5/pow(10,6);
	printf("Âü°ª=%lf\n",pow(sin(x),2)/x+log(x)*2*sin(x)*cos(x));
	for(i=1;i<=100;i++)
	{
		a=(f(x+(1/pow(2,i-1)))-f(x))/(1/pow(2,i-1));
		printf("h=1/%.0lf	f'%2d=%lf	error=%lf\n",pow(2,i-1),i,a,fabs(a-b));
		if(i!=1)
		{
			if(fabs(a-b)<error)
			break;
		}
		b=a;
	}
}
