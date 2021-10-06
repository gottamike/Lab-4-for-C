#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// printing function 
void printing(char *hurricanes[], int size){
       // creating a token for strtok
       	char *token;
	// creating an output file
	FILE *out_file;

	out_file = fopen("output.txt", "w");
	// if I cant make an output file throw an error
	if (out_file == NULL){
        printf("Error, could not open file.");
	return;
	}

	// header for the file that goes in first
	char *message = "Hurricanes in Florida with category and date";
	fprintf(out_file, "%s", message);
	fputs("\n", out_file);
	
	// for loop that formats and places parts of the hurricane into the output file
	for (int i = 0; i < size; i++){
		token = strtok(hurricanes[i], ",");
		// I use fprintf when something needs to be formatted in the file
		fprintf(out_file, "%-10s", token);

		token = strtok(NULL, ",");
		fprintf(out_file, "%-5c", token[9]);

		token = strtok(NULL, ",");
		fprintf(out_file, "%s ", token);

		token = strtok(NULL, ",");
		// I use fputs when the thing in the file doesnt need formatting
		fputs(token, out_file);
	}



	fclose(out_file);



}



// sort function for the hurricanes alphabetically
void sort(char *hurricanes[], int size){
	int x;
	// nested for loop using string compare 
	for (x = 0; x < size; x++){
		for (int y = x + 1; y < size; y++){
		//	string compare function with a temporary array that does swapping
			if ((strcmp(hurricanes[x], hurricanes[y])) > 0){
				char *temp = hurricanes[x];
				hurricanes[x] = hurricanes[y];
				hurricanes[y] = temp;
			}
		}
	}
}




int main(void){

// creating a hurricane with 100 spaces
char *hurricanes[100];	

// creating a file and opening it
FILE *in_file;
in_file = fopen("/public/lab4/hurricanes.csv", "r");

// if I cant find that file throw an error
if (in_file == NULL){
	printf("Error, could not open file.");
	return 0;
}

int i = 0;

// making room for all my hurricane data and keeping track of how many hurricanes there are with i
       do {
        hurricanes[i] = malloc(sizeof(char) * 200);
        } while (fgets(hurricanes[i++], 200, in_file) != NULL);
        
	// calling the sort function with the hurricanes and size
	sort(hurricanes, i-1);

	// calling the printing function with the hurricanes and size
	printing(hurricanes, i-1);

	



	return 0;

}
