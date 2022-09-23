#include<stdio.h>
#include<math.h>
#include"Library.h"
#include"Library.c"
int main()
{
    int a1,a2,b1,b2,c1,c2;
    double angle_at_chowk;
    printf("Enter Coordinates a1,b1 and c1 of a1X+b1Y+C1=0 (separated by space): ");
    scanf("%d%d%d",&a1,&b1,&c1);
    printf("Enter Coordinates a2 ,b2 and c2 of a2X+b2Y+C2=0 (separated by space): ");
    scanf("%d%d%d",&a2,&b2,&c2);
    angle_at_chowk = find_angle(a1,b1,a2,b2);
    printf("Angle at which these roads meets at 123 Chowk: %.2lf Degree\n\n",angle_at_chowk);
    return 0;
}

