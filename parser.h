#ifndef PARSER
#define PARSER

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BBUFSIZE 1024 * 1024
#define SEPAR "\t\r\n /"

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
	int readTag();
	int readAtr();
public:
	void addWord(const char * str);
	char * printList(char * b);
	int readHtml();
	elHtml(const char * t, const char * a);
	~elHtml();
};

#endif