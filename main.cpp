#include "header.h"
#include "parser.h"

int main(int argc, char ** argv)
{
	char vFlag = 0;
	int isAsc = -1;
	char * tag = 0;
	char * atr = 0;

	for (int i = 1; i < argc; ++i)
	{
		if (isHelp(argv[i]))
			help(argv[0]);
		else if (keycmp(argv[i], "v"))
			vFlag = 1;
		else if (keycmp(argv[i], "asc"))
			isAsc = 1;
		else if (keycmp(argv[i], "desc"))
			isAsc = 0;
		else if (keycmp(argv[i], "t") && i + 1 < argc)
			tag = argv[++i];
		else if (keycmp(argv[i], "a") && i + 1 < argc)
			atr = argv[++i];
	}
	if (tag == 0 && atr == 0)
	{
		fprintf(stderr, "Error\n");
		exit(1);
	}
	elHtml e = elHtml(tag, atr);
	if (e.readHtml())
	{
		if (isAsc != -1)
			e.sortList(isAsc);
		cout << e.printList(0);
	}
}