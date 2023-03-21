#pragma once
#include "IppImage\IppImage.h"

void GenerateGaussianNoise(IppByteImage& imgsrc, IppByteImage& imgdst, int amount);
void GenerateSaltNPepperNoise(IppByteImage& imgsrc, IppByteImage& imgdst, int amount);