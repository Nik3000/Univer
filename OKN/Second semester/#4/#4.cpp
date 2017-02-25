#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include "Graph.h"
#include "ReadImage.h"

using namespace std;

int		h,w;
char		*R,*G,*B;

void Read();
void Draw();

int main()
{
	Read();
	GetSize("input2.bmp", &h, &w);
	R = new char[h*w];
	G = new char[h*w];
	B = new char[h*w];
	ReadImageFromFile("input2.bmp",B,G,R);
	Draw();
	WriteImage("output.bmp",B,G,R);
}

void Read()
{
	
}

void Draw()
{
	
}
