// FileNewDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Filter.h"
#include <math.h>
#include <stdio.h>
#include <random>
const double PI = 3.13159265358979323846;
const float PI_F = 3.13159265358979323846f;

void GenerateGaussianNoise(IppByteImage& imgsrc, IppByteImage& imgdst, int amount)
{
	int size = imgsrc.GetSize();
	imgdst = imgsrc;
	BYTE* pdst = imgdst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	std::default_random_engine generator(seed);
	std::normal_distribution<double> distribution(0.0, 1.0);
	double rn;
	for (int i = 0; i < size; i++){
		rn = distribution(generator) * 255 * amount / 100;
		pdst[i] = static_cast<BYTE>(limit(pdst[i] + rn));
	}
}

void GenerateSaltNPepperNoise(IppByteImage& imgsrc, IppByteImage& imgdst, int amount)
{
	int size = imgsrc.GetSize();

	imgdst = imgsrc;
	BYTE* pdst = imgdst.GetPixels();

	unsigned int seed = static_cast<unsigned int>(time(NULL));
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(0, size - 1);

	int num = size * amount / 100;

	for (int i = 0; i < num; i++)
	{
		pdst[distribution(generator)] = (i & 0x01) * 255;
	}
}