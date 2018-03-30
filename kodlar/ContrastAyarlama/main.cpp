#include <QImage>
#include <QLabel>
#include <QApplication>

#include <stdio.h>

extern "C" {
	extern float calcContrast(char *nimg, int w, int h);
	extern void editImage(char *nimg, int w, int h);
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//QImage im(":/low.jpg");
	QImage im(":/high.jpg");
	im = im.convertToFormat(QImage::Format_Grayscale8);

	char *img = (char *)im.bits();
	int w = im.width();
	int h = im.height();

	calcContrast(img, w, h);
	editImage(img, w, h);

	QLabel l;
	l.setPixmap(QPixmap::fromImage(im));
	l.show();

	return a.exec();
}
