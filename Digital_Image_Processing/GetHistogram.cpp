#include "stdafx.h"

#include "GetHistogram.h"

void GetHistogram(IppByteImage& img, double histo[256])
{
	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	int cnt[256] = { 0 };

	for (int i = 0; i < size; i++)
	{
		cnt[p[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		histo[i] = static_cast<double>((double)cnt[i] / (double)size); //Á¤±ÔÈ­ È÷½ºÅä±×·¥À¸·Î ºÁ²¨ÁÜ 
	}
}

int GetMinGrayValue(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	int i = 0, min = 255;

	for (i = 0; i < size; i++)
	{
		if (min > p[i])
		{
			min = p[i];
		}
	}
	return min;
}

int GetMaxGrayValue(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	int i = 0, max = 0;

	for (i = 0; i < size; i++)
	{
		if (max < p[i])
		{
			max = p[i];
		}
	}
	return max;
}

