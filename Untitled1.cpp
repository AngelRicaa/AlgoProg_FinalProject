//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_LINE 1024
//
//typedef struct {
//    char *line;
//} Restaurant;
//
///* ================= READ FILE ================= */
//size_t bacaFile(Restaurant **outData) {
//    FILE *fp = fopen("restaurant.csv", "r");
//    if (!fp) {
//        printf("ERROR: file restaurant.csv tidak ditemukan\n");
//        return 0;
//    }
//
//    size_t capacity = 100;
//    size_t count = 0;
//	
//	char buffer[MAX_LINE];
//
//if (fgets(buffer, sizeof(buffer), fp)) {
//    printf("HEADER: %s\n", buffer);
//} else {
//    printf("GAGAL BACA HEADER\n");
//}
//
//
//    Restaurant *data = (Restaurant *)malloc(capacity * sizeof(Restaurant));
//    if (!data) {
//        printf("ERROR: malloc gagal\n");
//        fclose(fp);
//        return 0;
//    }
//
////    char buffer[1024];
//
//    /* skip header */
//    fgets(buffer, sizeof(buffer), fp);
//
//printf("Mulai baca data...\n");
//
//    while (fgets(buffer, sizeof(buffer), fp)) {
//
//        if (count == capacity) {
//            capacity *= 2;
//            Restaurant *tmp =
//                (Restaurant *)realloc(data, capacity * sizeof(Restaurant));
//
//            if (!tmp) {
//                printf("ERROR: realloc gagal\n");
//                break;
//            }
//            data = tmp;
//        }
//
//        data[count].line = (char *)malloc(strlen(buffer) + 1);
//        if (!data[count].line) {
//            printf("ERROR: malloc line gagal\n");
//            break;
//        }
//
//        strcpy(data[count].line, buffer);
//        count++;
//    }
//    
//    printf("DATA: %s\n", buffer);
//
//
//    fclose(fp);
//    *outData = data;
//    return count;
//}
//
///* ================= DISPLAY ================= */
//void displayData(Restaurant *data, size_t total, size_t n) {
//    if (n > total) n = total;
//
//    printf("\n===== DISPLAY DATA =====\n");
//    for (size_t i = 0; i < n; i++) {
//        printf("%s", data[i].line);
//    }
//    printf("========================\n");
//}
//
///* ================= FREE ================= */
//void freeData(Restaurant *data, size_t total) {
//    for (size_t i = 0; i < total; i++) {
//        free(data[i].line);
//    }
//    free(data);
//}
//
///* ================= MAIN ================= */
//int main(void) {
//    Restaurant *data = NULL;
//
//    size_t total = bacaFile(&data);
//    if (total == 0) {
//        printf("Tidak ada data terbaca.\n");
//        return 1;
//    }
//
//    int pilihan;
//    unsigned int temp;
//    size_t baris;
//
//    do {
//        system("cls");
//        printf("What do you want to do?\n");
//        printf("1. Display Data\n");
//        printf("2. Exit\n");
//        printf("Your choice: ");
//        scanf("%d", &pilihan);
//        getchar();
//
//        if (pilihan == 1) {
//            printf("Number of rows: ");
//            scanf("%u", &temp);
//            getchar();
//
//            baris = (size_t)temp;
//            displayData(data, total, baris);
//
//            printf("\nPress Enter to continue...");
//            getchar();
//        }
//
//    } while (pilihan != 2);
//
//    freeData(data, total);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_DATA 7370
//
//struct data{
//	char name[200];
//	char city[200];
//	int cost;
//	char currency[200];
//	int priceRange;
//	double rating;
//	char ratingText[200];
//	int votes;
//};
//
//int main(){
//	struct data data[MAX_DATA];
//	int i;
//	FILE *fp;
//	fp = fopen("restaurant.csv", "r");
//	if(!fp){
//		printf("Eror read file\n");
//		return 1;
//	}
//	
//	int count = 0;
//	while (count < MAX_DATA &&
//       fscanf(fp, " %[^,],%[^,],%d,%[^,],%d,%lf,%[^,],%d",
//              data[count].name,
//              data[count].city,
//              &data[count].cost,
//              data[count].currency,
//              &data[count].priceRange,
//              &data[count].rating,
//              data[count].ratingText,
//              &data[count].votes) == 8) {
//    count++;
//}
//	
////	for(i = 0; i < 73; i++){
////		fscanf(fp, " %[^,],%[^,],%d,%[^,],%d,%lf,%[^,],%d\n", data[i].name, data[i].city, &data[i].cost, 
////		data[i].currency, &data[i].priceRange, &data[i].rating, data[i].ratingText, &data[i].votes);
////	}
//	fclose(fp);
//	
////	for(i = 0; i < 73; i++){
////		printf(" %s ,%s ,%d ,%s ,%d, %.1lf, %s ,%d\n", data[i].name, data[i].city, data[i].cost, 
////		data[i].currency, data[i].priceRange, data[i].rating, data[i].ratingText, data[i].votes);
////	}
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main() {
//    FILE *file = fopen("restaurant.csv", "r");
//
//    if (file == NULL) {
//        perror("Gagal membuka file");
//        return 1;
//    }
//
//    char line[1024];
//
//    // Lewati header
//    fgets(line, sizeof(line), file);
//
//    while (fgets(line, sizeof(line), file)) {
//        char *token;
//
//        // Kolom 1: restaurant name
//        token = strtok(line, ";");
//        if (!token) continue;
//        char restaurant_name[100];
//        strcpy(restaurant_name, token);
//
//        // Kolom 2: city
//        token = strtok(NULL, ";");
//        if (!token) continue;
//        char city[50];
//        strcpy(city, token);
//
//        // Kolom 3: rating
//        token = strtok(NULL, ";");
//        if (!token) continue;
//        float rating = atof(token);
//
//        // Hilangkan newline
//        restaurant_name[strcspn(restaurant_name, "\r\n")] = 0;
//        city[strcspn(city, "\r\n")] = 0;
//
//        printf("Restaurant: %s | City: %s | Rating: %.1f\n",
//               restaurant_name, city, rating);
//    }
//    
//
//    fclose(file);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 7370

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

int bacaFile() {
    FILE *file = fopen("restaurant.csv", "r");
    if (!file) return 0;

    char line[4096];
    int count = 0;

    //fgets(line, sizeof(line), file);
	
	char header[4096];
	fgets(header, sizeof(header), file);

    while (fgets(line, sizeof(line), file) && count < MAX_DATA) {
        char *token;

        token = strtok(line, ";");
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
            if (token[i] == ',') token[i] = '.';
        data[count].rating = atof(token);

        token = strtok(NULL, ";");
        if (!token) continue;
        strcpy(data[count].ratingText, token);

        token = strtok(NULL, ";");
        if (!token) continue;
        data[count].votes = atoi(token);

        data[count].name[strcspn(data[count].name, "\r\n")] = 0;
        data[count].city[strcspn(data[count].city, "\r\n")] = 0;
        data[count].currency[strcspn(data[count].currency, "\r\n")] = 0;
        data[count].ratingText[strcspn(data[count].ratingText, "\r\n")] = 0;

        count++;
    }

    fclose(file);
    return count;
}

void viewData(int baris){
	puts(" ");
	int i;
	printf(
    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
    "Restaurant Name",
    "City",
    "Cost for two",
    "Currency",
    "Price Range",
    "Rating",
    "Rating Text",
    "Votes"
);

	for(i = 0; i < baris; i++){
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

void menuSearch(){
	int i, j, cariInt;
	char kolom[200];
	float cariFloat;
	char cari[200];
	
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
	
	if(strcmp(kolom, "Cost for two") == 0
	|| strcmp(kolom, "Price range") == 0 || strcmp(kolom, "Votes") == 0){
		printf("What data do you want to find? ");
		printf("\033[31m");
		scanf("%d", &cariInt); getchar();
		printf("\033[0m");	
	}else if(strcmp(kolom, "Rating") == 0){
		printf("What data do you want to find? ");
		printf("\033[31m");
		scanf("%f", &cariFloat); getchar();
		printf("\033[0m");
	}else{
		printf("What data do you want to find? ");
		printf("\033[31m");
		scanf("%[^\n]", cari); getchar();
		printf("\033[0m");
	}
	
	puts(" ");
	int pertama = 1;
	int found = 0;
	if(strcmp(kolom, "Restaurant name") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(strcmp(data[i].name, cari) == 0){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}
	
	else if(strcmp(kolom, "City") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(strcmp(data[i].city, cari) == 0){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Cost for two") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(data[i].cost == cariInt){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Currency") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(strcmp(data[i].currency, cari) == 0){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Price range") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(data[i].priceRange == cariInt){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Rating") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(data[i].rating == cariFloat){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Rating text") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(strcmp(data[i].ratingText, cari) == 0){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}  
	
	else if(strcmp(kolom, "Votes") == 0) {
    	for(i = 0; i < MAX_DATA ; i++){
    		if(data[i].votes == cariInt){
    			found = 1;
    			if(pertama){
    				printf(
				    "%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
				    "Restaurant Name",
				    "City",
				    "Cost for two",
				    "Currency",
				    "Price Range",
				    "Rating",
				    "Rating Text",
				    "Votes"
					);
				}
				pertama = 0;
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
		if(!found) printf("\nData not found!\n");
	}
}

int main() {
	int pilihan, baris;

    int totalData = bacaFile();
   
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
				break;
			case 4:
				break;
			case 5:
				break;
		}
		getchar();
	}while(pilihan != 5);
	
    return 0;
}




void menuSearch() {
    char kolom[200];
    char cariStr[200];
    int cariInt;
    float cariFloat;

    // Validasi kolom
    do {
        printf("Choose column: ");
        printf("\033[31m");
        scanf("%[^\n]", kolom); getchar();
        printf("\033[0m");
    } while(strcmp(kolom, "Restaurant name")!=0 && strcmp(kolom,"City")!=0 &&
            strcmp(kolom,"Cost for two")!=0 && strcmp(kolom,"Currency")!=0 &&
            strcmp(kolom,"Price range")!=0 && strcmp(kolom,"Rating")!=0 &&
            strcmp(kolom,"Rating text")!=0 && strcmp(kolom,"Votes")!=0);

    // Input sesuai tipe
    if(strcmp(kolom,"Cost for two")==0 || strcmp(kolom,"Price range")==0 || strcmp(kolom,"Votes")==0) {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%d",&cariInt); getchar();
        printf("\033[0m");
    } else if(strcmp(kolom,"Rating")==0) {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%f",&cariFloat); getchar();
        printf("\033[0m");
    } else {
        printf("What data do you want to find? ");
        printf("\033[31m");
        scanf("%[^\n]",cariStr); getchar();
        printf("\033[0m");
    }

    // Loop dan pencarian
    int found=0;
    for(int i=0; i<MAX_DATA; i++) {
        int match=0;

        if(strcmp(kolom,"Restaurant name")==0 && strcmp(data[i].name,cariStr)==0)
            match=1;
        else if(strcmp(kolom,"City")==0 && strcmp(data[i].city,cariStr)==0)
            match=1;
        else if(strcmp(kolom,"Cost for two")==0 && data[i].cost==cariInt)
            match=1;
        else if(strcmp(kolom,"Currency")==0 && strcmp(data[i].currency,cariStr)==0)
            match=1;
        else if(strcmp(kolom,"Price range")==0 && data[i].priceRange==cariInt)
            match=1;
        else if(strcmp(kolom,"Rating")==0 && data[i].rating==cariFloat)
            match=1;
        else if(strcmp(kolom,"Rating text")==0 && strcmp(data[i].ratingText,cariStr)==0)
            match=1;
        else if(strcmp(kolom,"Votes")==0 && data[i].votes==cariInt)
            match=1;

        if(match) {
            if(!found) {
                printf("%-40s  %-25s  %-12s  %-20s  %-11s  %-8s  %-15s  %-10s\n",
                    "Restaurant Name","City","Cost for two","Currency",
                    "Price Range","Rating","Rating Text","Votes");
            }
            found=1;
            printf("%-40s  %-25s  %-12d  %-20s  %-11d  %-8.1f  %-15s  %-10d\n",
                data[i].name, data[i].city, data[i].cost, data[i].currency,
                data[i].priceRange, data[i].rating, data[i].ratingText, data[i].votes);
        }
    }

    if(!found) printf("\nData not found!\n");
}

