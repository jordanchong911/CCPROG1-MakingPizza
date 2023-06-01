/********************************************************************************************************* 
This is to certify that this project is my own work, based on my personal efforts in studying and applying 
the concepts learned. I have constructed the functions and their respective algorithms and corresponding 
code by myself. The program was run, tested, and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
 															  Chong, Jordan Chester Sze, DLSU ID# 12140183 
*********************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "header.h"
#include "utils.c"
#include "functions.c"


int main()
{
	dictType aDictionary[ENTRIES];
	
	int 	 j, 
	         nStartMenu = 0, 
		     nManageData = 0, 
		     nLanguageTools = 0, 
		     nCount = 0,
		     nDelTrans = 0, 
		     nDelEntry = 0,
		     nChoice = 0;
		     
	string20 lang, 
			 word;
			 
	string30 filename;
	
	// Loop to check where the user wants to exit or not
	while (nStartMenu != 3)
	{
		// Gets input from user on where the person wants to go to
		StartMenu(&nStartMenu);
		// Switch statements for the user to move accross the selections
		switch(nStartMenu)
		{
			// Case 1 goes to "Manage Data" functions
			case 1:
				nManageData = 0;
				while (nManageData != 11)
				{
					// Gets inpt from user on what function does the user want
					ManageData(&nManageData);
					switch(nManageData)
					{
						// Case 1 for Manage Data is "Add Entries"
						case 1:
							// Checks if the number of entries are full or not.
							if (nCount == ENTRIES)
							{
								// Prints error messgae if the entries are full
								partition();
								printf("Max number of entries reached.\n");
								partition();
							}
							else
							{
								// Goes to function to add entries to the dictionary
								partition();
								printf("\n");
								AddEntry(aDictionary, &nCount);
								printf("\n");
								partition();
								printf("\n");
							}
							break;
						// Case 2 for Manage Data is "Add Translations"
						case 2:
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Goes to function to add translations in an entry
							partition();
							AddTranslations(aDictionary, &nCount);
							partition();
							break;
						// Case 3 for Manage Data is "Modify Entries"
						case 3:
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							partition();
							// Goes to function to modify entries inside the dictionary
							Modify(aDictionary, &nCount);
							partition();
							break;
						// Case 4 of Manage Data is "Delete Entry"
						case 4:
							partition();
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Prompts the user to find the entry that the user wants to delete
							printf("\nWhat entry would you like to delete?\n");
							nDelEntry = DeleteEntry(aDictionary, &nCount);
							
							// Checks if there's an error in nDelEntry function
							if (nDelEntry >= -1)
							{
								// Deletes the entry from the dictionary
								for (j = nDelEntry; j < nCount; j++)
								{
									aDictionary[j] = aDictionary[j + 1];
								}
								nCount -= 1;
							}
							
							nDelEntry = 0;
							
							partition();
							break;
						// Case 5 of Manage Data is "Delete Translations"
						case 5:
							partition();
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Prompts the user to delete their chosen translation
							printf("\n\nWhat translation would you like to delete?\n");
							
							nDelEntry = DeleteEntry(aDictionary, &nCount);
							
							// Checks if there's an error in nDelEntry function
							if (nDelEntry >= -1)
							{
								// Loop if the user wants to delete pairs
								while (nDelTrans != -1 && aDictionary[nDelEntry].nCountTrans != 0)
								{
									nDelTrans = DeleteTranslation(&aDictionary[nDelEntry]);
								
									if (nDelTrans >= -1)
									{
										// Loop to delete the pair from the entry
										for (j = nDelTrans; j < aDictionary[nDelEntry].nCountTrans; j++)
										{
											aDictionary[nDelEntry].aTrans[j] = aDictionary[nDelEntry].aTrans[j + 1];
										}
										
										// Decrement the amount of pairs inside an entry
										aDictionary[nDelEntry].nCountTrans -= 1;
									}
									
									// Checks if there are no more pairs inside an entry
									if (aDictionary[nDelEntry].nCountTrans == 0)
									{
										// Loop to delete the empty entry
										for (j = nDelEntry; j < nCount; j++)
										{
											aDictionary[j] = aDictionary[j + 1];
										}
										nCount -= 1;
										nDelTrans = -1;
									}
									
									// Prompt to ask user if the user wants to delete translations
									printf("Do you still want to delete translations? Press \"0\" to continue, else, press \"1\" to go back to main menu. ");
									scanf("%d", &nChoice);
									
									// Loop if the user does not follow instructions
									while (nChoice != 0 && nChoice != 1)
									{
										printf("Error. ");
										printf("Do you still want to delete translations? Press \"0\" to continue, else, press \"1\" to go back to main menu. ");
										scanf("%d", &nChoice);
									}
									
									// Forcefully end the loop
									if (nChoice == 1)
									{
										nDelTrans = -1;
									}
								}
							}
							
							nDelEntry = 0;
							nDelTrans = 0;
							
							partition();
							break;
						// Case 6 of Manage Data is "Display All Entries"
						case 6:
							partition();
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Checks if there are entries inside the dictionary.
							if (nCount == 0)
							{
								// Prints error message if there is no entries found inside the dictionary.
								printf("Error. No entries found.\n");
							}
							else
							{
								// Function to display all the entries
								DisplayAllEntries(aDictionary, &nCount);
							}
							
							partition();
							break;
						// Case 7 of Manage Data is "Search Word"
						case 7:
							// Loop to sort the translations inside entries to alphabetical order
							partition();
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Prompts the user to type in the word for searching
							printf("Enter the word that you want to search: ");
							scanf(" %s", word);
							
							// Puts the word into a function to search for it.
							SearchWord(aDictionary, &nCount, word);
							printf("\n\n");
							partition();
							break;
						// Case 8 of Manage Data is "Search Translation"
						case 8:
							partition();
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Prompts the user to type in the language the user wants to search
							printf("Enter the language that you want to search:\n");
							scanf(" %s", lang);
							// Prompts the user to type in the word that the user wants to search
							printf("\nEnter the word that you want to wordlate:\n");
							scanf(" %s", word);
							
							// Function to search the translation of the language translation pair
							SearchTranslation(aDictionary, lang, word, &nCount);
							partition();
							break;
						// Case 9 of Manage Data is "Export"
						case 9:
							partition();
							// Loop to sort the translations inside entries to alphabetical order
							for (j = 0; j < nCount; j++)
							{
								SortAlphabetical(&aDictionary[j]);
							}
							
							// Function to export dictionary data into a txt file
							Export(aDictionary, &nCount);
							break;
						// Case 10 of Manage Data is "Import"
						case 10:
							// Checks if import is successful or not
							if(!Import(aDictionary, &nCount))
							{
								// Prints if import is not successful
								printf("Error. Please type in a file currently inside the folder.\n\n");
							}
							else
							{
								// Prints if import is a success
								printf("\n\nSuccess!\n\n");
								partition();
								// Loop to sort the translations inside entries to alphabetical order
								for (j = 0; j < nCount; j++)
								{
									SortAlphabetical(&aDictionary[j]);
								}
							}
							break;
						// Case 11 of Manage Data is "Exit"
						case 11:
							break;
					}
				}
				partition();
				break;
			// Case 2 goes to "Language Tools" functions
			case 2:
				partition();
				nLanguageTools = 0;
				// Prompts the user to type in the txt file to import
				printf("\n\nBefore continuing, what file would you like to import to the database?\n");
				scanf(" %s", filename);
				if(ImportDatabase(aDictionary, &nCount, filename) == 1)
				{
					while (nLanguageTools != 3)
					{
						// Prompts the user to choose what function would you like to choose.
						LanguageTools(&nLanguageTools);
						switch(nLanguageTools)
						{
							// Case 1 of Language Tools is "Identify Main Language"
							case 1:
								// Function to identify the language of a sentence full of mixed translations
								IdentifyMainLanguage(aDictionary, &nCount);
								break;
							// Case 2 of Language Tools is "Simple Translation"
							case 2:
								// Function to identify the translations of the sentence
								SimpleTranslation(aDictionary, &nCount);
								break;
							// Case 3 of Language Tools is "Exit"
							case 3:
								break;
						}
					}
				}
				else
				{
					printf("Error. Please pick an existing file from your library.\n");
				}
				partition();
				break;
			// Case 3 goes to "Exit"
			case 3:
				nCount = 0;
				break;
		}	
		
		nCount = 0;
	}
	
	return 0;
}
