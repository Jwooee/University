#include "stdafx.h"

#include "Gamma.h"

void Gamma(IppByteImage& img, double r1) {

	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	
	if (r1 == 0)
	{
	}
	else
	{
	for (int i = 0; i < size; i++)
	{
		p[i] = (BYTE)limit((pow(p[i] / 255.0, 1 / r1) * 255));
	}

	}
} 