#include "stdafx.h"

#include "IppBitPlane.h"

void IppBitPlane(IppByteImage& img1, IppByteImage& img2, int bit)
{

	img2.CreateImage(img1.GetWidth(), img1.GetHeight());

	int size = img1.GetSize();
	BYTE* p1 = img1.GetPixels();
	BYTE* p2 = img2.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p2[i] = (p1[i] & (1 << bit)) ? 255 : 0;
	}
}