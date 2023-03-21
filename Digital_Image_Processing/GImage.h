#pragma once
#include "IppImage\IppImage.h"

void SamplingImage(IppByteImage& imgSrc, IppByteImage& imgDst, int nw, int nh);

void SamplingImage2(IppByteImage& imgSrc, IppByteImage& imgDst, int zoom);

void SamplingImage3(IppByteImage& imgSrc, IppByteImage& imgDst, int zoom);
