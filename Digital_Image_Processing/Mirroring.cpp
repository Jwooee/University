
#include "stdafx.h"

#include "Mirroring.h"

void Mirroring(IppByteImage& imgSrc, IppByteImage& imgDst, int MSize)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	MSize = MSize - 1;

	int nw = (MSize * 2) + w;
	int nh = (MSize * 2) + h;;

	imgDst.CreateImage(nw, nh);

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j;


	for (j = MSize; j < nh - MSize; j++)
	for (i = MSize; i < nw - MSize; i++)
	{

		pDst[j][i] = pSrc[j - MSize][i - MSize];
	}


	//»ó
	for (j = 0; j < MSize; j++)
	for (i = MSize; i < nw - MSize; i++)
	{
		pDst[j][i] = pSrc[MSize-j][i - MSize];
	}

	int a = 0;
	//ÇÏ
	for (j = nh - MSize; j < nh; j++)
	{
		for (i = MSize; i < nw - MSize; i++)
		{
			pDst[j][i] = pSrc[j - MSize - a - 1][i - MSize];
		}
		a+=2;
	}
	//ÁÂ
	for (j = MSize; j < nh - MSize; j++)
	for (i = 0; i < MSize; i++)
	{
		pDst[j][i] = pSrc[j-MSize][MSize-i];
	}

	

	//¿ì
	for (j = MSize; j < nh - MSize; j++)
	{
		a = 0;
		for (i = nw - MSize; i < nw; i++)
		{

			pDst[j][i] = pSrc[j - MSize][i - MSize - a - 1];

			a+=2;
		}
		

	}

		//»óÁÂ
		for (j = 0; j < MSize; j++)
		for (i = 0; i < MSize; i++)
		{
			pDst[j][i] = pSrc[MSize - j][MSize - i];
		}

		
		////ÇÏÁÂ
		a = 0;
		for (j = nh - MSize; j < nh; j++)
		{
			
			for (i = 0; i < MSize; i++)
			{
				pDst[j][i] = pSrc[h - a - 1][MSize - i];
			}
			a++;
		}

		//»ó¿ì
		for (j = 0; j < MSize; j++)
		{
			a = 0;

		for (i = nw - MSize; i < nw; i++)
		{

			pDst[j][i] = pSrc[MSize - j][w-a-1];
			a++;

		}

		}
		//ÇÏ¿ì
		a = 0;

		for (j = nh - MSize; j < nh; j++)
		{
			int b = 0;
		for (i = nw - MSize; i < nw; i++)
		{
			pDst[j][i] = pSrc[h - a - 1][w - b - 1];
			b++;
		}
		a++;
		}

		


}


