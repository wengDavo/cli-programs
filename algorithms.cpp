#include<iostream>
using namespace std;
int linearSearch(int array[], int size, int number){
	for(int i = 0; i<size; i++){
		if(array[i] == number){
			return i;
		}
	}
	return -1;
}
int binarySearch(int array[], int size, int number){
	int low = size - size;
	int high = size;
	while(low <= high){
		int mid = (low+high)/2;
		if(array[mid] > number)
		high = mid -1;
		else if(array[mid] < number)
		low = mid + 1;
		else 
		return mid;
	}
	return -1;
}
void bubbleSort(int array[], int size){
	bool swapped = true;
	while(swapped){
		swapped = false;
		for(int i = 0; i<size-1; i++){
			if(array[i] > array[i+1]){
				swapped = true;
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
		}
	}
}
void selectionSort(int array[], int size){
	for(int i = 0; i<size; i++){
		int min = i; 
		for(int j = i; j<size; j++){
			if(array[min] > array[j]){
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}
int main(){
    int array[] = {1,4,7,9,2,5};
	selectionSort(array,6);
	for(int i = 0; i<6; i++)
	cout<<array[i]<<endl;	
}
