#include<stdio.h>
#include<math.h>
#include"Library.h"
#include"Library.c"
int main()
{
    double lat1 ,long1,lat2,long2;
    double distance;
    printf("Enter Latitude and Longitude values of 1st Place (separated by space): ");
    scanf("%lf%lf",&lat1,&long1);
    printf("Enter Latitude and Longitude values of 2nd Place (separated by space): ");
    scanf("%lf%lf",&lat2,&long2);
    distance = find_distance(lat1,long1,lat2,long2);
    printf("\nDistance Between 1st Place and 2nd Place : %.2lf Km.\n\n",distance);
    return 0;
}
