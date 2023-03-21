#include "stdafx.h"

#include "Equalization.h"

void EQ(IppByteImage& img)
{

	int size = img.GetSize();
	BYTE *p = img.GetPixels();

	double sum[256] = { 0 };
	double cnt = 0;

	double histo[256] = { 0 };

	for (int i = 0; i < size; i++)
	{
		histo[p[i]]++;

	}

	for (int i = 0; i < 256; i++)
	{
		cnt += histo[i];
		sum[i] = cnt;
	}

	for (int i = 0; i < size; i++)
	{
		p[i] = (int)(sum[p[i]] * 255.) / size;
	}

}