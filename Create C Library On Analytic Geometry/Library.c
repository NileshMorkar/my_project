double find_angle(int a1,int b1 ,int a2,int b2 )
{
    double angle;
    angle=atan((a1*b2-a2*b1)*1.0/(a1*a2+b1*b2));
    if(angle>=0)
        return angle*(180/3.14);
    else
        return -angle*(180/3.14);
}
double find_distance(double lat1,double long1,double lat2,double long2)
{
    double Distance;
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
    
    dlong== long2 - long1;
    dlat = lat2 - lat1;
    
    Distance= pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);
 
    Distance = 12742*asin(sqrt(Distance));  
    return Distance;
}
double toRadians(double degree)
{
    return (degree/57.29578);
}
double find_area(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double area;
    area=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    if(area>=0)
        return area;
    else 
        return -area;
}