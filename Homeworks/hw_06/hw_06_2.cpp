#include<stdio.h>
#include<math.h>
double y1e(double t)
{
	return 5*exp(-t)+3*exp(4*t);
}
double y2e(double t)
{
	return 5*exp(-t)-2*exp(4*t);
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
	y1[0]=8;	y2[0]=3;
	double k11,k12,k13,k14,k21,k22,k23,k24;
	for (i=1;i<=n;i++)
	{
		double t=a+i*h;
		k11=2*y1[i-1]-3*y2[i-1];
		k21=y2[i-1]-2*y1[i-1];
		
		k12=2*(y1[i-1]+h/2*k11)-3*(y2[i-1]+h/2*k21);
		k22=(y2[i-1]+h/2*k21)-2*(y1[i-1]+h/2*k11);
		
		k13=2*(y1[i-1]+h/2*k12)-3*(y2[i-1]+h/2*k22);
		k23=(y2[i-1]+h/2*k22)-2*(y1[i-1]+h/2*k12);
		
		k14=2*(y1[i-1]+h*k13)-3*(y2[i-1]+h*k23);
		k24=(y2[i-1]+h*k23)-2*(y1[i-1]+h*k13);
		
		y1[i]=y1[i-1]+h/6*(k11+2*(k12+k13)+k14);
		y2[i]=y2[i-1]+h/6*(k21+2*(k22+k23)+k24);		
	}
	FILE*data=fopen("HW06_2.csv","w+");
	fprintf(data,"t,y1,y1 엄밀해,상대오차1(%%),y2,y2 엄밀해,상대오차2(%%)\n");
	for(i=0;i<=n;i++)
	{
		double t=a+i*h;
		double e1=fabs((y1[i]-y1e(t))/y1e(t))*100;
		double e2=fabs((y2[i]-y2e(t))/y2e(t))*100;
		fprintf(data,"%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",t,y1[i],y1e(t),e1,y2[i],y2e(t),e2);
	}
	fclose(data);
}
