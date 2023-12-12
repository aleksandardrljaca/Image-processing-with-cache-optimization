#include<gd.h>

typedef struct{
    gdImagePtr gd;
}image;

image loadPNG(char *filename);
void savePNG(image img,char filename[]);

int getWidth(image img);
int getHeight(image img);

int getPixel(image img,int x,int y);

int getPixelRed(int pixel);
int getPixelGreen(int pixel);
int getPixelBlue(int pixel);
int getAlpha(image img, int x, int y);
void setPixelRGB(gdImagePtr gd,int x,int y,int red,int green,int blue,int alpha);


