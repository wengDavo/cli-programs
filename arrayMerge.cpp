#include<iostream>
using namespace std;

void Merger(int arr1[], int arr2[],int arr3[],int n1, int n2){
	int i = 0, j = 0, k = 0;
	while(i<n1 && j<n2){
		if(arr1[i] < arr2[j])
		arr3[k++] = arr1[i++];
		else
		arr3[k++] = arr2[j++];
	}
	while(i<n1)
	arr3[k++] = arr1[i++];
	while(j<n2)
	arr3[k++] = arr2[j++];
}

int main(){
	int arr1[] = {1,2,3,4};
	int arr2[] = {1,2,3,4};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	int arr3[n1+n2];
	Merger(arr1, arr2,arr3,n1,n2);
	for(int i = 0; i<n1+n2; i++)
	cout<<arr3[i]<<"\t";
}


