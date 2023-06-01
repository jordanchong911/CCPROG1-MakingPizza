/********************************************************************************************************* 
This is to certify that this project is my own work, based on my personal efforts in studying and applying 
the concepts learned. I have constructed the functions and their respective algorithms and corresponding 
code by myself. The program was run, tested, and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
 															  Chong, Jordan Chester Sze, DLSU ID# 12140183 
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* partition function adds a partition to know if you are inside a function or not
*/

void partition()
{
	int i; 
	
	printf("\n");
	for (i = 0; i < 51; i++)
	{
		printf("=");
	}
	printf("\n");
}

/* AddTranslations2 is a continuation of adding translations to their respective entries
 @param *pD - an addressof struct dictTag where the user wants the specific translation to be added into
 
 Pre-conditions: the user only types the language and word that only has chaacters between 1 - 20.
*/

void AddTranslations2 (dictType *pD)
{
	char     cChoice;
	
	string20 lang, 
			 word;
	
	// Loop if the user wants to continue adding in translations
	while (cChoice != 'N')
	{
		// Checks if the translations inside the entry are full.
		if(pD->nCountTrans == TRANSLATIONS)
		{
			// Prints out the error message and goes back to main menu.
			printf("Translations full.\n\n");
			cChoice = 'N';
		}
		else 
		{	
			// Prompts the user to type in the language
			printf("Please type in the language.\n");
			scanf(" %s", lang);
			
			// Prompts the user to type in the word
			printf("\nPlease type in the word.\n");
			scanf(" %s", word);
			
			// Checks if the length of the language or word is acceptable or not
			while (strlen(lang) == 0 && strlen(word) == 0)
			{
				printf("Error. ");
				printf("Please type in the language.\n");
				scanf(" %s", lang);
				
				printf("\nPlease type in the word.\n");
				scanf(" %s", word);
			}
			
			// Puts the respective language and translation pair into their respective memory
			strcpy(pD->aTrans[pD->nCountTrans].strLang, lang);
			strcpy(pD->aTrans[pD->nCountTrans].strWord, word);
			// Notes how many translations are there in an entry
			pD->nCountTrans++;
			
			// Prompts the user if the person wants to continue adding in languages and translations.
			printf("Continue? Press \"Y\" to continue and \"N\" to go back. ");
			scanf(" %c", &cChoice);
			cChoice = toupper(cChoice);
			
			// Loops if the user does not follow instructions
			while (cChoice != 'Y' && cChoice != 'N')
			{
				printf("Error. ");
				printf("Continue? Press \"Y\" to continue and \"N\" to go back. ");
				scanf(" %c", &cChoice);
				cChoice = toupper(cChoice);
			}
		}
	}
}

/* Swap function swaps the contents of the language translation pair everytime this function is called
 @param *p1 - a struct wordTag containing the language and the translation of the word
 @param *p2 - a struct wordTag containing the language and the translation of the word
*/

void Swap (wordType *p1, wordType *p2)
{
	// Creates a temporary struct
	wordType temp;
	// Gets the contents of *p1
	temp = *p1;
	// Copies the contents of *p2 to *p1
	*p1 = *p2;
	// Copies the contents of *p1 to *p2
	*p2 = temp;
}

/* SortAlphabetical sorts the dictionary's entries to their respective alphabetical order
 @param *d - a singular struct dictTag where the logs of language translation pairs are found
*/

void SortAlphabetical (dictType *d)
{
	int j, 
		k, 
		nLow = 0;
	
	// Loops to arrange the arrays into alphabetical order
	for (j = 0; j < d->nCountTrans; j++)
	{
		nLow = j;
		for (k = j + 1; k < d->nCountTrans; k++)
		{
			if (strcmp(d->aTrans[nLow].strLang, d->aTrans[k].strLang) > 0)
			{
				nLow = k;
			}
		}
		
		if (nLow != j)
		{
			Swap(&d->aTrans[nLow], &d->aTrans[j]);
		}
	}
}

/* Check function checks if a word has a symbol at the end. If that's the case, then the symbol at the end will turn into a null character
 @param word - a string with at most 20 characters that contain the wordd to be translated / count for languages
*/
void Check (string20 word)
{
	if (isalpha(word[strlen(word) - 1]) == 0)
	{
		word[strlen(word) - 1] = '\0';
	}
}

/* SortArray sorts the array of languages to their respective alphabetical order
 @param lang[] - an array of languages converted from words
 @param *nNum - an address of the amount of languages inside the array
*/

void SortArray (string20 lang[], int *nNum)
{
	int      j,
		     k, 
			 nLow = 0;
			 
	string20 temp;
	// Loops to arrange the arrays into alphabetical order
	for (j = 0; j < *nNum; j++)
	{
		nLow = j;
		for (k = j + 1; k < *nNum; k++)
		{
			if (strcmp(lang[j], lang[k]) > 0)
			{
				nLow = k;
			}
		}
		
		if (nLow != j)
		{
			strcpy(temp, lang[nLow]);
			strcpy(lang[nLow], lang[j]);
			strcpy(lang[j], temp);
		}
	}
	
	printf("\n\n");
}

/* FoundTrans returns 1 if the dictionary has the word, and returns 0 if the word does not have a translation
 @param sentence - an array of 150 characters that contains the user's request of sentence translation
 @return an into (0 or 1) that says whether the dictionary has the word or not
*/

int FoundTrans (string20 word, string20 lang, dictType d[], int *nCount, int *nWhere1, int *nWhere2)
{
	int j, 
		k,
		nFound = 0;
	
	// Loop to find where the word is located
	for (j = 0; j < *nCount; j++)
	{
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			if (strcmp(word, d[j].aTrans[k].strWord) == 0)
			{
				*nWhere1 = j;
				nFound = 1;
				j = *nCount + 1;
			}
		}
	}
	
	// Checks if the word is found inside the dictionary
	if (nFound)
	{
		// Loop to find where the translation is located inside the entry
		for (j = 0; j < d[*nWhere1].nCountTrans; j++)
		{
			if (strcmp(lang, d[*nWhere1].aTrans[j].strLang) == 0)
			{
				*nWhere2 = j;
				return 1;
			}
		}
	}
	else
	{
		// Returns 0
		return 0;
	}
	
	return 0;
}

/* GetTranslationPair separates a string from a file into two: language and the translation
 @param pair - a string where it contains the language and translation pair from the file
 @param lang - a string of 20 characters where the language of a translation is located
 @param word - a string of 20 characters where the translation is located
 @reference - https://www.techcrashcourse.com/2016/05/c-program-to-split-string-into-two-equal-strings.html
*/

void GetTranslationPair(string40 pair, string20 lang, string20 word)
{
	int j,
		k, 
		nMid = 0;
	
	// Loop where it checks where the colon is located
	for (j = 0; j < strlen(pair); j++)
	{
		if (pair[j] == ':')
		{
			nMid = j;
		}
	}
	
	// Loop to copy the contents of "pair" before the colon to lang
	for (j = 0; j < nMid; j++)
	{
		if (pair[j] != '\n')
		{
			lang[j] = pair[j];
		}
		else
		{
			lang[j] = '\0';
		}
	}
	lang[j] = '\0';
	
	// Loop to copy the contents of "pair" after the colon to word
	for (j = nMid + 2, k = 0; j < strlen(pair); j++, k++)
	{
		if (pair[j] != '\n')
		{
			word[k] = pair[j];
		}
		else
		{
			word[k] = '\0';
		}
	}
}

/* ImportDatabase imports the data of the requested file into the dictionary
 @param d[] - a struct dictTag where all the entries will be put into
 @param *nCount - address of the number of entries inside the files
 @param filename- a string of 30 characters containing the file name
 @returns an integer (0 or 1) to check whether the import has been successful or not
*/

int ImportDatabase (dictType d[], int *nCount, string30 filename)
{
	FILE     *fp;
	
	string20 lang, 
			 word;
			 
	string40 pair;
	
	// Reads the file of specified file name
	fp = fopen(filename, "r");
	
	// Checks if the file exists or not
	if (fp == NULL)
	{
		// Return 0 if there is no such file
		return 0;
	}
	else
	{
		// Loops and check where the pointer is at the end of the file
		while (!feof(fp))
		{
			// Bug, need to double check if the pointer is really at the end of the file
			if (!feof(fp))
			{
				// Copies the pair into a string40 pair.
				fgets(pair, STRING * 2, fp);
				// Checks if the pair has a newline character or not
				if (strlen(pair) == 1)
				{
					// Addds the count of entries if it is true.
					*nCount += 1;
				}
				else if (strlen(pair) > 1)
				{
					// Separates the pair into language and the word
					GetTranslationPair(pair, lang, word);
					// Adds the word and the language to their respective places inside the word
					strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strLang, lang);
					strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strWord, word);
					// Counts how many pairs are there inside an entry
					d[*nCount].nCountTrans += 1;
				}
			}
		}
		*nCount -= 1;
		// Closes the file
		fclose(fp);
		
		// Returns 1 once finished
		return 1;
	}
}

