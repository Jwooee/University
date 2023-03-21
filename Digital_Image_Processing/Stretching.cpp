#include "stdafx.h"

#include "Stretching.h"

void STRGrayValue(IppByteImage& img)
{
	int size = img.GetSize();
	BYTE* p = img.GetPixels();

	// �ִ�, �ּ� �׷��̽����� �� ���
	int gray_max, gray_min;
	gray_max = gray_min = p[0];

	for (int i = 1; i < size; i++)
	{
		if (gray_max < p[i]) gray_max = p[i];
		if (gray_min > p[i]) gray_min = p[i];
	}

	if (gray_max == gray_min)
		return;

	// ������׷� ��Ʈ��Ī
	for (int i = 0; i < size; i++)
	{
		p[i] = (p[i] - gray_min) * 255 / (gray_max - gray_min);
	}
}