#include <iostream>
#include <stdlib.h>
#include <math.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
char* uno(char*,int);
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
				
			}
			case 3:{
				
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
char* uno(char* array,int size){
	char *ret=new char[1000];
	int cont2=0;
	int value;
	for(int i=0;i<size;i++ ){
		int digit=array[i]- '0';
		cout<<"DIGITO: "<<digit<<endl;
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
				cout<<"LETRA: "<<array[i]<<endl;
				ret[cont2]=array[i];
				cont2++;
			}
		}		
	}
	ret[cont2]='\n';
	cout<<endl;
	return ret;
}
void print(char* a,int size){
	for(int i=0;i<size;i++){
		
		cout<<a[i]<<" ";
	}
	cout<<endl;
}