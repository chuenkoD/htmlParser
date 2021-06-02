#include "parser.h"

int elHtml::readTag()
{
	char buf[BBUFSIZE];

	while (fread(buf, sizeof(char), BBUFSIZE, stdin))
	{

	}
	return 1;
}

int elHtml::readAtr()
{
	char buf[BBUFSIZE];

	while (fread(buf, sizeof(char), BBUFSIZE - 1, stdin))
	{
		char * sTag = (char*)memchr(buf, '<', BBUFSIZE);
		if (sTag)
		{
			if (sTag[1] != '/')
			{
				char * eTag = (char*)memchr(buf, '>', BBUFSIZE);
				if (eTag)
					*eTag = 0;
				char * t = new char[strlen(sTag)];
				strcpy(t, sTag + 1);
				if (tag)
				{
					if (strcmp(tag, t))
					{
						char * i = strtok(buf, SEPAR);
						if (strcmp(i, tag))
						{
							for (; i; i = strtok(0, SEPAR))
								if (strcmp(atr, i))
								{

								}
						}
					}
				}
				else
				{

				}
				delete[] t;
			}
		}
	}
	return 1;
}

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

void elHtml::addWord(const char * str)
{
	listWrd * t = new listWrd(str);
	if (l)
	{
		for (listWrd * i = l; i; i = i->next)
			if (i->next == 0)
				i->next = t;
	}
	else
		l = t;
}

static char* buf[BBUFSIZE];
char* elHtml::printList(char * b)
{
	if (b)
	{
		for (listWrd * i = l; i; i = i->next)
			sprintf(b, "%s\n", i->w);
		return b;
	}
	for (listWrd * i = l; i; i = i->next)
		sprintf((char * const)buf, "%s\n", i->w);
	return (char* const)buf;
}

int elHtml::readHtml()
{
	return atr == 0 ? readTag() : readAtr();
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
	l = 0;
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