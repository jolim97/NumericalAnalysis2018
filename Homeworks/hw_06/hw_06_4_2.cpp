#include<stdio.h>
#include<math.h>
double func(double t)
{
	return 4-1000/498*exp(-2*t)-992/498*exp(-500*t);
}
int main()
{
	int i;
	int a=0;
	int b=1;
	double h=0.01; // or h=0.0001
	int n=(b-a)/h;
	double y[n+1]={0};
	y[0]=0;
	double f[n]={0};
	for(i=1;i<=n;i++)
	{
		double t=a+i*h;
		f[i-1]=(-500*y[i-1]+2000-1000*exp(-2*(t+h)))/(1+500*h);
		y[i]=y[i-1]+h*f[i-1];
		
	}
	FILE* data=fopen("HW06_4_2_b.csv","w+");
	fprintf(data,"t,수치해,엄밀해,상대오차(%%)\n");
	for(i=0;i<=n;i++)
	{
		double t=a+i*h;
		double error=fabs((func(t)-y[i])/func(t));
		fprintf(data,"%lf,%lf,%lf,%lf\n",t,y[i],func(t),error*100);
	}
	fclose(data);
}
