//#include <stdio.h>

//int main(){
//	int j;
//	
//	FILE *fp = fopen("tes.txt", "r");
//	int penyimpanan[100];
//	int i = 0;
//	
//	while(fscanf(fp, "%d", &penyimpanan[i]) != EOF){
//		i++;
//	}
//	fclose(fp);
//	for(j = 0; j < i; j++){
//		printf("%d ", penyimpanan[j]);
//	}
//	return 0;
//}

//int main(){
//	FILE *f = fopen("tes2.txt", "r");
//	char penyimpanan[100];
//	fgets(penyimpanan, sizeof(penyimpanan), f);
//	fclose(f);
//	
//	printf("%s\n", penyimpanan);
//	return 0;
//}


//int main(){
//	FILE *f = fopen("tes3.txt", "w");
//	fprintf(f, "%s", penyimpanan);
//	fclose(f);
//	printf("Sukses\n");
//	return 0;
//}
//
//int main(){
//	FILE *f = fopen("tes.txt", "w");
//	fputs("Hello 123", f);
//	fclose(f);
//	return 0;
//}

//INI KALO KITA GA TAU JUMLAH DATANYA ADA SEBANYAK APA, JDI KITA HITUNG DULU DATANYA ADA BERAPA PAKE I, BARU DATANYA DI PRINT DAN DI LOOPING SAMPE I
//int main(){
//	FILE *tes = fopen("tesdata.in", "r");
//	int penyimpanan[100];
//	int j;
//	int i = 0;
//	while(fscanf(tes, "%d", &penyimpanan[i]) != EOF){
//		i++;
//	}
//	fclose(tes);
//	
//	int total = 0;
//	for(j = 0; j < i; j++){
//		total += penyimpanan[j];
//	}
//	printf("%d\n", total);
//	
//	return 0;
//}

//int main(){
//	FILE *fp;
//	fp = fopen("tesdata.in", "r");
//	int a, b;
//	fscanf(fp, "%d %d", &a, &b);
//	fclose(fp);
//	
//	printf("%d\n", a+b);
//	return 0;
//}

//#include <stdio.h>
//
//void tukar(int *angka1, int *angka2){
//	int temp = *angka1;
//	*angka1 = *angka2;
//	*angka2 = temp;
//}
//int main(){
//	int angka1, angka2;
//	FILE *fp;
//	
//	fp = fopen("testdata.in", "r");
//	if(!fp){
//		return -1;
//	}
//	
//	fscanf(fp, "%d %d", &angka1, &angka2);
//	fclose(fp);
//	
//	tukar(&angka1, &angka2);
//	printf("nilai A = %d\nnilai B = %d\n", angka1, angka2);
//	
//	return 0;
//}

//#include <stdio.h>
//
//void bubbleSort(int penyimpanan[], int n){
//	int i, j;
//	for(i = 0; i < n-1; i++){
//		for(j = 0; j < n-1-i; j++){
//			if(penyimpanan[j] > penyimpanan[j+1]){
//			int temp = penyimpanan[j];
//			penyimpanan[j] = penyimpanan[j+1];
//			penyimpanan[j+1] = temp;
//}
//		}
//	}
//	
//	for(i = 0; i < n; i++){
//		printf("%d", penyimpanan[i]);
//		if(i != n -1){
//			printf(" ");
//		}else{
//			printf("\n");
//		}
//	}
//}
//
//int main(){
//	int n, i;
//	FILE *fp;
//	
//	fp = fopen("testdata.in", "r");
//	if(!fp) return -1;
//	
//	fscanf(fp, "%d", &n);
//	int penyimpanan[n];
//	for(i = 0; i < n; i++){
//		fscanf(fp, "%d", &penyimpanan[i]);
//	}
//	
//	fclose(fp);
//	
//	bubbleSort(penyimpanan, n);
//	
//	return 0;
//}

//#include <stdio.h>
//
//struct data{
//	char nama[200];
//	int umur;
//};
//
//int main(){
//	int tc, i;
//	FILE *fp;
//	if(!fp) return -1;
//	
//	fp = fopen("testdata.in", "r");
//	fscanf(fp, "%d\n", &tc);
//	
//	struct data data[tc];
//	
//	for(i = 0; i < tc; i++){
//		fscanf(fp, "%[^#]#%d\n", data[i].nama, &data[i].umur);
//	}
//	
//	for(i = 0; i < tc; i++){
//		printf("Halo saya %s, umur %d\n", data[i].nama, data[i].umur);
//	}
//	fclose(fp);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//struct data{
//	char nama[100];
//	int umur;
//};
//
//int main(){
//	int tc, i, j;
//
//	scanf("%d", &tc); getchar();
//	
//	struct data data[tc];
//	
//	for(i = 0; i < tc; i++){
//		scanf("%s %d", data[i].nama, &data[i].umur); getchar();
//	}
//	
//	for(i = 0; i < tc-1; i++){
//		for(j = 0; j < tc-i-1; j++){
//			if(strcmp(data[j].nama, data[j+1].nama) == 1){
//				char temp[200];
//				strcpy(temp, data[j].nama);
//				strcpy(data[j].nama, data[j+1].nama);
//				strcpy(data[j+1].nama, temp);
//			}
//		}
//	}
//	
//	for(i = 0; i < tc; i++){
//		printf("%s %d\n", data[i].nama, data[i].umur);
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main(){
//	int tc, i, j, n, k;
//	char dari[200], ke[200];
//	char nama[200];
//	
//	FILE *fp;
//	
//	fp = fopen("testdata.in", "r");
//	fscanf(fp, "%d\n", &tc);
//	for(i = 0; i < tc; i++){
//	
//		fscanf(fp, "%s\n", nama);
//		fscanf(fp, "%d\n", &n);
//		for(j = 0; j < n; j++){
//			fscanf(fp, " %c %c\n", &dari[j], &ke[j]);
//			
//			for(k = 0; k < strlen(nama); k++){
//				if(nama[k] == dari[j]){
//					nama[k] = ke[j];
//				}
//			}
//		}
//	
//	}
//	
//	fclose(fp);
//	
//	int alphabet[26] = {0};
//	for(i = 0; i < strlen(nama); i++){
//		int index = nama[i] - 'A';
//		alphabet[index]++;
//	}
//	
//	for(i = 0; i < 26; i++){
//		if(alphabet[i] > 0){
//			char hasil = i + 'A';
//			printf("%c %d\n", hasil, alphabet[i]);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//struct data{
//	char nama[200];
//	char bunga[200];
//};
//
//int main(){
//	int tc, i, n, j;
//	
//	FILE *fp;
//	
//	fp = fopen("testdata.in", "r");
//	fscanf(fp, "%d\n", &tc);
//	
//	struct data data[tc];
//	for(i = 0; i < tc; i++){
//		fscanf(fp, "%[^#]#%[^\n]\n", data[i].nama, data[i].bunga);
//	}
//	
//	fscanf(fp, "%d\n", &n);
//	char cari[n][200];
//	for(i = 0; i < n; i++){
//		fscanf(fp, "%s\n", cari[i]);
//	}
//	
//	fclose(fp);
//	
//	for(i = 0; i < n; i++){
//		int flag = 0;
//		for(j = 0; j < tc; j++){
//			if(strcmp(cari[i], data[j].nama) == 0){
//				flag = 1;
//				printf("Case #%d: %s\n", i+1, data[j].bunga);
//			}
//		}
//		if(!flag){
//			printf("Case #%d: N/A\n", i+1);
//		}
//	}
//	return 0;
//}



