
#include "stdafx.h"
#include "Endin.h"

void ENDIN(IppByteImage& img, int min, int max)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	// 히스토그램 엔드 인
	for (int i = 0; i < size; i++)
	{
		if (p[i] <= min) p[i] = 0;
		else if (p[i] >= max) p[i] = 255;
		else p[i] = (int)((p[i] - min) * 255.) / (max - min);
	}
}
