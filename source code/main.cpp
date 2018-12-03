#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Master.h"
#include "function.h"
using namespace std;

int main(){
	char scene[15];
	int temp; //variabel untuk sembarang int
	int benar = 0; //jumlah benar
	int hapus; //variabel untuk Del
	int no = 1; //variabel penghitung scene

	Queue Q;
	CreateEmpty(&Q);

	for(int i=1; i<=3; i++){
		cout << "scene " << i << endl;
		IsiScene(scene);
		Output_Scene(scene);
		cout << endl;
		temp = HitungBintang(scene);
		Add(&Q,temp);
		Sleep(5000);
		system("cls");
	}
	cout << "Berapa jumlah Bintang di scene " << no << " ";
	cin >> temp;
	while(temp == InfoHead(Q)){
		no = no + 1;
		benar = benar + 1;
		Del(&Q,&hapus);
		system("cls");
		cout << "scene " << no+2 << endl;
		IsiScene(scene);
		Output_Scene(scene);
		cout << endl;
		temp = HitungBintang(scene);
		Add(&Q,temp);
		Sleep(5000);
		system("cls");
		cout << "Berapa jumlah Bintang di scene " << no << " ";
		cin >> temp;
	}

	cout << "jumlah benar : " << benar;
	return 0;
}