#include<stdio.h>
#include<math.h>

int summation(int *,int);
int *sqaured(int *,int);
int *multXY(int *,int *,int);

int main(){
	//y = a+bX [formula for least sqaured regression]
	
	int x[] = {62,64,60,58,68,66}; //the dependent variable set
	int y[] = {650,580,720,750,600,600}; // the independent variable set
	int len = sizeof(x)/sizeof(x[0]); // n = 6
	
	int *xSquared = sqaured(x,len);
	int *xy = multXY(x,y,len);
	
	int summationX = summation(x,len);
	int summationY = summation(y,len);
	int summationXsquared = summation(xSquared,len);
	int summationXY = summation(xy,len);
	
	double b = ((len*summationXY) - (summationX*summationY)) / ((len*summationXsquared) - pow(summationX,2));
	double a = (summationY - (b * summationX) ) / len;
	printf("--------------------------------------------------\n");
	printf("[1] The least sqaured regression is");
	printf("\n    y = %.3f + %.3fX",a,b);
	printf("\n--------------------------------------------------\n");
	printf("--------------------------------------------------\n");
	printf("[2] y = a +bX");
	printf("\nwhere Y is the independent variable");
	printf("\nwhere X is the dependent variable");
	printf("\nwhere A is the intercept of the line -> %.3f",a);
	printf("\nwhere B is the slope of the line -> %.3f",b);
	printf("\n--------------------------------------------------\n");	
}

int summation(int *arr, int len){
	int sum = 0;
	for(int i = 0; i<len; i++)
		sum = sum + arr[i];
	return sum;
}
int *sqaured(int *arr, int len){
	static int arraySqaured[5];
	for(int i = 0; i<len; i++)
		arrSqaured[i] = pow(arr[i],2);
	return arraySqaured;
}
int *multXY(int *x, int *y,int len){
	static int xy[6];
	for(int i = 0; i<len; i++)
		xy[i] = x[i]*y[i];
	return xy;
}

