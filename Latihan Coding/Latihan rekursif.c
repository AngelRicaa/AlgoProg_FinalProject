//#include <stdio.h>
//
//void cetakBalik(char kata[]){
//	if(*kata != '\0'){
//		cetakBalik(kata + 1);
//		printf("%c", *kata);
//	}
//}
//
//int main(){
//	cetakBalik("halo");
//	return 0;
//}

#include <stdio.h>

void cetakBalik(char kata[], int i){
	if(kata[i] == '\0'){
		return;
	}else{
		cetakBalik(kata, i+1);
		printf("%c", kata[i]);
	}
}

int main(){
	cetakBalik("heybroh", 0);
	return 0;
}

//#include <stdio.h>
//
//int hitung(int x){
//	if(x == 0){
//		return 5;
//	}	
//	else{
//		return hitung(x-1) + 2;
//	}
//}
//
//int main(){
//	int x;
//	
//	scanf("%d", &x); getchar();
//	int result = hitung(x);
//	printf("%d\n", result);
//	return 0;
//}

//#include <stdio.h>
//
//int fungsi(int n, int a[], int *total){
//	if(n == 0){
//		return *total;
//	}
//	else{
//		*total += (*a);
//		return fungsi(n -1, a + 1, total);
//	}
//}
//
//int main(){
//	int a[] = {2, 4, 6, 8};
//	int total = 0;
//	int n = sizeof(a)/sizeof(a[0]);
//	
//	int result = fungsi(n, a, &total);
//	printf("%d", result);
//	return 0;
//}

// INI MATERI HEAD AND TAIL RECURSION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//JADI INTINYA DIA AKAN TERUS PANGGIL FUNGSINYA BUAT DAPETIN NILAI DI INDEKS ITU, TERUS DISIMPAN KE VARIABEL HASIL, STELAH DIPANGGIL, DIA AKAN BALIK LAGI LALU BANMDINGIN 
//#include <stdio.h>
//
//int maksimum(int arr[], int index, int n){
//	if(index == n-1){
//		return arr[index];
//	}
//	
//	int hasil = maksimum(arr, index+1, n);
//	return (arr[index] > hasil)? arr[index] : hasil;
//}
//
//int main(){
//	int arr[] = {2, 5, 6, 7,11, 13, 4, 9, 21, 8, 3};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	
//	int result = maksimum(arr, 0, n);
//	printf("%d\n", result);
//	return 0;
//}
//===============================================================================================
//#include <stdio.h>
//
//int cariTarget(int arr[], int index, int n, int target){
//	if(index == n){
//		return 0;
//	}
//
//	if(arr[index] == target){
//		return 1;
//	}
//	
//	cariTarget(arr, index+1, n, target);
//}
//
//int main(){
//	int arr[] = {2, 5, 6, 7,11, 13, 4, 9, 21, 8, 3};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	int target = 18;
//	
//	int result = cariTarget(arr, 0, n, target);
//	
//	if(result){
//		printf("ada");
//	}else{
//		printf("ga");
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int cari(int arr[], int left, int right, int target){
//	if(left > right){
//		return 0;
//	}
//
//	int mid = (left + right)/2;
//	
//	if(arr[mid] == target){
//		return 1;
//	}
//	
//	int carileft = cari(arr, left, mid-1, target);
//	int cariright = cari(arr, mid+1, right, target);
//	
//	return (carileft == 1 || cariright == 1)? 1:0;
//}
//
//int main(){
//	int arr[] = {3, 6, 5, 1};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	int target = 4;
//	
//	int result = cari(arr, 0, n-1, target);
//	printf("%d\n", result);
//	return 0;
//}

//===================================== MATERI DIVIDE AND CONQUER ==========================================================
// INI TEKNIKNYA BEDA, INI TUH DIA BAGI TERUS SUPAYA DAPAT NILAI MAXNYA, namanya divide and conquer ===============================
//int findMaxDC(int arr[], int left, int right) {
//    if (left == right) {
//        return arr[left]; // hanya satu elemen
//    }
//
//    int mid = (left + right) / 2;
//
//    int maxLeft  = findMaxDC(arr, left, mid);
//    int maxRight = findMaxDC(arr, mid + 1, right);
//
//    return (maxLeft > maxRight) ? maxLeft : maxRight;
//}

// CARA CERDAS NIH, INI KITA JUMLAHIN DLU, BARU REKURSIF TERUS TERUSAN KAYAK PRINT DARI DEPAN ======================================================
//int length(char str[], int index) {
//    if (str[index] == '\0') {
//        return 0;
//    }
//    return 1 + length(str, index + 1);
//}

//#include <stdio.h>
//
//int jumlah(int arr[], int index, int n){
//	if(index == n){
//		return 0;
//	}
//	
//	int current = (arr[index] % 2 == 0)? arr[index]:0;
//	return current + jumlah(arr, index+1, n);
//}
//
//int main(){
//	int arr[] = {2, 5, 6, 7,11, 13, 4, 9, 21, 8, 3};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	
//	int result = jumlah(arr, 0, n);
//	printf("%d\n", result);
//	return 0;
//}

//#include <stdio.h>
//
//int countFreq(int arr[], int left, int right, int value) {
//    int count = 0;
//    for (int i = left; i <= right; i++) {
//        if (arr[i] == value) count++;
//    }
//    return count;
//}
//
//int majorityElement(int arr[], int left, int right) {
//    // base case: 1 elemen ? otomatis mayoritas di segmen ini
//    if (left == right) {
//        return arr[left];
//    }
//
//    int mid = (left + right) / 2;
//
//    int leftMajor = majorityElement(arr, left, mid);
//    int rightMajor = majorityElement(arr, mid + 1, right);
//
//    // jika kedua sisi sama ? ini otomatis mayoritas
//    if (leftMajor == rightMajor) {
//        return leftMajor;
//    }
//
//    // hitung frekuensi kedua kandidat
//    int leftCount = countFreq(arr, left, right, leftMajor);
//    int rightCount = countFreq(arr, left, right, rightMajor);
//
//    int length = right - left + 1;
//
//    if (leftCount > length / 2) {
//        return leftMajor;
//    } 
//    if (rightCount > length / 2) {
//        return rightMajor;
//    }
//
//    return -1; // tidak ada mayoritas
//}
//
//int main() {
//    int arr[] = {2, 2, 1, 1, 1, 2, 2};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    int result = majorityElement(arr, 0, n - 1);
//    printf("Majority element: %d\n", result);
//
//    return 0;
//}
//
//==========================================================================================

//#include <stdio.h>
//
//int total = 0;
//
//void jumlah(int n, int arr[], int node){
//	if (node >= n) return;
//	
//	int kiri = 2*node + 1;
//	int kanan = 2*node + 2;
//	
//	if(kiri < n || kanan < n){
//		printf("%d\n", arr[node]);
//	}
//	
//	jumlah(n, arr, kiri);
//	jumlah(n, arr, kanan);
//}
//
//int main(){
//	int arr[] = {7, 3, 9, 1, 5, 8};
//	int n = 6;
//
//	
//	jumlah(n, arr, 0);
//
//	return 0;
//}

// MASUK MATERI DFS SEDERHANA

//#include <stdio.h>
//
//int hubungan[100][100];
//int visited[100];
//int node, edge;
//int total = 0;
//
//int dfs(int u){
//	int i;
//	visited[u] = 1;
//	
//	for(i = 1; i <= node; i++){
//		if(hubungan[u][i] == 1 && !visited[i]){
//			dfs(i);
//		}
//	}
//	
//	total++;
//	return total;
//}
//
//int main() {
//   	int i, j, u, v;
//   	
//   	scanf("%d %d", &node, &edge); getchar();
//   	for(i = 0; i < edge; i++){
//   		scanf("%d %d", &u, &v); getchar();
//   		hubungan[u][v] = 1;
//   		hubungan[v][u] = 1;
//	}
//	
//	for(i = 1; i <= node; i++){
//		for(j = 0; j < edge; j++){
//			if(i == u[j] && !visited[i]) dfs(i);
//	}
//	}
//	printf("%d\n", total);
//    return 0;
//}

//#include <stdio.h>
//
//int elemen[100][100];
//int visited[100][100];
//
//void dfs( int i, int j){
//	if(i < 0 || j < 0 || i > 3 || j > 3){
//		return;
//	}
//	if(elemen[i][j] == 0 || visited[i][j]){
//		return;
//	}
//	visited[i][j] = 1;
//	
//	dfs(i+1, j);
//	dfs(i-1, j);
//	dfs(i, j+1);
//	dfs(i, j-1);
//}
//
//int main(){
//	int i, j, regionBaris, regionKolom;
//	int total = 0;
//	
//	for(i = 0; i < 4; i++){
//		for(j = 0; j < 4; j++){
//			scanf("%d", &elemen[i][j]); getchar();
//		}
//	}
//	
//	
//	for(i = 0; i < 4; i++){
//		for(j = 0; j < 4; j++){
//			if(elemen[i][j] == 1 && !visited[i][j]){
//				dfs( i , j);
//				total++;
//			}
//		}
//	}
//	printf("%d\n", total);
//	return 0;
//}

//#include <stdio.h>
//
//int baris, kolom;
//char elemen[100][100];
//int visited[100][100];
//int barisAwal, kolomAwal;
//int found = 0;
//void ada(int i, int j){
//	if(i < 0 || j < 0 || i >= baris || j >= kolom){
//		return;
//	}
//	if(elemen[i][j] == '#'){
//		return;
//	}
//	if(elemen[i][j] == 'G'){
//		found++;
//		return;
//	}
//	if(visited[i][j]){
//		return;
//	}
//	
//
//	visited[i][j] = 1;
//	
//	ada(i+1, j);
//	ada(i-1, j);
//	ada(i, j+1);
//	ada(i, j-1);
//	
//	visited[i][j] = 0;
//	return;
//}
//
//int main(){
//	int i, j;
//	
//	scanf("%d %d", &baris, &kolom); getchar();
//	for(i = 0; i < baris; i++){
//		for(j = 0; j < kolom; j++){
//			scanf(" %c", &elemen[i][j]);
//			if(elemen[i][j] == 'S'){
//				barisAwal = i;
//				kolomAwal = j;
//			}
//		}
//	}
//	
//	ada(barisAwal, kolomAwal);
//	printf("%d\n", found);
//	return 0;
//}

//#include <stdio.h>
//
//void fiboString(char hasil[], char s0, char s1, int n){
//	if(n == 0) {
//		hasil[0] = s0;
//		hasil[1] = '\0';
//		return;
//	}
//	if(n == 1){
//		hasil[0] = s1;
//		hasil[1] = '\0';
//		return;
//		
//	}
//	
//	else{
//		char a[10000], b[10000];
//		fiboString(a, s0, s1, n-1);
//		fiboString(b, s0, s1, n-2);
//		
//		strcpy(hasil, a);
//		strcat(hasil, b);
//	}
//}
//
//int main(){
//	int t, tc, i, n;
//	char s0, s1;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t < tc; t++){
//		scanf("%d %c %c", &n, &s0, &s1); getchar();
//		
//		printf("Case #%d: ", t+1);
//		char hasil[150];
//		fiboString(hasil, s0, s1, n);
//		printf("%s\n", hasil);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>

// BISA JKUGA 1 - GILIRAN ITU CARA PALING MUDQAHNYA ================================
//void menang(int *giliran, int n){
//	if(n == 1){
//		return;
//	}
//	else{
//		if(n % 2 == 0){
//			*giliran = (*giliran == 1) ? 0 : 1;
//			menang(giliran, n/2);
//		}
//		else{
//			*giliran = (*giliran == 1) ? 0 : 1;
//			menang(giliran, n*3+1);
//		}
//	}
//}
//
//int main(){
//	int t, tc, n;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t< tc; t++){
//		scanf("%d", &n); getchar();
//		char pemenang[100];
//		int giliran = 1;
//		menang(&giliran, n);
//		
//		if(giliran){
//			strcpy(pemenang, "Lili");
//		}
//		else{
//			strcpy(pemenang, "Jojo");
//		}
//		printf("Case #%d: %s\n", t+1, pemenang);
//	}
//	return 0;
//}
//

//#include <stdio.h>
//
//char peta[100][100];
//int baris, kolom, i, j;
//int visited[100][100];
//
//void makanan(int *makan, int i, int j){
//	if(i < 0 || j < 0 || i >= baris || j >= kolom){
//		return;
//	}
//	if(visited[i][j] || peta[i][j] == '#'){
//		return;
//	}
//	
//	visited[i][j] = 1;
//	
//	if(peta[i][j] == '*'){
//		(*makan)++;
//	}
//	
//	makanan(makan, i+1, j);
//	makanan(makan, i-1, j);
//	makanan(makan, i, j+1);
//	makanan(makan, i, j-1);
//}
//
//int main(){
//	int t, tc;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t < tc; t++){
//		
//		for(i = 0 ; i < 100; i++){
//			for(j = 0; j < 100; j++){
//				visited[i][j] = 0;
//			}
//		}
//		int barisAwal = -1, kolomAwal = -1;
//		scanf("%d %d", &baris, &kolom); getchar();
//		for(i = 0; i < baris; i++){
//			for(j = 0; j < kolom; j++){
//				scanf(" %c", &peta[i][j]);
//				if(peta[i][j] == 'P'){
//				barisAwal = i;
//				kolomAwal = j;
//				}
//			}
//		}
//		int makan = 0;
//		makanan(&makan, barisAwal, kolomAwal);
//		printf("%d\n", makan);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//#define SIZE 8
//
//int belakang = 0;
//int i, j;
//int depan = 0;
//int antrianBaris[100], antrianKolom[100];
//char papan[SIZE][SIZE];
//int visited[SIZE][SIZE] = {0};
//int gerakBaris[8] = {+1, +1, -1, -1, +2, +2, -2, -2};
//int gerakKolom[8] = {+2, -2, +2, -2, -1, +1, -1, +1};
//int barishitamsekarang, kolomhitamsekarang, barishitambaru, kolomhitambaru;
//int barisputihsekarang, kolomputihsekarang, barisputihbaru, kolomputihbaru;
//
//int validgak(int barishitambaru, int kolomhitambaru){
//	if(barishitambaru >= 0 && kolomhitambaru >= 0 && barishitambaru < SIZE && kolomhitambaru < SIZE){
//		return 1;
//	}
//	return 0;
//}
//
//int bisagak(int n, int kolomhitam, int barishitam, int kolomputih, int barisputih){
//	int i;
//	
//	for(int i = 0; i < SIZE; i++){
//        for(int j = 0; j < SIZE; j++){
//            visited[i][j] = 0;
//            langkah[i][j] = 0;
//        }
//    }
//    
//	antrianBaris[belakang] = barishitam;
//	antrianKolom[belakang] = kolomhitam;
//	belakang++;
//	visited[barishitam][kolomhitam] = 1;
//	
//	while(depan < belakang){
//		barishitamsekarang = antrianBaris[depan];
//		kolomhitamsekarang = antrianKolom[depan];
//		depan++;
//		
//		if(barishitamsekarang == barisputihsekarang && kolomhitamsekarang == kolomputihsekarang){
//			return 1;
//		}
//		
//		if(langkah[barishitamsekarang][kolomhitamsekarang] == n) continue;
//		
//		for(i = 0; i < 8; i++){
//			barishitambaru = barishitamsekarang + gerakBaris[i];
//			kolomhitambaru = kolomhitamsekarang + gerakKolom[i];
//			
//			if(!visited[barishitambaru][kolomhitambaru] && validgak(barishitambaru, kolomhitambaru)){
//				visited[barishitambaru][kolomhitambaru] = 1;
//				antrianBaris[belakang] = barishitambaru;
//				antrianKolom[belakang] = kolomhitambaru;
//				belakang++;
//			}
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int t, tc, n;
//	char kolomputih, kolomhitam;
//	int barisputih, barishitam;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0 ; t< tc; t++){
//		belakang = 0;
//		depan = 0;
//		
//		for(i = 0; i < 100; i++){
//			antrianBaris[i] = 0;
//			antrianKolom[i] = 0;
//		}
//		
//		scanf("%d", &n); getchar();
//		scanf("%c%d %c%d", &kolomhitam, &barishitam, &kolomputih, &barisputih); getchar();
//		
//		kolomhitam = kolomhitam - 'A';
//		barishitam = barishitam - 1;
//		kolomputih = kolomputih - 'A';
//		barisputih = barisputih - 1;
//		
//		int result = bisagak(n, kolomhitam, barishitam, kolomputih, barisputih);
//		
//		if(result){
//			printf("Case #%d: YES\n", t+1);
//		}else{
//			printf("Case #%d: NO\n", t+1);
//		}
//	}
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <stdio.h>
//
//#define SIZE 8
//
//int belakang = 0, depan = 0;
//int antrianBaris[100], antrianKolom[100];
//int visitedHitam[SIZE][SIZE], visitedPutih[SIZE][SIZE];
//int langkahHitam[SIZE][SIZE], langkahPutih[SIZE][SIZE];
//
//int gerakBaris[8] = {+1, +1, -1, -1, +2, +2, -2, -2};
//int gerakKolom[8] = {+2, -2, +2, -2, -1, +1, -1, +1};
//
//int validgak(int baris, int kolom){
//    return (baris >= 0 && kolom >= 0 && baris < SIZE && kolom < SIZE);
//}
//
//void BFS(int n, int startRow, int startCol, int visited[][SIZE], int langkah[][SIZE]){
//    belakang = depan = 0;
//
//    for(int i = 0; i < SIZE; i++){
//        for(int j = 0; j < SIZE; j++){
//            visited[i][j] = 0;
//            langkah[i][j] = 0;
//        }
//    }
//
//    antrianBaris[belakang] = startRow;
//    antrianKolom[belakang] = startCol;
//    belakang++;
//    visited[startRow][startCol] = 1;
//
//    while(depan < belakang){
//        int row = antrianBaris[depan];
//        int col = antrianKolom[depan];
//        depan++;
//
//        if(langkah[row][col] == n) continue;
//
//        for(int i = 0; i < 8; i++){
//            int rowBaru = row + gerakBaris[i];
//            int colBaru = col + gerakKolom[i];
//
//            if(validgak(rowBaru, colBaru) && !visited[rowBaru][colBaru]){
//                visited[rowBaru][colBaru] = 1;
//                langkah[rowBaru][colBaru] = langkah[row][col] + 1;
//                antrianBaris[belakang] = rowBaru;
//                antrianKolom[belakang] = colBaru;
//                belakang++;
//            }
//        }
//    }
//}
//
//int bisagak(int n, int kolomhitam, int barishitam, int kolomputih, int barisputih){
//    BFS(n, barishitam, kolomhitam, visitedHitam, langkahHitam);
//    BFS(n, barisputih, kolomputih, visitedPutih, langkahPutih);
//
//    // cek apakah ada posisi papan yg visited oleh keduanya
//    for(int i = 0; i < SIZE; i++){
//        for(int j = 0; j < SIZE; j++){
//            if(visitedHitam[i][j] && visitedPutih[i][j]){
//                return 1; // keduanya bisa sampai posisi ini
//            }
//        }
//    }
//    return 0; // tidak ada titik yang bisa dicapai keduanya
//}
//
//int main(){
//    int t, tc, n;
//    char kolomputih, kolomhitam;
//    int barisputih, barishitam;
//
//    scanf("%d", &tc); getchar();
//    for(t = 0; t < tc; t++){
//        scanf("%d", &n); getchar();
//        scanf("%c%d %c%d", &kolomhitam, &barishitam, &kolomputih, &barisputih); getchar();
//
//        kolomhitam -= 'A';
//        kolomputih -= 'A';
//        barishitam--;
//        barisputih--;
//
//        int result = bisagak(n, kolomhitam, barishitam, kolomputih, barisputih);
//
//        printf("Case #%d: %s\n", t+1, result ? "YES" : "NO");
//    }
//    return 0;
//}

//==============================================================================================================================================================
//#include <stdio.h>
//
//#define SIZE 8
//
//int depan = 0, belakang = 0;
//char papan[SIZE][SIZE];
//int visited[SIZE][SIZE] = {0};
//int gerakBaris[8] = {-1, +1, -1, +1, -2, +2, -2, +2};
//int gerakKolom[8] = {+2, -2, -2, +2, -1, +1, +1, -1};
//int antrianBaris[100];
//int antrianKolom[100];
//
//int posisiValid(int i, int j){
//	if(i >= 0 && j >= 0 && i < SIZE && j < SIZE){
//		return 1;
//	}
//	return 0;
//}
//
//int minimum(int kolomAwal, int barisAwal, int kolomTujuan, int barisTujuan){
//	int i;
//	int langkah[SIZE][SIZE] = {0};
//	
//	antrianBaris[belakang] = barisAwal;
//	antrianKolom[belakang] = kolomAwal;
//	belakang++;
//	visited[barisAwal][kolomAwal] = 1;
//	
//	while(depan < belakang){
//		int baris = antrianBaris[depan];
//		int kolom = antrianKolom[depan];
//		depan++;
//		
//		if(baris == barisTujuan && kolom == kolomTujuan){
//			return langkah[baris][kolom];
//		}
//		
//		for(i = 0; i < 8; i++){
//			int barisBaru = baris + gerakBaris[i];
//			int kolomBaru = kolom + gerakKolom[i];
//			
//			if(posisiValid(barisBaru, kolomBaru) && !visited[barisBaru][kolomBaru]){
//				visited[barisBaru][kolomBaru] = 1;
//				langkah[barisBaru][kolomBaru] = langkah[baris][kolom] + 1;
//				antrianBaris[belakang] = barisBaru;
//				antrianKolom[belakang] = kolomBaru;
//				belakang++;
//			}
//			
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int t, tc, i, j, barisAwal, barisTujuan;
//	char kolomAwal, kolomTujuan;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t < tc; t++){
//		depan = 0;
//		belakang = 0;
//		scanf("%c%d %c%d", &kolomAwal, &barisAwal, &kolomTujuan, &barisTujuan); getchar();
//		
//		for(i = 0; i < SIZE; i++){
//			for(j = 0; j < SIZE; j++){
//				visited[i][j] = 0;
//			}
//		}
//		
//		for(i = 0 ; i < 100; i++){
//			antrianBaris[i] = 0;
//			antrianKolom[i] = 0;
//		}
//		
//		kolomAwal -= 'A';
//		barisAwal--;
//		kolomTujuan -= 'A';
//		barisTujuan--;
//
//		int result = minimum(kolomAwal, barisAwal, kolomTujuan, barisTujuan);
//		printf("Case #%d: %d\n", t+1, result);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//#define SIZE 8
//
//char papan[SIZE][SIZE];
//int visitedhitam[SIZE][SIZE] = {0};
//int visitedputih[SIZE][SIZE] = {0};
//int depan = 0, belakang = 0;
//int antrianBaris[100], antrianKolom[100];
//int gerakBaris[8] = {-1, +1, -1, +1, -2, +2, -2, +2};
//int gerakKolom[8] = {+2, +2, -2, -2, -1, +1, +1, -1};
//int i, j;
//int langkahhitam[SIZE][SIZE], langkahputih[SIZE][SIZE];
//
//int amanga(int i, int j){
//	if(i >= 0 && j >= 0 && i < SIZE && j < SIZE){
//		return 1;
//	}
//	return 0;
//}
//void BFS(int n, int kolomawal, int barisawal, int visited[][SIZE], int langkah[][SIZE]){
//	belakang = 0;
//	depan = 0;
//	for(i = 0; i < SIZE; i++){
//		for(j = 0; j < SIZE; j++){
//			visited[i][j] = 0;
//			langkah[i][j] = 0;
//		}
//	}
//	
//	antrianBaris[belakang] = barisawal;
//	antrianKolom[belakang] = kolomawal;
//	belakang++;
//	visited[barisawal][kolomawal] = 1;
//	
//	while(depan < belakang){
//		int baris = antrianBaris[depan];
//		int kolom = antrianKolom[depan];
//		depan++;
//		
//		if(langkah[baris][kolom] == n){
//			continue;
//		}
//		
//		for(i = 0; i < 8; i++){
//			int barisBaru = baris + gerakBaris[i];
//			int kolomBaru = kolom + gerakKolom[i];
//			
//			if(amanga(barisBaru, kolomBaru) && !visited[barisBaru][kolomBaru]){
//				visited[barisBaru][kolomBaru] = 1;
//				langkah[barisBaru][kolomBaru] = langkah[baris][kolom]+1;
//				antrianBaris[belakang] = barisBaru;
//				antrianKolom[belakang] = kolomBaru;
//				belakang++;
//			}
//			
//		}
//	}
//}
//
//int bisagak(int n, int kolomhitam, int barishitam, int kolomputih, int barisputih){
//	BFS(n, kolomhitam, barishitam, visitedhitam, langkahhitam);
//	BFS(n, kolomputih, barisputih, visitedputih, langkahputih);
//	
//	for(i = 0; i < SIZE; i++){
//		for(j = 0; j < SIZE; j++){
//			if(visitedhitam[i][j] && visitedputih[i][j]){
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//int main(){
//	int t, tc, n;
//	char kolomhitam, kolomputih;
//	int barisputih, barishitam;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0;t < tc; t++){
//		scanf("%d", &n); getchar();
//		scanf("%c%d %c%d", &kolomhitam, &barishitam, &kolomputih, &barisputih); getchar();
//		
//		kolomhitam -= 'A';
//		kolomputih -= 'A';
//		barishitam--;
//		barisputih--;
//		
//		int result = bisagak(n, kolomhitam, barishitam, kolomputih, barisputih);
//		
//		if(result){
//			printf("Case #%d: YES\n", t+1);
//		}
//		else{
//			printf("Case #%d: NO\n", t+1);
//		}
//		
//	}
//	return 0;
//}

//============================================================================================================

//#include <stdio.h>
//
//#define SIZE 5
//
//int papan[SIZE][SIZE]= {
//{0, 0, 0, 1, 0},
//{1, 1, 0, 1, 0},
//{0, 0, 0, 0, 0},
//{0, 1, 1, 1, 0},
//{0, 0, 0, 0, 0},
//};
//int visited[SIZE][SIZE] = {0};
//int depan = 0, belakang = 0;
//int antrianBaris[100], antrianKolom[100];
//int gerakBaris[4] = {+1, -1, 0, 0};
//int gerakKolom[4] = {0, 0, +1, -1};
//int langkah[SIZE][SIZE];
//int i, j;
//
//int validgak(int i, int j){
//	if(i >= 0 && j >= 0 && i < SIZE && j < SIZE && papan[i][j] != 1){
//		return 1;
//	}	
//	return 0;
//}
//
//int minimum(int barisAwal, int kolomAwal, int barisTujuan, int kolomTujuan){
//	antrianBaris[belakang] = barisAwal;
//	antrianKolom[belakang] = kolomAwal;
//	belakang++;
//	visited[barisAwal][kolomAwal] = 1;
//	
//	while(depan < belakang){
//		int baris = antrianBaris[depan];
//		int kolom = antrianKolom[depan];
//		depan++;
//		
//		if(baris == barisTujuan &&kolom == kolomTujuan){
//			return langkah[baris][kolom];
//		}
//		
//		for(i = 0; i < 4; i++){
//			int barisBaru = baris + gerakBaris[i];
//			int kolomBaru = kolom + gerakKolom[i];
//			
//			if(!visited[barisBaru][kolomBaru] && validgak(barisBaru, kolomBaru)){
//				visited[barisBaru][kolomBaru] = 1;
//				langkah[barisBaru][kolomBaru] = langkah[baris][kolom] +1;
//				antrianBaris[belakang] = barisBaru;
//				antrianKolom[belakang] = kolomBaru;
//				belakang++;
// 			}
//		}
//	}
//	return -1;
//}
//
//int main(){
//	int barisAwal, kolomAwal, barisTujuan, kolomTujuan;
//	
//	scanf("%d %d", &barisAwal, &kolomAwal); getchar();
//	scanf("%d %d", &barisTujuan, &kolomTujuan); getchar();
//	
//	for(i = 0; i < SIZE; i++){
//		for(j = 0; j < SIZE; j++){
//			langkah[i][j] = 0;
//		}
//	}
//	
//	for(i = 0; i < 100; i++){
//		antrianBaris[i] = 0;
//		antrianKolom[i] = 0;
//	}
//	
//	int result = minimum(barisAwal, kolomAwal, barisTujuan, kolomTujuan);
//	printf("Langkah minimum: %d\n", result);
//	return 0;
//}


//#include <stdio.h>
//
//int N;
//char papan[100][100];
//
//// ===== CEK DIAGONAL =====
//int cekDiagonal(int row, int col){
//
//    // FIX: Simpan nilai awal supaya bisa reset dengan benar
//    int r, c;
//
//    // kiri-atas
//    r = row - 1; 
//    c = col - 1;
//    while(r >= 0 && c >= 0){
//        if(papan[r][c] == 'Q') return 0;
//        r--; c--;
//    }
//
//    // kanan-atas
//    r = row - 1; 
//    c = col + 1;
//    while(r >= 0 && c < N){
//        if(papan[r][c] == 'Q') return 0;
//        r--; c++;
//    }
//
//    // kiri-bawah
//    r = row + 1; 
//    c = col - 1;
//    while(r < N && c >= 0){
//        if(papan[r][c] == 'Q') return 0;
//        r++; c--;
//    }
//
//    // kanan-bawah
//    r = row + 1; 
//    c = col + 1;
//    while(r < N && c < N){
//        if(papan[r][c] == 'Q') return 0;
//        r++; c++;
//    }
//
//    return 1;
//}
//
//// ===== CEK KOLOM =====
//int cekKolom(int col){
//    int row;
//
//    for(row = 0; row < N; row++){
//        // FIX: kalau ketemu Q berarti kolom tidak aman
//        if(papan[row][col] == 'Q'){
//            return 0;
//        }
//    }
//    return 1;
//}
//
//// TIDAK DIPAKAI, tapi tetap disimpan agar mirip dengan punyamu
//int cekBaris(int row){
//    return 1;
//}
//
//// ===== CETAK PAPAN =====
//void printpapan(){
//    int i, j;
//    for(i = 0; i < N; i++){
//        for(j = 0; j < N; j++){
//            printf("%c", papan[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//// ===== BACKTRACKING =====
//int nqueen(int baris){
//
//    if(baris == N){
//        printpapan();
//        return 1;
//    }
//
//    int col;
//
//    for(col = 0; col < N; col++){
//
//        // FIX: cek hanya satu baris ? baris sekarang
//        if(
//            papan[baris][col] == '.' &&
//            cekKolom(col) &&
//            cekDiagonal(baris, col)
//        ){
//            papan[baris][col] = 'Q';
//
//            if(nqueen(baris+1)) return 1;
//
//            papan[baris][col] = '.';
//        }
//    }
//
//    return 0;
//}
//
//// ===== MAIN =====
//int main(){
//    int i, j;
//
//    scanf("%d", &N); getchar();
//
//    for(i = 0; i < N; i++){
//        for(j = 0; j < N; j++){
//            papan[i][j] = '.';
//        }
//    }
//
//    if (!nqueen(0))
//        printf("Tidak ada solusi\n");
//
//    return 0;
//}

//#include <stdio.h>
//
//int total = 0;
//
//void pohon(int jumlah, int daun[], int n, int node){
//	if(node > n) return;
//	
//	int kiri = node*2;
//	int kanan = node*2+1;
//	if(kiri <= n && kanan <= n){
//		total++;
//	}
//	else{
//		pohon(jumlah, daun, n, kiri);
//		pohon(jumlah, daun, n, kanan);
//	}
//	
//}
//
//int main(){
//	int t, tc, n, daun[100];
//	int i;
//	
//	scanf("%d", &tc); getchar();
//	for(t = 0; t < tc; t++){
//		total = 0;
//		scanf("%d", &n); getchar();
//		for(i = 1; i <= n; i++){
//			scanf("%d", &daun[i]); getchar();
//		}
//		
//		printf("Case #%d: %d\n", t+1, total);
//		pohon(0, daun, n, 1);
//	}
//	return 0;
//}

//=====================================================================================================================
//=============================================================================================================
//================================================================================================================
//#include <stdio.h>
//
//int total = 1;
//
//void hitung(int n, int m, int index){
//	if(index == m){
//		printf("%d\n", total);
//		return;
//	}
//	
//	total = total * n;
//	hitung(n, m, index+1);
//}
//
//int main(){
//	int n, m;
//	
//	scanf("%d %d", &n, &m); getchar();
//
//	total = 1;
//	hitung(n, m, 0);
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void palindrom(char kata[], int depan, int belakang, int *flag){
//	if(depan > belakang){
//		return;
//	}
//	
//	if(kata[depan] != kata[belakang]){
//		*flag = 0;
//		return;
//	}
//	
//	palindrom(kata, depan+1, belakang - 1, flag);
//}
//
//int main(){
//	char kata[1000];
//	
//	scanf("%[^\n]", kata); getchar();
//	int len = strlen(kata);
//	
//	int flag = 1;
//	palindrom(kata, 0, len-1, &flag);
//	if(flag){
//		printf("aman\n");
//	}
//	else{
//		printf("kaga\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//
//void cari(int arr[], int n, int index, int *min){
//	if(index == n){
//		return;
//	}
//	
//	if(arr[index] < *min){
//		*min = arr[index];
//	}
//	
//	cari(arr, n, index+1, min);
//}
//
//int main(){
//	int arr[] = {7, 4, 5, 6, 2, 3, 1, 6};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	
//	int min = arr[0];
//	cari(arr, n, 0, &min);
//	
//	printf("%d\n", min);
//	return 0;
//}

//#include <stdio.h>
//
//int min(int arr[], int n, int index){
//	if(index == n-1){
//		return arr[index];
//	}
//	
//	int cariMin = min(arr, n, index+1);
//	
//	return (arr[index] > cariMin) ? cariMin : arr[index];
//}
//
//int main(){
//	int arr[1000];
//	int n = 0;
//	
//	while(scanf("%d", &arr[n]) != EOF){
//		n++;
//	}
//	
//	int result = min(arr, n, 0);
//	
//	printf("%d\n", result);
//	return 0;
//}


// Hitung jumlah kemunculan angka dalama array secara rekursif
//#include <stdio.h>
//
//int total = 0;
//
//void hitung(int arr[], int n, int i, int index){
//	if(index == i){
//		printf("%d", total);
//		return;
//	}
//	
//	if(arr[index] == n){
//		total++;
//	}
//	
//	hitung(arr,n, i, index+1);
//}
//
//int main(){
//	int arr[1000];
//	int n;
//	int i = 0;
//	
//	while(scanf("%d", &arr[i]) != EOF){
//		i++;
//	}
//	scanf("%d", &n); getchar();
//	
//	 hitung(arr, n, i, 0);
//	return 0;
//}

//#include <stdio.h>
//
//void balik(char *kata, int index){
//	if(kata[index] != '\0'){
//		balik(kata, index+1);
//		printf("%c", kata[index]);
//	}	
//}
//
//int main(){
//	char kata[1000];
//	
//	scanf("%s", kata); getchar();
//	balik(kata, 0);
//	return 0;
//}

//================================================================
//divide and conquer

//#include <stdio.h>
//
//int total = 0;
//
//void leaf(int arr[], int n, int node){
//	if(node >= n){
//		return;
//	}
//	
//	int kiri = 2*node+1;
//	int kanan = 2*node+2;
//	
//	if(kiri < n && kanan < n){
//		total++;
//	}
//	
//	if(kiri < n){
//		leaf(arr, n, kiri);
//	}
//	if(kanan < n){
//		leaf(arr, n, kanan);
//	}
//}
//
//int main(){
//	int arr[1000];
//	int n = 0;
//	
//	while(scanf("%d", &arr[n]) != EOF){
//		n++;
//	}
//	
//	leaf(arr, n, 0);
//	printf("%d\n", total);
//	return 0;
//}

// DFS NODE SERING DIPAKAI ===============================================================

//#include <stdio.h>
//
//int hubungan[100][100];
//int visited[100];
//int node, edge;
//int total = 0;
//
//int dfs(int u){
//	int i;
//	visited[u] = 1;
//	
//	for(i = 1; i <= node; i++){
//		if(hubungan[u][i] == 1 && !visited[i]){
//			dfs(i);
//		}
//	}
//	
//	total++;
//	return total;
//}
//
//int main() {
//   	int i, j, u, v;
//   	
//   	scanf("%d %d", &node, &edge); getchar();
//   	for(i = 0; i < edge; i++){
//   		scanf("%d %d", &u, &v); getchar();
//   		hubungan[u][v] = 1;
//   		hubungan[v][u] = 1;
//	}
//	
//	for(i = 1; i <= node; i++){
//		for(j = 0; j < edge; j++){
//			if(i == u[j] && !visited[i]) dfs(i);
//	}
//	}
//	printf("%d\n", total);
//    return 0;
//}

//#include <stdio.h>
//
//int hubungan[100][100];
//int visited[100];
//int node, edge;
//int total = 0;
//
//int ceki(int i, int awal){
//	if(i == awal){
//		return 1;
//	}
//	
//	return 0;
//}
//
//int dfs(int u, int awal){
//	if(u > node){
//		return 0;
//	}
//	
//	int i;
//	visited[u] = 1;
//	
//	for(i = 1; i<=node; i++){
//		if(hubungan[u][i] == 1 && !visited[i]){
//			dfs(i, awal);
//		}
//		if(hubungan[u][i] == 1 && visited[i] && ceki(i, awal)){
//			break;
//		}
//	}
//	return 1;
//}
//
//int main(){
//	int u,i,j, v;
//	
//	scanf("%d %d", &node, &edge); getchar();
//	for(i = 0; i < edge; i++){
//		scanf("%d %d", &u, &v); getchar();
//		hubungan[v][u] = 1;
//		hubungan[u][v] = 1;
//	}
//	
//	int awal;
//	scanf("%d", &awal); getchar();
//	int result = dfs(awal, awal);
//	
//	
////	for(i = 1; i <= node; i++){
////		if(!visited[i]) dfs(i);
////	}
//	
//	if(result) printf("yes\n");
//	else{
//		printf("no\n");
//	}
//	
//	return 0;
//}
