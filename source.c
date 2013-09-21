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

main () {
	FILE *pKeyFile,*pResumeFile;
	char keyword[51], resWord[51];
	int score = 0;

	pKeyFile = fopen("keywords.txt", "r");

	if (pKeyFile == NULL){
		printf("Error opening keywords.txt.  Program exiting\n");
		exit (-1);
	} //end NULL check


	while (!feof(pKeyFile)) //Keep going until the EOF.
	{
		
		fscanf(pKeyFile,"%[^,], ", keyword); //reads file until comma is reached. Then skips a space, and goes to the next word.
		printf("Searching for: %s\n", keyword); //prints out every keword before it searches for it in the resume.
			
		pResumeFile = fopen("resume.txt", "r");//open resume file

		if (pResumeFile == NULL){
			printf("Error opening resume.txt. Program exiting\n");
			exit(-1);
		}//end NULL check

			while (!feof(pResumeFile)) //Keep going until the EOF.
			{
			fscanf(pResumeFile,"%s", resWord); //reads every word in the resume

			if (strcmp(keyword, resWord) == 0) { score++; } //can be used instead of checkForMatch
			}//end while
	}//end big while
	 pause;
	 cls;
	 printf("Your resume score is: %i", score);
	 pause; 

	fclose(pKeyFile);
	fclose(pResumeFile);
} //end of main

