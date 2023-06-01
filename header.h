/********************************************************************************************************* 
This is to certify that this project is my own work, based on my personal efforts in studying and applying 
the concepts learned. I have constructed the functions and their respective algorithms and corresponding 
code by myself. The program was run, tested, and debugged by my own efforts. I further certify that I have 
not copied in part or whole or otherwise plagiarized the work of other students and/or persons.
 															  Chong, Jordan Chester Sze, DLSU ID# 12140183 
*********************************************************************************************************/

#define ENTRIES 150
#define TRANSLATIONS 10
#define STRING 21
#define FILENAME 30

typedef char string20[STRING];
typedef char string40[STRING * 3];
typedef char string150[ENTRIES + 1];
typedef char string30[FILENAME + 1];

typedef struct wordTag
{
	string20    strWord;
	string20    strLang;
}wordType;

typedef struct dictTag
{
	struct wordTag aTrans[TRANSLATIONS];
	int            nCountTrans;
}dictType;
