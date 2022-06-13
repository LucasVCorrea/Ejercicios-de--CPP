#ifndef POINTERARRAY_H
#define POINTERARRAY_H
#include "stdlib.h"

template <class T> class PointerArray{
	private:
		unsigned int arrSize;
		T* pointerArray;
		
	public:
		
		/*
			pre: arrSize must be higher than 1, T should be a pointer
		*/
		PointerArray(unsigned int arrSize, T pointerArray){
			if(!validSize(arrSize)){
				throw "array size is not valid";
			}
			
			this->arrSize = arrSize;
			this->pointerArray = new T[this->arrSize + 1];
			for(int i = 0; i<this->arrSize; i++){
				this->pointerArray[i + 1] = NULL;
			}
		}
				
		/*
			pos: adds a pointer in the last non-null position
		*/
		void addPointer(T pointer){
			if(fullArray()){
				throw "array is already full";
			}
			this->pointerArray[this->lastNonNullPosition() + 1] = pointer;
		}
				
		/*
			returns how many pointers has been added so far
		*/
		unsigned int getPointersAdded(){
			return this->lastNonNullPosition();
		}
				
		/*
			pos: removes the last pointer added
		*/
		void removeAPointer(int position){
			this->pointerArray[position] = NULL;
		}
				
		/*
			pos: used to tell where to place the pointer
		*/
		int defaultPosition(){
			return this->lastNonNullPosition();
		}
		
		/*
			deletes every position in the array, then deletes the array direction
		*/
		virtual ~PointerArray(){
			for(int i = 0; i < this->arrSize; i++){
				delete this->pointerArray[i];
			}
			delete []this->pointerArray;
		}
	private:
		bool validSize(unsigned int sizeToCheck){
			return (sizeToCheck > 0);
		}
		
		int lastNonNullPosition(){
			int lastPosition = this->arrSize;
			for(int i = this->arrSize; i > 0; i--){
				if(this->pointerArray[i] == NULL){
					lastPosition--;
				}
			}
			return lastPosition;
		}
		
		bool fullArray(){
			return (this->lastNonNullPosition() == this->arrSize);
		}
		 
};

#endif
