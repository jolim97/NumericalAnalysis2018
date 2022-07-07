#include<stdio.h>
#include<math.h>
#include<time.h>
float func(float x)
{
	return 10*exp(-x)*sin(2*M_PI*x)-2;
}
int main()
{
	int i;
	double x0,x1,x2,h1,h2,g;
	x1=0.1;	x2=1;	x0=(x1+x2)/2;
	double x3;
	double error=0.5/pow(10,5);
	clock_t start,end;
	start=clock();
	for(i=0;i<=100;i++)
	{
		h1=x0-x1;	h2=x2-x0;	g=h2/h1;
		double a,b,c;
		a=(g*func(x1)-func(x0)*(1+g)+func(x2))/(g*h1*h1*(1+g));
		b=(a*h1*h1+func(x0)-func(x1))/h1;
		c=func(x0);
		if (b<0)
		{
			x3=x0-(2*c)/(b-pow(b*b-4*a*c,0.5));
			
		}
		else
		{
			x3=x0-(2*c)/(b+pow(b*b-4*a*c,0.5));
		}
		if(x3>x0)
		{
			x0=x3;
			x1=x0;
			x2=x2;
			printf("1 x=%lf	error=%lf\n",x0,fabs((x0-x1)/x0));
			if(fabs((x0-x1)/x0)<error) break;
		}
		else
		{
			x0=x3;
			x1=x1;
			x2=x0;
			printf("2 x=%lf	error=%lf\n",x0,fabs((x0-x2)/x0));
			if(fabs((x0-x2)/x0)<error) break;
		}
	}
	end=clock();
	printf("%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
