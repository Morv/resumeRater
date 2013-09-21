/****************************************************
Written by: Morvan Perez
Date Written: Sept 20, 2013
Purpose: Assignment 5: Resume Rater

Write a resume scanning simulator.  You are to write a program that will read in 
a resume (you can assume that the document is located with the source file and it is 
named resume.txt (make this up).

Your program will read in a text file that contains KEYWORDS from zero to 50 keywords (make this up). 
in the file will be separated by commas.  No keyword will contain a comma.  You are to count
the total times the keywords are found in the fake resume.  Your program will simply output
to the screen the count of keywords with in the document.  In real life the higher the number
the higher the chance that the person (the owner of the resume) will get an interview.

You are to turn in your design tool, your input file, your sample resume.txt, and your source file.
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush (stdin)

// FUNCTION PROTOTYPES
void checkForMatch (char a[], char b[], int *score);


main () {
	FILE *pKeyFile,*pResumeFile;
	char keyword[51], resWord[51], testA[51], testB[51];
	int score = 0, a = 0, b = 0;

	pKeyFile = fopen("keywords.txt", "r");

	if (pKeyFile == NULL){
		printf("Error opening keywords.txt.  Program exiting\n");
		exit (-1);
	} //end NULL check

	while (!feof(pKeyFile)) //Keep going until the EOF.
	{
		
		fscanf(pKeyFile,"%[^,],", keyword); //reads file until comma is reached. goes to the next word
		printf("Keyword: %s\n", keyword); //prints out every keword
		pause;
			
		pResumeFile = fopen("resume.txt", "r");//open resume file

		if (pResumeFile == NULL){
			printf("Error opening resume.txt. Program exiting\n");
			exit(-1);
		}//end NULL check

		while (!feof(pResumeFile)) //Keep going until the EOF.
		{
		fscanf(pResumeFile,"%s", resWord); //reads file until comma is reached. goes to the next word
		printf("Resume Word: %s\n", resWord); //prints out every word in the resume in a list

		//if (strcmp(keyword, resWord) == 0) { score++; } //can be used instead of checkForMatch
		checkForMatch(keyword, resWord, &score);

		}//end while



	}//end big while

	 cls;
	 printf("Your resume score is: %i", score);
	 pause; 

	fclose(pKeyFile);
	fclose(pResumeFile);
} //end of main

void checkForMatch (char a[], char b[], int *score){

	printf("%s compared to %s\n\n\n", a, b);


	if (strcmp(a, b) == 0) {
		*score += 1;
		printf("Match! score:%i\n\n", *score);
	}//end compare;

} //end checkForMatch
