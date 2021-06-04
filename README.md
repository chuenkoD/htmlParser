# htmlParser
This application find attribute parameters in html documents

## Installation
1. Clone the repository:
```bash
$ git clone https://github.com/chuenkoD/htmlParser
```
2. Open folder:
```bash
$ cd htmlParser
```
3. Compile the program or run script test.sh:

GCC:
```bash
$ g++ *.cpp /o parser.exe
```
Visual Studio:
```bash
$ cl *.cpp /EHsc /o parser.exe
```
or
```bash
$ ./test.sh
```
4. Run the program:
```bash
$ parser <in1.html -a name
```

## How to use
```bash
$ parser -?
application to parse html
usage:
./a.exe      [-?] [-v] [-asc | -desc] [-t tag] -a attribute
where
-?      this page
-v      to show additional info
-asc    set the ascending order of sorting
-desc   set the ascending order of sorting
-t tag  set the tag to search
-a atr  set the attribute to search
```
