#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Master.h"
#include "function.h"
using namespace std;

int main(){
	char scene[6]={'#','@','*','+','/','-'};
	int temp; //variabel untuk sembarang int
	int benar = 0; //jumlah benar
	int hapus; //variabel untuk Del
	int no = 1; //variabel penghitung scene
	int pilihan;
	
	//int pos = 80;

	Queue Q;
	CreateEmpty(&Q);
	
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE); //warna

	/*memutar musik*/
	PlaySound(TEXT("sound\\ls.wav"),NULL,SND_ASYNC|SND_LOOP);
	
	/*tampilan awal*/
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY); //warna
	 
	/*tampilan awal*/
	cout<<"--- GAME BRAIN CHALLENGE ---"<<endl;
	cout<<"[1] Main"<<endl;
	cout<<"[0] Keluar"<<endl;
	cout<<endl;
	cout<<"Pilihan : ";
	cin>>pilihan;
	system("CLS");

	/*jika pilihan 1 berarti main*/
	if(pilihan == 1){

		/*memutar musik*/
		PlaySound(TEXT("sound\\op.wav"),NULL,SND_ASYNC|SND_LOOP);

		/*mengeluarkan 3 scene pertama*/
		for(int i=1; i<=3; i++){
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "scene " << i << endl;
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			Scene(scene, &temp); //mengisi satu scene dengan karakter
			cout << endl;
			Add(&Q,temp);
			
			char b = 219;				
											
			for(int i=0; i<=28; i++){
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);	
				cout<<b;				
				Sleep(150);				
			}
			system("cls");
		}

		/*menanyakan jumlah bintang*/
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Berapa jumlah Bintang di scene " << no << " ?\n";
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cin >> temp;
		system("cls");

		/*jika jawaban benar*/
		while(temp == InfoHead(Q)){

			PlaySound(TEXT("sound\\airhorn.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound
			Sleep(2000); 												//lama waktu musik berjalan
			PlaySound(TEXT("sound\\op.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound

			no = no + 1;	
			benar = benar + 1;	//jumlah jawaban benar bertambah
			Del(&Q,&hapus);	//menghapus node di queue
			system("cls");

			/*mengeluarkan scene baru*/
			SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "scene " << no+2 << endl;
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			Scene(scene, &temp);
			cout << endl;
			Add(&Q,temp);
			
			char b = 219;				
											
			for(int i=0; i<=28; i++){	//waktu tunggu 5 detik
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);		
				cout<<b;				
				Sleep(150);				
			}																		
			system("cls");

			/*menanyakan lagi jumlah bintang*/
			SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << "Berapa jumlah Bintang di scene " << no << " ";
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cin >> temp;
			system("cls");
		}

		/*jika jawaban salah*/
		PlaySound(TEXT("sound\\buzzer.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound
		Sleep(1500);

		/*tampilan game over*/
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<<"---GAME OVER---"<<endl;
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout  << "Jawaban yang benar adalah ";
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<< InfoHead(Q)<<endl;
		PlaySound(TEXT("sound\\over.wav"),NULL,SND_ASYNC|SND_LOOP);	//playsound

		/*menunjukkan jumlah jawaban benar*/
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "jumlah benar = ";
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << benar << endl;
		Sleep(14000);
	}else if(pilihan == 0){
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "Terima Kasih\n";
		PlaySound(TEXT("sound\\y2.wav"),NULL,SND_ASYNC|SND_LOOP);
		system("pause");
	}
	return 0;
}
