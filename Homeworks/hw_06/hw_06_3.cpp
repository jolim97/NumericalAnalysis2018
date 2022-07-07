#include<stdio.h>
#include<math.h>
double func(double t)
{
	return (24+120*t+30*cos(3*t)+50*sin(3*t))/27;
}
int main()
{
	int a=0;
	int b=10;
	int i;
	double h=0.1;
	int n=(b-a)/h;
	double y1[n+1]={0};
	double y2[n+1]={0};
	y1[0]=2;
	y2[0]=0;
	double t[n+1]={0};
	t[0]=a;
	double f1[n+1]={0};
	double f2[n+1]={0};
	f1[0]=10-5*y2[0];
	f2[0]=y1[0]-2;
	double k11,k12,k13,k14,k21,k22,k23,k24;
	for(i=0;i<=n;i++)
	{
		t[i]=a+i*h;
	}
	//Runge-Kutta
	for (i=1;i<=3;i++)
	{
		k11=-5*y2[i-1]+10;
		k21=y1[i-1]-2*cos(2*t[i-1]);
		
		k12=-5*(y2[i-1]+h/2*k21)+10;
		k22=(y1[i-1]+h/2*k11)-2*cos(2*(t[i-1]+h/2));
		
		k13=-5*(y2[i-1]+h/2*k22)+10;
		k23=(y1[i-1]+h/2*k12)-2*cos(2*(t[i-1]+h/2));
		
		k14=-5*(y2[i-1]+h*k23)+10;
		k24=(y1[i-1]+h*k13)-2*cos(2*(t[i-1]+h));
		
		y1[i]=y1[i-1]+h/6*(k11+2*(k12+k13)+k14);
		y2[i]=y2[i-1]+h/6*(k21+2*(k22+k23)+k24);
		
		f1[i]=-5*y2[i]+10;
		f2[i]=y1[i]-2*cos(2*t[i]);
	}
	//Adams-Moulton
	double yp1[n+1]={0};
	double yp2[n+1]={0};//Predictor
	double yc1[n+1]={0};
	double yc2[n+1]={0};//Corrector
	double fp1[n+1]={0};
	double fp2[n+1]={0};
	for(i=4;i<=n;i++)
	{
		yp1[i]=y1[i-1]+h/24*(55*f1[i-1]-59*f1[i-2]+37*f1[i-3]-9*f1[i-4]);
		yp2[i]=y2[i-1]+h/24*(55*f2[i-1]-59*f2[i-2]+37*f2[i-3]-9*f2[i-4]);
		
		fp1[i]=-5*yp2[i]+10;
		fp2[i]=yp1[i]-2*cos(2*t[i]);
		
		yc1[i]=y1[i-1]+h/24*(9*fp1[i]+19*f1[i-1]-5*f1[i-2]+f1[i-3]);
		yc2[i]=y2[i-1]+h/24*(9*fp2[i]+19*f2[i-1]-5*f2[i-2]+f2[i-3]);
		
		f1[i]=-5*yc2[i]+10;
		f2[i]=yc1[i]-2*cos(2*t[i]);
		
		y1[i]=yc1[i];
		y2[i]=yc2[i];
	}
	FILE* data=fopen("HW06_3.csv","w+");
	fprintf(data,"t,엄밀해,수치해,상대오차(%%)\n");
	for(i=0;i<=3;i++)
	{
		fprintf(data,"%lf,%lf,%lf,%lf\n",t[i],func(t[i]),y1[i],fabs((y1[i]-func(t[i]))/func(t[i]))*100);
	}
	for(i=4;i<=n;i++)
	{
		fprintf(data,"%lf,%lf,%lf,%lf\n",t[i],func(t[i]),yc1[i],fabs((yc1[i]-func(t[i]))/func(t[i]))*100);
	}
	fclose(data);
}
