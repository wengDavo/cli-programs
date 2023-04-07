#include <iostream>
using namespace std;

int getFirstDay(int,int);
void printCalendar(string,int,int);
	
int main()
{
	cout<<"\n--------------------------------------------\n";
	cout<<"\tCALENDAR\n\tby weng";
	cout<<"\n--------------------------------------------\n";
	cout<<"\n--------------------------------------------\n";
	int year, firstDay, febDay;
	  cout<<"ENTER A YEAR - ";
	  cin>>year;
	  bool leapYear = ((year%4==0)&&(year%400==0||year%100!=0));
	  
	  if(leapYear){
	  cout<<year<<"-A LEAP YEAR\nNumber Of Days 366";
	  febDay = 29;
}
      else{
      cout<<year<<"-NOT A LEAP YEAR\nNumber Of Days 365";
      febDay = 28;
  }
     
	  int numDays[] = {31,febDay,31,30,31,30,31,31,30,31,31,31};
	  int monthCode[] = {1,4,4,0,2,5,0,3,6,6,4,6};
	  string monthName[] = {"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMEBER"};
	  
	  int monthTotal = 11;//index start from 0
	  for(int i = 0; i<=monthTotal; i++){
	  	firstDay = getFirstDay(year,monthCode[i]);
	  	printCalendar(monthName[i],numDays[i],firstDay);
	  }
}
	
void printCalendar(string nameMonth,int numDays,int firstDay){	
	cout<<"\n___________________________________________________\n"; 
    cout<<"\n____________________";cout<<nameMonth;cout<<"_______________________\n"<<endl;
    cout<<"SUN\tM0N\tTUE\tWED\tTHU\tFRI\tSAT"<<endl<<endl;
    int x = 0;
    for(x; x<firstDay; x++)
	cout<<"--------";
    for(int i = 1; i<=numDays; i++){
     	printf("%-8d",i);
    	if(++x>6){
				x = 0;
				cout<<endl;
			}   
	}
	cout<<endl;
}
int getFirstDay(int year,int monthcode){
	int yearCode,sum,century;
	//int monthCode = monthcode;
	yearCode = 6;
	century = year%100;
    sum = century/4;
	return(sum+monthcode+yearCode+century)%7;
}
