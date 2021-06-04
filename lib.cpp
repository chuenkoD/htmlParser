#include "header.h"

int keycmp(const char * arg, const char * key)
{
    if (arg && key)
        if (*arg == '-' || *arg == '/')
            if (!strcasecmp(arg + 1, key))
                return 1;
    return 0;
}

int isHelp(const char* s)
{
    return keycmp(s, "h") + keycmp(s, "help") + keycmp(s, "?");
}

void help(const char* nm)
{
    printf("application to parse html\n");
    printf("usage:\n");
    printf("%s      [-?] [-v] [-asc | -desc] {-t tag | -a attribute}\nwhere\n", nm);
    printf("-?      this page\n");
    printf("-v      to show additional info\n");
    printf("-asc    set the ascending order of sorting\n");
    printf("-desc   set the ascending order of sorting\n");
    printf("-t tag  set the tag to search\n");
    printf("-a atr  set the attribute to search\n");
    exit(1);
}