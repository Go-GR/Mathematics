#include <stdio.h>
 
#define SCALE_1      1.0   		   //기울기
#define OFFSET_1    -2.0   	   //y절편
#define PARALLEL     3.0   	   //평행이동
 
#define SCALE_0      2.0		   //기울기
#define OFFSET_0    -6.0    	   //y절편
 
#define X_BEGINE     100		   
 
float MyFunc(float x)
{
  float y = 0.0;
  y = ( SCALE_1 * (x - PARALLEL) * (x - PARALLEL) ) + OFFSET_1;
 
  return y;
}
 
float Derivative_MyFunc(float x)
{
  float tangentLine = 0.0;
  tangentLine = ( (SCALE_0) * x ) + OFFSET_0;
 
  return tangentLine;
}
 
int main(void)
{
    float y = 0.0, Slope = 0.0;
    float x = X_BEGINE;
    float x_next=0.0;
    int Num_Order = 0.0;		//몇 타임
 
  printf("< Newton's Method algorithm result >\n ");
    do{
        //---Newton's Method algorithm---//
        y  = MyFunc(x);	//y=f(x) 모양
        printf("%f \n", y);
        Slope = Derivative_MyFunc(x);
 
        if(( -0.0001 > Slope ) || (Slope > 0.0001))
        {
            x_next = x - (y/Slope);	//공식사용, 컴퓨터는 나누기를 싫어하지만...어쩔수...
            Num_Order ++;
        }
 
        //printf("X_next = %f \n", x_next);
        x = x_next; // iteration 재귀
        //------------------------------//
    }while((-0.00001 > y)||(y > 0.00001));
    printf("Order = %d \nX_next = %0.3f \n\n", Num_Order, x_next);
    
    y = 0.0, Slope = 0.0;
    x = -100;
    x_next=0.0;
    
    do{
        //---Newton's Method algorithm---//
        y  = MyFunc(x);	//y=f(x) 모양
        printf("%f \n ", y);
        Slope = Derivative_MyFunc(x);
 
        if(( -0.0001 > Slope ) || (Slope > 0.0001))
        {
            x_next = x - (y/Slope);
            Num_Order ++;
        }
 
        //printf("X_next = %f \n", x_next);
 
        x = x_next; // iteration 재귀
        //------------------------------//
    }while((-0.00001 > y)||(y > 0.00001));
    printf("Order = %d \n X_next = %0.3f \n\n", Num_Order, x_next);
  return 0;
}

