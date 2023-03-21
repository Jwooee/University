#include "stdafx.h"
#include "IppResizeNearest.h"

void IppResizeNearest(IppByteImage& imgSrc, IppByteImage& imgDst, int nw, int nh)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	imgDst.CreateImage(nw, nh);

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j, x, y;
	double rx, ry;
	for (j = 0; j < nh; j++)
	for (i = 0; i < nw; i++)
	{
		rx = static_cast<double>(w - 1) * i / (nw - 1);
		ry = static_cast<double>(h - 1) * j / (nh - 1);
		x = static_cast<int>(rx + 0.499999);
		y = static_cast<int>(ry + 0.499999);

		if (x >= w) x = w - 1;
		if (y >= h) y = h - 1;

		pDst[j][i] = pSrc[y][x];
	}
}