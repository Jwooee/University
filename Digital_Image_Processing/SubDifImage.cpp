
#include "stdafx.h"

#include "AddAvgImage.h"

bool SubImage(IppByteImage& img1, IppByteImage& img2, IppByteImage& img3)
{
	int w = img1.GetWidth();
	int h = img1.GetHeight();

	if (w != img2.GetWidth() || h != img2.GetHeight())
		return false;

	img3.CreateImage(w, h);

	int size = img3.GetSize();

	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();
	BYTE* p3 = img3.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p3[i] = limit(p1[i] - p2[i]);
	}

	return true;
}

bool DifImage(IppByteImage& img1, IppByteImage& img2, IppByteImage& img3)
{
	int w = img1.GetWidth();
	int h = img1.GetHeight();

	if (w != img2.GetWidth() || h != img2.GetHeight())
		return false;

	img3.CreateImage(w, h);

	int size = img3.GetSize();

	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();
	BYTE* p3 = img3.GetPixels();

	int diff;

	for (int i = 0; i < size; i++)
	{
		diff = p1[i] - p2[i];
		p3[i] = limit((diff >= 0) ? diff : -diff);
	}

	return true;
}