#include<stdio.h>
#include<math.h>
#include"Library.h"
#include"Library.c"
int main()
{
    double area_under_A,x1,x2,x3,y1,y2,y3;
    printf("Enter Three Co-Ordinates of Traingle (X Y) (separated by space)\n");
    printf("1] (X1,Y1) : ");
    scanf("%lf%lf",&x1,&y1);
    printf("2] (X2,Y2) : ");
    scanf("%lf%lf",&x2,&y2);
    printf("3] (X3,Y3) : ");
    scanf("%lf%lf",&x3,&y3);
    area_under_A = find_area(x1,y1,x2,y2,x3,y3);
    printf("\nArea to be coloured black: %.2lf Square Unit \n\n",area_under_A);
    return 0;
}
