#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* maximum length of word/translation*/
const int LEN = 20;

struct vocabl_word
{
	char word[LEN];
	char translation[LEN];
	int tested;
};
/*tests chosen number of words from vocabluary and show the percent of correct answers
takes as argument pointer on struct array and number of vocabluary words in created vocabluary*/
void Words_Tester(struct vocabl_word *vocabluary, unsigned int vocablen);

int main()
{
	
	printf("Welcome to your personal language trainer!.\n\n");
	printf("Enter English words and its translation on transliteration Ukraine language.\n");
	printf("For example, family-simia. Maximum length of word/translation 20. \n\n");
	printf("Enter how many words do you want to add to your vocabluary: ");

	unsigned int num_of_words;
	int retCode = scanf("%u",&num_of_words);
	if (retCode == 0)
	{
		printf("Type mismatch. Next time please enter integer number;)");
		return 0;
	}
	
	struct vocabl_word* vocabluary = (vocabl_word*) malloc(num_of_words*sizeof(vocabl_word));

	char temp[LEN * 2 + 1];
	int j;
	const char  separator = '-';

	

	for (int i = 0; i < num_of_words; i++)
	{
		printf("%i word: ", i + 1);
		scanf("%s", &temp);
		j = strchr(temp, separator) - temp;
		strcpy(vocabluary[i].translation, temp + j + 1);
		temp[j] = '\0';
		strcpy(vocabluary[i].word, temp);
		vocabluary[i].tested = 0;
	}


	
	Words_Tester(vocabluary, num_of_words);
	free(vocabluary);
	return 0;
}


void Words_Tester(struct vocabl_word *vocabluary, unsigned int vocablen)
{
	int attemp;
	printf("\nEnter how many words do you want to train: ");
	scanf("%i", &attemp);
	if (attemp>vocablen)
	{
		printf("The number is bigger than vocabluary length so we just gonna train all words\n ");
		attemp = vocablen;
	}

	system("cls");

	
	char temp[LEN * 2 + 1];
	int correctansw = 0, i = 0, j;
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
		scanf("%s", &temp);

		if (strcmp(temp, vocabluary[j].translation) == 0)
		{
			++correctansw;
		}
	}

	printf("Percentage of correct answers is %0.2f percent \n", (float)correctansw / attemp * 100);
}