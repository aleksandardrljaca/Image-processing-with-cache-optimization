#include<stdio.h>
#include"process.h"

int main(int argc, char* argv[])
{
    image process=loadPNG("cat.png");
    image result=loadPNG("cat.png");
    
   image x=unOpt(process,result);
   image y=opt(process,result);
   savePNG(x,"x.png");
   savePNG(y,"y.png");
  
    

}

