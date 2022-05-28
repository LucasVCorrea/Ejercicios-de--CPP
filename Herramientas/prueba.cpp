#include <iostream>
#include "BubbleSorting.h"

using namespace std;

int main(){
	
	int array[] = {2,4,3,6,7,1,6,8,10};
	int size = 9;
	
	cout<<"Array ingresado"<<endl;
	for(int i=0; i<size;i++){
		cout<<array[i]<<' ';
	}
	
	BubbleSorting(array,size);
	
	cout<<endl<<"Array ordenado"<<endl;
	for(int i=0; i<size;i++){
		cout<<array[i]<<' ';
	}
	
	return 0;
}
