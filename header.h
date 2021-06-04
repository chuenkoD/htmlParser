#ifndef HEAD
#define HEAD

#include <iostream>
#include <stdio.h>
#include <string.h>

#ifdef _MSC_VER
#define strcasecmp stricmp
#endif

using namespace std;

extern int keycmp(const char* arg, const char* key);
extern int isHelp(const char* s);
extern void help(const char* nm);

#endif