#ifndef BUBBLESORTING_H
#define BUBBLESORTINdG_H

class BubbleSorting
{

	public:
		
		/*
			pre: el tamaño debe ser mayor o igual a 1
			pos: ordena el arreglo
		*/
		BubbleSorting(int array[], int size){
			if(size < 1){
				throw "El array debe tener tamaño mayor o igual a 1";
			}

			for(int i=0;i < size-1; i++){
				for(int j=size-1; j > i; j--){
					if(array[j] < array[j-1]){
						int temp = array[j];
						array[j] = array[j-1];
						array[j-1] = temp;
					}
				}
			}
		}



};

#endif
