#include<stdio.h>

int score(int a);
int test(int a, int b);

int main()
{
	printf("\n--------------------------------------------");
	printf("\n\tSimple Gpa Calculator\n\tby weng");
	printf("\n--------------------------------------------\n");
	printf("\n--------------------------------------------");
    int number, score;
    double totalCourse,totalUnit;
    int result[number];
    int unit[number];
    printf("\nINPUT TOTAL NUMBER OF COURSES:");
    
    scanf("%d", &number);
    for (int x = 1; x<=number; x++){
     printf("\n----------");
	 printf("\n[%d]INPUT SCORE:",x);
	 scanf("%d", &score);
	 printf("INPUT UNITS:");
	 scanf("%d", &unit[x]);
	 test(score,unit[x]); 
	 result[x]= test(score,unit[x]);
	 printf("SCORE CONVERTED: %d", result[x]);
	 totalCourse = totalCourse+result[x];
	 totalUnit = totalUnit+unit[x];
	 printf("\n----------");
	}
	printf("\n---------------------------------");
	printf("\nTOTAL SCORE: %.2lf", totalCourse);
	printf("\nTOTAL UNIT :%.2lf", totalUnit);
	double average = totalCourse/totalUnit;
	printf("\nGPA:%.2lf", average);
}

//based on the 5 point grading system [70 to 90 ->A ->5] [60 to 69 ->B ->4] [0 to 39 ->F -> 0] and so on 
//this function takes the score the user gets and converts it to the gpa for that score i.e 5,4,3,2,1 or 0
int score(int i){
    int array[] = {70,60,50,45,40};
    int count = 5;
    int lenArray = 5;
    for(int x = 0; x<lenArray; x++){
    	if(i>=array[x])
    	return count;
    	else
    	count-=1;
}
	return 0;
}

int test(int a, int b){
    return score(a) * b;
}
