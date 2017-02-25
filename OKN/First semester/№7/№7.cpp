#include <stdio.h> 
#include <math.h>
#include <ctime>
using namespace std;

int n = 10000000;
int array[10000000];
int sum1, sum2, sum3;
int max1, max2, max3;
int min;
int Time;
int na1; //# NEW EL
int za1; //VALUE NEW EL
int na2; //# NEW EL
int za2; //VALUE NEW EL
int a; //FIRST EL
int da; //STEP
int Time1, Time2, Time3;	//Timers
void Generation(int n);
void Res1();
void Res2();
void Res3();
void Vvod(); //READ FIRST ELEMENT
void Vvod2(); //READ VALUE NEW ELEMENTS  
void Vivod();

int main()
{
	Vvod();
	Generation(n);
	Vvod2();
	Res1();
	Res2();
	Res3();
	Vivod();
}

void Vvod()				//INPUT FIRST ELEMENT
{
	char pust[100];
  
 	FILE *fp;								
	fp=fopen("in.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&a);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&da);
	fclose(fp);
}	

void Generation(int n) //GENERATION ARRAY
{
	array[0] = a;
	for(int i=1; i<n; i++)
	{
		array[i] = da + array[i-1];
	}
	for(int i=0; i<5; i++)
	{ printf("%5d", array[i]);
	}
}

void 
Vvod2()
{
	char pust[100];  //INPUT VALUE AND # ELEMENTS
 	FILE *fp;								
	fp=fopen("in.txt","r");
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&za1);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&na2);
	fscanf(fp,"%s",pust);
	fscanf(fp,"%d",&za2);
	fclose(fp);
}

void Res1()			//ONE CYKLE
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	
	array[na1] = za1; //NEW ELEMENTS
	array[na2] = za2; //NEW ELEMENTS
	
	max1 = array[0];
	max2 = array[1];
	max3 = array[2];
	for(int i=0; i<n; i++)
	{		
		if(max1<=max2 && max1<=max3)
			max1=array[i];
		else
		if(max2<=max3)
			max2=array[i];
		else
			max3=array[i];
	}
	sum1 = max1 + max2 + max3;
	TimeEnd = clock();
	Time1 = TimeEnd - TimeBegin;	
	
	//printf("%15d%15d%15d%15d", max1, max2, max3, sum1);
}

void Res2()			//THRE CYKLE
{
	clock_t TimeEnd, TimeBegin;
	TimeBegin = clock();
	
	array[na1] = za1; //NEW ELEMENT
	array[na2] = za2; //NEW ELEMENT
	
	int k;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<n; j++)
				{
					if (array[j] > array[j+1])
						{
							k = array[j];
							array[j] = array[j+1];
							array[j+1] = k;
						}
				}
		}		
	max1 = array[10000000];	//10000000
	max2 = array[9999999];	//9999999
	max3 = array[9999998];	//9999998
	sum2 = max1 + max2 + max3;
	TimeEnd = clock();
	Time2 = TimeEnd - TimeBegin;		
}

void Res3()
{
	array[na1] = za1; //NEW ELEMENT
	array[na2] = za2; //NEW ELEMENT
	
	clock_t TimeBegin, TimeEnd;
	TimeBegin = clock();
	int sum = 0;
	int min = array[0];
	for(int i = 0; i<n; i++)
	{
	if (min > array[i])
		min = array[i];
	}
	for(int j = 0; j<3; j++);
	{
		int NumMax = 0;
		int max = array[0];
	
		for(int i = 0; i < n; i++)
			{
				if (array[i] > max)
					{
						max = array[i];
						NumMax = i;
					}
				sum += max;
				min = array[NumMax];
			}
	}	
		//max1 = max2 = max3 = array[0];
		
	TimeEnd = clock();
	Time3 = TimeEnd - TimeBegin;
	sum3 = sum;
	//printf("%15d", sum3);
}

void Vivod()
{
	FILE *fp;
	fp=fopen("out.txt","w");
	fprintf(fp,"  Summa        Times\n\n");
	fprintf(fp,"  Summa 1    Times 1\n\n");
	fprintf(fp,"%10d", sum1);
	fprintf(fp,"%10d", Time1);
	fprintf(fp,"\n\n  Summa 2    Times 2\n\n");
	fprintf(fp,"%10d", sum2);
	fprintf(fp,"%10d", Time2);
	fprintf(fp,"\n\n  Summa 3    Times 3\n\n");
	fprintf(fp,"%10d", sum3);
	fprintf(fp,"%10d", Time3);
	fclose(fp);
}
