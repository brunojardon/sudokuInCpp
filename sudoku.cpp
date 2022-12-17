#include <iostream>
using namespace std;

void resolver();
void solucionar();
void proponer();
void show();

int tabla[9][9]={
	{5,3,4,6,7,8,9,1,2},
	{6,7,2,1,9,5,3,4,8},
	{1,9,8,3,4,2,5,6,7},
	{8,5,9,7,6,1,4,2,3},
	{4,2,6,8,5,3,7,9,1},
	{7,1,3,9,2,4,8,5,6},
	{9,6,1,5,3,7,2,8,4},
	{2,8,7,4,1,9,6,3,5},
	{3,4,5,2,8,6,1,7,9},
};

int main(){
	int opc=0;
	system("clear");
	cout<<"\n\n 		Sudoku";
	cout<<"\n\n\n 1) Resolver     (Resolver sudoku por tu propia cuenta)";
	cout<<"\n 2) Solucionar   (Se generará un sudoku y se resolverá automaticamente)";
	cout<<"\n 3) Proponer     (Introducir el sudoku y resolverlo automaticamente)";
	cout<<"\nOpcion: ";
	cin>>opc;
	switch(opc){
		case 1:
			resolver();
		break;
		case 2:
			solucionar();
		break;
		case 3:
			proponer();
		break;
		default:
			system("echo Opcion invalida...");
			system("sleep 1");
			main();
		break;
	}
	return 0;
}

void resolver(){
	system("clear");
	show();
}

void solucionar(){
	
}

void proponer(){
	
}

void show(){
	cout<<"\n";
	for(int subT=0; subT<3; subT++){
		for(int f=0; f<3; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=3; f<6; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=6; f<9; f++){cout<<tabla[subT][f]<<" ";}cout<<"\n";
	}cout<<"---------------------\n";
	for(int subT=3; subT<6; subT++){
		for(int f=0; f<3; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=3; f<6; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=6; f<9; f++){cout<<tabla[subT][f]<<" ";}cout<<"\n";
	}cout<<"---------------------\n";
	for(int subT=6; subT<9; subT++){
		for(int f=0; f<3; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=3; f<6; f++){cout<<tabla[subT][f]<<" ";}cout<<"| ";
		for(int f=6; f<9; f++){cout<<tabla[subT][f]<<" ";}cout<<"\n";
	}
}
