#include<stdio.h>
#include<math.h>
#include<time.h>
float func(float x)
{
	return log(x);
}
int main()
{
	int i;
	double a=0.01, b=2.0;
	double c;
	double error=0.5/pow(10,5);
	clock_t start,end;
	start=clock();
	for(i=0;i<=100;i++)
		{
			c=b-(b-a)/(func(b)-func(a))*func(b);
			if(func(a)*func(c)<0)
			{
				printf("Root of section [%.3lf,%.3lf] is %lf and error is %lf\n",a,b,c,fabs((b-c)/c*100));
				if(i!=0)
				{if(fabs((b-c)/c)<error) break;}
				b=c;
			}
			else
			{
				printf("Root of section [%.3lf,%.3lf] is %lf and error is %lf\n",a,b,c,fabs((a-c)/c*100));
				if(i!=0)
				{if(fabs((a-c)/c)<error) break;}
				a=c;
			}
		}
	printf("\n");
	end=clock();
	printf("%lfseconds",(double)(end-start)/CLOCKS_PER_SEC);
}
