#pragma once

#include "IppImage\IppImage.h"

void GetHistogram(IppByteImage& img, double histo[256]); //������׷� �����ִ� �Լ�
int GetMinGrayValue(IppByteImage& img); //�ּڰ�
int GetMaxGrayValue(IppByteImage& img); //�ִ�

