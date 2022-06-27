#ifndef CONJUNTO_H
#define CONJUNTO_H

template <class T>  class Conjunto

{
	private:
		unsigned int size;
		int espacioDisponible;
		T* vectorDinamico;
		
		
	public:
		Conjunto(unsigned int size, T primerElemento){
			
			if(size < 1){
				throw "El tamanio debe ser mayor o igual a 1";
			}
			
			this->size = size;
			this->vectorDinamico = new T[this->size];
			
			for(int i=0; i<this->size; i++){
				this->vectorDinamico[i] = NULL;
			}
			
			this->vectorDinamico[0] = primerElemento;
			this->espacioDisponible = this->size - 1;
		}
		
		void agregar(T elemento){
			int aux = 0;
			for(int i=0; i<this->getSize(); i++){
				if(this->vectorDinamico[i] == elemento){
					throw "El elemento ya fue agregado";
				}
				
				if(this->vectorDinamico[i] != 0){
					aux++;
				}
			}
			
			this->vectorDinamico[aux] = elemento;
			
			if(aux == this->getSize()){
				throw "no queda mas espacio";
			}
			this->espacioDisponible = this->getSize() - aux - 1;
		}
		
		int mostrarElementoEnPosicion(int posicion){
		
			return this->vectorDinamico[posicion];
		}
			 
		int getEspacioDisponible(){
			return this->espacioDisponible;
		}
		
		int getSize(){
			return this->size;
		}
		
		void reducirEspacio(){
			this->espacioDisponible--;
		}
		
		virtual ~Conjunto(){
			delete []this->vectorDinamico;
		}

};

#endif
