#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_DATA 7370 // Menentukan kapasitas maksimum data restoran

// Struktur data untuk menyimpan informasi restoran
struct Data {
    char name[200];      
    char city[200];      
    int cost;            
    char currency[200];  
    int priceRange;      
    float rating;        
    char ratingText[200];
    int votes;           
};

struct Data data[MAX_DATA]; 
int totalData;             

// Fungsi untuk membaca file CSV dan menyimpan data ke array
int bacaFile() {
    FILE *file = fopen("restaurant.csv", "r"); 
    if (!file){
    	printf("Gagal baca file\n");
    	return 0;
	}

    char line[4096]; 
    int count = 0;   // Menghitung jumlah data yang berhasil dibaca

    char header[4096];
    fgets(header, sizeof(header), file); // Membaca baris header dan diabaikan

    // Membaca setiap baris hingga akhir file atau sampai MAX_DATA
    while (fgets(line, sizeof(line), file) && count < MAX_DATA) {
        char *token;

        token = strtok(line, ";"); // Memisahkan setiap kolom berdasarkan delimiter ;
        if (!token) continue;
        strcpy(data[count].name, token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        strcpy(data[count].city, token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        data[count].cost = atoi(token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        strcpy(data[count].currency, token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        data[count].priceRange = atoi(token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        for (int i = 0; token[i]; i++)
            if (token[i] == ',') token[i] = '.'; // Mengganti koma menjadi titik untuk konversi float
        data[count].rating = atof(token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        strcpy(data[count].ratingText, token); 

        token = strtok(NULL, ";");
        if (!token) continue;
        data[count].votes = atoi(token); 

        // Menghapus karakter newline atau carriage return
        data[count].name[strcspn(data[count].name, "\r\n")] = 0;
        data[count].city[strcspn(data[count].city, "\r\n")] = 0;
        data[count].currency[strcspn(data[count].currency, "\r\n")] = 0;
        data[count].ratingText[strcspn(data[count].ratingText, "\r\n")] = 0;

        count++; 
    }

    fclose(file); 
    return count; 
}

// Fungsi untuk menampilkan data restoran sebanyak baris tertentu
void viewData(int baris){
    puts(" ");
    
    printf("%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
        "Restaurant Name","City","Cost for two","Currency",
        "Price Range","Rating","Rating Text","Votes");

    
    for(int i = 0; i < baris; i++){
        printf("%-40s  %-25s  %-12d  %-20s  %-11d  %-8.1f  %-15s  %-10d\n",
            data[i].name,
            data[i].city,
            data[i].cost,
            data[i].currency,
            data[i].priceRange,
            data[i].rating,
            data[i].ratingText,
            data[i].votes
        );
    }
}

// Fungsi untuk mencari data berdasarkan kolom dan nilai yang dimasukkan
void menuSearch() {
    char kolom[200];
    char cariStr[200];
    int cariInt;
    float cariFloat;

    
    do {
        printf("Choose column: ");
        printf("\033[31m");
        scanf("%[^\n]", kolom); getchar();
        printf("\033[0m");
    } while(strcmp(kolom, "Restaurant name") != 0 &&
            strcmp(kolom, "City") != 0 &&
            strcmp(kolom, "Cost for two") != 0 &&
            strcmp(kolom, "Currency") != 0 &&
            strcmp(kolom, "Price range") != 0 &&
            strcmp(kolom, "Rating") != 0 &&
            strcmp(kolom, "Rating text") != 0 &&
            strcmp(kolom, "Votes") != 0);

    
    if(strcmp(kolom, "Cost for two") == 0 ||
       strcmp(kolom, "Price range") == 0 ||
       strcmp(kolom, "Votes") == 0) {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%d", &cariInt); getchar();
        printf("\033[0m");
    } else if(strcmp(kolom, "Rating") == 0) {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%f", &cariFloat); getchar();
        printf("\033[0m");
    } else {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%[^\n]", cariStr); getchar();
        printf("\033[0m");
    }

    int found = 0; 
    for(int i = 0; i < totalData; i++) {
        int match = 0;

        // Mengecek apakah data sesuai dengan kolom dan nilai yang dicari
        if(strcmp(kolom, "Restaurant name") == 0 && strcmp(data[i].name, cariStr) == 0)
            match = 1;
        else if(strcmp(kolom, "City") == 0 && strcmp(data[i].city, cariStr) == 0)
            match = 1;
        else if(strcmp(kolom, "Cost for two") == 0 && data[i].cost == cariInt)
            match = 1;
        else if(strcmp(kolom, "Currency") == 0 && strcmp(data[i].currency, cariStr) == 0)
            match = 1;
        else if(strcmp(kolom, "Price range") == 0 && data[i].priceRange == cariInt)
            match = 1;
        else if(strcmp(kolom, "Rating") == 0 && fabs(data[i].rating - cariFloat) < 0.0001)
            match = 1;
        else if(strcmp(kolom, "Rating text") == 0 && strcmp(data[i].ratingText, cariStr) == 0)
            match = 1;
        else if(strcmp(kolom, "Votes") == 0 && data[i].votes == cariInt)
            match = 1;

        // Jika data cocok, tampilkan
        if(match) {
            if(!found) { // Jika baru pertama kali ditemukan, tampilkan header
                printf("%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
                    "Restaurant Name","City","Cost for two","Currency",
                    "Price Range","Rating","Rating Text","Votes");
            }
            found = 1;
            printf("%-40s  %-25s  %-12d  %-20s  %-11d  %-8.1f  %-15s  %-10d\n",
                data[i].name, data[i].city, data[i].cost, data[i].currency,
                data[i].priceRange, data[i].rating, data[i].ratingText, data[i].votes);
        }
    }

    // Jika tidak ditemukan, tampilkan pesan
    if(!found) printf("\nData not found!\n");
}

// Array sementara untuk merge sort
struct Data tempData[MAX_DATA];
char tempKey[MAX_DATA][200];

// Fungsi merge untuk ascending
void mergeAsc(char key[][200], int left, int mid, int right){
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right){
        if(strcmp(key[i], key[j]) <= 0){
            tempData[k] = data[i];
            strcpy(tempKey[k], key[i]);
            i++;
        }else{
            tempData[k] = data[j];
            strcpy(tempKey[k], key[j]);
            j++;
        }
        k++;
    }

    while(i <= mid){
        tempData[k] = data[i];
        strcpy(tempKey[k], key[i]);
        i++;
        k++;
    }

    while(j <= right){
        tempData[k] = data[j];
        strcpy(tempKey[k], key[j]);
        j++;
        k++;
    }

    for(int p = left; p <= right; p++){
    data[p] = tempData[p];
    strcpy(key[p], tempKey[p]);
	}
}

// Fungsi merge sort rekursif ascending
void mergeSortAsc(char key[][200], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSortAsc(key, left, mid);
        mergeSortAsc(key, mid + 1, right);
        mergeAsc(key, left, mid, right);
    }
}

// Fungsi merge untuk descending
void mergeDesc(char key[][200], int left, int mid, int right){
    int i = left, j = mid + 1, k = left;

    while(i <= mid && j <= right){
        if(strcmp(key[i], key[j]) >= 0){
            tempData[k] = data[i];
            strcpy(tempKey[k], key[i]);
            i++;
        }else{
            tempData[k] = data[j];
            strcpy(tempKey[k], key[j]);
            j++;
        }
        k++;
    }

    while(i <= mid){
        tempData[k] = data[i];
        strcpy(tempKey[k], key[i]);
        i++;
        k++;
    }

    while(j <= right){
        tempData[k] = data[j];
        strcpy(tempKey[k], key[j]);
        j++;
        k++;
    }

    for(int p = left; p <= right; p++){
    data[p] = tempData[p];
    strcpy(key[p], tempKey[p]);
	}
}

// Fungsi merge sort rekursif descending
void mergeSortDesc(char key[][200], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSortDesc(key, left, mid);
        mergeSortDesc(key, mid + 1, right);
        mergeDesc(key, left, mid, right);
    }
}

// Menu untuk mengurutkan data berdasarkan kolom dan urutan yang dipilih
void menuSort(){
    char kolom[200];
    char ascdesc[200];
    char key[MAX_DATA][200];

    do{
        printf("Choose column: ");
        printf("\033[31m");
        scanf("%[^\n]", kolom); getchar();
        printf("\033[0m");
    }while(strcmp(kolom, "Restaurant name") != 0 &&
           strcmp(kolom, "City") != 0 &&
           strcmp(kolom, "Cost for two") != 0 &&
           strcmp(kolom, "Currency") != 0 &&
           strcmp(kolom, "Price range") != 0 &&
           strcmp(kolom, "Rating") != 0 &&
           strcmp(kolom, "Rating text") != 0 &&
           strcmp(kolom, "Votes") != 0);

    do{
        printf("Sort ascending (asc) or descending (desc) ? ");
        printf("\033[31m");
        scanf("%[^\n]", ascdesc); getchar();
        printf("\033[0m");
    }while(strcmp(ascdesc, "asc") != 0 && strcmp(ascdesc, "desc") != 0);

    // Menyusun key array untuk mempermudah sorting
    for(int i = 0; i < totalData; i++){
        if(strcmp(kolom, "Restaurant name") == 0) strcpy(key[i], data[i].name);
        else if(strcmp(kolom, "City") == 0) strcpy(key[i], data[i].city);
        else if(strcmp(kolom, "Cost for two") == 0) sprintf(key[i], "%010d", data[i].cost);
        else if(strcmp(kolom, "Currency") == 0) strcpy(key[i], data[i].currency);
        else if(strcmp(kolom, "Price range") == 0) sprintf(key[i], "%02d", data[i].priceRange);
        else if(strcmp(kolom, "Rating") == 0) sprintf(key[i], "%06.1f", data[i].rating);
        else if(strcmp(kolom, "Rating text") == 0) strcpy(key[i], data[i].ratingText);
        else if(strcmp(kolom, "Votes") == 0) sprintf(key[i], "%010d", data[i].votes);
    }

    if(strcmp(ascdesc, "asc") == 0)
        mergeSortAsc(key, 0, totalData - 1);
    else
        mergeSortDesc(key, 0, totalData - 1);

    // Menampilkan 10 data teratas setelah sorting
    viewData(10);
}

// Fungsi untuk mengekspor data ke file CSV baru
void menuExport(char namaFile[]){
	FILE *fp;
	strcat(namaFile, ".csv"); 
	
	fp = fopen(namaFile, "w");
	if(!fp){
		printf("Can't export file! Please try again!\n");
		return;
	}
	

	fprintf(fp, "Restaurant Name;City;Cost for two;Currency;Price range;Rating;Rating text;Votes\n");
	

	for(int i = 0; i < totalData; i++){
		fprintf(fp, "%s;%s;%d;%s;%d;%.1f;%s;%d\n",
            data[i].name,
            data[i].city,
            data[i].cost,
            data[i].currency,
            data[i].priceRange,
            data[i].rating,
            data[i].ratingText,
            data[i].votes
        );
	}
    fclose(fp); 
    printf("Data succesfully written to %s\n", namaFile); 
}

// Fungsi utama program
int main() {
    int pilihan, baris;
    char namaFile[200];
    totalData = bacaFile(); 

    do{
        system("cls"); 
        printf("What do you want to do?\n");
        printf("1. Display Data\n2. Search Data\n3. Sort Data\n4. Export Data\n5. Exit\n");
        printf("Your choice: ");
        printf("\033[31m");
        scanf("%d", &pilihan); getchar(); 
        printf("\033[0m");

        switch(pilihan){
            case 1: 
                printf("Number of rows: ");
                printf("\033[31m");
                scanf("%d", &baris); getchar();
                printf("\033[0m");
                if(baris > totalData) baris = totalData; 
                viewData(baris);
                break;
            case 2: 
                menuSearch();
                break;
            case 3: 
                menuSort();
                break;
            case 4:
           		printf("File name: ");
   				printf("\033[31m");
    			scanf("%[^\n]", namaFile); getchar();
    			printf("\033[0m");
            	menuExport(namaFile);
                break;
            case 5: 
            	system("cls");
            	printf("--- Thank you ---\n");
            	printf("Made by Angel Rica - 2902566326\n\nPress enter to continue...");
                break;
        }
        getchar(); 
    }while(pilihan != 5);

    return 0;
}

