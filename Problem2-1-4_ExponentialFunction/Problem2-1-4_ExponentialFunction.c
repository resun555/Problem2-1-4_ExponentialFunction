// Problem2-1-4_ExponentialFunction.c : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma warning (disable : 4996)


int main()
{
	double n;
	scanf("%lf", &n);
	printf("%lf", FindPower1(n));
	printf("\n");
	printf("%lf", FindPower2(n));
    return 0;
}

