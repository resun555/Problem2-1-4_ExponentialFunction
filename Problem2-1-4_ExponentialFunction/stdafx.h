// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#include <math.h>

// TODO: macro definitions

#define PRECISION 1000000

// TODO: function declarations

double FindPower1(
	double
);

double FindPower2(
	double
);

double FindPower3(
	int
);

double FindPower4(
	double,
	size_t
);

double FindRoot(
	double, 
	size_t
);

void ToFraction(
	int[], 
	size_t[]
);
