#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void resolver();
void solucionar();
void proponer();
void generar();
void verificarFC(short F, short C);
bool completado();
void show();

short tabla[9][9]={
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
};

int main(){
	short opc=0;
	system("clear");
	cout<<"\n\n 		Sudoku";
	cout<<"\n\n\n 1) Resolver     (Resolver sudoku por tu propia cuenta)";
	cout<<"\n 2) Solucionar   (Se generar√° un sudoku y se resolver√° autom√°ticamente)";
	cout<<"\n 3) Proponer     (Introducir el sudoku y resolverlo autom√°ticamente)";
	cout<<"\n 4) Salir";
	cout<<"\n\nOpci√≥n: ";
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
		case 4:
		break;
		default:
			system("echo Opci√≥n invalida...");
			system("sleep 1");
			main();
		break;
	}
	return 0;
}

void resolver(){
	short mov=0;
	bool win;
	generar();
	do{
		short ifi=0, icol=0, input=0;
		system("clear");
		show();
		cout<<" En la fila: ";
		cin>>ifi;
		cout<<" Y la columna: ";
		cin>>icol;
		cout<<" Ingresar el valor: ";
		cin>>input;
		ifi-=1; icol-=1;
		if(input>9 or ifi>8 or icol>8){
			system("echo Valor o valores incorrectos... && sleep 1");
		}else{
			tabla[ifi][icol] = input;
			mov++;
			for(short F=0; F<=8; F++){
				for(short C=0; C<=8; C++){
					if(tabla[F][C] != 0){
						verificarFC(F, C);
					}
				}
			}
			win=completado();
		}
	}while(win==false);
	show();
	cout<<"\n\n\n       °°Felicitaciones Sudoku solucionado!!\n          Solucionado en "<<mov<<" movimientos.";
}



void solucionar(){
	
}

void proponer(){
	short input=0;
	for(short F=0; F <=8; F++){
		for(short C=0; C <= 8; C++){
			do{
				cout<<"Introduzca el valor del sudoku en la fila "<<F+1<<" y la columna "<<C+1<<": ";
				cin>>input;
				if(input > 9){cout<<"Se a producido un error, vuelva a introducir el valor...\n";}
			}while(input > 9);
			tabla[F][C]=input;
		}
	}
	system("clear");
	cout<<"El sudoku quedÛ de la siguiente forma: ";
	show();
	short opc=0;
	cout<<"øQue desea hacer?"<<endl;
	cout<<"\n 1- Editar.";
	cout<<"\n 2- Continuar.";
	cout<<"\n 3- Cancelar.";
	cout<<"\nOpcion: ";
	cin>>opc;
	switch(opc){
		case 1:
			bool edit;
			do{
				system("clear");
				short ifi=0, icol=0, input=0;
				show();
				cout<<"Ingrese la fila donde est· el error: ";
				cin>>ifi;
				cout<<"Ingrese la columna donde est· el error: ";
				cin>>icol;
				cout<<"Ingrese el valor correspondiente: ";
				cin>>input;
				ifi-=1;icol-=1;
				if(input<9 or ifi<8 or icol<8){
					tabla[ifi][icol]=input;
				}
				cout<<"øEditar otro valor?\n 0-No\n 1-Si";
				cin>>edit;
			}while(edit == true);
		break;
		case 2:
			//proximamente
		break;
		case 3:
		break;
		default:
			system("echo Opci√≥n invalida...");
			system("sleep 1"); //falta terminar <--------------------------
		break;
	}
}

void generar(){
	srand(time(NULL));
	short cont=0;
	do{
		for(short F=0; F <= 8; F++){
			for(short C=0; C <= 8; C++){
				tabla[F][C]=0;
			}
		}
		short rF=0, aF=0, rC=0, aC=0, X=0;
		for(short I=0; I <= 36; I++){
			do{
				rF=0+rand()%(9-0);
				rC=0+rand()%(9-0);
				X=1+rand()%(9-0);
			}while(rF == aF or rC == aC and tabla[rF][rC] == X);
			aF=rF; aC=rC;
			tabla[rF][rC]=X;
		}
		for(short F=0; F<=8; F++){
			for(short C=0; C<=8; C++){
				if(tabla[F][C] != 0){
					verificarFC(F, C);
				}
			}
		}
		cont=0;
		for(short F=0; F<=8; F++){
			for(short C=0; C<=8; C++){
				if(tabla[F][C] != 0){
					cont++;
				}
			}
		}
	}while(cont<32);
}

void verificarFC(short F, short C){
	short contC=0, contF=0;
	/*Verifica en Filas*/
	for(short Y=0; Y <= 8; Y++){
		if(tabla[F][C] == tabla[F][Y]){
			contF++;
		}
		if(contF >= 2){
			tabla[F][Y] = 0;
			contF=1;
		}
	}
	/*Verifica en Columnas*/
	for(short Y=0; Y <= 8; Y++){
		if(tabla[F][C] == tabla[Y][C]){
			contC++;
		}
		if(contC >= 2){
			tabla[Y][C] = 0;
			contC=1;
		}
	}
}

bool completado(){
	bool win=true;
	for(short F=0; F <= 8; F++){
		for(short C=0; C <= 8; C++){
			if(tabla[F][C] == 0){
				win=false;
			}
		}
	}
	return win;
}

void show(){
	cout<<"\n";
	for(short subT=0; subT<3; subT++){
		for(short F=0; F<3; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=3; F<6; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=6; F<9; F++){cout<<tabla[subT][F]<<" ";}cout<<"\n";
	}cout<<"------+-------+------\n";
	for(short subT=3; subT<6; subT++){
		for(short F=0; F<3; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=3; F<6; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=6; F<9; F++){cout<<tabla[subT][F]<<" ";}cout<<"\n";
	}cout<<"------+-------+------\n";
	for(short subT=6; subT<9; subT++){
		for(short F=0; F<3; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=3; F<6; F++){cout<<tabla[subT][F]<<" ";}cout<<"| ";
		for(short F=6; F<9; F++){cout<<tabla[subT][F]<<" ";}cout<<"\n";
	}
}

/*
short tabla[9][9]={
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
*/
