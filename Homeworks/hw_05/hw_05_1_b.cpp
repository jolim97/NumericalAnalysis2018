#include<stdio.h>
#include<math.h>
double func(double x)
{
	return exp(-x)*cos(x);
}
int main()
{
	double h,x;
	printf("구간 간격 h를 입력하시오 :");
	scanf("%lf",&h);
	x=1;
	int i,j,o;
	printf("오차의 정도를 입력하시오 :");
	scanf("%d",&o);
	printf("[차분표]\n"); 
	double df[o+2][o+2]={0};
	for(i=0;i<=o+1;i++)
	{
		printf("%d		",i);
	}
	printf("\n");
	for(i=0;i<=o+1;i++)
	{
		df[0][i]=func(x-h*i);
		printf("%lf	",df[0][i]);
	}
	printf("\n");
	for(j=1;j<=o+1;j++)
	{
		for(i=0;i<=o+1-j;i++)
		{
			df[j][i]=df[j-1][i]-df[j-1][i+1];
			printf("%lf	",df[j][i]);
		}
		printf("\n");
	}
	double differential=(df[1][0]+df[2][0]/2)/h;
	printf("f' = %lf\n",differential);
	double error=df[3][0]/3;
	printf("error = %lf",error);
}
