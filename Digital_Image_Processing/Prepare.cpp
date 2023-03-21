#include "stdafx.h"

#include "Prepare.h"

void Prepare(IppByteImage& img, double x1, double y1) {

	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (BYTE)limit(p[i] * x1 + y1 + 4.999999999);
	}
}