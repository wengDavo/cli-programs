#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;

double *calc(int,int);
double call(string shape,int a, int b,int c, int d){
	double *ptr = calc(a,b);
	double area = ( ptr[c]*ptr[d] )/2;
	cout<<"\nTHE AREA OF THE "<<shape<<":"<<area<<endl;
	
}
/*Function calc  = ( takes 2 values of type int First number for the number of times it should ask for values
Second number taken as an index to Display appropriate String As a pointer to be able to return the Values stored in the Array)*/
int main(){
	const double PI = 22.0/7.0;
	double area, apothem;
	string name;
	string shape[15] = {"TRIANGLE","CIRCLE","SQUARE","RECTANGLE","TRAPEZIUM","RHOMBUS","PARALLELOGRAM","SPHERE","CONE"};
	cout<<"INPUT-NAME - ";
	cin>>name;
	cout<<"\n--------------------------------------------\n";
	cout<<endl<<name<<" WElCOME TO A B C SHAPES CALCULATOR\n";
	cout<<"\n--------------------------------------------\n";
	start://for GOTO Statement
    cout<<"\n--------------------------------------------";
	cout<<"\n[1]TRIANGLE\t\t[6]RHOMBUS\n[2]CIRCLE\t\t[7]PARALLELOGRAM\n[3]SQUARE\t\t[8]SPHERE\n[4]RECTANGLE\t\t[9]CONE\n[5]TRAPEZIUM\t\t[10]NEXT PAGE"<<endl;
	cout<<"--------------------------------------------\n";
	int input;
	while(input != 15){
	cout<<"\nSELECT A SHAPE - ";
	cin>>input;
	
	switch(input){
	case 1:{ 
	//TRIANGLE 
	// AREA = b*h/2
	call("t",2,1,0,1);
	break;
}
	case 2:{
	//CIRCLE
	// AREA =  PI*r*r;
	double *ptr = calc(1,0);
	area = (ptr[0]*ptr[0])*PI;
	cout<<"\nTHE AREA OF THE CIRCLE:"<<area<<endl;	
	break;
}
    case 3:{
    //SQUARE
    // AREA =  l*l
	double *ptr = calc(1,2); 
	area = (ptr[0]*ptr[0]); 
	cout<<"\nTHE AREA OF THE SQUARE:"<<area<<endl;
	break;	
}
    case 4:{
    //RECTANGLE
    // AREA = l*b;
	double *ptr = calc(2,2);
	area = (ptr[0]*ptr[1]);
	cout<<"\nTHE AREA OF THE RECTANGLE:"<<area<<endl;	
	break;
}
    case 5:{
    //TRAPEZIUM
    // AREA = (a+b/2)*h
	double *ptr = calc(3,1);
	area = (((ptr[0]+ptr[2])/2)*ptr[1]); 
	cout<<"\nTHE AREA OF THE TRAPEZIUM:"<<area<<endl;	
	break;
}
    case 6:{
    //RHOOMBUS
	// AREA = l*b/2	
	double *ptr = calc(2,3);
	area = ( (ptr[0]*ptr[1])/2 );
	cout<<"\nTHE AREA OF THE RHOMBUS:"<<area<<endl;	
	break;
}
    case 7:{
    //PARALLELOLOGRAM
    // AREA = b*h
	double *ptr = calc(2,1);
	area = ( (ptr[0]*ptr[1]) ); 
	cout<<"\nTHE AREA OF THE PARALLELOGRAM:"<<area<<endl;	
	break;
}     
    case 8:{
    //SPHERE
    // AREA = 4*PI*r^2;
	double *ptr = calc(1,0);
	area = (4*(PI)*pow(ptr[0],2) );
	cout<<"\nTHE AREA OF THE SPHERE:"<<area<<endl;	
	break;
}
    case 9:{
    //CONE
    // AREA = PI * r( r + sqrt(h*2+r*2) );
    double *ptr = calc(2,0);
	area = PI * ptr[0] * ( ptr[0] + (sqrt (pow(ptr[1],2) + pow(ptr[0],2) ) ) );
	cout<<"\nTHE AREA OF THE CONE:"<<area<<endl;	
	break;	
			}
	case 10:{
		//case 10 breaks the function into a compound if to give the NEXT PAGE
		cout<<"\n--------------------------------------------";
	    cout<<"\n[11]CYLINDER\n[12]CUBE\n[13]KITE\n[14]ANY REGULAR POLYGON\n[15]TO QUIt\t\t[10]PREV PAGE"<<endl;
	    cout<<"--------------------------------------------\n";
	    resume://RESUME LABEL
	    cout<<"\nSELECT A SHAPE - ";
	    cin>>input;
	    if(input == 10)
	        goto start;
	        //if INPUT is equal to 10 flow should GOTO START I.E the beginigng of program
	    if(input  == 11){
		    //CYLINDER
		    // AREA = 2 * PI * r*r + h(2*PI*r)
            double *ptr = calc(2,0);
	        area = ( (2* PI* pow(ptr[0],2) + ptr [1] * (2 * PI * ptr [0] ) ) );
	        cout<<"THE AREA OF THE CYLINDER:"<<area<<endl;
			goto resume;//GOTO label to transfer flow to area indexed RESUME I.E top of CASE 10 to keep it in the loop until 15 is inputed		      
}
        if(input == 12){
	        //CUBE
	        // AREA = 6 * ( a^2 );
	        double *ptr = calc(1,7);
	        area = 6*(pow(ptr[0],2));
	        cout<<"\nTHE AREA OF THE CUBE:"<<area<<endl;
			goto resume;	
		}
		if(input == 13){
	        //KITE
	        // AREA = (p * q) / 2;
	        double *ptr = calc(2,8);
	        area = ( ptr[0] * ptr[1] )/2;
	        cout<<"\nTHE AREA OF THE KITE:"<<area<<endl;
			goto resume;	
		}
	    if(input == 14){ 
		     //ALL REGULAR POLYGONS
		     //FORMULA FOR APOTHEM = length[n] / 2(tan( 180/n ) );
		     //AREA = Number of side * length of sides * apothem / 2
	        double *ptr = calc(2,5);
	        apothem = (  ( ptr[1] )/2*(tan(180/ptr[1]) ) ); 
	        area = (ptr[1]*ptr[0]*apothem)/2;              
	        cout<<"\nTHE AREA OF THE "<<ptr[1]<<" SIDED POLYGON:"<<area<<endl;
			goto resume;	
}  
}
}
}
}
double *calc(int x,int a){
	string array[] = {"RADIUS","BASE","HEIGHT","LENGTH","BREADTH","LENGTH OF SIDE","NUMBER OF SIDE","EDGE","DIAGONAL-1","DIAGONAL-2"};
	static double arr[50];                                 
	for(int i = 0; i<x; i++){            
	cout<<"Input "<<array[a+i]<<":"; 
	cin>>arr[i];                          
	}
	return arr;
	//it returns the value of the array ARR stored from the function
}

