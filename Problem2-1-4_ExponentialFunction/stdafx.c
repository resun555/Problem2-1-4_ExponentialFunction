// stdafx.cpp : source file that includes just the standard includes
// Problem2-1-4_ExponentialFunction.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

double FindPower1(double n)
{
	int numerator[] = { (int)(n * PRECISION) };
	size_t denominator[] = { PRECISION };
	ToFraction(numerator, denominator);
	return FindRoot(FindPower3(numerator[0]), denominator[0]);
}


double FindPower2(double n)
{
	return pow(2., n);
}


double FindPower3(int exponent)
{
	double power = 1.;
	if (exponent > 0)
	{
		for (int i = 0; i < exponent; i++)
		{
			power *= 2;
		}
	}
	else if (exponent < 0)
	{
		for (int i = 0; i < -exponent; i++)
		{
			power /= 2;
		}
	}
	return power;
}


double FindPower4(double base, size_t exponent)
{
	double power = 1.;
	if (base == 0. && exponent == 0)
	{
		return NAN;
	}
	else
	{
		for (size_t i = 0; i < exponent; i++)
		{
			power *= base;
		}
		return power;
	}
}


double FindRoot(double radicand, size_t radical_exponent)
{
	double root = 0.;
	double power;
	for (size_t i = 0; ; i++)
	{
		if (FindPower4(i, radical_exponent) > radicand)
		{
			root += i - 1;
			power = FindPower4(root, radical_exponent);
			break;
		}
	}
	double current_precision = .1;
	while (fabs(power - radicand) >= fabs(FindPower4(root, radical_exponent) - FindPower4(root + 1. / PRECISION, radical_exponent)))
	{
		for (size_t i = 0; i < 11; i++)
		{
			if (FindPower4(root + i * current_precision, radical_exponent) > radicand)
			{
				root += (i - 1) * current_precision;
				power = FindPower4(root, radical_exponent);
				break;
			}
		}
		current_precision /= 10.;
	}
	return root;
}


void ToFraction(int numerator[], size_t denominator[])
{
	static size_t factor = 2;
	for (size_t i = factor - 2; i < denominator[0] - 1; i++)
	{
		if (numerator[0] % (i + 2) == 0 && denominator[0] % (i + 2) == 0)
		{
			factor = i + 2;
			numerator[0] /= factor;
			denominator[0] /= factor;
			ToFraction(numerator, denominator);
			break;
		}
	}
	return;
}

