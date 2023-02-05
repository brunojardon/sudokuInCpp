#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void resolver();
void solucionar();
void proponer();
void generar();
void verificarFC(short F, short C);
void obtenerBloque(short Ft, short Ct);
void verificarBloque(short Ft, short Ct);
void pasarBloque(short Ft, short Ct);
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

short bloque[3][3]{
	{0,0,0},
	{0,0,0},
	{0,0,0},
};

int main(){
	short opc=0;
	setlocale(LC_ALL, "");
	system("clear");
	cout<<"\n\n 		Sudoku(alpha version v0.0.1)";
	cout<<"\n\n\n 1) Resolver     (Resolver sudoku por tu propia cuenta)";
	cout<<"\n 2) Solucionar   (Se generara un sudoku y se resolver automáticamente) [No disponible]";
	cout<<"\n 3) Proponer     (Introducir el sudoku y resolverlo automáticamente) [No disponible]";
	cout<<"\n 4) Salir";
	cout<<"\n\nOpción: ";
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
			system("echo Opción invalida...");
			system("sleep 1");
			main();
		break;
	}
	return 0;
}

void resolver(){
	short mov=0;
	bool win;
	system("clear");
	cout<<"\n\n\n\n\n	Generando sudoku...";
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
			for(short Ft=0; Ft <= 6; Ft+=3){
				for(short Ct=0; Ct <= 6; Ct+=3){
					obtenerBloque(Ft, Ct);
					verificarBloque(Ft, Ct);
					pasarBloque(Ft, Ct);
				}
			}
			win=completado();
		}
	}while(win==false);
	show();
	cout<<"\n\n\n       ¡¡Felicitaciones Sudoku solucionado!!\n          Solucionado en "<<mov<<" movimientos.";
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
	cout<<"El sudoku quedo de la siguiente forma: ";
	show();
	short opc=0;
	cout<<"¿Que desea hacer?"<<endl;
	cout<<"\n 1- Editar.";
	cout<<"\n 2- Continuar.";
	cout<<"\n 3- Cancelar.";
	cout<<"\nOpción: ";
	cin>>opc;
	switch(opc){
		case 1:
			bool edit;
			do{
				system("clear");
				short ifi=0, icol=0, input=0;
				show();
				cout<<"Ingrese la fila donde esta el error: ";
				cin>>ifi;
				cout<<"Ingrese la columna donde esta el error: ";
				cin>>icol;
				cout<<"Ingrese el valor correspondiente: ";
				cin>>input;
				ifi-=1;icol-=1;
				if(input<9 or ifi<8 or icol<8){
					tabla[ifi][icol]=input;
				}
				cout<<"¿Editar otro valor?\n 0-No\n 1-Si";
				cin>>edit;
			}while(edit == true);
		break;
		case 2:
			//próximamente
		break;
		case 3:
		break;
		default:
			system("echo Opción invalida...");
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
			}while(rF == aF or rC == aC && tabla[rF][rC] == X);
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
		for(short Ft=0; Ft <= 6; Ft+=3){
			for(short Ct=0; Ct <= 6; Ct+=3){
				obtenerBloque(Ft, Ct);
				verificarBloque(Ft, Ct);
				pasarBloque(Ft, Ct);
			}
		}
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

void obtenerBloque(short Ft, short Ct){
	for(short Fb=0; Fb <= 2; Fb++){
		for(short Cb=0; Cb <= 2; Cb++){
			bloque[Fb][Cb]=tabla[Ft][Ct];
			Ct+=1;
		}
		Ft+=1;
		Ct-=3;
	}
}

void verificarBloque(short Ft, short Ct){
	for(short Fb=0; Fb<=2; Fb++){
		for(short Cb=0; Cb<=2; Cb++){
			short cont=0;
		for(short F=0; F<=2; F++){
			for(short C=0; C<=2; C++){
				if(bloque[Fb][Cb]==bloque[F][C] and bloque[Fb][Cb]!=0){
					cont++;
				}
				if(cont>=2){
					bloque[F][C]=0;
					cont=1; 
				}
				}
			}
		}
	}
}

void pasarBloque(short Ft, short Ct){
	for(short Fb=0; Fb<=2; Fb++){
		for(short Cb=0; Cb<=2; Cb++){
			tabla[Ft][Ct]=bloque[Fb][Cb];
			Ct+=1;
		}
		Ft+=1;
		Ct-=3;
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
	for(short subF=0; subF<3; subF++){
		for(short C=0; C<3; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=3; C<6; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=6; C<9; C++){cout<<tabla[subF][C]<<" ";}cout<<"\n";
	}cout<<"------+-------+------\n";
	for(short subF=3; subF<6; subF++){
		for(short C=0; C<3; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=3; C<6; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=6; C<9; C++){cout<<tabla[subF][C]<<" ";}cout<<"\n";
	}cout<<"------+-------+------\n";
	for(short subF=6; subF<9; subF++){
		for(short C=0; C<3; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=3; C<6; C++){cout<<tabla[subF][C]<<" ";}cout<<"| ";
		for(short C=6; C<9; C++){cout<<tabla[subF][C]<<" ";}cout<<"\n";
	}
}

