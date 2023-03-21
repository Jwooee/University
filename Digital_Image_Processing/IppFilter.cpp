#include "stdafx.h"

#include "IppFilter.h"

void IppFilterUnsharpMask(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst = imgSrc;

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j, sum;
	for (j = 1; j < h - 1; j++)
	for (i = 1; i < w - 1; i++)
	{

		sum = 5 * pSrc[j][i]
			- pSrc[j - 1][i] - pSrc[j][i - 1] - pSrc[j + 1][i] - pSrc[j][i + 1];


		pDst[j][i] = static_cast<BYTE>(limit(sum));
	}
}