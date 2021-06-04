#include "parser.h"

int isCumment(const char * str)
{
	if (str)
		if ((str[0] == '<' && str[1] == '!' && str[2] == '-' && str[3] == '-') ||
			(str[0] == '-' && str[1] == '-' && str[2] == '>'))
			return 1;
	return 0;
}

int elHtml::readTag()
{
	char buf[BBUFSIZE];

	while (fread(buf, sizeof(char), BBUFSIZE - 1, stdin))
	{

	}
	return 1;
}

int elHtml::readAtr()
{
	char buf[BBUFSIZE] = {0};
	if (fread(buf, sizeof(char), BBUFSIZE - 1, stdin))// читаємо файл
	{
		char * i = strchr(buf, '<');// знаходимо кінець тегу доктайп
		while (i ? *i : 0)// перевірка на 0
		{
			char * sTag = strchr(i, '<');// знаходимо тег
			i = sTag;
			printf("sTag %d %c\n", (int)strlen(i), i[1]);
			if (sTag ? (sTag[1] != '/' && sTag[1] != '!') : 0)// перевірка
			{// на кінцевий тег або комментар
				i = strchr(i, ' ');
				if (i)// знаходження пробілу після назви тегу
					*i = 0;

				++i;// початок атрибуту
				char * sAtr = i;// початок атрибуту
				printf("sAtr %d %c\n", (int)strlen(i), *i);
				char * sAtrPar = 0;
				while (*i != '>' && *i != '/')// перевірка на кінець
				{
					i = strchr(i, '=');
					*i = 0;// кінець атрибуту
					i = strchr(i + 1, '\"');// початок параметру
					if (strcasecmp(atr, sAtr) == 0)
					{
						sAtrPar = ++i;// початок параметру
						printf("sPar %d %c\n", (int)strlen(i), *i);
						i = strchr(i, '\"');// кінець параметру
						*i = 0;
						if (tag ? strcasecmp(tag, sTag) == 0 : 1)// перевірка тегу
							addWord(sAtrPar);
						i += 2;
					}
					else
					{
						i = strchr(i + 1, '\"') + 1;
					}
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
				i = strchr(i, '>') + 1;// знаходження кінця тегу
			printf("%d %c\n", (int)strlen(i), *i);
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

static char * printBuf[BBUFSIZE];
char* elHtml::printList(char * b)
{
	if (b)
	{
		for (listWrd * i = l; i; i = i->next)
			sprintf(b, "%s\n", i->w);
		return b;
	}
	for (listWrd * i = l; i; i = i->next)
		sprintf((char * const)printBuf, "%s\n", i->w);
	return (char* const)printBuf;
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
		strcpy(atr, a);
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

	for (listWrd * i = l; i; i = l)
	{
		l = l->next;
		delete i;
	}
}