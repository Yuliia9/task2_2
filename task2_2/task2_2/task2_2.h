#include "stdafx.h"

/* maximum length of word/translation*/
const int LEN = 20;

struct vword
{
	char word[LEN];
	char translation[LEN];
	int tested;
};

/*displays some information about program*/
void Interface();

/*checking entered data and return 0 if type doesn't match requirements*/
unsigned char Type_checking(int retCode, int val);


/*input coordinates of space points into list of points return 0 if some data doesn't match requirements*/
unsigned char Input(struct vword* vocabluary, unsigned int num);


/*tests chosen number of words from vocabluary and show the percent of correct answers
takes as argument pointer on struct array and number of vocabluary words in created vocabluary*/
void Words_Tester(struct vword* vocabluary, unsigned int vocablen);

