#include<iostream>
using namespace std;

bool check(int,int[]);
double discount(double);

int main(){
	cout<<"\n--------------------------------------------\n";
	cout<<"\tCLI SHOPPING SYSTEM\n\tby weng";
	cout<<"\n--------------------------------------------\n";
	cout<<"\n--------------------------------------------\n";
	int count,item;
	double total = 0.0;
	string nameCustomer;
	int picked [10] = {0};//to mark number of units bought of each item
	string name[] = {"Xbox","Milk","Gmt","Socks","Wigs","Pen","Pack","Shirt","Bread","Key"};
	double cost [] = {900.11,200.23,473.01,400.25,500.67,700.34,350.78,910.01,560.74,333.37};
	cout<<"Name:";
	cin>>nameCustomer;
	cout<<"\nWELCOME "<<nameCustomer<<" TO BUYALL MARKET\n";
	cout<<"--------------------------------------------";
	cout<<"\n[1]Milo\t\t[6]Pen\n[2]Milk\t\t[7]Pack\n[3]Pes\t\t[8]Shirt\n[4]Sock\t\t[9]Bread\n[5]Wigs\t\t[10]KEY"<<endl;
	cout<<"--------------------------------------------\n";
	int loopRuntime = 10;
	while(count<loopRuntime){
//Loop to run only 10 times
		cout<<"["<<count+1<<"]"<<".Select Any Item:";
		cin>>item;
	       	total+=cost[item-1];   //cost increases + value at the array COST throughout the lifecyle of the loop               
	     	picked[item-1] += 1; //picked increases by +1 depending on the number of times number is called
	count++;
}
        cout<<"\n----------\nRECEIPT\n----------\n";
        cout<<"NAME - "<<nameCustomer<<endl<<endl;
        cout<<"-------------------------\n";
        cout<<"SELECTED-ITEMS\tCOST\tUNIT\n";
        for(int i = 0; i<10; i++)
        if ( check(i, picked) )//if the number of units is greater than 1 print it
        cout<<name[i]<<"\t\t"<<cost[i]<<"  *"<<picked[i]<<endl;
        cout<<"--------------------------";
        cout<<"\nSum-Total:\t"<<total<<endl;
        if( discount (total) )
        cout<<"\nDicount[@2.5%]: "<<discount(total);
        else
        cout<<"\nNot Discounted ";
}
bool check(int x, int picked[]){
	return (picked[x]>0)?true:false;//returns true if the value at index[n] is greater than 1 else false
}
double discount(double amount){
	return (amount >= 5000)?amount - (amount*2.5)/100:0.0;//returns the discounted amount @2.5 if amount is greater than 5000
}
