#pragma once

#include "IppImage\IppImage.h"

void GetHistogram(IppByteImage& img, double histo[256]); //히스토그램 구해주는 함수
int GetMinGrayValue(IppByteImage& img); //최솟값
int GetMaxGrayValue(IppByteImage& img); //최댓값

