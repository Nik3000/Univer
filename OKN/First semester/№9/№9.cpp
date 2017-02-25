#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <ctime>
#define N 6000  //CONST

//x <= a0 < x

double array[N];
double array2[N];
double a; //FIRST EL
double da; //STEP
int Time;//Timers
int i;
int j;
int k;

void Generation(); //GENERATTION ARRAY
void Res();  //Calculation
void Read();

int main()
{
	//Read
	char pust[100];

	FILE *fp;
	fp=fopen("in.txt","r");  //FILE OPEN
	fscanf(fp,"%s",pust);  //PASS LINE
	fscanf(fp,"%lf",&a);  //READ VARIABLE
	fscanf(fp,"%s",pust);
	fscanf(fp,"%lf",&da);
	fclose(fp);  //FILE CLOSE

	//Generation
	array[0] = a;
	for(i=1; i < N; i++)
	{
		array[i] = da + array[i-1];
	}
	for (i = 0; i < 10; i++)
	{
	printf ("%10lf", array[i]);
	}

	//Calculation
	
	for (i = 1; i < N;)
	{
		if (array[i] <= a)
		{
			array2[i] = array[i];
			i++;
			k = i;
		}
		array2[k+1] = a;
	}
	for (i = k; i < N;)
	{
		if (array[i] > a)
		{
			array2[i] = array[i];
			i++;
		}
	}

for (i = 0; i < 10; i++)
{
	printf ("%5lf", array2[i]);
}
}


//int main()
//{
	//void Read();
	//void Generation();
	//void Res();
//}

//void Read()
//{
	//char pust[100];

	//FILE *fp;
	//fp=fopen("in.txt","r");  //FILE OPEN
	//fscanf(fp,"%s",pust);  //PASS LINE
	//fscanf(fp,"%lf",&a);  //READ VARIABLE
	//fscanf(fp,"%s",pust);
	//fscanf(fp,"%lf",&da);
	//fclose(fp);  //FILE CLOSE
	//printf ("%5lf", a);
//}

//void Generation()
//{
	//array[0] = a;
	//for(i=1; i < N; i++)
	//{
		//array[i] = da + array[i-1];
	//}
	//for (i = 0; i < 10; i++)
	//{
	//printf ("%5lf", array[i]);}
//}

//void Res()
//{
	
//}
