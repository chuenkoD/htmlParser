#include "parser.h"

listWrd::listWrd()
{
	w = 0;
	next = 0;
}

listWrd::listWrd(const char * word)
{
	w = new char[strlen(word) + 1];
	strcpy(w, word);
	next = 0;
}

listWrd::~listWrd()
{
	if (w)
	{
		delete[] w;
		w = 0;
	}
	next = 0;
}