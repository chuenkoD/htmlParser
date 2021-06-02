#ifndef HEAD
#define HEAD

#include <iostream>
#include <stdio.h>

using namespace std;

extern int keycmp(const char* arg, const char* key);
extern int isHelp(const char* s);
extern void help(const char* nm);

#endif