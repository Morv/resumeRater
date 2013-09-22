/******************************************************************************
*********                Written by: Morvan Perez           *******************
*********               Date Written: Sept 22, 2013         *******************
*********           Purpose: Assignment 5: Resume Rater     *******************
*******************************************************************************
* This program reads in keywords from the comma delimited file, keywords.txt, *
*                the keywords are compared to the words in resume.txt		  *
*       and outputs how many times the keywords appear in the resume file.    *
*                        Keywords are case sensitive.                         *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pause system ("pause")
#define cls system ("cls")
#define flush fflush (stdin)


// FUNCTION PROTOTYPES
void removePunctuation (char a[]);

main () {
	FILE *pKeyFile,*pResumeFile;
	char keyword[21], resWord[81];//max 20 characters for keyword, max 80 characters for resume word (for long emails addresses)
	int score = 0, unique = 0, test = 0;

	pKeyFile = fopen("keywords.txt", "r");

	if (pKeyFile == NULL){
		printf("Error opening keywords.txt.  Program exiting\n");
		exit (-1);
	} //end NULL check


	while (!feof(pKeyFile)) //Keep going until the EOF.
	{
		if (score > test){ 
			unique++; 
		} //if a keyword has been found, add 1 to the number of unique keywords in the resume.

		test = score; //resets for the if statement to check if it will increase (find a match).

		fscanf(pKeyFile,"%[^,], ", keyword); //reads file until comma is reached. Then skips a space, and goes to the next word.
		printf("Searching for: %s\n", keyword); //prints out every keword before it searches for it in the resume.
			
		pResumeFile = fopen("resume.txt", "r");//open resume file

			if (pResumeFile == NULL){
				printf("Error opening resume.txt. Program exiting\n");
				pause;
				exit(-1);
			}//end NULL check
	
				while (!feof(pResumeFile)) //Keep going until the EOF.
				{
				fscanf(pResumeFile,"%s", resWord); //reads every word in the resume
				
				removePunctuation (resWord);
			
				if (strcmp(keyword, resWord) == 0) {
					score++; 
				} //if the keyword matches the word in the resume, add 1 to the word count.
	
				}//end while
	}//end big while
	 cls;
	 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	 printf("~~~~~~~~~~~~~~ R E S U L T S ~~~~~~~~~~~~~~\n");
	 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	 printf("Unique keywords found: %i\n", unique);
	 printf("Total number of matches: %i\n", score);
	 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	 pause; 
	fclose(pKeyFile);
	fclose(pResumeFile);
} //end of main

void removePunctuation (char a[]){

	int length = strlen(a);

	if ( (a[length-1] >= 65 && a[length-1] <= 90) || (a[length-1] >= 97 && a[length-1] <= 122)) //if the last character of the word is "A-Z" or "a-z"
	{
		return;//The word does not have punctuation, I don't need to be in this function!
	}else{
		while ((a[length-1] < 65 ) || ( a[length-1] >= 91) && (a[length-1] <= 96) || (a[length-1] >= 123)) //while the last character of the word is not a letter
		{		
			if (length == 0)
			{
				return; //the first character is not a letter.
			} else {
			a[length-1] = '\0'; //make the last character null
			length--; //set your focus on the character before the one you just changed to null.
			}//end if-else
		}//end while
	}//end big if-else
}//punctuation removal complete
