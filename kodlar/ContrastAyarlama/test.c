#include <stdio.h>

float calcContrast(char *nimg, int w, int h)
{
	unsigned char *img = (unsigned char *)nimg;
	int size = w * h;
	unsigned char min = 255, max = 0;

	for (int i = 0; i < size; i++) {
		if (img[i] < min)
			min = img[i];
		if (img[i] > max)
			max = img[i];
	}

	/* contrast hesapla */
	float contrast = (float)max / (min + 0.00001);

	/* sonuclari yazdir */
	printf("min=%d max=%d contrast=%lf\n", min, max, contrast);
	return contrast;
}

void editImage(char *nimg, int w, int h)
{
	return;
	for (int i = 0; i < w * h; i++)
		nimg[i] = 0x80;
}
