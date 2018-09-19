========================================================================
    CONSOLE APPLICATION : Lab1 Project Overview
========================================================================
Ancy Pei Lab 1

Errors and Warnings: this program did not run into any error or warning.

/////////////////////////////////////////////////////////////////////////////

Trials: 

#1
H:\yupei332\Lab1\Lab1\Debug>Lab1.exe input_file.txt
these
all
are
strings
7string
str4ing
string2
more
strings
0
1
2
3
5
7
11
13
17
19

Analysis: this is correct behavior. It also returned success when the command echo %errorlevel% was run. 

#2
H:\yupei332\Lab1\Lab1\Debug>Lab1.exe
Wrong number of command line arguments
usage: Lab1.exe < input_file_name >
Analysis: only one command line was input while the correct number of command lines is 2.
(This is correct behavior, showing "Wrong number of command line arguments")

#3
H:\yupei332\Lab1\Lab1\Debug>Lab1.exe input_file.txt abc.txt
Wrong number of command line arguments
usage: Lab1.exe < input_file_name >
Analysis: three command lines were input while the correct number of command lines is 2.
(This is correct behavior, showing "Wrong number of command line arguments")

#4 
H:\yupei332\Lab1\Lab1\Debug>Lab1.exe abc.txt
Cannot Open File
Analysis: even though the number of command lines is correct, the file abc.txt cannot be found
(This is correct behavior because the second command line does not exist)


/////////////////////////////////////////////////////////////////////////////
