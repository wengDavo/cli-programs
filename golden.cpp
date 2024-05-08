#include <iostream>
#include<iomanip>
using namespace std;
class Designer{
	public:
	string name;
	int pin;
	public:
	Designer(string a, int b){
		name = a;
		pin = b;
	}
		public:
		printAccount(){
			cout<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Password: "<<pin<<endl;
			
		}
};
        string nameChecker(string name[],string nameCheck, int size);
        void greet(string correctName,string name[],int pin[],int limit,string Names[],string Type[], string Date[],double Measure[], double Cost[]);
        void mergeChecker(int max,int limit,double Cost[],double cost[], string call);
        void mergeChecker(int use,int limit,string Cost[],string cost[],string call);
int main(){
    Designer golden("Golden",1234);
    Designer weng("Weng",2222);
    Designer anthony("Anthony",3333);
    Designer oti("oti",4444);
    Designer okoro("Okoro",5555);
    string nameCheck;
    int pinCheck;
    string Names[] = {"NAT","ABA","JAC","JIL","SEPT","REP","STAR","WEST","SIK","JOS"};
    string Date[] = {"12/feb","13/mar","14/apr","15/may","16/jun","17/jul","18/aug","19/sep","20/oct","21/nov"};
    string Type[] ={"suit","suit","suit","suit","suit","native","ankara","ankara","long gown","long gown"};
    double Measure[] = {12.5,14.5,26.7,37.8,59.0,75.7,84.5,3.2,12.7,67.1};
    double Cost[] = {100000,120000,130000,140000,150000,16000,17000,18000,19000,2000};
   
    string name[] = {golden.name,weng.name,anthony.name,oti.name,okoro.name};
    int pin[] ={golden.pin,weng.pin,anthony.pin,oti.pin,okoro.pin};
    int nameSize = sizeof(name)/sizeof(name[0]);
    int pinSize = sizeof(pin)/sizeof(pin[0]);
    
    cout << "***************************************" << endl<<endl;
	cout << "WELCOME TO GOLDEN TAILORING MANAGEMENT SYSTEM :)" << endl<<endl;
	cout << "**************************************\n";

    cout<<"\nINPUT ACCOUNTS NAME TO LOGIN: ";
    cin>>nameCheck;
    string correctName = nameChecker(name,nameCheck,nameSize);
    if(correctName != "false"){
    	cout<<"-"<<correctName<<"\n-ACCOUNT FOUND-\n-SUCCESFULLY LOGED IN-"<<endl;
    	cout<<"PASSWORD:\n------\n";
    	cin>>pinCheck;
    	cout<<"------\n";
    	   if(correctName == golden.name && pinCheck == golden.pin)
    	   greet(correctName,name,pin,2,Names,Type,Date,Measure,Cost);
    	   else if(correctName == weng.name && pinCheck == weng.pin)
    	   greet(correctName,name,pin,4,Names,Type,Date,Measure,Cost);
    	   else if(correctName == anthony.name && pinCheck == anthony.pin)
    	    greet(correctName,name,pin,6,Names,Type,Date,Measure,Cost);
    	   else if(correctName == oti.name && pinCheck == oti.pin)
    	    greet(correctName,name,pin,8,Names,Type,Date,Measure,Cost);
    	   else if(correctName == okoro.name && pinCheck == okoro.pin)
    	    greet(correctName,name,pin,10,Names,Type,Date,Measure,Cost);
    	   else
    	   cout<<"Incorrect Pin";
		}
	else
	cout<<"Err.... name not found in database";	
	
	
return 0;
}

string nameChecker(string name[],string nameCheck, int size){
	string found = "false";
	 for(int i = 0; i<size; i++)
        if(nameCheck == name[i])
        	found  =  name[i];
        	return found;
}
void greet(string correctName,string name[],int pin[],int limit,string Names[],string Type[], string Date[],double Measure[], double Cost[]){
	int multiple;
	cout<<"\nVERIFIED PASSCODE\nWHAT WOULD YOU LIKE TO CHECK "<<correctName<<endl;
	start:
	cout<<endl;
	cout<<"\nPRESS\n[1].PENDING TASK\n[2].New Entries\n[3].TAILORS RECORD\n[4].QUIT\n\n-----\nINPUT - \n-----";
	cin>>multiple;
	int max;
	int use;
	if(max>50)max = 7;
	(max>6)?use = max :use = max;
	string customers[use], date[use],type[use];
	double size [use],cost [use];
	cout<<"\n\n-----------------------------------------------------------"<<endl;
	switch(multiple){
		  case 1:
		  	{
		  mergeChecker(use,limit,Names,customers,"CUSTOMER-NAMES:");
		  	cout<<endl;
		  	mergeChecker(use,limit,Date,date,"DATE:     ");
		  	cout<<endl;
		    mergeChecker(use,limit,Type,type,"TYPE:     ");
		    cout<<endl;
		  	mergeChecker(use,limit,Measure,size,"MEASUREMENT:");
		  	cout<<endl;
		  	mergeChecker(use,limit,Cost,cost,"COST:\t");
			goto start;
		}
			case 2:
			cout<<"How Many New Customers:";
		    cin>>max;
		    customers[use], date[use],type[use];
	        size [use],cost [use];
		    	for(int i = 0; i<max; i++){
		    		cout<<"\n["<<i+1<<"]"<<endl;
		    		cout<<i+1<<".Customers-Name:";
		    		cin>>customers[i];
		    		cout<<i+1<<".Date-D/M:";
		    		cin>>date[i];
		    		cout<<i+1<<".Cutomerse-Size:";
		    		cin>>size[i];
		    		cout<<i+1<<".Type:";
		    		cin>>type[i];
		    		cout<<i+1<<".Cost:";
		    		cin>>cost[i];
		    		
} 
               goto start;
    
	}
}
void mergeChecker(int use,int limit,double Cost[],double cost[],string call){
	if(use>6){
		int i = limit-2;
		cout<<call<<setw(6);
        for(i; i<limit; i++){
    	for(int j = 0; j<1; j++)
        cout<<"\t"<<left<<setw(4)<<Cost[i];
 }
}
    else{
    	 	cout<<call<<setw(6);
          for(int i = 0; i<use; i++)
          cout<<"\t"<<left<<setw(4)<<cost[i];      	
	
}
}


void mergeChecker(int use,int limit,string Type[],string type[],string call){
	if(use>6){
		int i = limit-2;
	 cout<<call<<setw(6);
          for(i; i<limit; i++){
    	  for(int j = 0; j<1; j++)
          cout<<"\t"<<left<<setw(4)<<Type[i];
 }
}
 else{
    	cout<<call<<setw(6);
          for(int i = 0; i<use; i++)
          cout<<"\t"<<left<<setw(4)<<type[i];   	
}
}
	


