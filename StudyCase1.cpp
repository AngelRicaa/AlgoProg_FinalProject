#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int i, j;
	char kata1[105], kata2[105];
	
	scanf("%s", kata1); getchar();
	scanf("%s", kata2); getchar();
	
	int len1 = strlen(kata1);
	int len2 = strlen(kata2);
	
	int index = 0;
	char temp[105];
	
	int prefix = 0;
	for(i = 0; i < len1 && i < len2; i++){
		if(kata1[i] == kata2[i]) prefix++;
		else break;
	}
	
	int suffix = 0;
	for(i = 1; i <= len1 && i <= len2; i++){
		if(len1 - i < prefix || len2 - i < prefix) break;
		if(kata1[len1 - i] == kata2[len2 - i]) suffix++;
    	else break;
	}
	
	for(i = 0; i < prefix; i++){
		temp[index++] = kata1[i];
	}
	
	for(i = 0; i < suffix; i++){
        temp[index++] = kata1[len1 - suffix + i];
    }
    
	temp[index] = '\0';
	
	for(i = 0; i < index; i++){
		if(isupper(temp[i])){
			temp[i] = tolower(temp[i]);
		}
		else{
			temp[i] = toupper(temp[i]);
		}
	}
	
	if(prefix == 0 && suffix == 0) printf("No Output\n");
	else{printf("%s\n", temp);}
	return 0;
}

