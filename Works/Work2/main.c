#include <math.h>
#include <stdio.h>

int main(){
    float a,radian,z1,z2;
    scanf("%f",&a);
    radian = ((a*M_PI)/180);
    z1 = cosf(radian) + sinf(radian) + cosf(3*radian) + sinf(3*radian);
    z2 = 2*sqrt(2)*cosf(radian)*sinf((M_PI/4)+2*radian);
    printf("%f ",z1);
    printf("%f",z2);
}
