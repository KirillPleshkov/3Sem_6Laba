#pragma once
#include <string>
#include <iostream>

using namespace std;

class Logger
{
public:
    void AddLog(string);
    void Print();

private:
    string log;
  
};

