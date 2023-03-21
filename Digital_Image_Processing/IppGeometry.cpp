#include "stdafx.h"
#include "IppGeometry.h"

bool IppTranslate(IppByteImage& imgSrc, IppByteImage& imgDst, int sx, int sy)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst.CreateImage(w, h);

	if ((sx > w-1 || sx < -w+1) || (sy > h-1 || sy < -h+1))
	{
		return false; 
	}
	
	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j, x, y;
	for (j = 0; j < h; j++)
		for (i = 0; i < w; i++)
		{
			x = i - sx;
			y = j - sy;
			if (x >= 0 && x < w && y >= 0 && y < h)
				pDst[j][i] = pSrc[y][x];
		}
		return true;
}
