#include<gd.h>
#include<stdio.h>
#include<stdlib.h>
#include"image.h"

//loading image
image loadPNG(char *filename)
{
    image img;
    FILE *in=fopen(filename,"rb");
    if(!in){
    fprintf(stderr,"Can't open %s for reading\n",filename);
    exit(1);
    }

    img.gd=gdImageCreateFromPng(in);
    return img;
}
//save image
void savePNG(image img,char filename[])
{
    FILE *out=fopen(filename,"wb");
    gdImagePng(img.gd,out);
}
int getWidth(image img)
{
    return gdImageSX(img.gd);
}
int getHeight(image img)
{
    return gdImageSY(img.gd);
}
int getPixel(image img,int x, int y)
{
    int gdPixel=gdImageGetPixel(img.gd,x,y);
    return gdPixel;
}
int getPixelRed(int pixel)
{
    return (pixel>>16);
}
int getPixelGreen(int pixel)
{
    return (pixel >>8)& 0xFF;
}
int getPixelBlue(int pixel)
{
    return pixel & 0xFF;
}

int getAlpha(image img, int x, int y)
{
    int gdPixel = gdImageGetPixel(img.gd, x, y);
    int alpha = gdImageAlpha(img.gd, gdPixel);
    return alpha;
}
void setPixelRGB(gdImagePtr gd,int x,int y, int red,int green,int blue,int alpha)
{
    int pixel=gdImageColorAllocateAlpha(gd, red, green, blue, alpha);
    gdImageSetPixel(gd,x,y,pixel);
}
