#include<iostream>
#include<ctime>
//to import the timne library for the random number generartor
#include<cstdlib>
//to import the random numnber generator RAND
#include<string>

using namespace std;
/////////value of ADMINPIN set to 1234
//register parties before voting, [max 100]

bool check(int);//to check if the regnumber fits the requirement
bool linearSearch(int,int [],int);//basic seraching algorithm
int winnerChecker(int[],int);//checks the array and sees the vcontestant who has the highest number of votes
int regGiver();//gives the user a random REGNUMBER using the ctime and cstdlib library
bool tieFinder(int[],int);//finds if there are any ties within the loop if any number re occurs

int main(){
	cout<<"\n--------------------------------------------\n";
	cout<<"\tVOTING MANAGEMENT SYSTEM\n\tby weng";
	cout<<"\n--------------------------------------------\n";
    int storeRegNumber[1000];//to store the valid regnumber
    int numTimesPicked[1000] = {0};//to store the number of votes each person has
    int lenPicked = sizeof(numTimesPicked)/sizeof(numTimesPicked[0]);
    int regNumber, input, pass = 0, index = 0,adminPin = 1234;
    string party[100] = {""};
    string name[100] = {" "};
    int arraySize = 1;
    bool end = false;
	while(!end){
	cout<<"\n--------------------------------------------";
	cout<<"\n\n[1]REGISTER PARTY\n[2]GET REGISTRATION NUMBER\n[3]TO VOTE\n[4]END VOTING PROCESS AND VIEW RESULTS\n\n";
	cout<<"--------------------------------------------\n";
	cout<<"-----\nINPUT OPTION NUMBER - ";
	cin>>input;
	switch(input){
		//REGISTER PARTY
		case 1:{
			int pin;
            cout<<"\nF O R  A D M I N S\n";
	        cout<<"\n------------------\n|INPUT ADMIN-PIN|\n------------------\n";
	        cout<<"- --"<<endl;
	        cin>>pin;
	        cout<<"- --"<<endl;
	        cout<<"VALID PIN\n\n";
	        if(pin == adminPin){//adminPin set as 1234
	         	cout<<"NUMBER OF NEW PARTIES - ";
	         	cin>>pass;
	         	for(int i = arraySize; i<pass+arraySize; i++){
	         	    cout<<"\n["<<i<<"]"<<endl;
					cout<<"NAME OF NEW PARTY:";
	         	    cin>>party[i];
	         	    cout<<"NAME OF REPRESENTATIVE:";
	         	    cin>>name[i];
				 }
				 cout<<"\nSUCCESFULLY ADDED";
			 }
			 else
			 cout<<"WRONG PIN";
			break;
	}
	       case 2:{
	       	//GET REGISTRATION NUMBER
	        int age;
			string name;
			cout<<"\n-----------\n|INPUT AGE|\n-----------\n";
			cin>>age;
			if(age>=18){
			cout<<"\nLEGIBLE TO VOTE\n";
			cout<<"WHAT IS YOUR NAME: ";
			cin>>name;
			cout<<"MR/MRS."<<name<<"\n-----------------------\n|THIS IS YOUR REG-NUMBER|\n-----------------------\n"<<regGiver();
			//calls the regGiver function which gives the participant a random regNumber
			}
			else
			cout<<"TO YOUNG CANT BE GIVEN REG-NUMBER";
			break;
		   }
			case 3:{
		    //TO VOTE
			cout<<"\n------------------\n|INPUT REG-NUMBER|\n------------------\n";
			cout<<"- - - -"<<endl;
			cin>>regNumber;
			cout<<"- - - - "<<endl;
			int sizeStore = sizeof(storeRegNumber)/sizeof(storeRegNumber[0]);
			bool validRegNumber  = check ( regNumber );
			//checks the number input by the user and passes it to the function which checks if it is a valid reg number
			bool hasVoted = linearSearch(regNumber,storeRegNumber,sizeStore);
			//checks if the user has voted by checking is the current reg number put by the user is in array
			if(hasVoted)
			cout<<"PARTICIPANT: "<<"\""<<regNumber<<"\""<<" You Have Already Voted Dont Try It Again";

		    else if( validRegNumber ){
		    storeRegNumber[index] = regNumber; //stores the valid regNumber in the array
            int select;
			cout<<"VALID REG-NUMBER\nWHO DO YOU WANT TO VOTE FOR\n\n";
            if(arraySize+pass<2) {
                cout << "NO PARTIES HAVE BEEN REGISTERED";//to see if any parties have been registred
                break;
            }
				for(int i = 1; i<arraySize+pass; i++){//to write all the participants name
    	        if(i % 2==0)
    	        cout<<"["<<i<<"]."<<name[i]<<" "<<party[i]<<endl;
    	        else
    	        cout<<"["<<i<<"]."<<name[i]<<" "<<party[i]<<"\t\t";
}
            cout<<"\n\nVOTE- ";
			cin>>select;
			if(select > 0  && select < arraySize+pass){//makes sure input is valid
			numTimesPicked[select - 1] += 1;
			//number of Votes increases by +1 depending on the number of times person is voted for, by adding one at the index @numTimes
	        cout<<"\n------------------\n      PARTICIPANT|\n------------------\n";
			cout<<regNumber<<"\nVOTED FOR\n++++++++++++++++++\n";
			cout<<"NAME:"<<name[select]<<"\nPARTY:"<<party[select]<<"\n------------------\n|T H A N K  Y O U|\n------------------\n";
	    }
	       else
	       cout<<"VOTE FOR A VALID CANDIDATE";
	  }
			else
			cout<<"\n... ERROR INVALID REG-NUMBER\n";
			break;
		}
		case 4:{
			//END PROCESS
		    end = true;
		    int pin;
		    cout<<"\nF O R  A D M I N S\n";
	        cout<<"\n-----------------\nINPUT ADMIN-PIN |\nTO  END PROCESS |\nAND VIEW RESULTS|\n-----------------\n";
	        cout<<"- --"<<endl;
	        cin>>pin;
	        cout<<"- --"<<endl;
	        if( pin == adminPin ){
	        cout<<"CORRECT PIN\n";
	        int sum = 0;
			bool foundTies = tieFinder(numTimesPicked,lenPicked);//function returns true if a number repaest itself
			int winner = winnerChecker(numTimesPicked,lenPicked);//function returns the value with the highest votes
			for(int i:numTimesPicked)//for in range loop to check the total number of votes assigns the value to sum
			sum = sum+i;
		    if(sum > 0){//if sum > 0 means someone has voted
	        cout<<"\n-------\t------\t------------------";
		    cout<<"\n|PARTY|\t|NAME|\t|NUMBER  OF VOTES|\n";
		    cout<<"-------\t------\t------------------\n";
		    for(int i = 0; i < arraySize+pass; i++)//
		    cout<<party[i+1]<<"\t\t"<<name[i+1]<<"\t\t"<<numTimesPicked[i]<<endl;//to print parties and representatives
		    cout<<"\n------------------\nT H E  W I N N E R|\n------------------\n"<<name[winner]<<endl;//shows winner
			cout<<"\n----------------------\nTOTAL NUMBER OF VOTES|\n----------------------\n"<<sum;//shows total num of votes
		    cout<<"\n------------------\nT I E S\n------------------\n";//shows if there were ties
		    if(foundTies)
		    cout<<"THERE WERE TIES"<<endl;
			else
			cout<<"THERE WERE NO TIES"<<endl;
		}
			else// else no person has voted
			cout<<"NOTHING TO SEE HERE ...NO ONE VOTED!";
		    break;
			}
			else
			cout<<"WRONG PIN";
		}
}
index++;//keep track of number of times the loop has run and helps in the position of regNum
}
}

//<--functions-->
bool check(int num){
	int track = num;
    int count = 0;
	while(track > 0){
		track = track/10;
		count++;
		//to check number of times Num can be divided by 10 and the number of times is 6 which presents 6 digits
}
	num = num % 10000;//to get the last 4 digits of 6 numbers 4 zeros
	bool good = ( ((num%4==0)&&(num%400==0||num%100!=0)) && (count == 6) );
	// first verification is to see if the number is divisible by (4) and then (400) and not (100)
	// second verification then checks if the digits is (6)
	return (good)? true : false;//if all Requirements are met then the number is valid
}
bool linearSearch(int regNum,int store[],int size){
	 for(int i = 0; i<size; i++)
     if(store[i] == regNum){return true;}
     return false;
}
int winnerChecker(int numTimesPicked[], int len){
	int max = 0,index = 0;
    for(int i = 0; i<len; i++){//check the particular index who has the highest value and return the index as the winner
	if(numTimesPicked[i] > max){
	max = numTimesPicked[i];
	index = i;
}
}
	return index+1;
}

int regGiver(){
	srand(time(0));//gets the time
	int validNum;
    for(int i = 1; i<50; i++){
    int num = (rand()%10000)+(i*10000);//generates the random number
    if( check(num) )//passes the number to the function check and sees if the number is valid
    validNum = num;
	}
	return validNum;
}

bool tieFinder(int array[],int size){
	for(int i = 0; i<size; i++){
		for(int j = i+1; j<size; j++)
		if(array[i] == array[j] && array[i] != 0 && array[j] != 0){return true;}
	}
	//using nested loop it checks if a particular value other than 0 repeats itself, if true there is a tie
	return false;
}


