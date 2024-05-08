#include<iostream>
using namespace std;
bool prime(int number){
	for(int i = 2; i<=(number/2); i++){
	   if(number%i == 0){return false;}
}
	return true;
}
int main(){
	int number = 100;
	for(int i = 2; i<number; i++){
		if( prime(i) )
		cout<<i<<" ";
	}
}
