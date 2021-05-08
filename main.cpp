#include <iostream>
#include <cstdlib>
#include <math.h> 
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void pasos(char*,char**,int,int,int,int,int ,int,int);
char** create(int,int);
void free(char**&,int);
char** game(int,int,int);
char* uno(char*,int);
void print2 (char**,int,int);
void print(char*,int);
int menu(){

	
	while(true){
		cout<<"MENU"<<endl;
		cout<<"1. Ejercicio 1 "<<endl<<"2. Ejercicio 2 "<<endl<<"3. Ejercicio 3"<<endl<<"4. Salir"<<endl;
		int valor;
		cin>>valor;
		if(valor > 0&& valor < 5)
			return valor;
		
	}
	
}
int main(int argc, char** argv) {
	int main=0;
	while(main!=4){
		switch(main=menu()){
			case 1:{
			
				int size;
				char*array;
				cout<<"ingrese el size: "<<endl;
				cin>>size;
				array=new char[size];
				for(int i=0;i<size;i++){
					cout<<"ingrese letra por letra: "<<endl;
					cin>>array[i];
				}
				for(int i=0;i<size;i++){
					cout<<array[i]<<" ";
				}
				cout<<endl;
				char* imp=uno(array,size)	;
				print(imp,100);
				delete[]array;
				delete[]imp;
			}
			case 2:{
				int n,m,k;
				cout<<"ingrese cantidad filas: "<<endl;
				cin>>n;
				cout<<"ingrese cantidad columnas: "<<endl;
				cin>>m;
				cout<<"ingrese cantidad obstaculos: "<<endl;
				cin>>k;
				char** matriz=game(n,m,k);
				print2(matriz,n,m);
				free(matriz,n);
				
			}
			case 3:{
				int size;
				int steps;
				cout<<"ingrese cantidad de pasos: "<<endl;
				cin>>steps;
				cout<<"ingrese tamano de array: "<<endl;
				cin>>size;
				char* pasos1=new char[size];
				for(int i=0;i<size;i++){
					cout<<" ingrese paso por paso (char) : " <<endl;
					cin>>pasos1[i];
				}
				int n,m,k;
				cout<<"ingrese cantidad filas: "<<endl;
				cin>>n;
				cout<<"ingrese cantidad columnas: "<<endl;
				cin>>m;
				cout<<"ingrese cantidad obstaculos: "<<endl;
				cin>>k;
				char** matriz=game(n,m,k);
				int filas,columnas;
				cout<<"ingrese fila donde va a empezar: "<<endl;
				cin>>filas;
				cout<<"ingrese columna donde va a empezar: "<<endl;
				cin>>columnas;
				char* array=uno(pasos1,size)	;
				print(array,size);
				cout<<size<<endl;
				pasos(array,matriz,n,m,k,size,filas,columnas,steps);
				delete[]array;
				delete[]pasos1;
				free(matriz,n);
				
				break;
			}
			case 4:{
				cout<<"el programa se acabara "<<endl;
				
				break;
			}
		}//sitwch
	}//while
	return 0;
}
void pasos(char*array,char**matriz,int n,int m,int k,int size,int filas,int columnas,int steps){
	//cout<<size<<endl;
	//cout<<steps;
	print2(matriz,n,m);
	int cont=0;
	char move;
	while(steps>0){
		for(int i=0;i<size;i++){
			for(int i2=0;i2<n;i2++){
				for(int j=0;j<m;j++){
					while(matriz[i2][j]!='#'){
						if(array[i]=='U'){
							if(steps==0){
								break;
							}
							move=186;
						
							matriz[filas][columnas]=move;
							filas-=1;
							columnas=columnas;
							cont++;
							
							cout<<"enter y mire el proximo "<<endl<<flush;
							system ("PAUSE");
							print2(matriz,n,m);
							steps--;
							cout<<"paso: "<<steps<<endl;
							if(matriz[n-n][columnas]==move){
								//cout<<filas<<" "<<columnas<<endl;
								columnas+=1;
								filas=0;
								steps--;
							}
							steps--;
						}
						
						
						if(array[i]=='R'){
							if(steps==0){
								break;
							}
							move=205;
							matriz[filas][columnas]=move;
							filas=filas;
							columnas+=1;
							
							cout<<"enter y mire el proximo "<<endl<<flush;
							system ("PAUSE");
							steps--;
							cout<<"paso: "<<steps<<endl;
							print2(matriz,n,m);
							if(matriz[filas-1][columnas-1]==move){
								columnas=columnas;
								filas
								=n-1;
								steps--;
							}
						}
						
						if(array[i]=='D'){
							if(steps==0){
								break;
							}
							move=186;
							matriz[filas][columnas]=move;
							
							filas+=1;
							columnas=columnas;
							cout<<"enter y mire el proximo "<<endl<<flush;
							system ("PAUSE");
							steps--;
							cout<<"paso: "<<steps<<endl;
							print2(matriz,n,m);
							if(matriz[n-1][columnas]==move){
								filas=filas;
								columnas+=1;
								steps--;
							}
						}
					
						if(array[i]=='L'){
							if(steps==0){
								break;
							}
							move=205;
							matriz[filas][columnas]=move;
							filas=filas;
							columnas-=1;
							cout<<"enter y mire el proximo "<<endl<<flush;
							system ("PAUSE");
							steps--;
							cout<<"paso: "<<steps<<endl;
							print2(matriz,n,m);
						}
						
					}
				}
			}
			
		}
		steps--;
	}
		
		
	
}
void free(char**& matriz,int size){
	if(matriz!=NULL){
		for(int i=0;i<size;i++){
			if(matriz[i]!=NULL){
				delete []matriz[i];
				matriz[i]=NULL;//null
			}
		}
		delete[]matriz;
		matriz=NULL;
	}
}
char* uno(char* array,int size){
	char *ret=new char[1000];
	int cont2=0;
	int value;
	for(int i=0;i<size;i++ ){
		int digit=array[i]- '0';
		//cout<<"DIGITO: "<<digit<<endl;
		if(digit>=1&&digit<=9){
			int cantveces=digit;
			int exp=1;
			int cont=i+1;
			while(array[cont]-'0'<=9&&array[cont]>=1){
				cantveces=cantveces*pow(10,exp);
				cantveces+=array[cont]-'0';
				exp+=1;
				cont+=1;
			}
			i=cont;
			for(int h=0;h<cantveces;h++){
				//cout<<"LETRA: "<<array[i]<<endl;
				ret[cont2]=array[i];
				cont2++;
			}
		}		
	}
	ret[cont2]='\n';
	cout<<endl;
	return ret;
}
char** create(int size,int size2){
	char** retVal=new char*[size];
	for(int i=0;i<size;i++){
		retVal[i]=new char[size2];
	}
	return retVal;
}
char** game(int n,int m,int k){
	char** matriz=create(n,m);
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			matriz[i][j]='-';
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int cont=0;
			while(k>0){	
				srand (time(NULL));
				int n2=1+(rand()%n-1);
				srand (time(NULL));
				int m2=1+(rand()%m-1);
				if(matriz[n2][m2]=='-'){
					matriz[n2][m2]='#';
					k--;
				}
			}
		}
	}
		
	return matriz;
	
}
void print2(char**matriz,int size,int size2){
	for(int i=0;i<size;i++){
		for(int j=0;j<size2;j++){
			cout<<matriz[i][j]<<"   ";
		}
		cout<<endl;
	}
}
void print(char* a,int size){
	for(int i=0;i<size;i++){
		
		cout<<a[i]<<" ";
	}
	cout<<endl;
}