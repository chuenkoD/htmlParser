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
	delete[] w;
	w = 0;
	next = 0;
}

static char * buf[BBUFSIZE];
char* elHtml::printList(char * b)
{
	if (b)
	{
		for (listWrd * i = l; i; i = i->next)
			sprintf(b, "%s\n", i->w);
		return b;
	}
	for (listWrd * i = l; i; i = i->next)
		sprintf(buf, "%s\n", i->w);
	return buf;
}

elHtml::elHtml(const char * t, const char * a)
{
	if (t)
	{
		tag = new char[strlen(t) + 1];
		strcpy(tag, t);
	}
	if (a)
	{
		atr = new char[strlen(a) + 1];
		strcpy(atr, t);
	}
}

elHtml::~elHtml()
{
	if (tag)
	{
		delete[] tag;
		tag = 0;
	}
	if (atr)
	{
		delete[] atr;
		atr = 0;
	}
}