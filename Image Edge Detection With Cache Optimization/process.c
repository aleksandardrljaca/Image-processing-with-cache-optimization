#include "process.h"
#include<time.h>

image opt(image process,image result)
{
int KERNEL[3][3]={{0,-1,0},{-1,4,-1},{0,-1,0}};
    image img=process;
    image processImg=result;
    

    int height=getHeight(img);
    int width=getWidth(img);
    int pixel[3][3];
    clock_t begin = clock();

    for(int y=0;y<height-2;y++)
    {   
        for(int x=0;x<width-2;x++)
        {
            pixel[0][0]=getPixel(img,x,y);
            pixel[0][1]=getPixel(img,x,y+1);
            pixel[0][2]=getPixel(img,x,y+2);
            pixel[1][0]=getPixel(img,x+1,y);
            pixel[1][1]=getPixel(img,x+1,y+1);
            pixel[1][2]=getPixel(img,x+1,y+2);
            pixel[2][0]=getPixel(img,x+2,y);
            pixel[2][1]=getPixel(img,x+2,y+1);
            pixel[2][2]=getPixel(img,x+2,y+2);
            int A=getAlpha(img,x+1,y+1);

            int R=((getPixelRed(pixel[0][0])*KERNEL[0][0])+
                    (getPixelRed(pixel[0][1])*KERNEL[0][1])+
                    (getPixelRed(pixel[0][2])*KERNEL[0][2])+
                    (getPixelRed(pixel[1][0])*KERNEL[1][0])+
                    (getPixelRed(pixel[1][1])*KERNEL[1][1])+
                    (getPixelRed(pixel[1][2])*KERNEL[1][2])+
                    (getPixelRed(pixel[2][0])*KERNEL[2][0])+
                    (getPixelRed(pixel[2][1])*KERNEL[2][1])+
                    (getPixelRed(pixel[2][2])*KERNEL[2][2]));
            if(R<0) R=0;
            else if(R>255)
                    R=255;

            int G=((getPixelGreen(pixel[0][0])*KERNEL[0][0])+
                    (getPixelGreen(pixel[0][1])*KERNEL[0][1])+
                    (getPixelGreen(pixel[0][2])*KERNEL[0][2])+
                    (getPixelGreen(pixel[1][0])*KERNEL[1][0])+
                    (getPixelGreen(pixel[1][1])*KERNEL[1][1])+
                    (getPixelGreen(pixel[1][2])*KERNEL[1][2])+
                    (getPixelGreen(pixel[2][0])*KERNEL[2][0])+
                    (getPixelGreen(pixel[2][1])*KERNEL[2][1])+
                    (getPixelGreen(pixel[2][2])*KERNEL[2][2]));
            if(G<0) G=0;
            else if(G>255)
                    G=255;
            
            int B=((getPixelBlue(pixel[0][0])*KERNEL[0][0])+
                    (getPixelBlue(pixel[0][1])*KERNEL[0][1])+
                    (getPixelBlue(pixel[0][2])*KERNEL[0][2])+
                    (getPixelBlue(pixel[1][0])*KERNEL[1][0])+
                    (getPixelBlue(pixel[1][1])*KERNEL[1][1])+
                    (getPixelBlue(pixel[1][2])*KERNEL[1][2])+
                    (getPixelBlue(pixel[2][0])*KERNEL[2][0])+
                    (getPixelBlue(pixel[2][1])*KERNEL[2][1])+
                    (getPixelBlue(pixel[2][2])*KERNEL[2][2]));
            if(B<0) B=0;
            else if(B>255)
                    B=255;

           setPixelRGB(processImg.gd,x+1,y+1,R,G,B,A);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
    printf("\t\t\t\t\t\t %f \n",time_spent);
    return processImg;
}
image unOpt(image process,image result)
{
int KERNEL[3][3]={{0,-1,0},{-1,4,-1},{0,-1,0}};
    image img=process;
    
    image processImg=result;
    

    int height=getHeight(img);
    int width=getWidth(img);
    int pixel[3][3];
    clock_t begin = clock();
    for(int x=0;x<height-2;x++)
    {   
        for(int y=0;y<width-2;y++)
        {
            pixel[0][0]=getPixel(img,x,y);
            pixel[0][1]=getPixel(img,x,y+1);
            pixel[0][2]=getPixel(img,x,y+2);
            pixel[1][0]=getPixel(img,x+1,y);
            pixel[1][1]=getPixel(img,x+1,y+1);
            pixel[1][2]=getPixel(img,x+1,y+2);
            pixel[2][0]=getPixel(img,x+2,y);
            pixel[2][1]=getPixel(img,x+2,y+1);
            pixel[2][2]=getPixel(img,x+2,y+2);
            int A=getAlpha(img,x+1,y+1);

            int R=((getPixelRed(pixel[0][0])*KERNEL[0][0])+
                    (getPixelRed(pixel[0][1])*KERNEL[0][1])+
                    (getPixelRed(pixel[0][2])*KERNEL[0][2])+
                    (getPixelRed(pixel[1][0])*KERNEL[1][0])+
                    (getPixelRed(pixel[1][1])*KERNEL[1][1])+
                    (getPixelRed(pixel[1][2])*KERNEL[1][2])+
                    (getPixelRed(pixel[2][0])*KERNEL[2][0])+
                    (getPixelRed(pixel[2][1])*KERNEL[2][1])+
                    (getPixelRed(pixel[2][2])*KERNEL[2][2]));
            if(R<0) R=0;
            else if(R>255)
                    R=255;

            int G=((getPixelGreen(pixel[0][0])*KERNEL[0][0])+
                    (getPixelGreen(pixel[0][1])*KERNEL[0][1])+
                    (getPixelGreen(pixel[0][2])*KERNEL[0][2])+
                    (getPixelGreen(pixel[1][0])*KERNEL[1][0])+
                    (getPixelGreen(pixel[1][1])*KERNEL[1][1])+
                    (getPixelGreen(pixel[1][2])*KERNEL[1][2])+
                    (getPixelGreen(pixel[2][0])*KERNEL[2][0])+
                    (getPixelGreen(pixel[2][1])*KERNEL[2][1])+
                    (getPixelGreen(pixel[2][2])*KERNEL[2][2]));
            if(G<0) G=0;
            else if(G>255)
                    G=255;
            
            int B=((getPixelBlue(pixel[0][0])*KERNEL[0][0])+
                    (getPixelBlue(pixel[0][1])*KERNEL[0][1])+
                    (getPixelBlue(pixel[0][2])*KERNEL[0][2])+
                    (getPixelBlue(pixel[1][0])*KERNEL[1][0])+
                    (getPixelBlue(pixel[1][1])*KERNEL[1][1])+
                    (getPixelBlue(pixel[1][2])*KERNEL[1][2])+
                    (getPixelBlue(pixel[2][0])*KERNEL[2][0])+
                    (getPixelBlue(pixel[2][1])*KERNEL[2][1])+
                    (getPixelBlue(pixel[2][2])*KERNEL[2][2]));
            if(B<0) B=0;
            else if(B>255)
                    B=255;

           setPixelRGB(processImg.gd,x+1,y+1,R,G,B,A);
        }
    }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
    printf("\t\t\t\t\t\t %f \n",time_spent);
    return processImg;
}
