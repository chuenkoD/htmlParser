#ifndef PARSER
#define PARSER

#include <stdio.h>

#define BBUFSIZE 1024 * 1024

struct listWrd
{
	char * w;
	listWrd * next;
	listWrd();
	listWrd(const char * word);
	~listWrd();
};

class elHtml
{
	char * tag;
	char * atr;
	listWrd * l;

	char * printList(char * b);

	elHtml(const char * t, const char * a);
	~elHtml();
};

#endif