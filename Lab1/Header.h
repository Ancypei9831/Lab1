#pragma once


#include <vector>
using namespace std;

enum argument { programName, fileName };

enum indicator { success, cannotopen, wrongArgNum };

enum argnum { correctArgNum = 2 };

int parsing(vector<string>& v, char * file_name);

int usage_message(char* a);