#ifndef PARSER
#define PARSER

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
public:
	int readHtml();
	void addWord(const char * str);
	void sortList(int isAsc);
	char * printList(char * b);
	elHtml(const char * t, const char * a);
	~elHtml();
};

#endif