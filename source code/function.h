void IsiScene(char *X[]){ /*fungsi untuk mengisi array pada setiap indeksnya,
							masih belum bisa dipake, srand(time(NULL)) taruh di int main aja*/
	int v;

	for(int i=0; i<15; i++){
		v = rand() % 6;
		switch(v){
			case 0 : *X[i] = '+';
			break;
			case 1 : *X[i] = '-';
			break;
			case 2 : *X[i] = '/';
			break;
			case 3 : *X[i] = '*';
			break;
			case 4 : *X[i] = '@';
			break;
			case 5 : *X[i] = '$';
			break; 
		}
	}
}

int HitungBintang(char X[]){ /*fungsi untuk menghitung bintang dalam array, array nya berjumlah 15*/
	int sum = 0;

	for(int i=0; i<15; i++){
		if(X[i] == '*'){
			sum = sum + 1;
		}
	}

	return sum;
}