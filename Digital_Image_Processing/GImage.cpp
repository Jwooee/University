#include "stdafx.h"
#include "GImage.h"

void SamplingImage(IppByteImage& imgSrc, IppByteImage& imgDst, int nw, int nh)
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


void SamplingImage2(IppByteImage& imgSrc, IppByteImage& imgDst, int zoom)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	int nw = (w + 1) / zoom;
	int nh = (h + 1) / zoom;

	int i, j, n, m, k, index = 0;
	double *Mask, value, sum = 0.0;

	imgDst.CreateImage(nw, nh);

	int size = imgDst.GetSize();

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE* pDst = imgDst.GetPixels();

	Mask = new double[zoom*zoom];

	for (i = 0; i < h - zoom - 1; i = i + zoom){
		for (j = 0; j < w - zoom - 1; j = j + zoom){
			for (n = 0; n < zoom; n++){
				for (m = 0; m < zoom; m++){
					Mask[n*zoom + m] = pSrc[i + n][j + m];
				}
			}
			for (k = 0; k < zoom*zoom; k++)
				sum = sum + Mask[k];

			value = (sum / (zoom*zoom));
			pDst[index] = static_cast<int>(value);
			sum = 0.0;
			index++;
		}
	}
}


void SamplingImage3(IppByteImage& imgSrc, IppByteImage& imgDst, int zoom)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	int nw = (w + 1) / zoom;
	int nh = (h + 1) / zoom;

	int i, j, n, m, index = 0;
	double *Mask, value, sum = 0.0;
	double temp;

	imgDst.CreateImage(nw, nh);

	int size = imgDst.GetSize();
	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE* pDst = imgDst.GetPixels();

	Mask = new double[zoom*zoom];

	for (i = 0; i < h - zoom - 1; i = i + zoom){
		for (j = 0; j < w - zoom - 1; j = j + zoom){
			for (n = 0; n < zoom; n++){
				for (m = 0; m < zoom; m++){
					Mask[n*zoom + m] = pSrc[i + n][j + m];
				}
			}
			for (int a = 0; a < zoom*zoom - 1; a++)
			for (int b = a + 1; b < zoom*zoom; b++){
				if (Mask[a]>Mask[b + 1]){

					temp = Mask[a];
					Mask[a] = Mask[b + 1];
					Mask[b + 1] = temp;

				}
			}

			value = Mask[((int)(zoom*zoom) / 2)];
			pDst[index] = (unsigned char)value;
			index++;

		}
	}
} 