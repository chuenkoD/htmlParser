#include "parser.h"
#include "header.h"

int isCumment(const char * str)
{
	if (str)
		if ((str[0] == '<' && str[1] == '!' && str[2] == '-' && str[3] == '-') ||
			(str[0] == '-' && str[1] == '-' && str[2] == '>'))
			return 1;
	return 0;
}

int elHtml::readHtml()
{
	if (atr == 0)
		return 1;
	char buf[BBUFSIZE] = {0};
	if (fread(buf, sizeof(char), BBUFSIZE - 1, stdin))// читаємо файл
	{
		char * i = strchr(buf, '<');// знаходимо початок тегу
		while (i ? *i : 0)// перевірка на 0
		{
			i = strchr(i, '<');// знаходимо тег
			if (i == 0)
				return 1;
			char * sTag = i + 1;// початок тегу
			if ((sTag ? (sTag[1] != '/' && sTag[1] != '!') : 0) && (strchr(i, '>')[-1] == '\"' || strchr(i, '>')[-2] == '\"'))// перевірка
			{// на кінцевий тег або комментар
				i = strchr(i, ' ');
				if (i)// знаходження пробілу після назви тегу
					*i = 0;
				
				char * sAtr = i + 1;// початок атрибуту
				char * sAtrPar = 0;
				while (*i != '>' && *i != '/' )// перевірка на кінець
				{
					++i;
					i = strchr(i, '=');
					*i = 0;// кінець атрибуту
					i = strchr(i + 1, '\"');// початок параметру
					if (strcasecmp(atr, sAtr) == 0)
					{
						sAtrPar = ++i;// початок параметру
						i = strchr(i, '\"');// кінець параметру
						*i = 0;
						if (tag ? strcasecmp(tag, sTag) == 0 : 1)// перевірка тегу
						{
							addWord(sAtrPar);
						}
						++i;
					}
					else
						i = strchr(i + 1, '\"') + 1;// кінець параметру
					sAtr = i + 1; // початок атрибуту
				}
			}
			else if (isCumment(sTag))// перевірка на коментар
			{
				i = sTag;
				for (;*i;++i)
				{
					i = strchr(i, '-');// знаходження кінця коментарю
					if (isCumment(i))// перевірка на коментар
					{
						i += 3;// -->i
						break;
					}
				}
			}
			else
				i = strchr(i, '>');// знаходження кінця тегу
		}
	}
	return 1;
}

void elHtml::addWord(const char * str)
{
	if (l)
	{
		for (listWrd * i = l; i; i = i->next)
			if (i->next == 0)
			{
				i->next = new listWrd(str);
				break;
			}
	}
	else
		l = new listWrd(str);
}

static char printBuf[BBUFSIZE];
char* elHtml::printList(char * b)
{
	if (b == 0)
		b = printBuf;
	char * bi = b;
	for (listWrd * i = l; i; i = i->next)
	{
		sprintf(bi, "%s\n", i->w);
		bi = bi + strlen(i->w) + 1;
	}
	return b;
}

void elHtml::sortList(int isAsc)
{
	for (listWrd * i = l; i; i = i->next)
		for (listWrd * j = i->next; j; j = j->next)
			if ((strcmp(i->w, j->w) < 0 && isAsc == 0) ||
				(strcmp(i->w, j->w) > 0 && isAsc == 1))
			{
				char * t = i->w;
				i->w = j->w;
				j->w = t;
			}
}

elHtml::elHtml(const char * t, const char * a)
{
	if (t)
	{
		tag = new char[strlen(t) + 1];
		strcpy(tag, t);
	}
	else
		tag = 0;
	if (a)
	{
		atr = new char[strlen(a) + 1];
		strcpy(atr, a);
	}
	else
		atr = 0;
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

	for (listWrd * i = l; i; i = l)
	{
		l = l->next;
		delete i;
	}
}