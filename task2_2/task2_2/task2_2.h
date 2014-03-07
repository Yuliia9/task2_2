/**
* @file		task2_2.h
* @brief	header file for task2_2.cpp
			defines data types and prototypes for functions used in task2_2.cpp
*/

#include "stdafx.h"

/* maximum length of word/translation in vocabluary*/
const int LEN = 20;

/*defines data type for holding word, it's translation and mark that shows if word was tested*/
struct vword
{
	char word[LEN];
	char translation[LEN];
	int tested;
};


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface();




/**
* @brief						Checking if data match requirements set to that data types or functions return values

* @param	[in]				unsigned char retCode - return value of other functions for checking if functions ended properly
			[in]				int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);




/**
* @brief					Function for input words and their transliteration translation
* @param	[in/out]		struct vword* vocabluary - pointer to array of structures that holds words and their translation
			[in]			unsigned int num - the capacity of vocabulary
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was inputed
*/
unsigned char Input(struct vword* vocabluary, unsigned int num);





/**
* @brief					Function for testing chosen number of words from vocabluary 
							and showing the percentage of correct answers

* @param	[in/out]		struct vword* vocabluary - pointer to array of structures that holds words and their translation
			[in]			unsigned int vocablen - the capacity of vocabulary
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if words were tested and percentage of correct answers was shown
*/
unsigned char Words_Tester(struct vword* vocabluary, unsigned int vocablen);

