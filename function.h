#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

/*--------Variabel Bebas--------*/
string username, password, filename;
int highscore; 
/*------------------------------*/

void Menu_Masuk(string username);

void Scene(char X[], int *jumlah){ /*fungsi untuk mengeluarkan scene dan menghitung jumlah bintang*/
	*jumlah = 0;
	int v;

	srand(time(NULL));
	for(int i=0; i<15; i++){
		v = rand() % 6;
		cout << X[v] << " ";
		if(X[v] == '*'){
			*jumlah = *jumlah + 1;		 
		}
	}
}

/*biar bisa berfungsi gotoxy*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Daftar(string username){
	gotoxy(0,1);cout << "Username 	: "; 
	gotoxy(0,2);cout << "Password 	: "; 
	gotoxy(20,1);cin >> username;
	gotoxy(20,2);cin >> password;

	ofstream tulis;
	highscore = 0;
	filename = username+".txt";
	tulis.open(filename.c_str());
	tulis << username << endl;
	tulis << password << endl;
	tulis << highscore;
	tulis.close();
}

void Masuk(string username){
	gotoxy(0,1);cout << "Username 	: "; 
	gotoxy(0,2);cout << "Password 	: "; 
	gotoxy(20,1);cin >> username;
	gotoxy(20,2);cin >> password;
	ifstream baca;
	filename = username+".txt";//membuat file external sesuai username
	baca.open(filename.c_str());
	string tempUsername, tempPassword, tempHighscore;
	baca >> filename;
	tempUsername = filename;
	baca >> filename;
	tempPassword = filename;
	baca >> filename;
	tempHighscore = filename;
	if(username == tempUsername && password == tempPassword){
		cout << "Hallo " << tempUsername << "!, Login Berhasil!" << endl;
		cout << "Username	: ";
		cout << tempUsername << endl;
		cout << "Highscore	: "<< tempHighscore;
		cout << endl;
		cout << "Mari bermain" << endl;
		system("pause");
	}else{
		cout << "Login Gagal!" << endl;
		if(username!=tempUsername){
			cout << "Username ";
		}else if(password!=tempPassword){
			cout << "Password ";
		}
		cout << "Salah!" << endl;
		system("pause");
		system("cls");
		Menu_Masuk(username);
	}
	
	baca.close();
}

void Menu_Masuk(string username){
	int pilihan;

	cout<<"--- REGISTER OR LOGIN ---"<<endl;
	cout<<"[1] Daftar"<<endl;
	cout<<"[0] Masuk"<<endl;
	cout<<endl;
	cout<<"Pilihan : ";
	cin>>pilihan;
	system("CLS");

	if(pilihan == 1){
		Daftar(username);
		system("cls");
	}else if(pilihan == 0){
		Masuk(username);
		system("cls");
	}else{
		cout << "tolong lihat pilihannya" << endl;
	}
}