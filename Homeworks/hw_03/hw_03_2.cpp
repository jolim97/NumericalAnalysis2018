//Crout
#include<stdio.h>
int main()
{
	double A[3][3]={{3,-0.1,-0.2},{0.1,7,-0.3},{0.3,-0.2,10}};
	double L[3][3]={0}, U[3][3]={0};
	int i,j;
	for(i=0;i<=2;i++)
	{
		L[i][0]=A[i][0];
		U[0][i]=A[0][i]/L[0][0];
	}
	L[1][1]=A[1][1]-L[1][0]*U[0][1];
	L[2][1]=A[2][1]-L[2][0]*U[0][1];
	L[2][2]=A[2][2]-L[2][0]*U[0][2]-L[2][1]*U[1][2];
	U[1][1]=1;	U[2][2]=1;
	U[1][2]=(A[1][2]-L[1][0]*U[0][2])/L[1][1];
	printf("Matrix L\n");
	for(j=0;j<=2;j++)
	{
		for(i=0;i<=2;i++)
		{
			printf("%.2lf	",L[j][i]);
		}
		printf("\n");
	}
	printf("Matrix U\n");
	for(j=0;j<=2;j++)
	{
		for(i=0;i<=2;i++)
		{
			printf("%.2lf	",U[j][i]);
		}
		printf("\n");
	}
	double invL[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	double invU[3][3]={{1,0,0},{0,1,0},{0,0,1}};
	for(i=0;i<=2;i++)
	{
		invL[0][i]=invL[0][i]/L[0][0];
	}
	for(i=0;i<=2;i++)
	{
		invL[1][i]=invL[1][i]-invL[0][i]*L[1][0];
	}
	for(i=0;i<=2;i++)
	{
		invL[1][i]=invL[1][i]/L[1][1];
	}
	for(i=0;i<=2;i++)
	{
		invL[2][i]=invL[2][i]-invL[0][i]*L[2][0]-invL[1][i]*L[2][1];
	}
	for(i=0;i<=2;i++)
	{
		invL[2][i]=invL[2][i]/L[2][2];
	}
	for(i=0;i<=2;i++)
	{
		invU[1][i]=invU[1][i]-invU[2][i]*U[1][2];
	}
	for(i=0;i<=2;i++)
	{
		invU[0][i]=invU[0][i]-invU[1][i]*U[0][1]-invU[2][i]*U[0][2];
	}
	printf("Inverse Matrix of L\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%.2lf	",invL[i][j]);
		}
		printf("\n");
	}
	printf("Inverse Matrix of U\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%.2lf	",invU[i][j]);
		}
		printf("\n");
	}
	double invA[3][3]={0};
	int k;
	printf("Inverse Matrix of A\n");
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			for(k=0;k<=2;k++)
			{
				invA[i][j]=invA[i][j]+invU[i][k]*invL[k][j];
			}
			printf("%.2lf	",invA[i][j]);
		}
		printf("\n");
	}
}
