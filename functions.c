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

/* StartMenu returns the number the user types when choosing what function will he use.
 @param *nStartMenu - address of a value that the will update once the user makes a choice
 @return the number that the user chooses
 Pre-condition: the user only chooses the numbers 1 - 3.
*/

void StartMenu (int *nStartMenu)
{
	int nChoice = 0;
	
	// Header for start of program
	printf("\n=== Machine Project # 2 : Simple Language Tools ===\n");
	partition();
	printf("\n\n");
	
	// Lists down the options the user has can list down
	printf("Start Menu: \n\n");
	printf("1) Manage Data\n2) Language Tools\n3) Exit\n");
	partition();
	printf("\n");
	
	// Prompts the user to type a number
	scanf("%d", &nChoice);
	
	// Loops if the user types in a number that's too high or too low
	while (nChoice > 3 && nChoice < 0)
	{
		printf("Error.\n");
		scanf("%d", &nChoice);
	}
	
	// Returns what the user types in
	*nStartMenu = nChoice;
}

/* ManageData returns the number the user types when choosing what function will he use.
 @param *nManageData - address of a value that the will update once the user makes a choice
 @return the number that the user chooses
*/

void ManageData (int *nManageData)
{
	int j, 
		nChoice = 0;
	
	// Header for Manage Data
	partition();
	printf("\n");
	for (j = 0; j < 20; j++)
	{
		printf("=");
	}
	printf("Manage Data");
	for (j = 0; j < 20; j++)
	{
		printf("=");
	}
	printf("\n");
	partition();
	
	printf("\n\n");
	
	// Lists down the choices that the user can have
	printf("Start Menu: \n\n");
	printf("1) Add Entry\n2) Add Translations\n3) Modify Entry\n4) Delete Entry\n5) Delete Translation\n");
	printf("6) Display All Entries\n7) Search Word\n8) Search Translation\n9) Export\n10) Import\n11) Exit\n");
	partition();
	printf("\n");
	
	// Prompts the user to type in the desired choice.
	scanf("%d", &nChoice);
	
	// Loops if the user types in a number that's too high or too low
	while (nChoice > 12 && nChoice < 0)
	{
		printf("Error.\n");
		scanf("%d", &nChoice);
	}
	
	// Return the number of choice for the user
	*nManageData = nChoice;
}

/* LanuageTools returns the number the user types when choosing what function will he use.
 @param *nLanguageTools - address of a value that the will update once the user makes a choice
 @return the number that the user chooses
*/

void LanguageTools (int *nLanguageTools)
{
	int j, 
		nChoice = 0;
	
	// Header for Language Tools portion
	partition();
	printf("\n");
	for (j = 0; j < 18; j++)
	{
		printf("=");
	}
	printf("Language Tools");
	for (j = 0; j < 18; j++)
	{
		printf("=");
	}
	printf("\n");
	partition();
	
	// Displays the choices the user can make for the program.
	printf("\n\n");
	printf("Start Menu:\n\n");
	printf("1) Identify Main Language\n2) Simple Translation\n3) Exit\n");
	partition();
	printf("\n");
	
	// Prompts the user to typing in the data
	scanf("%d", &nChoice);
	
	// Loops if the user types in a number that's too high or too low 
	while (nChoice > 3 && nChoice < 0)
	{
		printf("Error.\n");
		scanf("%d", &nChoice);
	}
	
	// Returns the choice that the user makes
	*nLanguageTools = nChoice;
}

/* AddEntry updates the dictionary with initial entries of a language and translation pair.
 @param d[] - a struct dictType array that contains information regarding the amount of translation inside entries
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns an updated dictionary with the additional entries made by the user
 
 Pre-condition: the number of letters inside the language and word pair should be between 1 and 20.
*/

void AddEntry (dictType d[], int *nCount)
{
	char     cChoice1, 
		     cChoice2;
		     
	string20 lang, 
		 	 word;
		 	 
	int      j, 
			 k,
			 nWord = 0;
			 
	int      aPosition[*nCount];
	
	while (cChoice1 != 'N')
	{
		partition();
		
		// Prompts the user to type in the language of the translation
		printf("\n\nType in the language of the translation:\n");
		scanf(" %s", lang);
		
		// Prompts the user to type in the translation
		printf("\nType in the word.\n");
		scanf(" %s", word);
		
		// Checks if the length of the word is not 0
		if (strlen(lang) != 0 && strlen(word) != 0)
		{
			for (j = 0; j < *nCount; j++)
			{
				for (k = 0; k < d[j].nCountTrans; k++)
				{
					// Loops to check whether there are similar / same translations inside the dictionary.
					if (strcmp(lang, d[j].aTrans[k].strLang) == 0 &&
					    strcmp(word, d[j].aTrans[k].strWord) == 0)
					{
						// Puts the position of the simillar word to a numbered array
						aPosition[nWord] = j;
						nWord++;
					}
				}
			}
			
			// Checks if there are similar words in the first place
			if (nWord >= 1)
			{
				// Displays the similar words.
				printf("These are the language and translation pairs that are similar.\n");
				
				for (j = 0; j < nWord; j++)
				{
					// Loops to see the entries with similar words.
					printf("%d)\n", j + 1);
					
					for (k = 0; k < d[aPosition[j]].nCountTrans; k++)
					{
						printf("%s: %s\n", d[aPosition[j]].aTrans[k].strLang, d[aPosition[j]].aTrans[k].strWord);
					}
				}
				
				// Prompts the user to continue with the selection or not.
				printf("Continue? Press \"Y\" to go to the next step and press \"N\" to go back to the main menu. ");
				scanf(" %c", &cChoice2);
				cChoice2 = toupper(cChoice2);
				
				// Loop if the user does not follow instructions.
				while (cChoice2 != 'N' && cChoice2 != 'Y')
				{
					printf("Error. ");
					printf("Continue? Press \"Y\" to go to the next step and press \"N\" to go back to the main menu. ");
					scanf(" %c", &cChoice2);
					cChoice2 = toupper(cChoice2);
				}
			}
			
			if (cChoice2 != 'N')
			{
				// Puts the word into their respective array
				strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strLang, lang);
				strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strWord, word);
				// Updates the count of translations inside a certain entry
				d[*nCount].nCountTrans = 1;
				// Updates the number of entries inside an array
				*nCount += 1;
				// Reverts back to 0 after listing down similar words.
				nWord = 0;
				
				// Prompts the user to continue on with typing in new entries or go back to the main menu
				printf("Continue? Press \"Y\" to type in new translations and press \"N\" to go back to the main menu. ");
				scanf(" %c", &cChoice1);
				cChoice1 = toupper(cChoice1);
				
				// Loops if the user doesn't follow instructions
				while (cChoice1 != 'N' && cChoice1 != 'Y')
				{
					printf("Error. ");
					printf("Continue? Press \"Y\" to type in new translations and press \"N\" to go back to the main menu. ");
					scanf(" %c", &cChoice1);
					cChoice1 = toupper(cChoice1);
				}
				printf("\n\n");
				partition();
			}
			else
			{
				// Forces the function to close.
				cChoice1 = 'N';
			}
		}
		else
		{ 
			printf("Please type in AT LEAST one character for both the language and the translation.\n\n");
		}
	}
}

/* AddEntry updates the dictionary with initial entries of a language and translation pair.
 @param d[] - a struct dictType array that contains information regarding the amount of translation inside entries
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns an updated dictionary with the additional translations with a certain entry made by the user
 
 Pre-condition: the number of letters inside the language and word pair should be between 1 and 20.
*/

void AddTranslations (dictType d[], int *nCount)
{
	string20 lang, 
			 word;
			 
	int 	 j, 
			 k, 
			 nWord = 0, 
			 nChoice = 0,
			 aPosition[*nCount];
	
	partition();
	
	//Prompts the user to type in the language and translation pair
	printf("\n\nEnter the language that you want to add.\n");
	scanf(" %s", lang);
	printf("\nEnter the word that you want to add.\n");
	scanf(" %s", word);
	
	for (j = 0; j < *nCount; j++)
	{
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			// Loops to find the similar word and the language pair inside the dictionary
			if (strcmp(lang, d[j].aTrans[k].strLang) == 0 && 
			    strcmp(word, d[j].aTrans[k].strWord) == 0)
			{
				// Adds the index of the similar said pair into the int array
				aPosition[nWord] = j;
				nWord++;
			}
		}
	}
	
	// Checks if there is more than one language and translation pair that is similar
	if (nWord > 1)
	{
		// Displays the user the similar pairs with different meanings
		printf("These are the language and translation pairs that are similar.\n");
		
		for (j = 0; j < nWord; j++)
		{
			printf("%d)\n", j + 1);
			for (k = 0; k < d[aPosition[j]].nCountTrans; k++)
			{
				printf("%s: %s\n", d[aPosition[j]].aTrans[k].strLang,
				                   d[aPosition[j]].aTrans[k].strWord);
			}
		}
		
		// Prompts the user to typein the number that they want to add in
		printf("Type in the number of the translation would you like to add to. Or press \"0\" to go back to main menu. ");
		scanf("%d", &nChoice);
		
		// Loops if the user is not following instructions
		while (nChoice < 0 && nChoice > nWord)
		{
			printf("Error. ");
			
			printf("Type in the number of the translation would you like to add to. ");
			scanf("%d", &nChoice);
		}
		
		// Prompts and adds the pair into the dictionary.
		if (nChoice != 0)
		{
			AddTranslations2(&d[aPosition[nChoice - 1]]);
		}
	}
	// Checks if there is ONLY one word that has similar said pair.
	else if (nWord == 1)
	{
		// Displays the pair to make sure that the user wants to add translation and language pair here.
		printf("This is the only language and translation pair that is similar.\n");
		
		for (j = 0; j < nWord; j++)
		{
			printf("%d)\n", j + 1);
			for (k = 0; k < d[aPosition[j]].nCountTrans; k++)
			{
				printf("%s: %s\n", d[aPosition[j]].aTrans[k].strLang,
				                   d[aPosition[j]].aTrans[k].strWord);
			}
		}
		
		// Prompts the user if the person wants to add translations to this entry
		printf("Would you like to add translations to this entry? Press \"1\" to continue and press \"0\" to go back to main menu. ");
		scanf("%d", &nChoice);
		
		// Loop if the user does not follow instructions.
		while (nChoice < 0 || nChoice > nWord)
		{
			printf("Error. ");
			printf("Type in the number of the translation would you like to add to. ");
			scanf("%d", &nChoice);
		}
		
		// Prompts and adds the pair to the dictionary.
		if (nChoice != 0)
		{
			AddTranslations2(&d[aPosition[nChoice - 1]]);
		}
	}
	// If there are no entries that are present inside the dictionary using what the user wants to add into the dictionary.
	else
	{
		// Displays the warning to guide the user to first add entry beofre moving back here.
		printf("No Results. Please go to \"Add Entry \" to add this current entry to the database.\n\n");
	}
	
	// Resets the counters and choices of the user.
	nWord = 0;
	nChoice = 0;
	partition();
}

/* ModifyEntry returns the index of the entry that the user wants to edit.
 @param d[] - a struct dictType array that contains information regarding the amount of translation inside entries
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns the index of the entry that you want to modify
*/

int ModifyEntry(dictType d[], int *nCount)
{
	int j = 0, 
		k = 0, 
		nChoice = 0;
	
	while (nChoice == 0)
	{
		// Displays one entry of the language and translation pair
		printf("%d)\n", j + 1);
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			printf("%s: %s\n", d[j].aTrans[k].strLang, d[j].aTrans[k].strWord);
		}
		
		// Prompts the user to either look at the next entry or type in the number of the index that you want to change
		printf("\n\nPress \"0\" to look at the next translation, Otherwise type in the number that you would like to modify. ");
		scanf("%d", &nChoice);
		
		// Checks whether the user inputs '0' or not.
		if (nChoice == 0)
		{
			// Goes to the next entry
			if (j < *nCount - 1)
			{
				j++;
			}
			// Or loops the last entry if there are no more entries
			else if (j > *nCount)
			{
				printf("Last entry.\n");
				j = *nCount - 1;
			}
		}
	}
	
	// Checks whether the user types in a proper index number
	if (nChoice > *nCount || nChoice < 0)
	{
		// Returns -1 if the user did not follow instructions
		printf("Error.\n\n");
		return -1;
	}
	else
	{
		// Returns the index of the entry that you want to modify
		return nChoice - 1;
	}
}

/* ModifyTranslation returns the index of the pair that the user wants to edit.
 @param *pD - an address of where the entry is located inside the dictionary
 @returns the index of the pair that you want to modify
*/

int ModifyTranslation (dictType *pD)
{
	int j, 
		nChoice = 0;
	
	// Displays all the pairs inside an entry
	for (j = 0; j < pD->nCountTrans; j++)
	{
		printf("%d) %s: %s\n", j + 1, pD->aTrans[j].strLang, pD->aTrans[j].strWord);
	}
	
	// Prompts the user to type in the index that the user wants to modify
	printf("\n\nPlease type in the number that you would like to modify. ");
	scanf("%d", &nChoice);
	
	// Checks if the user types in a proper number
	if (nChoice > pD->nCountTrans || nChoice < 0)
	{
		// Return -1 if the user did not follow instructions
		printf("Error.\n\n");
		return -1;
	}
	else
	{
		// Returns the index of the pair that the user wants to modify
		return nChoice - 1;
	}
}

/* Modify function updates the contents of the dictionary if a user chooses to update some of the translation pairs
 @param d[] - a struct dictType array that contains information regarding the amount of translation inside entries
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns the index of the entry that you want to modify
*/

void Modify (dictType d[], int *nCount)
{
	int  nModEntry,
		 nModTrans;
		 
	char cChoice = 'Y';
	
	// Loops if the person still wants to modify some pairs
	while (cChoice != 'N')
	{
		// Prompts the user on what entry that they want to update and gets the index of the entry that they want to update
		nModEntry = ModifyEntry(d, nCount);
		
		// Checks if the user did or did not follow instructions				
		if (nModEntry >= -1)
		{
			// Prompts the user on what pair that they want to update and gets the index of the pair that they want to update
			nModTrans = ModifyTranslation(&d[nModEntry]);
			
			// Checks if the user did or did not follow instructions
			if (nModTrans >= -1)
			{
				// Prompts the user to update the pair.
				printf("Please type in the updated language.\n");
				scanf(" %s", d[nModEntry].aTrans[nModTrans].strLang);
				printf("Please type in the updated word.\n");
				scanf(" %s", d[nModEntry].aTrans[nModTrans].strWord);
			}
			else
			{
				// Goes out of the loop if the user has an error
				cChoice = 'N';
			}
		}
		else
		{
			// Goes out of the loop if the user has an error
			cChoice = 'N';
		}
		
		// Prompts the user if the person wants to update mort entries / pairs.
		printf("Do you want to modify more entries? Press \'Y\' to continue, otherwise, press \'N\' to go back to the main menu. ");
		scanf(" %c", &cChoice);
		cChoice = toupper(cChoice);
		
		// Loops if the user does not follow instructions
		while (cChoice != 'Y' && cChoice != 'N')
		{
			printf("Error. ");
			printf("Do you want to modify more entries? Press \'Y\' to continue, otherwise, press \'N\' to go back to the main menu. ");
			scanf(" %c", &cChoice);
			cChoice = toupper(cChoice);
		}
	}
}

/* DeleteEntry returns the index of the entry that the user wants to delete.
 @param d[] - a struct dictType array that contains information regarding the amount of translation inside entries
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns the index of the entry that you want to delete
*/

int DeleteEntry(dictType d[], int *nCount)
{
	int j = 0, 
		k, 
		nChoice = 0;
	
	// Loops if the user does not want to quit the application
	while (nChoice == 0)
	{
		// Displays all the entries one by one
		printf("%d)\n", j + 1);
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			printf("%s: %s\n", d[j].aTrans[k].strLang, d[j].aTrans[k].strWord);
		}
		
		// Prompts the user if the user wants to go to the next entry or they want to delete a certain entry.
		printf("\n\nPress \"0\" to look at the next translation, Otherwise type in the number that you would like to delete. ");
		scanf("%d", &nChoice);
		
		// Checks if the uiser chooses to look the next entry
		if (nChoice == 0)
		{
			j++;
		}
	}
	
	// Checks if the user makes an error in input
	if (nChoice > *nCount || nChoice < 0)
	{
		// Prints an error message, then returns -1
		printf("Error.\n\n");
		return -1;
	}
	else
	{
		// Return the index of the entry
		return nChoice - 1;
	}
	
}

/* DeleteTranslation returns the index of the entry that the user wants to delete.
 @param *pD - an address of where the entry is located inside the dictionary
 @returns the index of the pair that you want to delete
*/

int DeleteTranslation(dictType *pD)
{
	int j, 
		nChoice = 0;
	
	// Loops if the user does not want to quit the application
	while (nChoice != -1)
	{
		// Prints all the pairs inside an entry
		for (j = 0; j < pD->nCountTrans; j++)
		{
			printf("%d) %s: %s\n", j + 1, pD->aTrans[j].strLang, pD->aTrans[j].strWord);
		}
		
		// Prompts the user to type in the number that they want to delete
		printf("Please type in the number that you would like to delete. ");
		scanf("%d", &nChoice);
		
		// Checks if the user does not follow instructions
		if (nChoice > pD->nCountTrans || nChoice < 0)
		{
			// Prompts the user if the person still wants to continue deleting
			printf("\nError. Do you still want to delete entries? ");
			printf("Press \'0\' to continue, otherwise, press \'1\' to go back to the main menu. ");
			scanf("%d", &nChoice);
			
			// Loops if the user does not follow instructions
			while (nChoice != 0 && nChoice != 1)
			{
				printf("Error. ");
				printf("Press \'0\' to continue, otherwise, press \'1\' to go back to the main menu. ");
				scanf("%d", &nChoice);
			}
			
			// Forces the application to close if the user chooses to quit
			if (nChoice == 1)
			{
				nChoice = -1;
			}
		}
		else
		{
			// Returns index if the user has input a proper number
			return nChoice - 1;
		}
	}
	
	// Returns -1 if the user quits the application
	return nChoice;
}

/* DisplayAllEntries displays entries one by one
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
*/

void DisplayAllEntries(dictType d[], int *nCount)
{
	int  j = 0, 
		 k = 0, 
		 nNum = 0;
		 
	char cChoice = 'Y';
	
	printf("\n\n");
	
	// Loops if the user still wants to look at the entries
	while (cChoice != 'N')
	{
		// Prints one of the entries
		printf("%d)\n", j + 1);
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			nNum++;
			printf("%d. %s: %s\n", k + 1, d[j].aTrans[k].strLang, d[j].aTrans[k].strWord);
		}
		nNum = 0;
		
		// Prompts the user to choose whether to look at the next entry or go back to the main menu
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
		
		// Checks if the user wants to see the next entry
		if (cChoice == 'Y')
		{
			// Checks if the user is at the last entry
			if (j > *nCount - 2)
			{
				// Prints out an error message, then goes back to the last entry
				printf("This is the last entry.\n");
				j = *nCount - 1;
			}
			else
			{
				// Shows another entry
				j++;
			}
		}
	}
}

/* SearchWord searches the language translation pairs of a word.
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @param word - a string of 20 characters that the user wants to see the translation of
*/

void SearchWord (dictType d[], int *nCount, string20 word)
{
	int  j, 
	     k, 
		 nWord = 0, 
		 nNum = 1,
		 aPositions[*nCount];
		 
	char cChoice;
	
	// Loops to find the word and puts it in an array
	for (j = 0; j < *nCount; j++)
	{
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			if (strcmp(word, d[j].aTrans[k].strWord) == 0)
			{
				aPositions[nWord] = j;
				nWord++;
				k = d[j].nCountTrans + 1;
			}
		}
	}
	
	// Checks if there is more than one entry
	if (nWord > 1)
	{
		// Prints out the entries that are similar one by one
		printf("Here's the result of the following translation:\n");
		
		j = 0;
		
		// Loops if the user wants to see the next entry
		while (cChoice != 'N')
		{
			// Prints the language translation pair
			for (k = 0; k < d[aPositions[j]].nCountTrans; k++)
			{
				printf("%d) %s: %s\n", nNum, d[aPositions[j]].aTrans[k].strLang, d[aPositions[j]].aTrans[k].strWord);
				nNum++;
			}
			
			// Prompts the user if they want to see the next entry or if they want to go back to main menu.
			printf("See next translation? Press \"Y\" to go next and \"N\" to go back to the main menu. ");
			scanf(" %c", &cChoice);
			cChoice = toupper(cChoice);
			
			// Loops if the user does not follow instructions
			while (cChoice != 'Y' && cChoice != 'N')
			{
				printf("Error. ");
				printf("See next translation? Press \"Y\" to go next and \"N\" to go back to the main menu. ");
				scanf(" %c", &cChoice);
				cChoice = toupper(cChoice);
			}
			
			// Checks if the user wants to see the next entry
			if (cChoice == 'Y')
			{
				// Checks if the current entry's index is less than the list of numbers of similar words
				if (j < nWord)
				{
					j++;
				}
				else
				{
					// Goes back to the last entry of the word
					printf("\n\nThis is the last entry.\n");
					j = nWord - 1;
				}
			}
		}
	}
	// Checks if the number of similar words is just one
	else if (nWord == 1)
	{
		// Prints out the entry
		printf("Here's the result of the following translation:\n");
		
		for (k = 0; k < d[aPositions[nWord - 1]].nCountTrans; k++)
		{
			printf("%d) %s: %s\n", j, d[aPositions[j]].aTrans[k].strLang, d[aPositions[j]].aTrans[k].strWord);
		}
	}
	// Checks if there are no similar words
	else
	{
		// Prints if there are no translations available.
		printf("No translations available.\n\n");
	}
	
	nNum = 1;
	nWord = 0;
}

/* SearchWord searches the language translation pairs of a word.
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @param lang - a string of 20 characters that the language the user want to see the translation of
 @param word - a string of 20 characters that the user wants to see the translation of
*/

void SearchTranslation(dictType d[], string20 lang, string20 word, int *nCount)
{
	int  j, 
		 k, 
		 nWord = 0, 
		 nNum = 1,
		 aPositions[*nCount];
		 
	char cChoice;
	
	// Loop to check if there are similar words
	for (j = 0; j < *nCount; j++)
	{
		for (k = 0; k < d[j].nCountTrans; k++)
		{
			if (strcmp(word, d[j].aTrans[k].strWord) == 0 && strcmp(lang, d[j].aTrans[k].strLang))
			{
				aPositions[nWord] = j;
				nWord++;
			}
		}
	}
	
	// Checks if there is more than one entry
	if (nWord > 1)
	{
		// Prints out the entries that are similar one by one
		printf("Here's the result of the following translation:\n");
		
		j = 0;
		
		// Loops if the user wants to see the next entry
		while (cChoice != 'N')
		{
			// Prints the language translation pair
			for (k = 0; k < d[aPositions[j]].nCountTrans; k++)
			{
				printf("%d) %s: %s\n", nNum, d[aPositions[j]].aTrans[k].strLang, d[aPositions[j]].aTrans[k].strWord);
				nNum++;
			}
			
			// Prompts the user if they want to see the next entry or if they want to go back to main menu.
			printf("See next translation? Press \"Y\" to go next and \"N\" to go back to the main menu. ");
			scanf(" %c", &cChoice);
			cChoice = toupper(cChoice);
			
			// Loops if the user does not follow instructions
			while (cChoice != 'Y' && cChoice != 'N')
			{
				printf("Error. ");
				printf("See next translation? Press \"Y\" to go next and \"N\" to go back to the main menu. ");
				scanf(" %c", &cChoice);
				cChoice = toupper(cChoice);
			}
			
			// Checks if the user wants to see the next entry
			if (cChoice == 'Y')
			{
				// Checks if the current entry's index is less than the list of numbers of similar words
				if (j < nWord)
				{
					j++;
				}
				else
				{
					// Goes back to the last entry of the word
					printf("\n\nThis is the last entry.\n");
					j = nWord - 1;
				}
			}
		}
	}
	// Checks if the number of similar words is just one
	else if (nWord == 1)
	{
		// Prints out the entry
		printf("Here's the result of the following translation:\n");
		
		for (k = 0; k < d[aPositions[nWord - 1]].nCountTrans; k++)
		{
			printf("%d) %s: %s\n", j, d[aPositions[j]].aTrans[k].strLang, d[aPositions[j]].aTrans[k].strWord);
		}
	}
	else
	{
		// Prints if there are no translations available.
		printf("No translations available.\n\n");
	}
	
	nNum = 1;
	nWord = 0;
}

/* Export function exports the data inside the dictionary and converts it into a text file
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns - an integer whether it is successful in exporting or not
 
 Pre-conditions: file name should never exceed 30 characters (including the tag at the end)
*/


int Export (dictType d[], int *nCount)
{
	FILE     *fp;
	
	string30 filename;
	int      j, 
			 k;
	
	// Prompts user to type in a file name
	printf("Enter file name: ");
	scanf(" %s", filename);
	
	// Creates (if the file name is unique) or replaces (if the file name has a same file with the same name) 
	// the file and updates it to what the dictionary has currently.
	fp = fopen(filename, "w");
	
	// Checks if there is a file present
	if (fp == NULL)
	{
		// Prints out an error message and returns 0;
		printf("File does not exist.\n");
		return 0;
	}
	else
	{
		// Prints out the contents of the dictionary
		for (j = 0; j < *nCount; j++)
		{
			for (k = 0; k < d[j].nCountTrans; k++)
			{
				fprintf(fp, "%s: %s\n", d[j].aTrans[k].strLang, d[j].aTrans[k].strWord);
			}
			fprintf(fp, "\n");
		}
		
		// Closes the file
		fclose(fp);
		// Returns 1 when finished
		return 1;
	}
}

/* Import fuinction takes the data inside the text file and puts it inside the dictionary
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 @returns - an integer whether it is successful in exporting or not
 
 Pre-conditions: file name should never exceed 30 characters (including the tag at the end)
*/

int Import (dictType d[], int *nCount)
{
	FILE     *fp;
	string30 filename;
	string20 lang, 
			 word;
	string40 pair;
	char     cChoice;
	
	// Prompts user to type in a file name
	printf("Enter file name: ");
	scanf(" %s", filename);
	
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
					// Prints out the entries that are found inside the text file
					printf("\n\nDo you want to add these words to the entry?\n");
					printf("%s: %s\n", lang, word);
					
					// Prompts the user if they want to add the entry or not
					printf("Press \"Y\" to continue. Otherwise, press \"N\" to go to the next entry. ");
					scanf(" %c", &cChoice);
					cChoice = toupper(cChoice);
					
					// Loops if the user does not follow instructions
					while (cChoice != 'Y' && cChoice != 'N')
					{
						printf("Error. ");
						printf("Press \"Y\" to continue. Otherwise, press \"N\" to go to the next entry. ");
						scanf(" %c", &cChoice);
						cChoice = toupper(cChoice);
					}
					
					// Checks if the user wants the entry to be put inside the dictionary
					if (cChoice == 'Y')
					{
						// Adds the word and the language to their respective places inside the word
						strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strLang, lang);
						strcpy(d[*nCount].aTrans[d[*nCount].nCountTrans].strWord, word);
						// Counts how many pairs are there inside an entry
						d[*nCount].nCountTrans += 1;
					}
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

/* IdentifyMainLanguage counts how many foreign languages are there inside a sentence
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
*/

void IdentifyMainLanguage(dictType d[], int *nCount)
{
	int  j, 
		 k, 
		 l, 
		 m,
		 nWords = 0,  
		 nNum = 0, 
		 nLangCount = 0,
		 nFound = 0,
		 nSum = 0;
		 
	char delim[2] = " ";
	char *ptr;
	
	string150 sentence;
	
	string20 words[ENTRIES], 
			 lang[ENTRIES];
	
	// Prompts the user to type in the sentence that they would like to know the count of
	printf("\n\nType in the sentence that you want to identify:\n");
	scanf(" %[^\n]%*c", sentence);
	
	// Function to separate the words inside a sentence
	ptr = strtok(sentence, delim);
	
	while (ptr != NULL)
	{
		// Puts the tokenized word inside the array
		strcpy(words[nWords], ptr);
		// Checks if the word ends in a symbol
		Check(words[nWords]);
		nWords++;
		// Puts a pointer to another word
		ptr = strtok(NULL, delim);
	}
	
	// Loops to see what language is the word in
	for (j = 0; j < nWords; j++)
	{
		for (k = 0; k < *nCount; k++)
		{
			for (l = 0; l < d[k].nCountTrans; l++)
			{
				// Checks if the word is in the dictionary
				if (strcmp(words[j], d[k].aTrans[l].strWord) == 0)
				{
					// Checks if the language is already in the lang array for a certain word
					for (m = nLangCount; m < nNum; m++)
					{
						if (strcmp(d[k].aTrans[l].strLang, lang[m]) == 0)
						{
							nFound = 1;
						}
					}
					
					// Adds the language if it didn't find the language for the wordd
					if (nFound == 0)
					{
						strcpy(lang[nNum], d[k].aTrans[l].strLang);
						nNum++;
					}
				}
			}
		}
		nLangCount = nNum;
		nFound = 0;
	}
	
	// Arranges the array of languages into alphabetical order
	SortArray(lang, &nNum);
	
	printf("Results:\n");
	
	// Calculates and prints out the number of a certain language
	for (j = 0; j < nNum; j++)
	{
		if (strcmp(lang[j], lang[j+1]) == 0)
		{
			nSum++;
		}
		else
		{
			nSum++;
			printf("%s: %d\n", lang[j], nSum);
			nSum = 0;
		}
	}
}

/* SimpleTranslation translates a sentence and converts it to another translation with the language requested
 @param d[] - a struct dictType array that has all the translations
 @param *nCount - address corresponding to the number of words / translations inside the dictType array
 Reference: https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character
*/

void SimpleTranslation(dictType d[], int *nCount)
{	
	int       j, 
		      nWords = 0,
	 	      nWhere1 = 0, 
		      nWhere2 = 0;
		 
	char      delim[2] = " ";
	char      *ptr;
	string20 words[ENTRIES],
			 trans[ENTRIES];
	
	string150 sentence;
	string20  lang;
	
	// Prompts the user to type in the sentence
	printf("\n\nType in the sentence that you want to translate:\n");
	scanf(" %[^\n]%*c", sentence);
	
	// Prompts the user to type in the language that the user wants to be translated
	printf("\nType the language that you want the sentence to be translated to:\n");
	scanf(" %s", lang);
	
	// Function to separate the words inside a sentence
	ptr = strtok(sentence, delim);
	
	while (ptr != NULL)
	{
		// Puts the tokenized word inside the array
		strcpy(words[nWords], ptr);
		Check(words[nWords]);
		nWords++;
		
		// Puts a pointer to another word
		ptr = strtok(NULL, delim);
	}
	
	for (j = 0; j < nWords; j++)
	{
		printf("%s\n", words[j]);
	}
	
	// Loops to see what are the translations of the words in the array
	for (j = 0; j < nWords; j++)
	{
		if (FoundTrans(words[j], lang, d, nCount, &nWhere1, &nWhere2) == 1)
		{
			strcpy(trans[j], d[nWhere1].aTrans[nWhere2].strWord);
		}
		else
		{
			strcpy(trans[j], words[j]);
		}
	}
	
	printf("Translation: ");
	
	// Prints the translations of the words
	for (j = 0; j < nWords; j++)
	{
		printf("%s ", trans[j]);
	}
}
