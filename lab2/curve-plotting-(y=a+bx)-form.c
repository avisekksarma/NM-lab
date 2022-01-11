#include <stdio.h>

int main(){
    int n;
    float x[10]={0},y[10]={0},sumX =0,sumY=0,sumX2=0,sumXY=0,a=0,b=0;
    printf("Enter the num: ");
    scanf("%d",&n);
    int i;
    for(i =0;i<n;i++){
        printf("Enter the %d th x and y values: ",i+1);
        scanf("%f %f",&x[i],&y[i]);
        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumX2 = sumX2 +x[i]*x[i];
        sumXY = sumXY+ x[i]*y[i];
    }
    a = (sumY*sumX2 - sumX*sumXY)/(n*sumX2 - sumX*sumX);
    b = (n*sumXY - sumX*sumY) /(n*sumX2 - sumX*sumX);
    printf("\n%f and %f\n",a,b);
    return 0;
}