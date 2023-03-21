#include "stdafx.h"

#include "DivConst.h"

void DivConst(IppByteImage& img, double addc)
{
	int size = img.GetSize();
	BYTE*p = img.GetPixels();

	for (int i = 0; i < size; i++)
	{
		p[i] = (BYTE)limit(p[i] / addc + 4.9999999999);
	}
}