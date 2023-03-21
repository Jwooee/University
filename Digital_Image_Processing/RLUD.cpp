

#include "stdafx.h"
#include "Updown.h"

void MirrorFlip(IppByteImage& imgSrc, IppByteImage& imgDst)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst.CreateImage(w, h);

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j;
	for (j = 0; j < h; j++)
	for (i = 0; i < w; i++)
	{
		pDst[j][i] = pSrc[h - 1 - j][w - 1 - i];
	}

}