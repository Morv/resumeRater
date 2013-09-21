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
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush (stdin)

// FUNCTION PROTOTYPES

main () {
	FILE *pKeyFile;
	char keyword[51];

	pKeyFile = fopen("keywords.txt", "r");

	if (pKeyFile == NULL){
		printf("Error opening file.  Program exiting");
		exit (-1);
	}

	while (!feof(pKeyFile)) // Keep going until EOF
	{
		fscanf(pKeyFile,"%[^,],", keyword); //reads file until comma is reached. goes to the next word
		printf("Keyword: %s\n", keyword);
		pause;
	}


	fclose(pKeyFile);
} //end of main
