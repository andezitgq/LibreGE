#ifndef DEBUG_H
#define DEBUG_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW  "\033[33m"

#include <iostream>
#include <string>
using namespace std;

class Debug
{
public:
    Debug();
    ~Debug();
    static void Log(string msg);
    static void Error(string msg);
    static void Warn(string msg);
};

#endif // DEBUG_H
