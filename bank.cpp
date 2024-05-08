#include<iostream>
#include<windows.h>
using namespace std;
int search(string,string[],int);
double withdraw(double[],int,int);
double deposit(double[],int,int);
double transfer(double[],int,int,int);
bool billChecker(int,int);
int main(){
	      string banks[] = {" ","ZENITH","UBA","ACCESS","DIAMOND","KUDA","SKYE","ODIY","FIRST"};
	      char banksColor[][10] = {" ","Color 1","Color 2","Color 3","Color 4","Color 5","Color 6","Color 7","Color 8"};
	      string personName[100] = {"ODINAKA","BLAISE","ALFRED"};
	      int personPin[100] = {1111,2222,3333};
	      double personBal[100] = {12000.4,2009.9,3924.4};
	      cout<<"\n--------------------------------------------\n";
	      cout<<"\n\tAUTOMATED TELLER MACHINE\n";
	      cout<<"\n--------------------------------------------\n\n";
	      cout<<"\n--------------------------------------------\n";
          cout<<"\n\tWELCOME TO ODINAKA'S ATM\n";
          cout<<"\n--------------------------------------------\n";
	      bankMenu:
	      	
	      for(int i = 1; i<9; i++)
          if(i % 2==0)
          cout<<"["<<i<<"]."<<banks[i]<<endl;
          else
          cout<<"["<<i<<"]."<<banks[i]<<"\t\t";
          
          int input = 0,password = 0, amount = 0, valid,take = 0,position = 0;
          string accountName;
          cout<<"\n-----\nINPUT - ";
          cin>>input;
          cout<<"\n-----\n";
          int choose;
          cout<<"[1].LOGIN EXISTING "<<banks[input]<<" ACCOUNT\n[2].TO CREATE NEW "<<banks[input]<<" ACCOUNT\n";
          cout<<"\n-----\nINPUT - ";
          cin>>choose;
          
          if(choose == 1){
          choose1:
          int size = sizeof(personName)/sizeof(personName[0]);
          cout<<"\nINPUT ACCOUNT NAME\n";
          cin>>accountName;
          int index  = search(accountName,personName,size);
          if(index >= 0){
          cout<<"ACCOUNT FOUND\n";
          cout<<"INPUT PIN\n";
          cin>>password;
          bool correctPin = ( password == personPin[index] );
          if(correctPin){
          system(banksColor[input]); // to chnage tghe color of the background based on banks
          cout<<"\n--------\nWELCOME TO \n"<<banks[input]<<" BANK"<<endl<<"----------\n";
          while(take != 7){
          position++;
          cout<<endl;
          string menu[] = {"","WITHDRAW","DEPOSIT","PAY BILLS","TRANSFER","INQUIRE BALANCE","BANK SELECT","QUIT"};
          for(int i = 1; i<8; i++)
          cout<<"["<<i<<"]."<<menu[i]<<endl;
          cout<<"\n-----\nINPUT - ";
          cin>>take;
          cout<<"\n-----\n";
          switch(take){
          	        case 1:{//withdraw
          	        cout<<"\nWITHDRAW\nWITHDRAW AMOUNT - ";
          	        cin>>amount;
          	        if(index >= 0)
          	        valid = withdraw(personBal,index,amount);
          	        if(valid!=0)
          	        cout<<"WITHDRAWAL SUCCESFUL\n";
          	        else
          	        cout<<"INSUFFICIEMT FUNDS\n";
					break;
					  }
					case 2:{//deposit
                    cout<<"\nDEPOSIT\nDEPOSIT AMOUNT - ";
                    cin>>amount;
					if(index >= 0)
          	        deposit(personBal,index,amount);
          	        cout<<"DEPOSIT SUCCESFUL\n";
					break;
					}
					case 3:{//pay bills
					int billIndex,number;
					cout<<"\nPAY BILLS\n";
					string bill[] = {"PAY LOAN","LIGHT BILLS","WATER BILLS","SCHOOL FEES"};
					int billNum[] = {9,6,6,8};
					for(int i = 0; i<4; i++)
					cout<<"["<<i+1<<"]."<<bill[i]<<endl;
					cout<<"\nSelect - ";
					cin>>billIndex;
					   cout<<"INPUT ID FOR "<<bill[billIndex - 1]<<":["<<billNum[billIndex - 1]<<"]"<<endl;
					   cin>>number;
					   if( billChecker ( number, billNum[billIndex - 1]) ){
					   cout<<"\nVALID NUMBER";
					   cout<<"\nAMOUNT TO BE PAID FOR "<<bill[billIndex - 1];
					   cout<<"\n"<<billNum[billIndex-1]*1000<<" NAIRA\n\nPAY - ";
					   cin>>amount;
					   if(index >= 0)
          	           valid = withdraw(personBal,index,amount);
          	           if(valid!=0)
          	           cout<<"\nREMAINING BALANCE TO BE PAID:"<<billNum[billIndex-1]*1000-amount<<endl;
          	           else
          	           cout<<"INSUFFICIEMT FUNDS\n";
          	           
		}
					   else
					   cout<<"INVALID NUMBER\n";
					
					break;
					}
					case 4:{//transfer
					string scanner;
					cout<<"\nTRANSFER\nACCOUNT TO TRANSFER TO\n";
					cin>>scanner;
					int found = search(scanner,personName,size); 
					if( found >= 0 ){
                    cout<<"AMOUNT - ";
                    cin>>amount;
                    if(index >= 0 && found >= 0)
                    valid = transfer(personBal,index,found,amount);
                    if(index == found)
                    cout<<"ERROR CANNOT TRANSFER TO SELF\n";
                    
                     if(valid!=0)
          	           cout<<"TRANSFER SUCCESFUL\nFROM "<<"\nSENDER - "<<personName[index]<<"\nRECEIVER - "<<personName[found]<<endl;
          	           else
          	           cout<<"INSUFFICIEMT FUNDS\n";
					}
					else
					cout<<"ACCOUNT NOT FOUND\n";
					break;
					}
					case 5:{//inquire balance
					cout<<"\n-----\t\t--------\n";
	                cout<<"BANK\t\tBALANCE\n";
	                cout<<"-----\t\t--------\n";
	                cout<<banks[input]<<"\t\t"<<personBal[index]<<endl;
					break;
				}
					case 6:{//bank select
						goto bankMenu;
						break;
					}
		  }
	}
      }   
          else
         cout<<"WRONG PIN\n";        
}
    else
    cout<<"ACCOUNT NOT FOUND\n";
}
   if(choose == 2){
   	cout<<"INPUT YOUR NAME - ";
   	cin>>personName[position+4];
   	cout<<"INPUT YOUR PIN - ";
   	cin>>personPin[position+4];
   	cout<<"\n"<<banks[input]<<" ACCOUNT SUCCESFULLY CREATED\nLOGIN INTO YOUR NEW "<<banks[input]<<" ACCOUNT\n";
   	goto choose1;
}
	
}
int search(string name,string store[],int size){
	 for(int i = 0; i<size; i++)
     if(store[i] == name){return i;}
     return -1;
} 
double withdraw(double bal[],int index,int withdraw){
	if(withdraw > bal[index])
	return 0;
	else
	return bal[index] -= withdraw;
}
double deposit(double bal[],int index,int deposit){
	bal[index] += deposit;
	return bal[index]; 
}
double transfer(double bal[],int index,int found,int amount){
	double check = withdraw(bal,index,amount);
	deposit(bal,found,amount);	
	return check;
}
bool billChecker(int number, int valid){
	int count = 0;
		while(number > 0){
		number = number/10;
		count++;
} 
    return (count==valid)?true:false;
}

