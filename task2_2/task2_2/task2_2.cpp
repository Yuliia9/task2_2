/**
* @file		task2_2.cpp
* @brief	Program creates vocabluary of foreign word and it's transliteration translation,
			random chooses words for testing and estimates percentage of correct answers
*
* Copyright 2014 by Yuliia Lyubchik
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*/


#include "stdafx.h"
#include "task2_2.h" /*defines data types and prototypes of used in this file functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;


int main()
{
	Interface();
	
	unsigned int num;
	unsigned char retCode;
	do 
	{
		printf("Enter how many words do you want to add to your vocabluary: ");
		retCode = scanf("%u",&num);
		fflush(stdin); // Flush the input buffer

	} while (Type_checking(retCode, (int) num) == ERROR);

	printf("Vocabluary will consist of %u word(s).\n", num);

	struct vword* vocabluary = (vword*) malloc(num*sizeof(vword));
	if (vocabluary == NULL)
	{
		printf("Error occurs while trying to allocate memory for vocabluary. \n");
		return (int)ERROR;
	}
	

	retCode = Input(vocabluary, num);
	if (retCode == ERROR)
	{
		printf("Error occurs while trying to input data. \n");
		free(vocabluary);
		return (int)ERROR;
	}


	retCode =  Words_Tester(vocabluary, num);
	if (retCode == ERROR)
	{
		printf("Error occurs while trying to train words.\n");
		free(vocabluary);
		return (int) ERROR;
	}

	free(vocabluary);
	system("pause");
	return MAIN_SUCCESS;
}


void Interface()
{
	printf("----------------------------------------------------------------------------\n");
	printf("Welcome to your personal language trainer!. \n\n");
	printf("Enter English words and it's transliteration translation in Ukraine language.\n");
	printf("Without spaces!\n");
	printf("For example, family-simia. Maximum length of word/translation 20. \n");
	printf("---------------------------------------------------------------------------\n\n");
	
}


unsigned char Type_checking(unsigned char retCode, int val)
{
	if (retCode == ERROR)
	{
		printf("Type mismatch. Please next time check if you enter integer number. \n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The value can not be negative or zero.\n");
		return ERROR;
	}
	return SUCCESS;
}



unsigned char Input(struct vword* vocabluary, unsigned int num)
{
	if (vocabluary == NULL)
	{
		printf("Error occurs while trying to get access to memory.\n");
		return ERROR;
	}
	char temp[LEN * 2 + 1];
	unsigned int i;
	int j;
	const char  separator = '-';
	unsigned char retCode;
	

	for (i = 0; i < num; ++i)
	{
		printf("%i word: ", i + 1);
		gets(temp);
		
		j = strchr(temp, separator) - temp;
		if (j <= 0)
		{
			printf("Please enter word and it's translation! \n");
			--i;
			continue;
		}
		temp[j] = '\0';
		for (;;)
		{
			if (temp[j+1] == ' ')
			{	
				++j;
			}
			else break;
		} 
		strcpy(vocabluary[i].translation, temp + j + 1);
		
		strcpy(vocabluary[i].word, temp);
		vocabluary[i].tested = 0;
		printf("%s", vocabluary[i].word);
		printf("%s", vocabluary[i].translation);
	}
	return SUCCESS;
}



unsigned char Words_Tester(struct vword *vocabluary, unsigned int vocablen)
{
	if (vocabluary == NULL)
	{
		printf("Error occurs while training to get data. \n");
		return ERROR;
	}

	unsigned char retCode;
	unsigned int attemp;
	
	do
	{
		printf("\nEnter how many words do you want to train: ");
		retCode = scanf("%u", &attemp);
		fflush(stdin); // Flush the input buffer
	} while (Type_checking(retCode, (int) attemp) == ERROR);

	


	system("cls");
	if (attemp>vocablen)
	{
		printf("The number is bigger than vocabluary length so we just gonna train all words\n ");
		attemp = vocablen;
	}
	
	char temp[LEN * 2 + 1];
	unsigned int correctansw = 0, i = 0, j;
	printf("Let's check you knowledge. \nEnter translation for following words.\n");

	while (i < attemp)
	{
		j = rand() % vocablen;
		if (vocabluary[j].tested == 0)
		{
			vocabluary[j].tested = 1;
		}
		else 
		{
			continue;
		}
			
		++i;
		printf("%s", vocabluary[j].word);
		printf("-\t");
		gets(temp);

		if (strcmp(temp, vocabluary[j].translation) == 0)
		{
			++correctansw;
		}
	}

	printf("Percentage of correct answers is %0.2f percent \n", (float)correctansw / attemp * 100);
	return SUCCESS;
}