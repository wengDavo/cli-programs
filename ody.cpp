#include<iostream>
#include<string.h>
using namespace std;
	class Account{
		public:
		string name;
		int password;
		double accBalance;
		public:
		Account(string a, int b, double c){
			name  = a;
			password = b;
			accBalance = c;
		}
		public:
		printAccount(string name, int password, double bal){
			cout<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Password: "<<password<<endl;
			cout<<"Balance: $"<<bal<<endl;
			
		}
	};
    void depositGreet(string name);
    void withdrawGreet(string name);
    void balGreet(string name);
	void showBal(string wN,int wP,double wB, string oN,int oP,double oB, string tN,int tP,double tB, string gN,int gP,double gB,string nN,int nP, double nB);
		
int main()
{   
    string nameCheck;
    int deposit,withdraw;
    int newPass = 0000;
	string newName = " ";
	double newBal = 0.0;
    Account newAccount(newName,newPass,newBal);
	Account wengAccount("weng",1234,100.0);
	double wengBal = wengAccount.accBalance;
	string wengName = wengAccount.name;
	int wengPass = wengAccount.password;
	Account odyAccount("Odinaka",1358,1.05);
	double odyBal = odyAccount.accBalance;
	string odyName = odyAccount.name;
	int odyPass = odyAccount.password;
	Account tonyAccount("Anthony",2563,6798.5);
	double tonyBal = tonyAccount.accBalance;
	string tonyName = tonyAccount.name;
	int tonyPass = tonyAccount.password;
	Account goldenAccount("Golden",9343,10.78);
	double goldenBal = goldenAccount.accBalance;
	string goldenName = goldenAccount.name;
	int goldenPass = tonyAccount.password;
	
	cout<<"-------------------------"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"BANK MANAGEMENT SYSTEM"<<endl;
	cout<<"-------------------------"<<endl<<endl;
	cout<<"   ::MAIN MENU::\n";
	bool end = false;
	cout<<"\n1.OPEN NEW ACCOUNT\n2.DEPOSIT\n3.WITHDRAW\n4.BALANCE\n5.ALL ACCOUNTS\n6.EXIT";
	while(!end){
	cout<<"\n\nInput - ";	
	int check;
	cin>>check;
	switch(check){
		case 1:
		    cout<<"------------------"<<endl;
			cout<<"NEW ACCOUNT"<<endl;
			cout<<"Input New Accounts Name:";
			cin>>newName;
			cout<<"Set Password:";
			cin>>newPass;
			cout<<"System Has Been Updated - "<<endl;
			break;
		case 2:
		cout<<"Account Name: ";
		cin>>nameCheck;
		if(nameCheck == wengName){	
		depositGreet(wengName);
		cin>>deposit;
		wengBal+=deposit;
		cout<<"\nCurrent Balance:$"<<wengBal;
	}
		else if(nameCheck == odyName){	
		depositGreet(odyName);
		cin>>deposit;
		odyBal+=deposit;
		cout<<"\nCurrent Balance:$"<<odyBal;
	}
		else if (nameCheck == tonyName)
		{	
	    depositGreet(tonyName);
		cin>>deposit;
		tonyBal+=deposit;
		cout<<"\nCurrent Balance:$"<<tonyBal;
	}
		else if(nameCheck == goldenName)
		{	
		depositGreet(goldenName);
		cin>>deposit;
		goldenBal+=deposit;
		cout<<"\nCurrent Balance:$"<<goldenBal;
	}
	    else if(nameCheck == newName){
	    	depositGreet(newName);
	    	cin>>deposit;
	    	newBal+=deposit;
	    	cout<<"\nCurrent Balance:$"<<newBal;
		}
		else
		cout<<"....ERR....\nAccount Name not Founds in Records";
			break;
		case 3:
		cout<<"Account Name: ";
		cin>>nameCheck;
		if(nameCheck == wengName){	
		withdrawGreet(wengName);
		cin>>withdraw;
		if(withdraw<=wengBal){
		wengBal-=withdraw;
		cout<<"\nCurrent Balance:$"<<wengBal;
	    }
	    else 
	    cout<<"INSUFFICIENT FUNDS !";
	}
		else if(nameCheck == odyName){	
		withdrawGreet(odyName);
		cin>>withdraw;
		odyBal-=withdraw;
	   if(withdraw<=odyBal){
		odyBal-=withdraw;
		cout<<"\nCurrent Balance:$"<<odyBal;
	    }
		else
		cout<<"INSUFFICIENT FUNDS !";
	}
		else if (nameCheck == tonyName)
		{	
	    withdrawGreet(tonyName);
		cin>>withdraw;
		tonyBal-=withdraw;
		if(withdraw<=tonyBal){
		tonyBal-=withdraw;
		cout<<"\nCurrent Balance:$"<<tonyBal;
	    }
		else
		cout<<"INSUFFICIENT FUNDS !";
	}
		else if(nameCheck == goldenName)
		{	
		withdrawGreet(goldenName);
		cin>>withdraw;
		if(withdraw<=goldenBal){
		goldenBal-=withdraw;
		cout<<"\nCurrent Balance:$"<<goldenBal;
	    }
		
		else
		cout<<"INSUFFICIENT FUNDS !";
	}
		else if(nameCheck == newName)
		{	
		withdrawGreet(newName);
		cin>>withdraw;
		if(withdraw<=newBal){
		newBal-=withdraw;
		cout<<"\nCurrent Balance:$"<<newBal;
	    }
		
		else
		cout<<"INSUFFICIENT FUNDS !";
	}
		else
		cout<<"....ERR....\nAccount Name not Founds in Records";
		    break;	
		case 4:
			showBal(wengName,wengPass,wengBal,odyName,odyPass,odyBal,tonyName,tonyPass,tonyBal,goldenName,goldenPass,goldenBal,newName,newPass,newBal);
			break;
		case 5:
			wengAccount.printAccount(wengName,wengPass,wengBal);
	        odyAccount.printAccount(odyName,odyPass,odyBal);
            tonyAccount.printAccount(tonyName,tonyPass,tonyBal);
	        goldenAccount.printAccount(goldenName,goldenPass,goldenBal);
	        newAccount.printAccount(newName,newPass,newBal);
			break;
		case 6:
			end = true;
			cout<<"EXITED";
			break;
		default:
			cout<<">>>ERROR 508<<Input a Valid Number";	    
}
}
}
	void showBal(string wengName,int wengPass,double wengBal, string odyName,int odyPass,double odyBal, string tonyName,int tonyPass,double tonyBal, string goldenName,int goldenPass,double goldenBal, string newName, int newPass,double newBal){
		string nameCheck;
		int pin;
		cout<<"Account Name: ";
		cin>>nameCheck;
		if(nameCheck == wengName){	
		balGreet(wengName);
		cin>>pin;
		if(pin==wengPass)
		cout<<"\nBalance:$"<<wengBal;
		else
		cout<<"Access Denied Wrong Pin";
	}
		else if(nameCheck == odyName){	
	    balGreet(odyName);
		cin>>pin;
		if(pin==odyPass)
		cout<<"\nBalance:$"<<odyBal;
		else
		cout<<"Access Denied Wrong Pin";
	}
		else if(nameCheck == tonyName){	
		balGreet(tonyName);
		cin>>pin;
		if(pin==tonyPass)
		cout<<"\nBalance:$"<<tonyBal;
		else
		cout<<"Access Denied Wrong Pin";
	}
		else if(nameCheck == goldenName){	
		balGreet(goldenName);
		cin>>pin;
		if(pin==goldenPass)
		cout<<"\nBalance:$"<<goldenBal;
		else
		cout<<"Access Denied Wrong Pin";
		}
		else if(nameCheck == newName){
		balGreet(newName);
		cin>>pin;
		if(pin==newPass)
		cout<<"\nBalance:$"<<newBal;
		else
		cout<<"Access Denied Wrong Pin";
		}
		else
		cout<<"....ERR....\nAccount Name not Founds in Records";
	}

  void depositGreet(string name){
  		cout<<"\nMr."<<name<<" welcome to Odys Banking"<<endl;
		cout<<"How Much Would You Like To Deposit:";
  }
  void withdrawGreet(string name){
  		cout<<"\nMr."<<name<<" welcome to Odys Banking"<<endl;
		cout<<"How Much Would You Like To Withdraw:";
  }
  void balGreet(string name){
  		cout<<"\nMr."<<name<<" welcome to Odys Banking"<<endl;
		cout<<"Input your Pin:";
  }
	

