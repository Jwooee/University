
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


	//��
	for (j = 0; j < MSize; j++)
	for (i = MSize; i < nw - MSize; i++)
	{
		pDst[j][i] = pSrc[MSize-j][i - MSize];
	}

	int a = 0;
	//��
	for (j = nh - MSize; j < nh; j++)
	{
		for (i = MSize; i < nw - MSize; i++)
		{
			pDst[j][i] = pSrc[j - MSize - a - 1][i - MSize];
		}
		a+=2;
	}
	//��
	for (j = MSize; j < nh - MSize; j++)
	for (i = 0; i < MSize; i++)
	{
		pDst[j][i] = pSrc[j-MSize][MSize-i];
	}

	

	//��
	for (j = MSize; j < nh - MSize; j++)
	{
		a = 0;
		for (i = nw - MSize; i < nw; i++)
		{

			pDst[j][i] = pSrc[j - MSize][i - MSize - a - 1];

			a+=2;
		}
		

	}

		//����
		for (j = 0; j < MSize; j++)
		for (i = 0; i < MSize; i++)
		{
			pDst[j][i] = pSrc[MSize - j][MSize - i];
		}

		
		////����
		a = 0;
		for (j = nh - MSize; j < nh; j++)
		{
			
			for (i = 0; i < MSize; i++)
			{
				pDst[j][i] = pSrc[h - a - 1][MSize - i];
			}
			a++;
		}

		//���
		for (j = 0; j < MSize; j++)
		{
			a = 0;

		for (i = nw - MSize; i < nw; i++)
		{

			pDst[j][i] = pSrc[MSize - j][w-a-1];
			a++;

		}

		}
		//�Ͽ�
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


