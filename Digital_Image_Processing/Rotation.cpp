#include "stdafx.h"
#include "Rotation.h"
#include <math.h>

const double PI = 3.14159265358979323846;

void IppRotate(IppByteImage& imgSrc, IppByteImage& imgDst, double angle)
{
	int w = imgSrc.GetWidth();
	int h = imgSrc.GetHeight();

	double rad = (angle * PI) / 180.;
	double cos_value = cos(rad);
	double sin_value = sin(rad);

	// 회전 후 생성되는 영상의 크기를 계산.
	// 4개의 코너 포인트의 이동 좌표를 계산하여 최대, 최소점의 차이를 구한다.

	int nx, ny, minx, miny, maxx, maxy, nw, nh;

	minx = maxx = 0;
	miny = maxy = 0;

	nx = static_cast<int>(floor((w - 1)* cos_value + 0.4999999));
	ny = static_cast<int>(floor((w - 1) * sin_value + 0.4999999));
	minx = (minx < nx) ? minx : nx; maxx = (maxx > nx) ? maxx : nx;
	miny = (miny < ny) ? miny : ny; maxy = (maxy > ny) ? maxy : ny;

	nx = static_cast<int>(floor(-(h - 1) * sin_value + 0.4999999));
	ny = static_cast<int>(floor((h - 1) * cos_value + 0.4999999));
	minx = (minx < nx) ? minx : nx; maxx = (maxx > nx) ? maxx : nx;
	miny = (miny < ny) ? miny : ny; maxy = (maxy > ny) ? maxy : ny;

	nx = static_cast<int>(floor((w - 1) * cos_value - (h - 1) * sin_value + 0.4999999));
	ny = static_cast<int>(floor((w - 1) * sin_value + (h - 1) * cos_value + 0.4999999));
	minx = (minx < nx) ? minx : nx; maxx = (maxx > nx) ? maxx : nx;
	miny = (miny < ny) ? miny : ny; maxy = (maxy > ny) ? maxy : ny;

	nw = maxx - minx + 1;
	nh = maxy - miny + 1;

	// 실제 회전 변환

	imgDst.CreateImage(nw, nh);

	BYTE** pSrc = imgSrc.GetPixels2D();
	BYTE** pDst = imgDst.GetPixels2D();

	int i, j, x1, x2, y1, y2;
	double rx, ry, p, q, temp;

	for (j = miny; j <= maxy; j++)
	for (i = minx; i <= maxx; i++)
	{
		rx = i * cos_value + j * sin_value;
		ry = -i * sin_value + j * cos_value;

		x1 = static_cast<int>(rx);
		y1 = static_cast<int>(ry);

		// 원본 영상 내에 포함된 좌표가 아니라면 무시.
		if (x1 < 0 || x1 > w - 1 || y1 < 0 || y1 > h - 1)
			continue;

		x2 = x1 + 1; if (x2 == w) x2 = w - 1;
		y2 = y1 + 1; if (y2 == h) y2 = h - 1;

		p = rx - x1;
		q = ry - y1;

		temp = (1.0 - p) * (1.0 - q) * pSrc[y1][x1]
			+ p * (1.0 - q) * pSrc[y1][x2]
			+ (1.0 - p) * q * pSrc[y2][x1]
			+ p * q * pSrc[y2][x2];

		pDst[j - miny][i - minx] = static_cast<BYTE>(limit(temp));
	}
}
