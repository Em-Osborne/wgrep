#include <iostream> 
#include <stdio.h>
#include <string.h>
using namespace std; 

int NUMBER_CHARS = 200; // max number of characters per line it reads

int main(int argc, char** argv) { // arguments: the word you're searching, filenames

	if(argc < 3){
		cout<< "enter ./wgrep searchterm files \n";
	}
	char* word = argv[1];
	int NUM = 100; // this is max charactes per line. It's a variable so it can be changed easily
	for( int i = 2; i < argc; i++){
		char myarray[NUM]; // initializing this inside the loop so we get a new one each time

		FILE *fp = fopen(argv[i], "r"); 
		if (fp == NULL){ 
			printf("cannot open file\n");
			return(1);
		}
		while((fgets (myarray, NUM, fp)) != NULL) { // while loop makes it read until the end of document because fgets() stops at a linebreak 
			if(strstr(myarray, word)!=NULL){ 
				cout << myarray << "\n";				
			} 
		}
		fclose(fp);
	}
	return 0;
}
	




